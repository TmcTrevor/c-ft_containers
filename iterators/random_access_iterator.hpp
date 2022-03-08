#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

//#include "utils.hpp"
#include <iterator_traits.hpp>
namespace ft
{
    // RANDOM_ACCESS_ITERATOR class
    template <typename T>
    class Ra_iterator : public ft::iterator<ft::random_access_iterator , T>
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

                Ra_iterator() {it = NULL;}
                Ra_iterator(iterator_type a) : it(a) {}
                template <typename T>
                Ra_iterator(const Ra_iterator<T>& a) :  {*this = a;}
                ~Ra_iterator(){}
           ////////////////////////////////////////////////////



        /** ************************************************************************** */
		/**                                  MEMBERS                                   */
		/** ************************************************************************** */




            iterator_type base() const { return iterator; }

        /** ************************************************************************** */
		/**                                COMPARAISON OPERATORS PROTOTYPES            */
		/** ************************************************************************** */
        Ra_iterator &operator=(Ra_iterator const &c)
        {
            it = c.it;
        }

        template <typename it1, typename it2>
        friend bool operator==(const Ra_iterator<it1> &, const Ra_iterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator!=(const Ra_iterator<it1> &, const Ra_iterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator>=(const Ra_iterator<it1> &, const Ra_iterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator<=(const Ra_iterator<it1> &, const Ra_iterator <it2> &);

        template <typename it1, typename it2>
        friend bool operator>(const Ra_iterator<it1> &, const Ra_iterator <it2> &);
        
        template <typename it1, typename it2>
        friend bool operator<(const Ra_iterator<it1> &, const Ra_iterator <it2> &);

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
        Ra_iterator &operator++()
        {
            ++it;
            return *this;
        }
        Ra_iterator &operator--()
        {
            --it;
            return *this;
        }
        Ra_iterator operator++(int)
        {
            Ra_iterator copie(*this);
            ++it;
            return copie;
        }
        Ra_iterator operator--(int)
        {
            Ra_iterator copie(*this);
            --it;
            return copie;
        }

        /** ************************************************************************** */
		/**                                ARETHMETIC OPERATORS                        */
		/** ************************************************************************** */


        Ra_iterator operator+(difference_type n)
        {
            return (this->it + n);
        }
        
        Ra_iterator operator-(difference_type n)
        {
            return (this->it - n);
        }

        Ra_iterator operator+=(difference_type n)
        {
            it += n;
            return (*this);
        }

        Ra_iterator operator-=(difference_type n)
        {
            it -= n;
            return (*this);
        }

        Ra_iterator operator[](difference_type n)
        {
            return (*(this->it));
        }

        
    }; /// RANDOM_ACCESS_ITERATOR class

    /** ************************************************************************** */
	/**                                COMPARAISON OPERATORS DEFINITION            */
	/** ************************************************************************** */
    
    template <typename it1, typename it2>
    bool operator==(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it == s1.it);
    }

    template <typename it1, typename it2>
    bool operator!=(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it != s1.it);
    }

    template <typename it1, typename it2>
    bool operator>=(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it >= s1.it);
    }

    template <typename it1, typename it2>
    bool operator<=(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it <= s1.it);
    }

    template <typename it1, typename it2>
    bool operator>(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it > s1.it);
    }

    template <typename it1, typename it2>
    bool operator<(const Ra_iterator<it1> &s, const Ra_iterator <it2> &s1)
    {
        return (s.it < s1.it);
    }


} // for namespace
#endif