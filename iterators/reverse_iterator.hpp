#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "utils.hpp"

namespace ft {

    template <class Iterator>
    class reverse_iterator 
    {
        public :   
            typedef Iterator        iterator_type;
		    typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		    typedef typename ft::iterator_traits<Iterator>::pointer			pointer;
		    typedef typename ft::iterator_traits<Iterator>::reference			reference;
		    typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
		    typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        private :
            iterator_type rv;

        public :
            ~reverse_iterator(){};
            
            reverse_iterator() { rv = NULL; }
            
            reverse_iterator(iterator_type rv) { this->rv = rv; }
            
            reverse_iterator(reverse_iterator const &c) { rv = c.rv; }
            
            template<typename iterator1>
            reverse_iterator operator=(reverse_iterator<iterator1> const &c) { rv = c.base(); return *this; }
            
            iterator_type base() const { return rv; }
            
            reference operator*() const 
            {
                iterator_type tmp = rv;
                --tmp;
                return (*tmp);
            }

            pointer operator->() const
            {
                return (&(operator*()));
            }

            reverse_iterator &operator++()
            {
                --rv;
                return (*this);
            }

            reverse_iterator &operator--()
            {
                 ++rv;
                return *this;
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator copy(*this);
                ++rv;
                return copy;
            }

            reverse_iterator operator++(int)
            {   
                reverse_iterator copy(*this);
                --rv;
                return copy;
            }

        /** ************************************************************************** */
		/**                                ARETHMETIC OPERATORS                        */
		/** ************************************************************************** */


        reverse_iterator operator+(difference_type n)
        {
            return (this->rv - n);
        }
        
        reverse_iterator operator-(difference_type n)
        {
            return (this->rv + n);
        }

        reverse_iterator &operator+=(difference_type n)
        {
            rv -= n;
            return (*this);
        }

        reverse_iterator &operator-=(difference_type n)
        {
            rv += n;
            return (*this);
        }

        reference operator[](difference_type n)
        {

            return (*(*this + n));
        }

    template <class it1, class it2>
	friend bool operator<  (const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2);

    };// end of class reverse iterator 
    template <class it1, class it2>
bool operator==(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return cp1.base() == cp2.base();
}

template <class it1, class it2>
bool operator<  (const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return (cp1.base() > cp2.base());
}
template <class it1, class it2>
bool operator>  (const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return (cp1.base() < cp2.base());
}

template <class it1, class it2>
bool operator!=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return cp1.base() != cp2.base();
}

template <class it1, class it2>
bool operator<=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return cp1.base() >= cp2.base();
}

template <class it1, class it2>
bool operator>=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
{
    return cp1.base() <= cp2.base();
}

//operator- (reverse_iterator)
template <class it1, class it2>
typename reverse_iterator<it1>::difference_type operator-(const reverse_iterator<it1>& __x, const reverse_iterator<it2>& __y)
{
    return (__y.base()) - (__x.base());
}

template <class it1>
reverse_iterator<it1> operator+(typename reverse_iterator<it1>::difference_type __n, const reverse_iterator<it1>& __x)
{
    return reverse_iterator<it1>((__x.base()) - __n);
}

} // end namespace
#endif