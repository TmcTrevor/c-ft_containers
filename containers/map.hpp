#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../tools/pair.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../tools/RBT.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft {

    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > 
    class map
    {
        public :
            typedef Key key_type;
            typedef T   mapped_type;
            typedef ft::pair<const Key, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

            class value_compare
            {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
                //friend class map;
                protected:
                key_compare comp;
                public :
                value_compare() : comp() {}
                value_compare (key_compare c) : comp(c) {}  // constructed with map's comparison object
               	public:
                	typedef bool result_type;
                	typedef value_type first_argument_type;
                	typedef value_type second_argument_type;
                	bool operator() (const value_type& x, const value_type& y) const
                	{
                	    return comp(x.first, y.first);
                	}
			};
            typedef ft::RBT<value_type, value_compare, allocator_type> RBT;
            typedef ft::BidiIterator<value_type, value_compare, Alloc > iterator;
            //typedef ft::BidiIterator<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            //typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
            typedef std::size_t     size_type;


            //template <class Key, class T, class Compare, class Alloc>

       // private :
            RBT _rbt;
            key_compare _cmp;
			allocator_type _alloc;
			size_type size;
            
        public :
            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _cmp(comp), _alloc(alloc), size(0)
            {

            }

        template <class InputIterator>
             map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type())
        {
                
        }
	
        map (const map& x)
        {

        }

        iterator begin()
        {
            //std::cout << _rbt.begin()->data.first << std::endl;
            iterator it(_rbt.begin());
           // std::cout << it << std::endl;
            return it;
        }
    
    };

    

}
#endif