#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/random_access_iterator.hpp"
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


    //// constructor
    Vector();
    ~Vector();
    Vector operator=(const Vector& c);

};
#endif