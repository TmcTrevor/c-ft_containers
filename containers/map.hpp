#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../tools/pair.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../tools/RBT.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "vector.hpp"

namespace ft
{

    template <class Key,                                            // map::key_type
              class T,                                              // map::mapped_type
              class Compare = std::less<Key>,                       // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<Key, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;

        class value_compare
        { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            // friend class map;
        protected:
            key_compare comp;

        public:
            value_compare() : comp() {}
            value_compare(key_compare c) : comp(c) {} // constructed with map's comparison object
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

        typedef ft::RBT<value_type, value_compare, allocator_type> RBT;
        typedef typename Node<value_type>::Nodeptr nodeptr;
        typedef typename Node<value_type>::const_Nodeptr const_nodeptr;
        typedef ft::BidiIterator<nodeptr, value_type, value_compare, Alloc> iterator;
        typedef ft::BidiIterator<nodeptr, const value_type, value_compare, Alloc> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef std::size_t size_type;

        // template <class Key, class T, class Compare, class Alloc>

        // private :
        RBT _rbt;
        key_compare _cmp;
        allocator_type _alloc;
        size_type size1;

    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _cmp(comp), _alloc(alloc), size1(0)
        {
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
            size_type a = 0;
            InputIterator f = first;
            while (f != last)
            {
                a++;
                f++;
            }
            insert(first, last);
            this->_cmp = comp;
            this->_alloc = alloc;
            this->size1 = a;
        }

        map(const map &x)
        {
            *this = x;
        }

        map &operator=(const map &t)
        {
           // std::cout << "operator = " << std::endl;
            if (size1 != 0)
                this->clear();
            this->insert(t.begin(), t.end());
            this->_alloc = t._alloc;
            this->_cmp = t._cmp;
           //std::cout << "t = " << t.size() << std::endl;
           //std::cout << "this = " << size() << std::endl;
            this->size1 = t.size();
           //std::cout << "this = " << this->size1 << std::endl;
            // _rbt = t._rbt;
            // }
            return *this;
        }

        ~map()
        {
            // std::cout << " sad" << std::endl;
            //clear();
        }
        /** ************************************************************************** */
        /**                               ITERATORS                                    */
        /** ************************************************************************** */

        iterator begin()
        {
            // std::cout << _rbt.begin()->data.first << std::endl;
            iterator it(_rbt.getRoot(), _rbt.begin());
            // std::cout << it << std::endl;
            return it;
        }

        const_iterator begin() const
        {
            return (const_iterator(_rbt.getRoot(), _rbt.begin()));
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
            return reverse_iterator(this->end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->begin());
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
            return size1;
        }

        size_type max_size() const
        {
            return _alloc.max_size();
        }

        /** ************************************************************************** **/
        /**                               ELEMENT ACCESS                               **/
        /** ************************************************************************** **/

        // mapped_type &operator[](const key_type &k)
        // {
        //     value_type a(k, mapped_type());
        //     // nodeptr node = _rbt.search(a);

        //     return (*((this->insert(a).first))).second;
        //     //   typename RBT::nodeptr node = _rbt.search(a);

        //     //     return node->data.second;
        // }
        mapped_type& operator[] (const key_type& k) { return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second; }
        /** ************************************************************************** **/
        /**                               Modifiers                                    **/
        /** ************************************************************************** **/

        ft::pair<iterator, bool> insert(const value_type &val)
        {
            nodeptr a;
            bool exists = false;

            if ((a = _rbt.search(_rbt.getRoot(), val)))
                exists = true;
            //std::cout << "insert" << std::endl;
            a = _rbt.insetINRbt(val);
            if (a)
                size1++;
            return ft::make_pair<iterator, bool>(iterator(_rbt.getRoot(), a), exists);
        }

        iterator insert(iterator position, const value_type &val)
        {
            static_cast<void>(position);
            nodeptr a = _rbt.insetINRbt(val);
            size1++;
            return iterator(_rbt.getRoot(), a);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                this->insert(*first);
                first++;
            }
        }

        void erase(iterator position)
        {
            // static_cast<void>(position);
            // std::cout << "erase" << std::endl;
            if (_rbt.empty() == true)
                return;
          //  std::cout << "erase" << std::endl;
            value_type a(position.base()->data.first, mapped_type());
            _rbt.deleteNode(a);
            size1--;
        }

        size_type erase(const key_type &k)
        {

            if (_rbt.empty() == true)
                return 0;
            // key_type &e = const_cast<key_type>(k);
            // key_type c = key_type();

            value_type a(k, mapped_type());
            size_type s = _rbt.getSize();
            _rbt.deleteNode(a);
            if (_rbt.getSize() != s)
            {
                size1--;
                return 1;
            }
            return 0;
        }

        void erase(iterator first, iterator last)
        {
            // ft::vector<key_type> a(0, 0);
            // if (_rbt.empty() == true)
            //     return;
            //  iterator it(first);
            //  iterator it1(last);
            // while (it1 != begin())
            // {
            //      a.insert(a.begin(), it.base()->data.first);
            //     --it1;
            // }
            // for (typename ft::vector<key_type>::iterator it2 = a.begin(); it2 != a.end(); ++it2)
            //     this->erase(*it2);
             if (_rbt.empty())
                return ;
                int a = 1;
            while (first != last)
            {
                // std::cout << " test " << a << std::endl;
                this->erase(first);
                first++;
                a++;
            }
        }

        void swap(map &x)
        {
            RBT _tmpTree = x._rbt;
            size_type i = x.size();
            x._rbt = this->_rbt;
            x.size1 = this->size();
            this->_rbt = _tmpTree;
            this->size1 = i;
        }

        void clear()
        {
            // calling erase from begin() to end();
            this->erase(begin(), end());
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

        iterator find(const key_type &k)
        {
            value_type a(k, mapped_type());
            nodeptr node = _rbt.search(_rbt.getRoot(), a);
            return iterator(_rbt.getRoot(), node);
        }

        const_iterator find(const key_type &k) const
        {
            value_type a(k, mapped_type());
            nodeptr node = _rbt.search(_rbt.getRoot(), a);
            return const_iterator(_rbt.getRoot(), node);
        }

        size_type count(const key_type &k) const
        {
             value_type a(k, mapped_type());
            // nodeptr node = _rbt.search(_rbt.getRoot(), a);
            // if (node)
            //     return 1;
            static_cast<void>(a);
            return (0);
        }

        iterator lower_bound(const key_type &k)
        {
            std::cout << "lower_bound iter" << std::endl;
            value_type a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
                return iterator(_rbt.getRoot(), node);
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return iterator(_rbt.getRoot(), node);
            }
            else if (node && _cmp(node->data.first, k))
                return iterator(_rbt.getRoot(), node);
            return end();
        }

        const_iterator lower_bound(const key_type &k) const
        {
            std::cout << " const lower_bound iter" << std::endl;
            value_type a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
                return const_iterator((_rbt.getRoot(), node));
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return const_iterator(_rbt.getRoot(), node);
            }
            else if (node && _cmp(node->data.first, k))
                return const_iterator(_rbt.getRoot(), node);
            return end();
        }
        iterator upper_bound(const key_type &k)
        {
            std::cout << "upper_bound iter" << std::endl;
            value_type a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
            {
                iterator a(_rbt.getRoot(), node);
                return ++a;
            }
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return iterator(_rbt.getRoot(), node);
            }
            else if (node && _cmp(node->data.first, k))
                return iterator(_rbt.getRoot(), node);
            return end();
        }

        const_iterator upper_bound(const key_type &k) const
        {
            std::cout << " const upper_bound iter" << std::endl;
            value_type a(k, mapped_type());
            nodeptr node = _rbt.place_search(a);

            if (node->data.first == k)
            {
                const_iterator a(_rbt.getRoot(), node);
                return ++a;
            }
            else if (!_cmp(node->data.first, k))
            {
                while (node->parent && !_cmp(node->data.first, k))
                    node = node->parent;
                return const_iterator(_rbt.getRoot(), node);
            }
            else if (node && _cmp(node->data.first, k))
                return const_iterator(_rbt.getRoot(), node);
            return end();
        }

        pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
        }

        pair<iterator, iterator> equal_range(const key_type &k)
        {
            return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
        }

        allocator_type get_allocator() const
        {
            return _alloc;
        }
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool
    operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return rhs < lhs;
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    }

}
#endif