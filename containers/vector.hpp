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
        while (first != last)
        {
            _current++;
            _capacity++;
            first++;
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
                    this->alloc = alloc;
                    this->vector_impl(first, last, typename iterator_traits<InputIterator>::iterator_category());
                    // InputIterator f = first;
                    // _current = -
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
        if (_arr != nullptr) {
        for (size_type i = 0; i < _current; i++)
           alloc.destroy(_arr + i);
        alloc.deallocate(_arr, _capacity);
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
        return alloc.max_size();
    }

    void resize (size_type n, value_type val = value_type()) /// resize the the vector (destroy extra element if n < current size) else reallocate and insert val;
    {
        if (n > max_size())
            throw std::length_error("vector::resize");
        if (n < _current)
        {
            for (size_type i = n; i < _current;i++)
                this->alloc.destroy(_arr + i);
            this->alloc.deallocate(_arr + n, _capacity);
        }
        else
        {
            // reserve and insert
        }
        _current = n;
    }

    size_type capacity() const
    {
        return _capacity;
    }
    bool empty() const
    {
        if (_current == 0)
            return (true);
        return false;
    }
    void reserve (size_type n)              // reallocate the array with n 
    {
         if (n > max_size())
            throw std::length_error("vector::resize");
        if (n > _capacity)
        {
            pointer tmp = nullptr;
            tmp = this->alloc.allocate(n);
            size_type i;
            for (i = 0; i < this->size(); i++)
            {
                this->alloc.construct(tmp + i, _arr[i]);
                this->alloc.destroy(_arr + i);
            }
           // std::cout << "i = " <<  i << std::endl;
            this->alloc.deallocate(_arr, _capacity);
            _arr = nullptr;
            _arr = tmp;
            _capacity = n;
           
        }

    }


    void shrink_to_fit()            //// change the allocation size to the _current aka size of vector
    {
        if (_capacity != _current)
        {
            pointer tmp = nullptr;
            tmp = this->alloc.allocate(_current);
            size_type i;
            for (i = 0; i < this->size(); i++)
            {

                this->alloc.construct(tmp + i, _arr[i]);
                this->alloc.destroy(_arr + i);
            }
            this->alloc.deallocate(_arr, _capacity);
            _arr = tmp;
            _capacity = _current;
        }
    }

    /** ************************************************************************** **/
	/**                               ELEMENT ACCESS                               **/
	/** ************************************************************************** **/
       reference operator[] (size_type n)
       {
           return  _arr[n];
       }

        const_reference operator[] (size_type n) const
        {
            return _arr[n];
        }

        reference at (size_type n)
        {
            if (n < 0 || n >= size())
                throw "vector";
            return _arr[n];
        }
        const_reference at (size_type n) const
        {
            if (n < 0 || n >= size())
                    throw "vector";
            return _arr[n];
        }
        reference front()
        {
            return (_arr[0]);

        }
        const_reference front() const
        {
            return (_arr[0]);
        }
        reference back()
        {
            return (_arr[size() - 1]);
        }
        const_reference back() const
        {
            return (_arr[size() - 1]);
        }

    /** ************************************************************************** **/
	/**                               Modifiers                                    **/
	/** ************************************************************************** **/

    template <class InputIterator>
    void assign (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator >::type last)
    {
        InputIterator f = first;
        difference_type n = 0;

        while (f != last)
        {
            f++;
            n++;
        }
        if (n != 0)
        {
            if (n > _capacity)
            {
                reserve(n);
                _capacity = n;
            }
            for (size_type i = 0; i < n; i++)
            {
                if (i < size())
                    this->alloc.destroy(_arr + i);
                this->alloc.construct(_arr + i, *first);
                first++;
            }
            _current = n;
        }
    }
	
    void assign (size_type n, const value_type& val)
    {
        if (n > _capacity)
            reserve(n);
        for (size_type i = 0; i < n; i++)
        {
            if (i < size())
                this->alloc.destroy(_arr + i);
            this->alloc.construct(_arr + i, val);
        }
        _current = n;
    }

    void push_back (const value_type& val)
    {
        if (empty())
            reserve(1);
        else if (_current + 1 > _capacity)
            reserve(_capacity * 2);
        this->alloc.construct(_arr + _current, val);
        _current++;
    }

    void pop_back()
    {
        this->alloc.destroy(_arr + _current);
        _current--;
    }

    iterator insert (iterator position, const value_type& val)
    {
        iterator a = this->begin();
        size_type n = 0;
        if (empty())
            reserve(1);
        else if (_current + 1 > _capacity)
            reserve(_capacity * 2);
        while (a != position)
        {
            n++;
            a++;
        }
        for (size_t i = n; i <= size(); i++)
            this->alloc.construct(_arr + i + 1, _arr[i]);
        this->alloc.construct(_arr + n, val);
        _current++;
        return (iterator(_arr + n));
    }

    void insert (iterator position, size_type n, const value_type& val)
    { 
        iterator a = begin();
        size_type e = 0;
        if (n + size() > _capacity)
        {
            if (n + size() > _capacity * 2)
                reserve(n + size());
            else
                reserve(_capacity * 2);    
        }
        while (a != position)
        {
            e++;
            a++;
        }
        for (size_type i = e; i <= size(); i++)
            this->alloc.construct(_arr + i + n, _arr[i]);
        for (size_type i = e; i < n;i++)
            this->alloc.construct(_arr + i, val);
        _current+=n;
    }
    template <class InputIterator>
    void insert (iterator position, InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator >::type last)
    {
        size_type e = 0;
        size_type n = 0;
        InputIterator a = first;
         iterator pos = begin();
        while (a != last)
        {
            a++;e++;
        }
        if (e != 0)
        {
            if (e + size() > _capacity * 2)
                reserve(e + size());
            else
                reserve(_capacity * 2);
            while (pos != position)
            {
                pos++;n++;
            }
            for (size_type i = n; i <= size(); i++)
                this->alloc.construct(_arr + i + e, _arr[i]);
            for (size_type i = n; i < e;i++)
            {
                this->alloc.construct(_arr + i, *first);
                first++;
            }
            _current+=e;
        }
        //     iterator a;
        //     for (;first != last; ++first)
        //     {
        //         a = iterator(_arr + n);
        //         insert(a, *first);
        //     } //
    }
    iterator erase (iterator position)
    {
        
    }
    iterator erase (iterator first, iterator last)
    {

    }

}; /// end class vector
} //end namespace
#endif