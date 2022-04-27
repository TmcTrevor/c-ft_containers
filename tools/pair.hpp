#ifndef PAIR_HPP
#define PAIR_HPP


namespace ft{

template <class T1, class T2>
struct pair
{
    public:
        //Member types 
        typedef T1  first_type;
        typedef T2  second_type;
        // Member variables
        T1 first;
        T2 second;
        //Member functions
                //Constructs
        pair(): first(T1()), second(T2())//default 
        {
          // std::cout << "is here" << std::endl;
            // first = T1();
            // second = T2();
        } 
        template<class U, class V> 
        pair (const pair<U, V>  &pr): first(pr.first), second(pr.second) {}// copy constructs
        pair (const first_type& a, const second_type& b) : first(a), second(b){} //initialization constructs
        // private:
        ~pair(){} // dest
        public:
        pair<T1, T2> &operator = (const pair<T1, T2>& otherPair) 
    	{
        	first=otherPair.first;
        	second=otherPair.second;
       	 	return *this;
    	}
};
//Non-member pair function overloads
    template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
      return (lhs.first == rhs.first && lhs.second == rhs.second);
  }
     template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return !(lhs == rhs); 
  }
  template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
 { 
    return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
 }
 template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(rhs < lhs); 
    }
template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
     return rhs < lhs; 
}

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ 
    return !(lhs < rhs); 
}

template <class T1, class T2>
ft::pair<T1, T2> make_pair (T1 x, T2 y)
{
    return (ft::pair<T1, T2>(x, y));
}


}

#endif 