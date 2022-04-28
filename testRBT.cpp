#include <iostream>
//#include <map>
#include <string>
#include <map>
// #include "tools/RBT.hpp"
// #include "tools/pair.hpp"
#include "containers/map.hpp"
// #include "tools/"
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
    // std::map<int, int> map;

    // map.insert(std::make_pair(10,15));
    // std::map<int, int>::iterator it = map.begin();
    // map.insert(std::make_pair(30,15));
    // map.insert(std::make_pair(15,15));
    // map.insert(std::make_pair(29,15));
    // map.insert(std::make_pair(34,15));


    // while (it != map.end())
    // {
    //     std::cout << (*it).first << std::endl;
    //     it++;
    // }


    const ft::map<int, int> map;

    // map.insert(ft::make_pair(10,15));
    // map.insert(ft::make_pair(30,15));
    // map.insert(ft::make_pair(15,15));
    // map.insert(ft::make_pair(29,15));
    // map.insert(ft::make_pair(34,15));

    // ft::map<int, int>::iterator it = map.lower_bound(15);
    ft::map<int, int>::iterator it = map.end();


    //  if (it != map.end())
    //     std::cout << "asda" << std::endl;
    while (it != map.begin())
    {
        //std::cout <<"dasd" << std::endl;
        std::cout << (*it).first << std::endl;
        --it;
    }
}

// int main()
// {
//      std::map<int, int> map1;
//      std::pair< std::map<int, int>::iterator, bool> a;
//     a = map1.insert(std::make_pair(10,15));
//     a = map1.insert(std::make_pair(10,15));
//     std::cout << a.second << std::endl;
//     // map1.insert(std::make_pair(101,15));
//     // map1.insert(std::make_pair(106,15));
//     // map1.insert(std::make_pair(11,15));
//     std::map<int, int>::iterator mit = map1.end(); ;
//     --mit;
//     //++mit;
//     // ++mit;
//     std::cout << (*mit).first << std::endl;

//      ft::map<int, int> pq;
    // ft::pair<int, int> a;
    // a.first = 10;
    // a.second = 15;
   // pq._rbt.insetINRbt(ft::make_pair(10, 1));
//    ft::pair<ft::map<int, int>::iterator, bool> q;
    
//    q = pq.insert(ft::make_pair(10, 15));
//    q = pq.insert(ft::make_pair(30, 111));
//    q = pq.insert(ft::make_pair(15, 12));
//    q = pq.insert(ft::make_pair(29, 18));
//    q = pq.insert(ft::make_pair(34, 1));

//    ft::map<int, int>::iterator qc = pq.lower_bound(34);
// //    pq.erase(qc);

//     // for (qc = pq.begin(); qc != pq.end(); qc++)
//         std::cout << (*qc).first << " -----" << (*qc).second << std::endl;
//     qc++;
//    // qc--;
//     if (qc != pq.end())
//         std::cout << "wqeqw" << std::endl;
//    std::map<char,int> mymap;
//   std::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['e']=80;
//   mymap['f']=100;

//   itlow=mymap.lower_bound ('d');  // itlow points to b
// //   itup=mymap.upper_bound ('d');   // itup points to e (not d!)

// // std::cout << (*itup).first << std::endl;
// std::cout << (*itlow).first << std::endl;
 // mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
//    q = pq.insert(ft::make_pair(10, 15));
    //pq._rbt.insetINRbt(ft::make_pair(10, 15));
    //if (q.first.base())
    //std::cout << q.second << std::endl;
    
    // pq._rbt.insetINRbt(ft::make_pair(30, 15));
    // pq._rbt.insetINRbt(ft::make_pair(15, 15));
    // pq._rbt.insetINRbt(ft::make_pair(29, 15));
    // pq._rbt.insetINRbt(ft::make_pair(34, 15));
    //pq._rbt.inoderprint(pq._rbt.root);
    // ft::map<int, int>::iterator it = pq.begin();
    //  ft::map<int, int>::iterator it1 = pq.end();
     //std::cout << "dasd"<<std::endl;
    // std::cout << "--------------------------------" << std::endl;
    //  --it1;
    // for (it = pq.end(); it != pq.begin(); --it)
    // {
    //   std::cout << pq[10] << std::endl;
    // }
    //std::cout << (*it).first << std::endl;
   
    // ft::make_pair(10)
     //ft::Node<ft::pair<int, int> >::Nodeptr c;
//     ft::pair<int, int> c;
//     //std::allocator<ft::pair<int, int> >::rebind<ft::Node<ft::pair<int, int> > >::other  alloc_type;
//     //c = alloc_type.allocate(1);
//     c.first = 22;
//     c.second = 10;
//     // ft::Node<ft::pair<int, int> >::Nodeptr q;
//     // q = alloc_type.allocate(1);
//     // q->data.first = 7;
//     // q->data.second = -1;
//     ft::RBT<ft::pair<int, int>, ft::value_compare<int, int> > a;
//       a.insetINRbt(c);
//        ft::pair<int, int> q;
//      q.first = 31;
//     q.second = 10;
// //     a.root = a.insertNode(a.root, c);
// //    a.root =  a.insertNode(a.root, q);

//       a.insetINRbt(q);

//      ft::pair<int, int> e;
//      e.first = 19;
//     e.second = 10;
//     //a.insetINRbt(e);

//   //a.printTree(a.root, NULL, false);
//  // a.leftRotate(a.root->left);

//       //  e.first = 26;
//       // a.insetINRbt(e);

//       e.first = 16;
//     a.insetINRbt(e);
//       e.first = 26;
//     a.insetINRbt(e);
//     e.first = 27;
//     a.insetINRbt(e);
//      e.first = 201;
//     a.insetINRbt(e);
//      e.first = 250;
//     a.insetINRbt(e);
//      e.first = 298;
//     a.insetINRbt(e);
//      e.first = 2777;
//     a.insetINRbt(e);
//       e.first = 2135;
//     a.insetINRbt(e);
//     //   e.first = 17;
//     // a.insetINRbt(e);
//      e.first = 2;
//     a.insetINRbt(e);
//      e.first = 18;
//     a.insetINRbt(e);

    
//     //ft::Node<ft::pair<int, int> >::Nodeptr q;
//    // q = a.search(298);
//     e.first = 201;
//      a.deleteNode(e);
//       e.first = 298;
//     a.deleteNode(e);

//     //a.isBalanced(a.root) ? std::cout << "Balanced" << std::endl : std::cout << "NOTBalanced" << std::endl;
//     //   e.first = 2777;
//     // a.deleteNode(e);
//       e.first = 22;
//     a.deleteNode(e);
//    a.inoderprint(a.root);
//     e.first = 16;
//    a.deleteNode(e);
//   //  e.first = 22;
//   //  a.deleteNode(e);
    

//     //a.search(2135);

//   std::cout << std::endl <<"--------------------------------" << std::endl;
//     // std::cout << a.root->right->left << std::endl;
//     //  std::cout << a.root->color << std::endl;
//     //  std::cout << a.root->data.first << std::endl;
//     //   std::cout << a.root->left->color << std::endl;
//     //  std::cout << a.root->left->data.first << std::endl;
//     // std::cout << a.root->right->color << std::endl;
//     // std::cout << a.root->right->data.first << std::endl;
//     // std::cout << a.root->left->left->color << std::endl;
//     // std::cout << a.root->left->left->data.first << std::endl;
//   //  std::cout << a.root->left->left->color << std::endl;
//   //  std::cout << a.root->left->left->data.first << std::endl;
//   //  std::cout << a.root->right->right->data.first << std::endl;
// //    std::cout << a.root->left->left->data.first << std::endl;
//   //std::cout <<  "------------------------------" << std::endl;
  // pq._rbt.printTree(pq._rbt.root, NULL, false);
// //    a.print2DUtil(a.root, 0);
//    //a.root =  a.insertNode(a.root, q);
//     //std::cout << a.root->data.second << std::endl;
//     // a.print_node(a.root);
// }


    //Y


        //X
//y             