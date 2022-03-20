#include <iostream>
#include "containers/vector.hpp"
#include <vector>


// class c{};
// class b{};


// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (2,200);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";




//   return 0;
// }
// int main()
//  {

    
//     // std::vector<int> a(7, 15);
//     // std::vector<int> b(10,2);

//     //b = a;
// // //     std ::cout << "size = " <<  a.size() << " capacity = " << a.capacity() << std::endl;
// //      ft::vector<int> b(20, 2);
// //      if ()
// //     // a.push_back(10);
// //     ft::vector<int>::iterator e = a.begin();
// //     ft::vector<int>::iterator x = a.insert(e, 20);
// //     std ::cout << "size = " <<  a.size() << " capacity = " << a.capacity() << std::endl;
// //     a.insert(a.begin(), b.begin(),b.end());
// //     std ::cout << "size = " <<  a.size() << " capacity = " << a.capacity() << std::endl;
//     // std::cout << *e << std::endl;
//     // std::cout << *x << std::endl;
//     // a.push_back(10);
//     // std ::cout << "size = " <<  a.size() << "capacity = " << a.capacity() << std::endl;
//     // a.push_back(90);
//     // a.push_back(50);
//     // a.push_back(20);
//     // a.push_back(20);
//     // a.push_back(20);
//     // b.push_back(100);
//     // b.push_back(900);
//     // b.push_back(500);
//   //  std ::cout << "size = " <<  b.size() << "capacity = " << b.capacity() << std::endl;
//   //   b.assign(19, 14);
//   //  std ::cout << "size = " <<  b.size() << "capacity = " << b.capacity() << std::endl;
  

//     // try {
//     // std::cout << a.at(-1) << std::endl;
//     // }
//     // catch(const char *c)
//     // {
//     //   std::cout << c << std::endl;
//     // }
//     // ft::vector<int> b(10,15);
//      //ft::vector<int>::iterator it = a.begin();
//     // ft::vector<int>::iterator it2 = a.end();
    
//     //  ft::vector<int> c(it,it2);

//     // std::istream_iterator<int> start(std::cin);
//     // std::istream_iterator<int> end;

//     // const   std::vector<int> v(start, end);
//     //std::cout << v.capacity() << std::endl;
//     //  ft::vector<int>::iterator it = a.begin();
//     // for (it = v.begin(); it != v.end();it++)
//     //      std::cout << *it << ' ';
//     // std::cout << std::endl;
//   //   std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//   //   //a.reserve(11);
//   //   while (it != a.end())
//   //  {
//   //    std::cout << *it << " ";
//   //    it++;
//   //  }
//   //  std::cout << std::endl;
//   //   std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//     // a.push_back(10);
//     // a.push_back(90);
//     // a.push_back(50);
//     // a.push_back(20);
//     // std::cout << a.front() <<  "     ----     " << a.back() << std::endl;
    
//     // ////////////////////////////////////////////////////////////////////////
//     //  //       Capacity allocation test                                       //
//     //  ////////////////////////////////////////////////////////////////////////

//     // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//     // a.resize(9, 10);
//     // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//     // a.resize(19, 10);
//     // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;


//      ////////////////////////////////////////////////////////////////////////
//      //        resize() test (if capacity > n ) capacity = n; size = n;     //
//      //              size = n; capacity unchaged = capacity                 //
//      ////////////////////////////////////////////////////////////////////////
    
//     ft::vector<int> a(7, 15);
//     ft::vector<int> b(10,2);
//     ft::vector<int>::iterator it = a.begin();
//    ft::vector<int>::iterator it1 = b.begin();

//     while (it != a.end())
//     {
//         std::cout << *it << "  ";
//         it++;
//     }
//     std::cout << std::endl;
//     // while (it1 != b.end())
//     // {
//     //     std::cout << *it1 << " xo ";
//     //     it1++;
//     // }
//     // // std::cout << std::endl;
//     // try {
//      std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//       a.resize(8,8);
//      std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
//     // } catch (const std::exception &e)
//     // {
//     //     std::cout << e.what() << std::endl;
//     // }
//      it = a.begin();
//     // std::cout << std::endl << "iahsdoahsdasdhaskdhajksdhajkshdjash djkash  "<< std::endl;
    
//     std::cout << std::endl;
//     std::cout << b.capacity() << std::endl << b.size() << std::endl<< std::endl;
//     b.resize(21,8);
//     std::cout << b.capacity() << std::endl << b.size() << std::endl<< std::endl;
//     it1 = b.begin();
//     while (it1 != b.end())
//     {
//         std::cout << *it1 << " ";
//         it1++;
//     }
//     std::cout << std::endl;



//     // std::allocator<int> a;

//     // int *arr = a.allocate(5);
//     // a.construct(arr, 100);
//     // a.construct(arr + 1, 101);
//     // a.construct(arr + 2, 102);
//     // a.construct(arr + 3, 103);
//     // a.construct(arr + 4, 105);

//     // ft::vector<int> b;
//     // ft::vector<int>::iterator it;
//     // //ft::vector<int>::reverse_iterator rev;

//     // for (it = b.begin(); it != b.end();it++)
//     //     std::cout << *it << std::endl;
//     // //it = arr;
 
//     //ft::vector<int> second (4,100);                       // four ints with value 100
//    // ft::vector<int> third (second.begin(),second.end());
//     //std::cout << b.capacity() << std::endl << b.size() << std::endl << b.max_size() << std::endl;
//     //allocator<int> a = allocator<int>();
    
//      return 0;
//  }

///// resize 
// int main()
// {
//   ft::vector<std::string> a(10, "string2");
//   std::vector<std::string> b(10, "string2");
//  std::string s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
//   std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3;

//   ft::vector<std::string>::iterator it = a.begin();
//   std::vector<std::string>::iterator it2 = b.begin();
//    std::vector<std::string>::iterator valid_it, valid_eit;
//     ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;



//   a.resize(1e6, "hello");
//   b.resize(1e6, "hello");
//   std::cout << a.capacity() << "-------" << a.size() << std::endl<< std::endl;
//   std::cout << b.capacity() << "-------" << b.size() << std::endl<< std::endl;
//   for (size_t i = 0; i < b.size(); ++i)
//           s1 += a[i];

//   for (ft::vector<std::string>::iterator it3 = a.begin(); it3 != a.end(); ++it3)
//             ft_s1 += *it3;
//   if (s1 == ft_s1)
//     std::cout <<"yup" << std::endl;

//   b.resize(20);
//   valid_it = b.begin();
//   valid_eit = b.end();
//   b.resize(1e5);


//   a.resize(20);
//   ft_valid_it = a.begin();
//   ft_valid_eit = a.end();
//   a.resize(1e5);

//   std::cout << a.capacity() << "-------" << a.size() << std::endl<< std::endl;
//   std::cout << b.capacity() << "-------" << b.size() << std::endl<< std::endl;

  
//   // while (it != a.end())
//   // {
//   //     std::cout << *it << " ";
//   //     it++;
//   // }

//   // std::cout << std::endl;
//   // while (it2 != b.end())
//   // {
//   //     std::cout << *it << " ";
//   //     it2++;
//   // }


// }

