#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "../tools/RBT.hpp"
//#include "../includes/mapInclude.hpp"
// #include "../÷"

namespace ft
{
    template <class Node, class T, class value_compare, class Alloc >
    class BidiIterator
    {
        public :   
            typedef T         value_type;
            typedef Node      iterator_type;
		    // typedef typename ft::iterator_traits<T>::value_type			value_type;
		     typedef  T*		pointer;
		     typedef  T&		reference;
             typedef std::ptrdiff_t difference_type;
		   //  typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		// typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
            //  typedef typename ft::Node<iterator_type>  Node;
            //  typedef typename ft::Node<iterator_type>::Nodeptr    nodeptr;
            //  typedef typename ft::Node<iterator_type>::Nodeptr    const_nodeptr;
             typedef ft::RBT<T, value_compare, Alloc> RBT;
            typedef std::bidirectional_iterator_tag iterator_category;

        private :
           // typedef ft::RBT<value_type, ft::value_compare, Alloc>::
            typedef BidiIterator<const iterator_type, value_type, value_compare, Alloc > const_iterator;
            Node root;
            // Node max;
            Node it;
            // nodeptr prev;
            // nodeptr nil;


        public :
        /** ************************************************************************** */
		/**                                CONSTRUCTORS  AND DESTRUCTORS               */
		/** ************************************************************************** */
            
          
                BidiIterator() {it = NULL; root = NULL;}
                BidiIterator(const Node a) : it(a) { root = a->find_root(a); }
                BidiIterator(const Node root, const Node a) : it(a)
                {
                    if (root)
                        //std::cout << tree.root->data.first << std::endl;
                        this->root = root;
                }
                //   BidiIterator(const_Node root, const_Node a) : it(a)
                // {
                //     if (root)
                //         //std::cout << tree.root->data.first << std::endl;
                //         this->root = root;
                // }
                operator const_iterator()
	            {
	            	// overload for const cast
	            	return const_iterator(root, it);
	            } 
                // template<typename it1>
                //  operator bidirectional_iterator<TT> () { return bidirectional_iterator<TT> (reinterpret_cast <typename bidirectional_iterator<TT>::node_ptr> (__current) , reinterpret_cast <typename bidirectional_iterator<TT>::node_ptr *> (__root)); }
                // operator BidiIterator<it1, value_compare, Alloc> () { return BidiIterator<it1, value_compare, Alloc>(reinterpret_cast< typename BidiIterator<it1 , value_compare, Alloc>::Node> (root), reinterpret_cast<typename BidiIterator<it1, value_compare, Alloc>::Node>(it));}
                template <typename it1>
                BidiIterator(const BidiIterator<Node, it1, value_compare, Alloc>& a) : it(a.base()) {this->root = a.getRoot();} 
                ~BidiIterator()
                {
                    
                }

                // operator const_Node() const
                // {
                //     return this->base();
                // }
           ////////////////////////////////////////////////////



        /** ************************************************************************** */
		/**                                  MEMBERS                                   */
		/** ************************************************************************** */




            Node base() const { return it; }
            Node getRoot() const { return root;}
            // const_nodeptr base() const { return it; }

        /** ************************************************************************** */
		/**                                COMPARAISON OPERATORS PROTOTYPES            */
		/** ************************************************************************** */
        BidiIterator &operator=(BidiIterator const &c)
        {
            it = c.it;
            root = c.root;
            return *this;
        }

      
        template <class Node1,class it1, typename it2, class value_compare1, class Alloc1 >
        friend bool operator==(const BidiIterator<Node1, it1, value_compare1, Alloc1> &a, const BidiIterator <Node1, it2, value_compare1, Alloc1> &b);
      

          template <class Node1,class it1, typename it2, class value_compare1, class Alloc1 >
        friend bool operator!=(const BidiIterator<Node1, it1, value_compare1, Alloc1> &a, const BidiIterator <Node1, it2, value_compare1, Alloc1> &b);
        

        // template <typename it1, typename it2>
        // friend bool operator>=(const BidiIterator<it1> &, const BidiIterator <it2> &);

        // template <typename it1, typename it2>
        // friend bool operator<=(const BidiIterator<it1> &, const BidiIterator <it2> &);

        // template <typename it1, typename it2>
        // friend bool operator>(const BidiIterator<it1> &, const BidiIterator <it2> &);
        
        // template <typename it1, typename it2>
        // friend bool operator<(const BidiIterator<it1> &, const BidiIterator <it2> &);

        /** ************************************************************************** */
		/**                                ACCESS OPERATORS                            */
		/** ************************************************************************** */

        reference operator*()
        {
        //    std::cout << "reference operator = " << std::endl;
            // if (it == NULL)
            //     return ;
            // return it->data;
            return *(operator->());
        }

        pointer operator->() const
        {
            if (it == NULL)
                return NULL ;
            return &(it->data);
            //return (&operator*());
        }

        BidiIterator &operator++()
        {
            //  if (it == RBT::find_max(root))
            if (it == find_max(root))
                it = NULL;
            else
                it = successor(it);
            return *this;
        }

        BidiIterator &operator--()
        {
            // std::cout << root->data.first << std::endl;
            if (it == NULL)
                it = find_max(root);
            else
                it = predecessor(it);
            return *this;
        }

        BidiIterator operator++(int)
        {

            BidiIterator copie(*this);
            ++(*this);
            return copie;
        }
        BidiIterator operator--(int)
        {
            BidiIterator copie(*this);
            --(*this);
            return copie;
        }
        // pointer search()
        // {
            
        // }
        /** ************************************************************************** */
		/**                                ARETHMETIC OPERATORS                        */
		/** ************************************************************************** */


            Node find_min(Node x)
		{
			//std::cout << "find_min" << std::endl;
			//x = x->right;
			if (x == NULL)
				return NULL;
			while (x->left != NULL)
				x = x->left;
			return x;
		}
		
	Node find_max(Node x)
		{
			if (x == NULL)
				return NULL;
			while (x->right != NULL)
				x = x->right;
			return x;
			
		}

	Node predecessor(Node x)
		{
			Node y;

			if (x->left != NULL)
				return (find_max(x->left));
			y = x->parent;
			while (y && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

	Node successor(Node x)
		{
			Node y;
			
			if (x->right != NULL)
				return (find_min(x->right));
			y = x->parent;
			while (y && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
        
    }; /// RANDOM_ACCESS_ITERATOR class

    /** ************************************************************************** */
	/**                                COMPARAISON OPERATORS DEFINITION            */
	/** ************************************************************************** */
    

    
      template <class Node, class it1, typename it2, class value_compare1, class Alloc1 >
    bool operator==(const BidiIterator<Node, it1, value_compare1, Alloc1> &a, const BidiIterator <Node, it2, value_compare1, Alloc1> &b)
    {
        if (a.base() == NULL && b.base() == NULL)
            return true;
        return (a.it == b.it);
    }

      template <class Node, class it1, typename it2, class value_compare1, class Alloc1 >
    bool operator!=(const BidiIterator<Node, it1, value_compare1, Alloc1> &a, const BidiIterator <Node, it2, value_compare1, Alloc1> &b)
    {
        // =std::cout << "dasd" << std::endl;
        if (a.base() == NULL && b.base() == NULL)
            return false;
        return (a.it != b.it);
    }

    // template <typename it1, typename it2>
    // bool operator>=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it >= s1.it);
    // }

    // template <typename it1, typename it2>
    // bool operator<=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it <= s1.it);
    // }

    // template <typename it1, typename it2>
    // bool operator>(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it > s1.it);
    // }
 
    // template <typename it1, typename it2>
    // bool operator<(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it < s1.it);
    // }

    // template<class it1, class it2>
    // typename BidiIterator<it1>::difference_type operator-(const BidiIterator<it1> &cp1, const BidiIterator<it2> &cp2)
	// {
    //     return (cp1.base() - cp2.base());
    // }
    // template<class it1>
	// BidiIterator<it1> operator+(typename BidiIterator<it1>::difference_type n, const BidiIterator<it1> &cp)
    // {
    //     return (BidiIterator<it1>(cp.base() + n));
    // }
} // for namespace∏
#endif