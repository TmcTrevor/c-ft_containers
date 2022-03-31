#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    // RANDOM_ACCESS_ITERATOR class
    template <class T>
    class BidiIterator
    {
        public :   
            typedef T         iterator_type;
		    typedef typename ft::iterator_traits<T>::value_type			value_type;
		    typedef typename ft::iterator_traits<T>::pointer			pointer;
		    typedef typename ft::iterator_traits<T>::reference			reference;
		    typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		    typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        private :
            iterator_type it;

        public :
        /** ************************************************************************** */
		/**                                CONSTRUCTORS  AND DESTRUCTORS               */
		/** ************************************************************************** */

                BidiIterator() {it = NULL;}
                BidiIterator(iterator_type a) : it(a) {}
                template <typename it1>
                BidiIterator(const BidiIterator<it1>& a) : it(a.base()) {} 
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

        template <typename it1, typename it2>
        friend bool operator==(const BidiIterator<it1> &, const BidiIterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator!=(const BidiIterator<it1> &, const BidiIterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator>=(const BidiIterator<it1> &, const BidiIterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator<=(const BidiIterator<it1> &, const BidiIterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator>(const BidiIterator<it1> &, const BidiIterator <it2> &);
        
        template <typename it1, typename it2>
        friend bool operator<(const BidiIterator<it1> &, const BidiIterator <it2> &);

        /** ************************************************************************** */
		/**                                ACCESS OPERATORS                            */
		/** ************************************************************************** */

        reference operator*()
        {
            return *it;
        }

        pointer operator->() const
        {
            return it;
        }
        BidiIterator &operator++()
        {
            ++it;
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
        template<class it1, class it2>
        friend typename BidiIterator<it1>::difference_type operator-(const BidiIterator<it1> &cp1, const BidiIterator<it2> &cp2);
		template<class it1>
		friend BidiIterator<it1> operator+(typename BidiIterator<it1>::difference_type n, const BidiIterator<it1> &cp);
        
    }; /// RANDOM_ACCESS_ITERATOR class

    /** ************************************************************************** */
	/**                                COMPARAISON OPERATORS DEFINITION            */
	/** ************************************************************************** */
    
    template <typename it1, typename it2>
    bool operator==(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it == s1.it);
    }

    template <typename it1, typename it2>
    bool operator!=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it != s1.it);
    }

    template <typename it1, typename it2>
    bool operator>=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it >= s1.it);
    }

    template <typename it1, typename it2>
    bool operator<=(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it <= s1.it);
    }

    template <typename it1, typename it2>
    bool operator>(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it > s1.it);
    }
 
    template <typename it1, typename it2>
    bool operator<(const BidiIterator<it1> &s, const BidiIterator <it2> &s1)
    {
        return (s.it < s1.it);
    }

    template<class it1, class it2>
    typename BidiIterator<it1>::difference_type operator-(const BidiIterator<it1> &cp1, const BidiIterator<it2> &cp2)
	{
        return (cp1.base() - cp2.base());
    }
    template<class it1>
	BidiIterator<it1> operator+(typename BidiIterator<it1>::difference_type n, const BidiIterator<it1> &cp)
    {
        return (BidiIterator<it1>(cp.base() + n));
    }
} // for namespace
#endif