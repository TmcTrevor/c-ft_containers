#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#define BLACK 0
#define RED   1
namespace ft {
    template <typename T, class Alloc>
    struct Node {
        public :
        typedef Node* Nodeptr;
        typedef const Node* const_Nodeptr;
        typedef size_t size_type;
        typedef typename T::first_type first;
        typedef typename T::second_type second;
        
        T       *data;
        Nodeptr parent;
        Nodeptr left;
        Nodeptr right;
        Alloc alloc;
        size_type height;
        size_type blackheight;
        size_type redheight;
        int color;

        Node(T data) : parent(NULL), left(NULL), right(NULL), height(1), color(RED), blackheight(2), redheight(0)
        {
            this->data = alloc.allocate(1);
            alloc.construct(this->data, T(data.first, data.second));
        }

        Node(first &f, second &s) : parent(NULL), left(NULL), right(NULL), height(1). color(RED), blackheight(2), redheight(0) 
        {
            this->data = alloc.allocate(1);
            alloc.construct(this->data, T(f, s));
        }

        Node(const Node &c)
        {
            this->data = alloc.allocate(1);
            alloc.construct(this->data, c.data);
            left = c.left;
            right = c.right;
            parent = c.parent;
            color = c.color;
        }
        Node &operator=(Nodenconst Node &c)
        {
            this->data = alloc.allocate(1);
            alloc.construct(this->data, c.data);
            left = c.left;
            right = c.right;
            parent = c.parent;
            color = c.color;
            return *this;
        }

        ~Node()
        {
            if (data)
            {
                alloc.destroy(data);
                alloc.deallocate(data, 1);
            }
        }
            
    };
    template <typename T, class comp, class Alloc = std::allocator<T> >
    class RBT 
    {
            public :
            typedef T value_type;
            typedef typename Node<value_type>::Nodeptr    nodeptr;
            typedef typename Node<value_type>::size_type size_type;
            typedef typename Alloc::template rebind<Node<value_type> >::other allocator_type;
            


        typedef typename T::first_type first;
        typedef typename T::second_type second;
        private:
                nodeptr  root;
                nodeptr nil;
                comp     comp_;
                allocator_type alloc;
                size_type size;
    public:
        RBT()
        {
            root = NULL;
            nil = NULL;
        }

        ~RBT()
        {
            
        }

        void    leftRotate(nodeptr x)
        {
            nodeptr y = x->right;
            if (x == NULL) return;
            if (y && y->left)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == NULL)
                this->x = y;
            else if (x->parent->left == x)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        
        void    rightRotate(nodeptr y)
        {
            nodeptr x = y->left;
            if (y == NULL) return;
            if (x && x->right)
                x->right->parent = y;
            x->parent = y->parent;
            if (y->parent == NULL)
                this->root = x;
            else if (y->parent->left == x)
                y->parent->left = x;
            else
                y->parent->right = x;
            x->right = y;
            y->parent = x;
        }

        nodeptr insertNode(nodeptr t, nodeptr new_node)
        {
            nodeptr y = NULL;
            nodeptr x = this->root;
            first oldfirst = t->data.first;
            first newfirst = new_node->data.first;
            if (t == NULL)
            {
                new_node->color =  BLACK
                this->root = new_node;
                return  new_node;
            }
            else
            {
                while (t != NULL)
                {
                    y = t;
                    if (comp(oldfirst, newfirst))
                        t = t->right;
                    else if (comp(newfirst, oldfirst))
                        t = t->left;
                    else
                        return t;
                }
                new_node->parent = y;
                if (y == NULL)
                    this->root = new_node;
                else if (comp(y->data.first, newfirst))
                    y->left = new_node;
                else
                    y->right = new_node;

                new_node->color = RED;

            }
            return t;
        }

        void insetINRbt(value_type val)
        {
            nodeptr *newNode = alloc.allocate(1);
            alloc.construct(newNode, val);

            root = insertNode(root, newNode);

            // fix
        }

        // void fixBRT(nodeptr root, nodeptr newNode)
        // {
        //     nodeptr pnew = new_node->parent;

        //     while (pnew->color == RED)
        //     {
        //         if (p == )
        //     }
        // }

    };

}
#endif