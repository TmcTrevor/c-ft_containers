#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#define BLACK 0
#define RED   1
#define COUNT 10

# define 	Getline 	std::getline
# define 	GREEN 		"\e[1;32m"
# define 	Red 		"\e[1;31m"
# define 	WHITE 		"\e[1;37m"
# define 	YELLOW 	"\e[1;33m"
# define 	BLUE 		"\e[1;34m"
# define    Black   "\e[0;30m"
# define 	PURPLE 	"\033[1;35m"
# define 	DEFAULT	"\e[0;37m"

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
            // std::cout << y->data.first << std::endl;
            // std::cout << y->left->data.first << std::endl;

            x->right = y->left;
            if (y->left != NULL)
                y->left->parent = x;
            y->parent = x->parent;
            nodeptr tmp = x;
           //std::cout << tmp->data.first << std::endl;
            if (x->parent == NULL)
            {
                this->root = y;
                //  std::cout <<" root 1 : " << root->data.first << std::endl;
                // x = tmp;
                //  std::cout <<" root 2 : " << root->data.first << std::endl;
            }
            else if (x->parent->left == x)
                x->parent->left = y;
            else
                x->parent->right = y;
            //std::cout << y->left->data.first << std::endl;
            y->left = x;
            // std::cout << y->left->data.first << std::endl;
            x->parent = y;
        }
        
        void    rightRotate(nodeptr y)
        {
            nodeptr x = y->left;
            //x->right = y->left;
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
                //std::cout << "hello " << oldfirst << " " << x->right->data.first  << std::endl;
                while (x != NULL)
                {
                    y = x;
                    oldfirst = x->data.first;
                    //std::cout << "hello " << std::endl;
                    if (comp_(oldfirst, newfirst))
                    {
                        // if (newfirst == 11)
                       // std::cout << "hello " << oldfirst << " " << x->right->data.first  << std::endl;
                        x = x->right;
                    }
                   else if (comp_(newfirst, oldfirst))
                    {
                        //std::cout << "hello " << oldfirst << " " << x->right->data.first  << std::endl;
                        // if (newfirst == 11)
                            // std::cout << "hello41561" << std::endl;
                        x = x->left;
                    }
                }
                new_node->parent = y;
                //  if (y == NULL)
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
            //leftRotate(root);
           //fixBRT(newNode);
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
            if (node == NULL)
                return (false);
            // std::cout << node->color << std::endl;
            // std::cout << "fuck" << std::endl;
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
                    //std::cout << "hello" << std::endl;
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
    if (root->color == BLACK)
        std::cout<< Black <<root->data.first<< DEFAULT << "\n";
    else
        std::cout<< Red <<root->data.first<< DEFAULT << "\n";

 
    // Process left child
    print2DUtil(root->left, space);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                struct Trunk
                {
                    Trunk *prev;
                    std::string str;
                
                    Trunk(Trunk *prev, std::string str)
                    {
                        this->prev = prev;
                        this->str = str;
                    }
                };
                
                // Helper function to print branches of the binary tree
                void showTrunks(Trunk *p)
                {
                    if (p == nullptr) {
                        return;
                    }
                
                    showTrunks(p->prev);
                    std::cout << p->str;
                }
                
                void printTree(nodeptr root, Trunk *prev, bool isLeft)
                {
                    if (root == nullptr) {
                        return;
                    }
                
                    std::string prev_str = "    ";
                    Trunk *trunk = new Trunk(prev, prev_str);
                
                    printTree(root->right, trunk, true);
                
                    if (!prev) {
                        trunk->str = "———";
                    }
                    else if (isLeft)
                    {
                        trunk->str = ".———";
                        prev_str = "   |";
                    }
                    else {
                        trunk->str = "`———";
                        prev->str = prev_str;
                    }
                
                    showTrunks(trunk);
                    if (root->color == BLACK)
                        std::cout<< Black <<root->data.first<< DEFAULT << "\n";
                     else
                        std::cout<< Red <<root->data.first<< DEFAULT << "\n";
                
                    if (prev) {
                        prev->str = prev_str;
                    }
                    trunk->str = "   |";
                
                    printTree(root->left, trunk, false);
                }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    };

}
#endif