#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#define BLACK 0
#define RED   1
#define COUNT 10
namespace ft {
    template <typename T, class Alloc = std::allocator<T> >
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
        Alloc alloc;
        size_type height;
        size_type blackheight;
        size_type redheight;
        int color;

        Node(T data) : data(data), parent(NULL), left(NULL), right(NULL), height(1), color(RED), blackheight(2), redheight(0)
        {
            //this->data = alloc.allocate(1);
            //alloc.construct(this->data, T(data.first, data.second));
        }

        Node(first &f, second &s) :  data(f,s), parent(NULL), left(NULL), right(NULL), height(1), color(RED), blackheight(2), redheight(0) 
        {
            // this->data = alloc.allocate(1);
            // alloc.construct(this->data, T(f, s));
        }

        Node(const_Nodeptr &c)
        {
            // this->data = alloc.allocate(1);
            // alloc.construct(this->data, c.data);
            left = c->left;
            right = c->right;
            parent = c->parent;
            color = c->color;
        }
        Node &operator=(const_Nodeptr &c)
        {
            // this->data = alloc->allocate(1);
            // alloc->construct(this->data, c->data);
            left = c->left;
            right = c->right;
            parent = c->parent;
            color = c->color;
            return *this;
        }

        ~Node()
        {
            // if (data)
            // {
            //     alloc.destroy(data);
            //     alloc.deallocate(data, 1);
            // }
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
        //private:
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
            x->right = y->left;
            if (x == NULL) return;
            if (y && y->left)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == NULL)
                this->root = y;
            else if (x->parent->left == x)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
         //  x->right = y
        }
        
        void    rightRotate(nodeptr y)
        {
            nodeptr x = y->left;
            x->right = y->left;
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
            nodeptr x = t;
            if (t == NULL)
            {
                new_node->color =  BLACK;
                this->root = new_node;
                return  new_node;
            }
            else
            {
                first oldfirst  = x->data.first;
                first newfirst = new_node->data.first;
                while (x != NULL)
                {
                    y = x;
                    oldfirst = x->data.first;
                    if (comp_(oldfirst, newfirst))
                    {
                        // if (newfirst == 11)
                        //     std::cout << "hello " << oldfirst << " " << x->right->data.first  << std::endl;
                        x = x->right;
                    }
                   else if (comp_(newfirst, oldfirst))
                    {
                        // if (newfirst == 11)
                            // std::cout << "hello41561" << std::endl;
                        x = x->left;
                    }
                }
                new_node->parent = y;
                // if (y == NULL)
                //     this->root = new_node;
               // std::cout << oldfirst << "  " << newfirst << std::endl;
                if (comp_(newfirst, y->data.first))
                    y->left = new_node;
                else
                    y->right = new_node;

                new_node->color = RED;
            }
            return t;
        }

        void insetINRbt(value_type val)
        {
            nodeptr newNode = alloc.allocate(1);
           alloc.construct(newNode, Node<value_type>(val.first, val.second));

            root = insertNode(root, newNode);

           fixBRT(newNode);
        }


        bool isRoot(nodeptr node)
        {
            if (this->root == node)
                return (true);
            return false;
        }

        void makeItBlack(nodeptr node)
        {
            node->color = BLACK;
        }
         void makeItRED(nodeptr node)
        {
            node->color = RED;
        }

        bool isBlack(nodeptr node)
        {
            if (node == NULL || node->color == BLACK)
                return (true);
            return false;
        }
        bool isRed(nodeptr node)
        {
            if (node->color == RED)
                return (true);
            return false;
        }

        nodeptr sibling(nodeptr y)
        {
            nodeptr s = NULL;
            nodeptr z = y->parent;
            if (y == z->left)
                s = z->right;
            else
                s = z->left;
            return s;
        }

        void restructure(nodeptr y, nodeptr z)
        {
            if (y == z->left)
                leftRotate(z);
            else
                rightRotate(z);
        }



        void fixBRT(nodeptr x)
        {
            if (isRoot(x))
                makeItBlack(x);
            else
            {
                nodeptr y = x->parent;
                nodeptr z = y->parent;
                if (isRed(y))
                {
                    nodeptr s = sibling(y);
                    if (isBlack(s))
                    {
                        restructure(y, z);
                        makeItBlack(y);
                        makeItRED(x);
                        makeItRED(z);
                    }
                    else
                    {
                        makeItBlack(y);
                        makeItBlack(s);
                        makeItRED(z);
                        fixBRT(z);
                    }
                }

            }

        }

        void print2DUtil(nodeptr root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<<root->data.first<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}

    };

}
#endif