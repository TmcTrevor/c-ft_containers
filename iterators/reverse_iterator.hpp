#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


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
            ~reverse_iterator();
            reverse_iterator() { rv = NULL; }
            reverse_iterator(iterator_type rv) { this->rv = rv; }
            reverse_iterator(reverse_iterator const &c) { rv = c.rv; }
            template<typename iterator1>
            reverse_iterator operator=(reverse_iterator<iterator1> const &c) { rv = c.rv; return *this; }
            iterator_type base() const { return rv; }
            reference operator*() const 
            {
                return (*r);
            }
            pointer operator->() const
            {
                return (rv);
            }
            Ra_iterator &operator++()
            {
                
            }



    };// end of class reverse iterator 
} // end namespace
#endif