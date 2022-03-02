#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include <iostream>
#include "../tools/iterator_traits.hpp"

// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
//   struct iterator {
//     typedef T         value_type;
//     typedef Distance  difference_type;
//     typedef Pointer   pointer;
//     typedef Reference reference;
//     typedef Category  iterator_category;
//   };


template <class T>
class Myiterator
{
    private:

    public:

    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;

};

#endif