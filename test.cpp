#include <iostream>
#include "containers/vector.hpp"
#include <vector>


// class c{};
// class b{};

int main()
{

    ft::vector<int> a(10,15);
    //  ft::vector<int> b;
    // ft::vector<int>::iterator it = a.begin();
    // ft::vector<int>::iterator it2 = a.end();
    
    //  ft::vector<int> c(it,it2);

    std::istream_iterator<int> start(std::cin);
    std::istream_iterator<int> end;

    const   std::vector<int> v(start, end);
    //std::cout << v.capacity() << std::endl;
    // ft::vector<int>::iterator it = v.begin();
    // for (it = v.begin(); it != v.end();it++)
    //      std::cout << *it << ' ';
    // std::cout << std::endl;
    // while (it++ != a.end())
    //     std::cout << *it << std::endl;
    // a.push_back(10);
    // a.push_back(90);
    // a.push_back(50);
    // a.push_back(20);
    
    // ////////////////////////////////////////////////////////////////////////
    //  //       Capacity allocation test                                       //
    //  ////////////////////////////////////////////////////////////////////////

    // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
    // a.resize(9, 10);
    // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
    // a.resize(19, 10);
    // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;


     ////////////////////////////////////////////////////////////////////////
     //        resize() test (if capacity > n ) capacity = n; size = n;     //
     //              size = n; capacity unchaged = capacity                 //
     ////////////////////////////////////////////////////////////////////////
     
    // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
    // a.resize(1,8);
    // std::cout << a.capacity() << std::endl << a.size() << std::endl<< std::endl;
    // std::vector<int>::iterator it = a.begin();
    // while (it != a.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
    




    // std::allocator<int> a;

    // int *arr = a.allocate(5);
    // a.construct(arr, 100);
    // a.construct(arr + 1, 101);
    // a.construct(arr + 2, 102);
    // a.construct(arr + 3, 103);
    // a.construct(arr + 4, 105);

    // ft::vector<int> b;
    // ft::vector<int>::iterator it;
    // //ft::vector<int>::reverse_iterator rev;

    // for (it = b.begin(); it != b.end();it++)
    //     std::cout << *it << std::endl;
    // //it = arr;
 
    //ft::vector<int> second (4,100);                       // four ints with value 100
   // ft::vector<int> third (second.begin(),second.end());
    //std::cout << b.capacity() << std::endl << b.size() << std::endl << b.max_size() << std::endl;
    //allocator<int> a = allocator<int>();
    
    return 0;
}