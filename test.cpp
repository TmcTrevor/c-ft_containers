#include <iostream>
#include "containers/vector.hpp"
#include <vector>
  
int main()
{
     //ft::vector<int> a;
    

    //a.push_back(10);
    //a.push_back(90);
    //a.push_back(50);
    //a.push_back(20);
    // std::allocator<int> a;

    // int *arr = a.allocate(5);
    // a.construct(arr, 100);
    // a.construct(arr + 1, 101);
    // a.construct(arr + 2, 102);
    // a.construct(arr + 3, 103);
    // a.construct(arr + 4, 105);

    ft::vector<int> b(5, 80);
    ft::vector<int>::iterator it;
    ft::vector<int>::reverse_iterator rev;

    for (it = b.begin(); it != b.end();it++)
        std::cout << *it << std::endl;
    //it = arr;
 
    //ft::vector<int> second (4,100);                       // four ints with value 100
   // ft::vector<int> third (second.begin(),second.end());
    //std::cout << a.capacity() << std::endl << a.size() << std::endl << a.max_size() << std::endl<< std::endl;
    //std::cout << b.capacity() << std::endl << b.size() << std::endl << b.max_size() << std::endl;
    //allocator<int> a = allocator<int>();
    
    return 0;
}