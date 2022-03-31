#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

namespace ft {
    template <typename T>
    struct Node {
        typedef Node* Nodeptr;
        typedef const Node* const_Nodeptr;
        typedef size_t size_type;
        
        T       data;
        Nodeptr parent;
        Nodeptr left;
        Nodeptr right;
        size_type height;

        Node(T data) : data(data), parent(NULL), left(NULL), right(NULL), height(1){}
        
            
    };

    template <typename T, class comp, class Alloc = std::allocator<T> >
    class AVL
    {
        public :
            typedef T value_type;
            typedef Node<value_type>::Nodeptr    nodeptr;
            typedef Node<value_type>::size_type size_type;
            typedef typename Alloc::template rebind<Node<value_type>>::other allocor_type;
        private : 

        nodeptr  root;
        nodeptr nil;
        comp     comp;
        allocator_type alloc;
        size_type size;

        size_type max(size_type a, size_type b)
        {
            return a > b ? a : b;
        }

        size_type height(Node *t)
        {
            if (t == NULL) return 0;
            return t->height;
        }

        size_type balance_factor(Node *t)
        {
            if (t == NULL) return 0;
            return height(t->left) - height(t->right);
        }

        void left_rotate(Node *t)
        {

            if (t == NULL || t->right == NULL) return;
            
            if (t->right->left != NULL)
            {
                t->right->left->parent = t;
                t->right = t->right->left;
            }
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

           void insert(Node *t, int i)
           {
               
           }
            




    };
}
#endif