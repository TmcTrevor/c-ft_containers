#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"


namespace ft {

template < class T, class Alloc = std::allocator<T> > 
class vector
{
    public :

    typedef T value_type;
    typedef Alloc allocator_type;
    typedef allocator_type::reference reference;
    typedef allocator_type::const_reference const_reference;
    typedef allocater_type::pointer pointer;
    typedef allocator_type::const_pointer const_pointer;
    typedef ft::Ra_iterator<pointer> iterator;
    typedef ft::Ra_iterator<const_pointer> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef typename ft::iterator_traits<iterator>::value_type value_type;difference_type	difference_type;
    typedef std::size_t     size_type;

    private :
        pointer _arr;
        allocator_type alloc;
        size_type       _current;
        size_type       _capacity;
    
    public :

     /** ************************************************************************** */
	 /**     MEMBER FUNCTION  : CONSTRUCTORS & DESTRUCTOR                           */
	 /** ************************************************************************** */

   explicit vector (const allocator_type& alloc = allocator_type())
   {
            _capacity = 0;
            _current = 0;
            _arr = nullptr;
            this->alloc = alloc;
   }
	
    explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
                 {
                    _arr = alloc.allocate(n);
                    _current = n;
                    _capacity = n;
                    this->alloc = alloc;
                    for (int i = 0; i < n; i++)
                        this->alloc.construct(_arr + i , val);
                 }
	
    template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
                 {
                    this->alloc = alloc;
                    InputIterator f = first;
                    while (f != last)
                    {
                        _current++;
                        _capacity++;
                        f++;
                    }
                    this->alloc.allocate(_current);
                    int i = 0;
                    while (first != last)
                    {
                        this->alloc.construct((_arr + i), *first);
                        first++;
                        i++;
                    }
                 }
	
    vector (const vector& x)
    {
        *this = x;
    }

    ~vector() {
        if (_arr != nullptr) {
        for (int i = 0; i < _current; i++)
            this->alloc.destroy(_arr + i);
        this->alloc.deallocate(_arr, capacity);
        }
    }
    
    vector operator=(const vector& c)
    {
        if (*this != c)
        {
            for (size_t i = 0; i < _current; i++)
                this->alloc.destroy(_arr + i);
            //if (this->_capacity > 0)
                this->alloc.deallocate(_arr, capacity);
            this->_current = c._current;
            this->_capacity = c._capacity;
           // this->alloc = c.alloc;
            this->alloc.allocate(c._capacity);
            for (size_t i = 0; i < c._current;i++)
                this->alloc.construct(_arr + i, c._arr + i);
           
            
        }
        return *this;
    }

     /** ************************************************************************** */
	 /**                                CONSTRUCTOR & DESTRUCTOR                    */
	 /** ************************************************************************** */

    


}; /// end class vector
} //end namespace
#endif