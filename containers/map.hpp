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
            typedef ft::BidiIterator<const value_type, value_compare, Alloc > const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
            typedef std::size_t     size_type;
            typedef typename Node<value_type>::Nodeptr    nodeptr;
            typedef typename Node<value_type>::const_Nodeptr    const_nodeptr;

            //template <class Key, class T, class Compare, class Alloc>

       // private :
            RBT _rbt;
            key_compare _cmp;
			allocator_type _alloc;
			size_type size1;
            
        public :
            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _cmp(comp), _alloc(alloc), size1(0)
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

    /** ************************************************************************** */
	 /**                               ITERATORS                                    */
	 /** ************************************************************************** */

        
        iterator begin()
        {
            //std::cout << _rbt.begin()->data.first << std::endl;
            iterator it(_rbt.begin());
           // std::cout << it << std::endl;
            return it;
        }

        const_iterator begin() const
        {
            return (const_iterator(_rbt.begin()));
        }

        iterator end()
        {
            return iterator(_rbt.getRoot(), _rbt.end());
        }

        const_iterator end() const
        {
            return (const_iterator(_rbt.getRoot(), _rbt.end()));
        }

        reverse_iterator rbegin()
        {
            reverse_iterator(RBT::find_max(_rbt.root));
        }

        const_reverse_iterator rbegin() const
        {
                const_reverse_iterator(RBT::find_max(_rbt.root));
        }


        reverse_iterator rend()
        {
                return reverse_iterator(end());
        }
        const_reverse_iterator rend() const
        {
            return reverse_iterator(end());
        }


        /** ************************************************************************** **/
	    /**                               CAPACITY                                     **/
	    /** ************************************************************************** **/

        bool empty() const
        {
            return _rbt.empty();
        }

        size_type size() const
        {
            return _rbt.getSize();
        }

        size_type max_size() const
        {
            return _alloc.max_size();
        }
        
         /** ************************************************************************** **/
	/**                               ELEMENT ACCESS                               **/
	/** ************************************************************************** **/
       
       mapped_type& operator[] (const key_type& k)
       {
        //    value_type a(k, mapped_type());

        //   typename RBT::nodeptr node = _rbt.search(a);
        //     return node->data.second;

       }
        /** ************************************************************************** **/
	    /**                               Modifiers                                    **/
	    /** ************************************************************************** **/

	
        ft::pair<iterator,bool> insert (const value_type& val)
        {
            //nodeptr a(val);
            bool exists = false;
            if (!_rbt.search(val))
                exists = true;
            nodeptr a = _rbt.insetINRbt(val);
           // std::cout << exists << std::endl;
            return ft::make_pair<iterator, bool>(iterator(_rbt.getRoot(), a), exists);
        }
     
        iterator insert (iterator position, const value_type& val)
        {
             nodeptr a = _rbt.insetINRbt(val);
             return iterator(_rbt.getRoot(), a);
        }
    
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
                while (first != last)
                {
                    this->insert(*first);
                    first++;
                }
        }


        void erase (iterator position)
        {
                _rbt.deleteNode(position.base());
        }

       void erase (const key_type& k)
        {
            
        }
        void erase (iterator first, iterator last)
        {

        }

        void swap (map& x)
        {
            RBT _tmpTree = x->_rbt;
            size_type i = x->size();
            x->_rbt = this->_rbt;
            x->size1 =  this->size();
            this->_rbt = _tmpTree;
            this->size1 = i;
        }
        void clear()
        {
            //calling erase from begin() to end();
        }

        /** ************************************************************************** **/
	    /**                               OBSERVERS                                    **/
	    /** ************************************************************************** **/

        key_compare key_comp() const
        {
            return _cmp;
        }

        value_compare value_comp() const
        {
            return value_compare(_cmp);
        }
         /** ************************************************************************** **/
	    /**                               OPERATIONS                                    **/
	    /** ************************************************************************** **/

         iterator find (const key_type& k)
         {
            ft::pair<key_type, mapped_type> a(k, mapped_type()) ;
            nodeptr node = _rbt.search(a);
            return iterator(_rbt.getRoot(), a);
         }

        const_iterator find (const key_type& k) const
        {
            ft::pair<key_type, mapped_type> a(k, mapped_type());
            nodeptr node = _rbt.search(a);
            return const_iterator(_rbt.getRoot(), a);
        }

        size_type count (const key_type& k) const
        {
            if (find(k))
                return 1;
            return (0);
        }

        iterator lower_bound (const key_type& k)
        {
            std::cout << "lower_bound iter" << std::endl;
            ft::pair<const key_type, mapped_type> a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
                 return iterator(_rbt.getRoot(), node);
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return iterator(_rbt.getRoot(), node);
            }
            else  if (node && _cmp(node->data.first, k))
                return iterator(_rbt.getRoot(),node);
            return end();
        }

        const_iterator lower_bound (const key_type& k) const
        {
            std::cout << " const lower_bound iter" << std::endl;
            ft::pair<const key_type, mapped_type> a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
                 return const_iterator((_rbt.getRoot(), node));
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return const_iterator(_rbt.getRoot(), node);
            }
            else  if (node && _cmp(node->data.first, k))
                return const_iterator(_rbt.getRoot(), node);
            return end();
        }

        

    };

    

}
#endif