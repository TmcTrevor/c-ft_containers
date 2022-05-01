#include <iostream>
//#include <map>
#include <string>
#include <map>
// #include "tools/RBT.hpp"
// #include "tools/pair.hpp"
#include "containers/map.hpp"

 #include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
#define TIME_FAC 4 

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};
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




#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))



void test_map_assignment_operator(void)
{
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            std::map<int, std::string> m1;
            std::map<int, std::string> m2;
            ft::map<int, std::string> ft_m1;
            ft::map<int, std::string> ft_m2;
            for (int i = 0; i < 10000; ++i)
            {
                m1.insert(std::make_pair(i, "string1"));
                m2.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string1"));
                ft_m2.insert(ft::make_pair(i, "string2"));
            }

           start = get_time();
            m1 = m2;
           end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::map ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1 = ft_m2;
            std::cout << ft_m1.size() << std::endl;
            std::cout << ft_m2.size() << std::endl;
            if (ft_m1 == ft_m2)
                std::cout << "error" <<std::endl;


             ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;
        for (int i = 0; i < 10; ++i)
        {
            m1.insert(std::make_pair(i, "string1"));
            m2.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }

        m1 = m2;
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->first;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->first;

        EQUAL(res == ft_res);
    }
}

void iterator_tests(void)
{
    /*------------ std::map ---------*/
    std::map<int, char> m;
    std::map<int, char>::iterator it, it1;

    ft::map<int, char> my_m;
    ft::map<int, char>::iterator my_it, my_it1, tmp;

    for (int i = 0; i < 10; ++i)
    {
        my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
        m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    }

    it = m.begin();
    it1 = ++(m.begin());
    my_it = my_m.begin();
    my_it1 = ++(my_m.begin());
    /*----------------------------------*/
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     ft::map<int, char>::iterator ob(my_it);
    //     EQUAL(&(*my_it) == &(*ob));
    // }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " iterator to const_iterator "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     ft::map<int, char>::const_iterator c_it, c_ob(my_it);
    //     c_it = my_it;
    //     EQUAL(&(*my_it) == &(*c_it) && (&(*my_it) == &(*c_ob)));
    // }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
    //           << "] --------------------]\t\t\033[0m";
    // EQUAL((it == it1) == (my_it == my_it1));
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
    //           << "] --------------------]\t\t\033[0m";
    // EQUAL((it != it1) == (my_it != my_it1));
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator "
    //           << "] --------------------]\t\t\033[0m";
    // EQUAL((((*my_it).second = '6') == '6') && ((*my_it).first == ((*my_m.begin()).first)));
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*--------------- std::map-------------------- */
    //     std::map<int, std::string> m;
    //     ft::map<int, std::string> my_m;

    //     for (int i = 0; i < 5; ++i)
    //     {
    //         m.insert(std::make_pair(13, "HELLO"));
    //         my_m.insert(ft::make_pair(13, "HELLO"));
    //     }

    //     ft::map<int, std::string>::iterator my_it = my_m.begin();
    //     std::map<int, std::string>::iterator it = m.begin();
    //     /*---------------------------------------------- */
    //     EQUAL(it->second.length() == my_it->second.length());
    // }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        // {
        //     time_t start, end, diff;

        //     std::map<int, std::string> m;
        //     ft::map<int, std::string> ft_m;
        //     for (size_t i = 0; i < 1e6; ++i)
        //     {
        //         m.insert(std::make_pair(i, "value"));
        //         ft_m.insert(ft::make_pair(i, "value"));
        //     }
        //     start = get_time();
        //     for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
        //         ;
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        //     ualarm(diff * 1e3, 0);
        //     for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
        //         ;
        //     ualarm(0, 0);
        // }
        bool cond(false);
        // {
        //     int res(0);
        //     int myints[] = {12, 82, 37, 64, 15};
        //     ft::map<int, int> m;
        //     for (size_t i = 0; i < 5; ++i)
        //         m.insert(ft::make_pair(myints[i], i));
        //     for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        //         res += it->first;
        //     cond = res == 210;
        // }
        {
            int res(0), tmp;
            int myints[] = {12, 82, 37, 64, 15};
             int myints1[] = {10, 30, 15, 29, 34};
            ft::map<int, int> m;
            ft::map<int, int> m1;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            for (size_t i = 0; i < 5; ++i)
                m1.insert(ft::make_pair(myints1[i], i));
             ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
             ft::map<int, int>::iterator  eit1 = --m1.end();
            // tmp = eit->first;
            m.erase(eit);
            //m1.erase(eit);
            // for (; it != m.end(); ++it)
            //   //  res += it->first;
            //     std::cout << (*it).first << std::endl;
            std::cout << std::endl;
             m._rbt.printTree(m._rbt.root, NULL, false);
             std::cout << std::endl;
             std::cout << std::endl;
             std::cout << std::endl;
             m1._rbt.printTree(m1._rbt.root, NULL, false);
            cond = cond && (res == (210 - tmp));
        }
        ++my_it; // I incremented here to make sure that the object changes
        EQUAL(*my_it == *my_it1);
    }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;

    //         std::map<int, std::string> m;
    //         ft::map<int, std::string> ft_m;
    //         for (size_t i = 0; i < 1e6; ++i)
    //         {
    //             m.insert(std::make_pair(i, "value"));
    //             ft_m.insert(ft::make_pair(i, "value"));
    //         }
    //         start = get_time();
    //         std::map<int, std::string>::iterator it = --m.end();
    //         for (; it != m.begin(); --it)
    //             ;
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

    //         ualarm(diff * 1e3, 0);
    //         ft::map<int, std::string>::iterator ft_it = --ft_m.end();
    //         for (; ft_it != ft_m.begin(); --ft_it)
    //             ;
    //         ualarm(0, 0);
    //     }
    //     int res(0);
    //     {
    //         int myints[] = {12, 82, 37, 64, 15};
    //         ft::map<int, int> m;
    //         for (size_t i = 0; i < 5; ++i)
    //             m.insert(ft::make_pair(myints[i], i));
    //         ft::map<int, int>::iterator it = --m.end();
    //         for (;; --it)
    //         {
    //             if (it == m.begin())
    //             {
    //                 res += it->first;
    //                 break;
    //             }
    //             res += it->first;
    //         }
    //     }
    //     --my_it; // I decremented here to make sure that the object changes
    //     EQUAL(*my_it != *my_it1);
    // }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
    //           << "] --------------------]\t\t\033[0m";
    // tmp = my_it++;
    // EQUAL(*my_it != *tmp && *my_it == *my_it1);
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
    //           << "] --------------------]\t\t\033[0m";
    // tmp = my_it--;
    // EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));
}

void element_access()
{
    ft::map<int, char> map;

    map.insert(ft::make_pair(10,'a'));
    map.insert(ft::make_pair(30,'a'));
    map.insert(ft::make_pair(15,'a'));
    map.insert(ft::make_pair(29,'a'));
    map.insert(ft::make_pair(34,'a'));

    // std::cout << map[10] << ft::endl;
    ft::map<int, char>::iterator it = map.begin();
    std::cout << map[10] << std::endl;
    while (it != map.end())
    {
            std::cout << it->first << std::endl;
        it++;
    }
}


// void fixDoubleBlack(RedBlack *targetNode)
// 			{
// 				if (targetNode == root)
// 				// Reached root
// 					return;
			
// 				RedBlack *sib = sibling(targetNode);
// 				RedBlack *parent = targetNode->parent;
// 				if (sib == NULL)
// 				{
// 					// No sibiling, double black pushed up
// 					fixDoubleBlack(parent);
// 				}
// 				else
// 				{
// 					if (sib->color == RED)
// 					{
// 						// sib red
// 						parent->color = RED;
// 						sib->color = BLACK;
// 						if (isOnLeft(sib))
// 						{
// 							// left case
// 							rotateRight(root, parent);
// 						}
// 						else
// 						{
// 							// right case
// 							rotateLeft(root, parent);
// 						}
// 						fixDoubleBlack(targetNode);
// 					}
// 					else
// 					{
// 						// Sibling black
// 						if (hasRedChild(sib))
// 						{
// 							// at least 1 red children
// 							if (sib->left != NULL && sib->left->color == RED)
// 							{
// 								if (isOnLeft(sib))
// 								{
// 									// left left
// 									sib->left->color = sib->color;
// 									sib->color = parent->color;
// 									rotateRight(root, parent);
// 								}
// 								else
// 								{
// 									// right left
// 									sib->left->color = parent->color;
// 									rotateRight(root, sib);
// 									rotateLeft(root, parent);
// 								}
// 							}
// 							else
// 							{
// 								if (isOnLeft(sib))
// 								{
// 									// left right
// 									sib->right->color = parent->color;
// 									rotateLeft(root, sib);
// 									rotateRight(root, parent);
// 								}
// 								else
// 								{
// 									// right right
// 									sib->right->color = sib->color;
// 									sib->color = parent->color;
// 									rotateLeft(root, parent);
// 								}
// 							}
// 							parent->color = BLACK;
// 						}
// 						else
// 						{
// 							// 2 black children
// 							sib->color = RED;
// 							if (parent->color == BLACK)
// 								fixDoubleBlack(parent);
// 							else
// 								parent->color = BLACK;
// 						}
// 					}
// 				}
// 			}
// void deleteNode(RedBlack *&targetNode)
// {
// 	RedBlack *nodeReplaceTarget = BSTreplace(targetNode); // looking here debug

// 	// True when u and v are both black
// 	bool rtBlack = ((nodeReplaceTarget == NULL || nodeReplaceTarget->color == BLACK) && (targetNode->color == BLACK));
// 	RedBlack *parentTarget = targetNode->parent;

// 	if (nodeReplaceTarget == NULL) 
// 	{
// 		// nodeReplaceTarget is NULL therefore targetNode is leaf
// 		if (targetNode == root)
// 		{
// 			// targetNode is root, making root null
// 			root = NULL;
// 		}
// 		else
// 		{
// 			if (rtBlack)
// 			{
// 				// u and targetNode both black
// 				// targetNode is leaf, fix double black at targetNode
// 				fixDoubleBlack(targetNode);
// 			}
// 			else
// 			{
// 				RedBlack *tmp = sibling(targetNode);
// 				// u or targetNode is red
// 				if (tmp != NULL)
// 					// sibling is not null, make it red"
// 					tmp->color = RED;
// 			}
// 			// delete targetNode from the tree
// 			if (isOnLeft(targetNode))
// 				parentTarget->left = NULL;
// 			else
// 				parentTarget->right = NULL;
// 		}
// 		_allocRebind.destroy(targetNode);
// 		_allocRebind.deallocate(targetNode, 1);
// 		return;
// 	}

// 	if (targetNode->left == NULL || targetNode->right == NULL)
// 	{
// 		// targetNode has 1 child
// 		if (targetNode == root)
// 		{
// 			std::swap(targetNode->data, nodeReplaceTarget->data);
// 			targetNode->left = targetNode->right = NULL;
// 			_allocRebind.destroy(nodeReplaceTarget);
// 			_allocRebind.deallocate(nodeReplaceTarget, 1);
// 		}
// 		else
// 		{
// 			// Detach targetNode from tree and motargetNodee u up
// 			if (isOnLeft(targetNode))
// 				parentTarget->left = nodeReplaceTarget;
// 			else
// 				parentTarget->right = nodeReplaceTarget;
// 			_allocRebind.destroy(targetNode);
// 			_allocRebind.deallocate(targetNode, 1);
// 			nodeReplaceTarget->parent = parentTarget;
// 			if (rtBlack)
// 				// u and v both black, fix double black at u
// 				fixDoubleBlack(nodeReplaceTarget);
// 			else
// 				// u or v red, color u black
// 				nodeReplaceTarget->color = BLACK;
// 		}
// 		return;
// 	}
// 	// v has 2 children, swap values with successor and recurse
// 	swapValues(nodeReplaceTarget, targetNode);
// 	deleteNode(nodeReplaceTarget);
// }
			

void assignmentWithlgh()
{
    std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;

        for (int i = 0; i < 20; ++i)
        {
            m1.insert(std::make_pair(i, "string1"));
            ft_m1.insert(ft::make_pair(i, "string1"));
        }

        for (int i = 0; i < 10; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/
       // ft_m1.clear();
         //ft_m1 = ft_m2;
    //  for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it)
    //  {
    //     std::cout << it->first << " "<< std::endl;
    //     ft_m1._rbt.deleteNode(it.base()->data);
    //     ft_m1._rbt.deleteNode(it.base()->data);

    //     //ft_m1.erase(it->first);
    //  }
    int i = 0;
    while (i < ft_m1.size()) 
    {
        std::cout << i << std::endl;
        ft_m1._rbt.deleteNode(ft::make_pair(i, "string2"));
        i++;
    }
      // ft_m1.clear();
      // ft_m1.clear();
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        // std::string res, ft_res;
        // /*----------------------------------------------------*/
        // for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
        // {std::cout << it->first << " ";
        // std::cout << std::endl;}
            // res += it->second;

        std::cout << std::endl;
        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
        std::cout << it->first << " ";
        std::cout << std::endl;
        //     ft_res += it->second;

        // EQUAL(res == ft_res);
}
void test_iter_after_delete()
{
     ft::map<int, int> map;

    // map.insert(ft::make_pair(10,'a'));
    // map.insert(ft::make_pair(30,'a'));
    // map.insert(ft::make_pair(15,'a'));
    // map.insert(ft::make_pair(29,'a'));
    // map.insert(ft::make_pair(34,'a'));
     int myints[] = {12, 82, 37, 64, 15};
    for (size_t i = 0; i < 1; ++i)
        map.insert(ft::make_pair(myints[i], i));
     map.clear();
    // map.erase(12);
    //map._rbt.printTree(map._rbt.getRoot(), NULL, false);
    
    for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); ++it) // fill ft_res from ft_m1
    // {
    //     // std::cout << "--------------------------------";
         std::cout << it->first << " " << std::endl;
    //     // std::cout << "-------------------" << (--map.end())->first << "-------------"<<std::endl;
    //     // std::cout << std::endl;
    //     //  std::cout << std::endl;
    //     //  std::cout << std::endl;
    //     //  std::cout << std::endl;
    //     //  std::cout << std::endl;
    //    map.erase(it);
    //     // ft::map<int, int>::iterator it1(it);
    //     // it1++;
    //     // if (it1 == (--map.end()))
    //     //     std::cout << "yup" << std::endl;
    //     // std::cout << "-------------------" << it->first << "-------------" <<std::endl;;
    //     // std::cout << "-------------------" << (--map.end())->first << "-------------" <<std::endl;;
    //      map._rbt.printTree(map._rbt.getRoot(), NULL, false);
    // }


}

void testonassign()
{
        /*-------------------------------------- time limit test -----------------------------------*/
   {
        /*-------------------------------------- time limit test -----------------------------------*/
        // {
        //     time_t start, end, diff;
        //     /*------------------ std::map ---------------------*/
        //     std::map<int, std::string> m1;
        //     std::map<int, std::string> m2;
        //     ft::map<int, std::string> ft_m1;
        //     ft::map<int, std::string> ft_m2;

        //     for (int i = 0; i < 1e4; ++i)
        //     {
        //         m1.insert(std::make_pair(i, "string1"));
        //         ft_m1.insert(ft::make_pair(i, "string1"));
        //     }

        //     for (int i = 0; i < 1e2; ++i)
        //     {
        //         m2.insert(std::make_pair(i, "string2"));
        //         ft_m2.insert(ft::make_pair(i, "string2"));
        //     }
        //     start = get_time();
        //     m1 = m2;
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::map ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m1 = ft_m2;
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;

        for (int i = 0; i < 20; ++i)
        {
            m1.insert(std::make_pair(i, "string1"));
            ft_m1.insert(ft::make_pair(i, "string1"));
        }

        for (int i = 0; i < 10; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;

        EQUAL(res == ft_res);
    }
}

void Random_test()
{
    ft::map<int, char> map;

    map.insert(ft::make_pair(10,'a'));
    map.insert(ft::make_pair(30,'a'));
    map.insert(ft::make_pair(15,'a'));
    map.insert(ft::make_pair(29,'a'));
    map.insert(ft::make_pair(34,'a'));

    // std::cout << map[10] << ft::endl;
    ft::map<int, char>::iterator it = map.begin();
    // map.clear();
    // map.erase(10);
    map._rbt.deleteNode(ft::make_pair(10, 'a'));
   // std::cout << map[10] << std::endl;
    while (it != map.end())
    {
            std::cout << it->first << std::endl;
        ++it;
    }
}

int main()
{
    //element_access();
//    iterator_tests();
   //test_map_assignment_operator();
   Random_test();
//    test_iter_after_delete();
  // testonassign();
   //assignmentWithlgh();
    // ft::map<int, int> map;

    // map.insert(std::make_pair(10,15));
    // map.insert(std::make_pair(30,15));
    // map.insert(std::make_pair(15,15));
    // map.insert(std::make_pair(29,15));
    // map.insert(std::make_pair(34,15));

    // while (it != map.end())
    // {
    //     std::cout << (*it).first << std::endl;
    //     it++;
    // }

    // ft::map<int, char> map;

    // map.insert(ft::make_pair(10,'a'));
    // map.insert(ft::make_pair(30,'a'));
    // map.insert(ft::make_pair(15,'a'));
    // map.insert(ft::make_pair(29,'a'));
    // map.insert(ft::make_pair(34,'a'));
    // // map.insert(ft::make_pair(34,'a'));



    //   ft::map<int, char>::iterator mp  = map.begin();
    // // map.clear();
    // map.erase(mp, map.end());
    // //  ft::map<int, char>::iterator mp1  = --map.end();
    // // map.erase(mp1);

    //  while (mp != map.end())
    //  {
    //      std::cout << (*mp).first << std::endl;
    //      ++mp;
    //  }
    // for (; mp != map.end(); ++mp)
    //         // //      res += it->first;
    //             std::cout << (*mp).first << std::endl;
   
    // ft::Node<ft::pair<int, char> >::Nodeptr a = mp._rbt.search(ft::make_pair(15, 'a'));

    // if (!a)
    //     std::cout << "rip" << std::endl;
    // else

    //     std::cout << "a = " << a->data.first << std::endl;

   // map.erase(30);
    
// //     // std::cout << map[15] << std::endl;


// ft::map<int, char>::reverse_iterator my_rit2(map.begin());
// my_rit2--;
// std::cout << (*my_rit2).first << std::endl;

// ft::map<int, char>::const_reverse_iterator c_it, c_ob(map.end()); 
//  c_it = my_rit2;
//   EQUAL(my_rit2->first == c_it->first && my_rit2->first == c_ob->first);
      /*---------------------------------- time limit test --------------------------------------------*/
        // {
            //time_t start, end, diff;
        //     std::map<int, char> m;
        //     ft::map<int, char> my_m;

        //     for (size_t i = 0; i < 1e3; i++)
        //     {
        //         m.insert(std::make_pair(i, 'X'));
        //         my_m.insert(ft::make_pair(i, 'X'));
        //     }

        //    // start = get_time();
        //     //std::map<int, char> copy_m(m);
        //     // end = get_time();
        //     // diff = end - start;
        //     // diff = (diff) ? (diff * 20) : 20;

        //     // alarm(diff);
        //     ft::map<int, char> my_copy_m(my_m);
        //     // alarm(0);
        // }
        // /*---------------------------------------------------------------------------------------------*/
        // /*---------------------------- declare a vector and fill with 'a', and create a copy of it ------------------*/
        // ft::map<int, char> m1;
        // for (int i = 0; i < 10; i++)
        //     m1.insert(ft::make_pair(i, 'a'));
        // ft::map<int, char> copy_m(m1);
        // /*-----------------------------------------------------------------------------------------------------------*/
        // /*--------------- declare tow strings to store the results ------*/
        // std::string res, res1;
        // /*--------------------------------------------------------*/
        // for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
        //     res += it->second;

        // for (ft::map<int, char>::iterator it = copy_m.begin(); it != copy_m.end(); ++it) // fill res from copy_m
        //     res1 += it->second;
        // EQUAL(res == res1);
//     //  ft::map<int, int>::reverse_iterator<std::map<int, int>::iterator> my_rit = map.begin();
//     //  ft::reverse_iterator<std::map<int, int>::iterator> ob(my_rit);
//     //  ft::map<int, int>::iterator it = map.lower_bound(15);
//     ft::map<int, int>::reverse_iterator my_rit(map.end());
//     ft::map<int, int>::reverse_iterator ob(my_rit);


        // {
        //    // time_t start, end, diff;
        //     std::map<int, std::string> m1;
        //     std::map<int, std::string> m2;
        //     ft::map<int, std::string> ft_m1;
        //     ft::map<int, std::string> ft_m2;
        //     for (int i = 0; i < 100; ++i)
        //     {
        //         m1.insert(std::make_pair(i, "string1"));
        //         m2.insert(std::make_pair(i, "string2"));
        //         ft_m1.insert(ft::make_pair(i, "string1"));
        //         ft_m2.insert(ft::make_pair(i, "string2"));
        //     }

        //     // start = get_time();
        //     // m1 = m2;
        //     // end = get_time();
        //     // diff = end - start;
        //     // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::map ---------------------*/
        //     // ualarm(diff * 1e3, 0);
        //     ft_m1 = ft_m2;
        //     // ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
//         {
//             std::map<int, std::string> m1;
//             std::map<int, std::string> m2;
//             ft::map<int, std::string> ft_m1;
//             ft::map<int, std::string> ft_m2;
//             for (int i = 0; i < 5; ++i)
//             {
//                 m1.insert(std::make_pair(i, "string1"));
//                 m2.insert(std::make_pair(i, "string2"));
//                 ft_m1.insert(ft::make_pair(i, "string1"));
//                 ft_m2.insert(ft::make_pair(i, "string2"));
//             }
//             // ft_m2.insert(ft::make_pair(0, "string1"));
//             //  m1 = m2;
//             ft_m1 = ft_m2;
//             // // /*----------------------------------------------------*/
//             // // /*------------------ strings to store the results ----*/
//             // std::string res, ft_res;
//             // /*----------------------------------------------------*/
//             //for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill  res from m1
//             //     std::cout << " first "<< (*it).first << " --";
//             // std::cout << std::endl;
        
//             //  ft::map<int, std::string>::iterator it = ft_m1.begin();
//             //  while (it != ft_m1.end())
//             //  {
//             //      std::cout << "hhhh" << std::endl;
//             //      it++;
//             //  }
//             // it--;
//             // std::cout << " " << (*it).first << std::endl;
//             for (std::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) /  / fill ft_res from ft_m1
//                  std::cout << " second "<< (*it).first << " --";
//             std::cout << std::endl;
// // 
//             // ft_m1.erase(ft_m1.begin(), ft_m1.end());
//             // m1.erase(m1.begin(), m1.end());
//             // for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) //    fill ft_res from ft_m1
//             //         std::cout << " first "<< (*it).first << " --";
//             // std::cout << std::endl;
//             for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) //    fill ft_res from ft_m1
//                     std::cout << " second "<< (*it).first << " --";
//         }


        // EQUAL(res == ft_res);
    // }
//     // std::cout <<    ( (*ob) == (*my_rit)) << std::endl;
//     //std::cout << (*my_rit) << std::endl;
//    EQUAL(*my_rit == *ob);
    // std::cout << ((it1) == it) << std::endl;

    // //  if (it != map.end())
    // //     std::cout << "asda" << std::endl;
    // while (it != map.begin())
    // {
    //     //std::cout <<"dasd" << std::endl;
    //         --it;
    //     std::cout << (*it).first << std::endl;
    // }
}

// ----------------------------------------------------------------

//      15
// 10         30
//          29    
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