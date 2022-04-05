#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

namespace ft {
    template <typename T>
    struct Node {
        public :
        typedef Node* Nodeptr;
        typedef const Node* const_Nodeptr;
        typedef size_t size_type;
        typedef typename T::first_type first;
        typedef typename T::second_type second;
        
        T       data;
        Nodeptr parent;
        Nodeptr left;
        Nodeptr right;
        size_type height;

        Node(T data) : data(data), parent(NULL), left(NULL), right(NULL), height(1){}
        Node(first &f, second &s) : data(f,s), parent(NULL), left(NULL), right(NULL), height(1) {}
            
    };

    template <typename T, class comp, class Alloc = std::allocator<T> >
    class AVL
    {
        public :
            typedef T value_type;
            typedef typename Node<value_type>::Nodeptr    nodeptr;
            typedef typename Node<value_type>::size_type size_type;
            typedef typename Alloc::template rebind<Node<value_type> >::other allocator_type;


        typedef typename T::first_type first;
        typedef typename T::second_type second;

        nodeptr  root;
        nodeptr nil;
        comp     comp_;
        allocator_type alloc;
        size_type size;

        size_type max(size_type a, size_type b)
        {
            return a > b ? a : b;
        }

        size_type height(nodeptr *t)
        {
            if (t == NULL) return 0;
            return t->height;
        }

        size_type balance_factor(nodeptr t)
        {
            if (t == NULL) return 0;
            return height(t->left) - height(t->right);
        }

        void left_rotate(nodeptr t)
        {
            
            //if (t == NULL || t->right == NULL) return;
            if (t == NULL) return;
            
            // if (t->right->left != NULL)
            // {
            //     t->right->left->parent = t;
            //     t->right = t->right->left;
            // }
            t->left->right->parent = t->left;
            if (t->parent == NULL)
            {
                root = t->right;
                t->right->parent = NULL;
            }
            else if (t->parent->left == t)
                t->parent->left = t->right;
            else
                t->parent->right = t->right;
        }

        public :
            AVL(const allocator_type& alloc = allocator_type()) : root(NULL), nil(NULL), size(0) {
                this->alloc = alloc;
            }

           nodeptr insertNode(nodeptr t, nodeptr new_node)
           {
               if (t == NULL)
                {
                    t = new_node;
                   // std::cout << new_node->data.first;
                    return t;
                }
                
            //    if (t->right == NULL)
            //    {
            //        std::cout << "right is NULL" << std::endl;
            //    }
            //    if (t->left == NULL)
            //    {
            //        std::cout << "left is NULL" << std::endl;
            //    }
               first oldfirst = t->data.first;
               first newfirst = new_node->data.first;
               //first lfirst = t->left->data.first;
               //first rfirst = t->right->data.first;
               //std::cout << oldfirst << std::endl;
                if (comp_(newfirst,oldfirst))
                {
                    t->left = insertNode(t->left, new_node);
                    std::cout << "dasdasd 1÷÷" << std::endl;
                }
                else if (comp_(oldfirst,newfirst))
                {
                    t->right = insertNode(t->right, new_node);
                    std::cout << "dasdasd" << std::endl;
                }
                else    // duplicated key
                     return t;
                // t->height = 1 + max(height(t->left) , height(t->right));
                // size_type i = balance_factor(t);
                // if (i > 1 && newfirst < lfirst)
                //         return t;
                return t;
           }
            void print_node(nodeptr t)
            {
               // nodeptr tmp = t->right;

                while (t)
                {
                    // if (t->right == NULL)
                    // {
                    //     std::cout << "right is NULL" << std::endl;
                    // }
                   std:: cout << t->data.first << std::endl;
                    t = t->right;
                }
            }




    };
}
#endif