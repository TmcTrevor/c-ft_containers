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
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef ft::Ra_iterator<pointer> iterator;
    typedef ft::Ra_iterator<const_pointer> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
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
        this->alloc = x.alloc;
        *this = x;
    }

    ~vector() {
        if (_arr != nullptr) {
        for (int i = 0; i < _current; i++)
            this->alloc.destroy(_arr + i);
        this->alloc.deallocate(_arr, _capacity);
        }
    }
    
    vector operator=(const vector& c)
    {
        if (*this != c)
        {
            for (size_t i = 0; i < _current; i++)
                this->alloc.destroy(_arr + i);
            this->alloc.deallocate(_arr, _capacity);
            this->_current = c._current;
            if (this->_capacity < c->_capacity)
                this->_capacity = c._current;
           // this->alloc = c.alloc;
            this->alloc.allocate(c._capacity);
            for (size_t i = 0; i < c._current;i++)
                this->alloc.construct(_arr + i, c._arr + i);
        }
        return *this;
    }

     /** ************************************************************************** */
	 /**                               ITERATORS                                    */
	 /** ************************************************************************** */

    iterator begin()
    {
        return iterator(_arr);
    }

    const_iterator begin() const
    {
        return (const_iterator(_arr));
    }

    iterator end()
    {
        return (iterator(_arr + _current));
    }
    const_iterator end() const
    {
        return (const_iterator(_arr + _current));
    }
    reverse_iterator rbegin()
    {
        return (reverse_iterator(_arr + _current));
    }
    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(_arr + _current));
    }

     /** ************************************************************************** */
	 /**                               CAPACITY                                     */
	 /** ************************************************************************** */

    size_type size() const 
    {
        return _current;
    }

    size_type max_size() const
    {
        return alloc->max_size();
    }

    void resize (size_type n, value_type val = value_type())
    {
        if (_capacity < n)
            _capacity = n;
        if (_current > n)
        {
            for (size_type i = n; i < _current;i++)
                this->alloc.destroy(_arr + i);
            this->alloc.deallocate(_arr + n, _capacity);
        }
        else
        {
            this->alloc.allocate(n);
             for (size_type i = _current; i < n; i++)
                this->alloc.construct(_arr +i, val);
        }
        _current = n;
    }



}; /// end class vector
} //end namespace
#endif