#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/utils.hpp"


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
             std::cout << "545613" << std::endl;
   }
	
    explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
                 {
                    _arr = this->alloc.allocate(n);
                    _current = n;
                    _capacity = n;
                    this->alloc = alloc;
                    for (int i = 0; i < n; i++)
                        this->alloc.construct(_arr + i , val);
                       // std::cout << "adasd" << std::endl;
                 }
	
    template <class Iterator>
    void vector_impl(Iterator first, Iterator last,std::input_iterator_tag)
    {
        //std::cout << "i am in input iteerator" << std::endl;
        
    }

     template <class Iterator>
    void vector_impl(Iterator first, Iterator last, std::random_access_iterator_tag)
    {
        std::cout << "i am in ra iteerator" << std::endl;
        _current = 0;
        _capacity = 0;
        while (start != last)
        {
            _current++;
            _capacity++;
            start++;
        }
    }
    // template <class Iterator>
    // void vector_impl(Iterator first, Iterator last, const allocator_type &alloc, typename iterator::iterator_category tag)
    // {
    //     std::cout << "i am in ra iteerator" << std::endl;
    // }
    template <class InputIterator>
         vector (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator >::type last,
                 const allocator_type& alloc = allocator_type()) 
                 {
                    //this->vector_impl(first, last, typename iterator_traits<InputIterator>::iterator_category());
                    this->alloc = alloc;
                    // InputIterator f = first;
                    // _current = 0;
                    // _capacity = 0;
                    // while (f != last)
                    // {
                    //     _current++;
                    //     _capacity++;
                    //     f++;
                    // }
                    // _arr = this->alloc.allocate(_capacity);
                    // int i = 0;
                    // while (first != last)
                    // {
                    //     this->alloc.construct((_arr + i), *first);
                    //     first++;
                    //     i++;
                    // }
                    //std::cout << "dasda" << std::endl;
                 }
	
    vector (const vector& x)
    {
        this->alloc = x.alloc;
        *this = x;
    }

    ~vector() {
        // if (_arr != nullptr) {
        // for (size_type i = 0; i < _current; i++)
        //    alloc.destroy(_arr + i);
        // alloc.deallocate(_arr, _capacity);
        // }
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