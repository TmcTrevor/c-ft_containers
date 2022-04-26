#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "../tools/RBT.hpp"

namespace ft
{

  
    // RANDOM_ACCESS_ITERATOR class

      template <class T>
	    std::ostream & operator<<(std::ostream &os, Node<T> const &c)
	    {
	    	std::cout << "dasdasd" << std::endl;
             os << c->data.first;
    	    os << c->data.second;
	        return os;
	    }
    template <class T, class value_compare, class Alloc >
    class BidiIterator
    {
        public :   
            typedef T         iterator_type;
		    // typedef typename ft::iterator_traits<T>::value_type			value_type;
		     typedef  T*		pointer;
		     typedef  T&		reference;
             typedef std::ptrdiff_t difference_type;
		   //  typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		// typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
             typedef typename ft::Node<iterator_type>::Nodeptr    nodeptr;
             typedef ft::RBT<T, value_compare, Alloc> RBT;
            typedef std::bidirectional_iterator_tag iterator_category;

        private :
           // typedef ft::RBT<value_type, ft::value_compare, Alloc>::
            nodeptr root;
            nodeptr max;
            nodeptr it;
            nodeptr prev;
            // nodeptr nil;


        public :
        /** ************************************************************************** */
		/**                                CONSTRUCTORS  AND DESTRUCTORS               */
		/** ************************************************************************** */
            
          
                BidiIterator() {it = NULL; root = NULL; max = NULL;}
                BidiIterator(nodeptr a) : it(a) { }
                template <typename it1>
                BidiIterator(const BidiIterator<it1, value_compare, Alloc>& a) : it(a.base()) {} 
                ~BidiIterator(){}
           ////////////////////////////////////////////////////



        /** ************************************************************************** */
		/**                                  MEMBERS                                   */
		/** ************************************************************************** */




            iterator_type base() const { return it; }

        /** ************************************************************************** */
		/**                                COMPARAISON OPERATORS PROTOTYPES            */
		/** ************************************************************************** */
        BidiIterator &operator=(BidiIterator const &c)
        {
            it = c.it;
            return *this;
        }

        // template <typename it1, typename it2>
        // friend bool operator==(const BidiIterator<it1> &, const BidiIterator <it2> &);

        // template <typename it1, typename it2>
        // friend bool operator!=(const BidiIterator<it1> &, const BidiIterator <it2> &);

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
           // std::cout << "reference operator = " << it << std::endl;
            return (*it).data;
        }

        pointer operator->() const
        {
            return it->data;
        }

        BidiIterator &operator++()
        {
            if (it == RBT::find_max(root))
                it = NULL;
            else
                it = RBT::successor(it);
            return *this;
        }

        BidiIterator &operator--()
        {
            --it;
            return *this;
        }
        BidiIterator operator++(int)
        {

            BidiIterator copie(*this);
            ++it;
            return copie;
        }
        BidiIterator operator--(int)
        {
            BidiIterator copie(*this);
            --it;
            return copie;
        }
        pointer search()
        {
            
        }
        /** ************************************************************************** */
		/**                                ARETHMETIC OPERATORS                        */
		/** ************************************************************************** */


        BidiIterator operator+(difference_type n)
        {
            return (this->it + n);
        }
        
        BidiIterator operator-(difference_type n)
        {
            return (this->it - n);
        }

        BidiIterator &operator+=(difference_type n)
        {
            it += n;
            return (*this);
        }

        BidiIterator &operator-=(difference_type n)
        {
            it -= n;
            return (*this);
        }

        reference operator[](difference_type n)
        {
            return (it[n]);
        }
        // template<class it1, class it2>
        // friend typename BidiIterator<it1>::difference_type operator-(const BidiIterator<it1> &cp1, const BidiIterator<it2> &cp2);
		// template<class it1>
		// friend BidiIterator<it1> operator+(typename BidiIterator<it1>::difference_type n, const BidiIterator<it1> &cp);
        
    }; /// RANDOM_ACCESS_ITERATOR class

    /** ************************************************************************** */
	/**                                COMPARAISON OPERATORS DEFINITION            */
	/** ************************************************************************** */
    
    // template <typename it1, typename it2>
    // bool operator==(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it == s1.it);
    // }

    // template <typename it1, typename it2>
    // bool operator!=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    // {
    //     return (s.it != s1.it);
    // }

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