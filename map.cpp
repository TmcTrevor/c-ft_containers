#include <iostream>
#include <map>
#include <string>

#include "tools/RBT.hpp"
#include "tools/pair.hpp"
// int main()
// {
//     std::map<std::string, int> map;
//     map["aa"] = 10;
//     map["bb"] = 5;
//     map["cc"] = 1;
//     map["ab"] = 69999;
//     for (std::map<std::string, int>::iterator it = map.begin(); it != map.end();it++)
//         std::cout << it->first << " -------" << it->second << std::endl;

// }



            //aa        // first insert
               // bb    // second insert

        //inserting third requires left rot 
        //
            //bb 
        //aa    //cc


        //bb // third insert
    //aa        //cc 
// unsigned long int next=1; 
// //Random Number Generator in range [0,32767] 
// unsigned long int random1(void) 
// { 
//           next = next*11035 +12345;
//           return (next*65536) % 32768; 
// }

// int seeding(unsigned int seed) 
// { 
//              next=seed;
//              return next;
// }

// int main() 
// { 
// int a = 44999;
// int b = 26;
//    if (a == 1 & b == -9)
//     std::cerr << "adsada";
   
//    a = (a & b);
//    std::cerr << a << " " <<std::endl;
// }
int main()
{
    
    // ft::make_pair(10)
     //ft::Node<ft::pair<int, int> >::Nodeptr c;
    ft::pair<int, int> c;
    std::allocator<ft::pair<int, int> >::rebind<ft::Node<ft::pair<int, int> > >::other  alloc_type;
    //c = alloc_type.allocate(1);
    c.first = 31;
    c.second = 10;
    // ft::Node<ft::pair<int, int> >::Nodeptr q;
    // q = alloc_type.allocate(1);
    // q->data.first = 7;
    // q->data.second = -1;
    ft::RBT<ft::pair<int, int>, std::less<int> > a;
      a.insetINRbt(c);
       ft::pair<int, int> q;
     q.first = 64;
    q.second = 10;
//     a.root = a.insertNode(a.root, c);
//    a.root =  a.insertNode(a.root, q);

      a.insetINRbt(q);

     ft::pair<int, int> e;
     e.first = 50;
    e.second = 10;
    a.insetINRbt(e);
  //a.printTree(a.root, NULL, false);
  //a.leftRotate(a.root);

    //   e.first = 7;
    // a.insetINRbt(e);
    //   e.first = 10;
    // a.insetINRbt(e);
    //   e.first = 50;
    // a.insetINRbt(e);
    //   e.first = 29;
    // a.insetINRbt(e);

    //   e.first = 80;
    // a.insetINRbt(e);

    // std::cout << a.root->right->left << std::endl;
//    std::cout << a.root->color << std::endl;
//    std::cout << a.root->data.first << std::endl;
//    std::cout << a.root->left->color << std::endl;
//    std::cout << a.root->left->data.first << std::endl;
//    std::cout << a.root->right->color << std::endl;
//    std::cout << a.root->right->data.first << std::endl;
//    std::cout << a.root->right->right->data.first << std::endl;
//    std::cout << a.root->left->left->data.first << std::endl;
  std::cout <<  "------------------------------" << std::endl;
  a.printTree(a.root, NULL, false);
//    a.print2DUtil(a.root, 0);
   //a.root =  a.insertNode(a.root, q);
    //std::cout << a.root->data.second << std::endl;
    // a.print_node(a.root);
}


    //Y


        //X
//y             