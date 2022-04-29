#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
// #include "pair.hpp"
#include "../iterators/bidirectional_iterator.hpp"  
// #include "../containers/map.hpp"
template <class T, class value_compare, class Alloc >
class BidiIterator;


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

	template <typename T >
	struct Node {
		public :
		typedef Node* Nodeptr;
		typedef const Node* const_Nodeptr;
		typedef size_t size_type;
		// typedef typename T::first_type first;
		// typedef typename T::second_type second;
		
		T       data;
		Nodeptr parent;
		Nodeptr left;
		Nodeptr right;
		Nodeptr root;
		//Alloc alloc;
		// size_type height;
		// size_type blackheight;
		// size_type redheight;
		int color;

		Node(T data) : data(data), parent(NULL), left(NULL), right(NULL), root(NULL), color(RED)
		{
			//this->data = alloc.allocate(1);
			//alloc.construct(this->data, T(data.first, data.second));
		}

		// Node(first &f, second &s) :  data(f,s), parent(NULL), left(NULL), right(NULL), height(1), color(RED), blackheight(2), redheight(0) 
		// {
		// 	// this->data = alloc.allocate(1);
		// 	// alloc.construct(this->data, T(f, s));
		// }

		Node(const_Nodeptr &c) : data(c->data)
		{
			// this->data = alloc.allocate(1);
			// alloc.construct(this->data, c.data);
			// std::cout << "data: " << c->data << std::endl;
			// ÷
			// data.first = c->data.first;
			// data.second = c->data.second;
			root = c->root;
			left = c->left;
			right = c->right;
			parent = c->parent;
			color = c->color;
		}
		Node &operator=(const_Nodeptr &c)
		{
			// this->data = alloc->allocate(1);
			// alloc->construct(this->data, c->data);
		   // std::cout << "operator" << std::endl;
			// data.first = c->data.first;
			// data.second = c->data.second;
			data = c->data;
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

		// operator const_Nodeptr() const 
		// {
		// 	return *this;
		// }

		Nodeptr find_root(Nodeptr x)
		{
			return x->root;
		}

			
	};
	// template <class T>
	// std::ostream & operator<<(std::ostream &os, const Node<T> &c)
	// {
	// 	std::cout << "dasdasd" << std::endl;
	// 	os << c->data.first;
	// 	os << c->data.second;
	// 	return os;
	// }

	template <typename T, class comp, class Alloc = std::allocator<T> >
	class RBT 
	{
			public :
			typedef T value_type;
			typedef typename Node<value_type>::Nodeptr    nodeptr;
			typedef typename Node<value_type>::const_Nodeptr const_nodeptr;
			typedef typename Node<value_type>::size_type size_type;
			typedef typename Alloc::template rebind<Node<value_type> >::other allocator_type;
			// typedef ft::BidiIterator<value_type, comp , Alloc > iterator;
            // typedef ft::BidiIterator<const value_type, comp , Alloc > const_iterator;

			


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
			size = 0;
		}

		~RBT()
		{
			//clear_all(this->root);
		}

		RBT &operator=(RBT const & a)
		{
			root = a.getRoot();
			size = a.size;
			alloc = a.alloc;
			comp_ = a.comp_;
			//}
			return *this;
		}

		// RBT(const RBT& a)
		// {
		// 	root = 
		// }

		nodeptr getRoot() const
		{
			return root;
		}

		size_type getSize() const
		{
			return size;
		}

		void    leftRotate(nodeptr x)
		{
			nodeptr y = x->right;
			int flag = 0;
			//if (x->right)
			// std::cout << "Left Rotate before" << x->data.first << std::endl;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
			{
				this->root = y;
				flag = 1;
			}
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
			if (flag)
				update_root(root);
		}
		
		void    rightRotate(nodeptr y)
		{
			nodeptr x = y->left;
			int flag = 0;
			//if (x)
			//{
				 //x->right = y->left;
				y->left = x->right;
				if (x && x->right)
					x->right->parent = y;
				x->parent = y->parent;
				if (y->parent == NULL)
				{
					this->root = x;
					flag = 1;
					//update_root(root);
				}
				else if (y->parent->left == x)
					y->parent->left = x;
				else
					y->parent->right = x;
				x->right = y;
				y->parent = x;
				if (flag)
				update_root(root);
			//}
		}
		nodeptr place_search(value_type a) const
		{
			nodeptr x = this->root;
			nodeptr y;

			while (x != NULL)
			{
				y = x;
				//oldfirst = x->data;
				if (comp_(x->data, a))
					x = x->right;
				else if (comp_(a, x->data))
					x = x->left;
				else
					return x;
			}
			return y;
		}

		nodeptr insertNode(nodeptr t, nodeptr new_node)
		{
			nodeptr y = NULL;
			nodeptr x = t;
			if (t == NULL)
			{
				new_node->color =  BLACK;
				this->root = new_node;
				new_node->root = new_node;
				//update_root(root);
				return  new_node;
			}
			else
			{
				value_type oldfirst(x->data);
				//value_type newfirst = new_node->data;
				y = place_search(new_node->data);
				new_node->parent = y;
				if (comp_(new_node->data, y->data))
					y->left = new_node;
				else
					y->right = new_node;

				new_node->color = RED;
			}
			new_node->root = t;
			return t;
		}

		nodeptr insetINRbt(value_type val)
		{
			nodeptr a;
			 if ((a = search(root, val)))
			{
				std::cout << "dddd" << std::endl;
				return NULL;
			}
			nodeptr newNode = alloc.allocate(1);
			alloc.construct(newNode, Node<value_type>(val));

			root = insertNode(root, newNode);
			size++;
			//update_root(root);
			
			fixBRT(newNode);
			return newNode;
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
			if (y == NULL)
				return NULL;
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
				// leftRotate(z);
				 leftRotate(y);
			else
				 rightRotate(y);
			//    rightRotate(y);
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
					if (y == z->left)
					{ 
						if (isBlack(s))
						{
							if (x == y->right)
							{
								leftRotate(y);
								x = y;
								y = x->parent;
							}
							makeItBlack(y);
							makeItRED(z);
							rightRotate(z);
							x = y;
						}
						else
						{
							makeItBlack(s);
							makeItBlack(y);
							makeItRED(z);
							x = z;
							fixBRT(z);
						}
					}
					else
					{
						if (isRed(s))
						{
							makeItBlack(s);
							makeItBlack(y);
							makeItRED(z);
							x = z;
							fixBRT(z);
						}
						else
						{
							if (x == y->left)
							{
								rightRotate(y);
								x = y;
								y = x->parent;
							}
							makeItBlack(y);
							makeItRED(z);
							leftRotate(z);
							x = y;
						}
					}
				}
			}
			this->root->color = BLACK;
		}


		nodeptr search(nodeptr x, value_type val)
		{
			if (x == NULL)
				return NULL;
			if (comp_(val, x->data) && x->left)
				return search(x->left, val);
			else if (comp_(x->data, val) && x->right)
				return search(x->right, val);
			else
				return x;
		}

		nodeptr search(value_type val) const
		{
				nodeptr tmp = root;
				while (1)
				{
					// if (tmp)
					// 	std::cout << tmp->data.first << " " << tmp->data.second << std::endl;
					if (tmp == NULL)
						return NULL;
					if (val == tmp->data)
						return tmp;
					if (comp_(val, tmp->data))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				return tmp;
		}
		
		
		static nodeptr find_min(nodeptr x)
		{
			//std::cout << "find_min" << std::endl;
			//x = x->right;
			if (x == NULL)
				return NULL;
			while (x->left != NULL)
				x = x->left;
			return x;
		}
		
		static nodeptr find_max(nodeptr x)
		{
			if (x == NULL)
				return NULL;
			while (x->right != NULL)
				x = x->right;
			return x;
			
		}

		static nodeptr predecessor(nodeptr x)
		{
			nodeptr y;

			if (x->left != NULL)
				return (find_max(x->left));
			y = x->parent;
			while (y && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		static nodeptr successor(nodeptr x)
		{
			nodeptr y;
			
			if (x->right != NULL)
				return (find_min(x->right));
			y = x->parent;
			while (y && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
			////////////////////////////////////////////////////////////////


			
			//////////////////		///////////////////////////////////////
		
		void rbTransplant(nodeptr u, nodeptr v) 
		{
			if (u->parent == nullptr) 
			{
				this->root = v;
				update_root(root);
			}
			else if (u == u->parent->left)
			{
				u->parent->left = v;
				//std::cout << "dasd" << std::endl; 
			}
			else
				u->parent->right = v;
			//v->parent = u->parent;
 		}

		bool isleft(nodeptr x)
		{
			if (x == NULL)
				return false;
			if (x->parent)
				return (x == x->parent->left);
			return false;
		}

		// void deleteFix(nodeptr x)
		// {
		// 	nodeptr w;
		// 	while (x && x != this->root && isBlack(x))
		// 	{
		// 		if (isleft(x))
		// 		{
		// 			w = sibling(x);
		// 			if (w->color == RED)
		// 			{
		// 				makeItBlack(x->parent->right);
		// 				makeItRED(x->parent);
		// 				leftRotate(x->parent);
		// 				x->parent->right = w;
		// 			}
		// 			if (w->left == BLACK && w->right == BLACK)
		// 			{
		// 				makeItRED(w);
		// 				x = x->parent;
		// 			}
		// 			else if (w->right == BLACK)
		// 			{
		// 				makeItBlack(w->left);
		// 				makeItRED(w);
		// 				rightRotate(w);
		// 				w = x->parent->right;
		// 			}
		// 			else
		// 			{
		// 				w->color = x->parent->parent->color;
		// 				x->parent->parent->color = BLACK;
		// 				w->right->color = BLACK;
		// 				leftRotate(x->parent);
		// 				this->root = x;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			w = sibling(x);
		// 			std::cout << "dasdqqqq" << std::endl;
		// 			if (w->color == RED)
		// 			{
		// 				makeItBlack(x->parent->left);
		// 				makeItRED(x->parent);
		// 				rightRotate(x->parent);
		// 				x->parent->right = w;
		// 			}
		// 			if (w->left == BLACK && w->right == BLACK)
		// 			{
		// 				makeItRED(w);
		// 				x = x->parent;
		// 			}
		// 			else if (w->left == BLACK)
		// 			{
		// 				makeItBlack(w->right);
		// 				makeItRED(w);
		// 				leftRotate(w);
		// 				w = x->parent->right;
		// 			}
		// 			else
		// 			{
		// 				w->color = x->parent->parent->color;
		// 				x->parent->parent->color = BLACK;
		// 				w->left->color = BLACK;
		// 				rightRotate(x->parent);
		// 				this->root = x;
		// 			}
		// 		}
		// 		x->color = BLACK;
		// 	}
		// }

	

		bool hasRedChild(nodeptr w)
		{
			if ((w->left != NULL && isRed(w->left) ) || (w->right != NULL && isRed(w->right)))
				return true;
			return false;
		}

		//////////////////////


	///////////////////////


	

		void fixDoubleBlack(nodeptr x)
		{
			if (x == this->root)
				return ;
			nodeptr w = sibling(x); // 2777 // 16
			nodeptr y = x->parent; // 2135 // 26
			if (w == NULL) // x have no sibling , double black is up
				fixDoubleBlack(y);
			else
			{
				if (isRed(w))
				{
					makeItRED(y);
					makeItBlack(w);
					if (isleft(w))
						rightRotate(y);
					else
						leftRotate(y);
					fixDoubleBlack(x);
				}
				else
				{
					if (hasRedChild(w))
					{
						if (w->left != NULL && isRed(w->left))
						{
							 if (isleft(w))
							 {
								  //if (w->data.first == 16)
								  	//std::cout << "adasd" << std::endl;
									//leftRotate(w);
								 w->left->color = w ->color;
								 w->color = y->color;
								 rightRotate(y);
							 }
							 else
							 {
			
								 w->left->color = y->color;
								 //w->color = y->color;
								 rightRotate(w);
								
								 leftRotate(y);
		
							 }
						}
						else
						{ 
							/// this part isn't 100% functionable test it tomorow
							if (isleft(w))
							{
								w->right->color = w->color;
								w->color = y->color;
								//leftRotate(w);
								rightRotate(y);
							}
							else
							{
								w->right->color = y->color;
								//w->color = y->color;
								leftRotate(y);
							}
						}
						makeItBlack(y);
					}
					else
					{
						makeItRED(w);
						if (isBlack(y))
							fixDoubleBlack(y);
						else
							makeItBlack(y);
					}

				}
			}

		}
		
		nodeptr nodeToReplace(nodeptr x)
		{
			if (x->left && x->right)
				//return find_min(x->right);
				return find_max(x->left);
			if (!x->right && !x->left)
				return NULL;
			if (x->left)
				return (x->left);
			else
				return (x->right);
		}


	


		void deleteNode(nodeptr z, int a)
		{
			nodeptr x, y;
			(void)a;
			if (z == NULL)
				return;
			y = nodeToReplace(z); // 250 // null
			//std::cout <<" dasdasd = " << y->data.first << std::endl;
			bool doubleBlack = (isBlack(y) && isBlack(z));
			//std::cout << "y = " << y->data.first << " db = " << doubleBlack << std::endl;
			if (!y)
			{
				if (z == this->root)
					this->root = NULL;
				else
				{
				// std::cout << "asdasd" << std::endl;
					if (doubleBlack)
						fixDoubleBlack(z);
					else
					{
						x = sibling(z);
						if (x)
							makeItRED(x);
					}
					if (isleft(z))
						z->parent->left = NULL;
					else
						z->parent->right = NULL;
				}
				alloc.destroy(z);
				alloc.deallocate(z, 1);
				return ;
				
			}
			if (!z->left || !z->right)
			{
				if (z == this->root)
				{
					// std::swap(z->data, y->data);
					mySwap(z, y);
					z->left = NULL;
					z->right = NULL;
					alloc.destroy(y);
					alloc.deallocate(y, 1);
				}
				else
				{
					if (isleft(y))
						z->parent->left = y;
					else
						z->parent->right = y;
					nodeptr w  = z->parent;
					alloc.destroy(z);
					alloc.deallocate(z, 1);
					y->parent = w;
					if (doubleBlack)
						fixDoubleBlack(y);
					else
						makeItBlack(y);
				}
				return ;
			}/// if the node to be delete is Red 
			mySwap(y, z);
			// std::swap(y->data, z->data);
			//std::cout << y->data.first << std::endl;
			deleteNode(y, 0);
		}

		void mySwap(nodeptr y, nodeptr z)
		{
			first a = y->data.first;
			second b = y->data.second;
			y->data.first = z->data.first;
			y->data.second = z->data.second;
			z->data.first  = a;
			z->data.second = b;
		}
		// void deleteNode(value_type val)
		// {
		// 	nodeptr z = search()
		// }

		void deleteNode(value_type val)
		{
			nodeptr z = NULL;
			//nodeptr x;
			z = search(val);

			if (z == NULL)
				return ;
			deleteNode(z, 0);
			size--;
		}	

		// void deleteNode(nodeptr node, value_type key)
		// {
		// 	nodeptr z = NULL;
		// 	nodeptr x, y;
		// 	//std::cout << key << std::endl;
		// 	z = search(key);

		// 	if (z == NULL)
		// 		return ;
		// 	deleteNode(z);
		// 	size--;
		// }	

		nodeptr begin() const
		{
			nodeptr z = find_min(root);
			return z;
		}

		nodeptr end() const
		{
			return NULL;
		}
		// iterator begin()
		// {
		// 	iterator z(this->root, find_min(root));
		// 	return z;
		// }

		// iterator end()
		// {
		// 	iterator z(this->root, NULL);
		// 	return z;
		// }

		// const_iterator begin() const
		// {
		// 	const_iterator z(this->root, find_min(root));
		// 	return z;
		// }

		// const_iterator end() const
		// {
		// 	const_iterator z(this->root, NULL);
		// 	return z;
		// }




		// nodeptr lower_bound()
		// void deleteNode(nodeptr node, first key)
		// {
		// 	nodeptr z = NULL;
		// 	nodeptr x, y;

		// 	z = search(node, key);
		// 	if (z == NULL)
		// 		return;
		// 	y = z;
		// 	//std::cout << z->data.first;
		// 	int y_color = z->color; // black
		// 	if (!z->left)
		// 	{
		// 		x = z->right;
		// 		// z = x;
		// 		rbTransplant(z, z->right);
		// 	}
		// 	else if (!z->right)
		// 	{
		// 		x = z->left;
		// 		//z = x;
		// 		rbTransplant(z, z->left);
		// 	}
		// 	else
		// 	{
		// 		y = find_min(z->right);
		// 		y_color = y->color; //  black
		// 		x = y->right;
		// 		if (y->parent == z)
		// 			x->parent = y;
		// 		else
		// 		{
		// 			rbTransplant(y, y->right);
		// 			y->right = z->right;
		// 			y->right->parent = y;
		// 		}
		// 		rbTransplant(z, y);
     	// 		y->left = z->left;
     	// 		y->left->parent = y;
     	// 		y->color = z->color;
		// 	}
		// 	 delete z;
		// 	if (y_color == BLACK) {
		// 		//std::cout << x->data.first << std::endl;
		// 		fixDoubleBlack(x);
		// 	}
		// }


		bool empty() const { if (root) return false; return true;}


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
		std::cout<< Black << root->data.first<< DEFAULT << "\n";
	else
		std::cout<< Red << root->data.first<< DEFAULT << "\n";

 
	// Process left child
	print2DUtil(root->left, space);
}


bool isBalancedUtil(nodeptr root, int &maxh1, int &minh1)
{
   if (root == NULL){
      maxh1 = minh1 = 0;
      return true;
   }
   int lmxh1, lmnh1;
   int rmxh1, rmnh1;
   if (isBalancedUtil(root->left, lmxh1, lmnh1) == false)
      return false;
   if (isBalancedUtil(root->right, rmxh1, rmnh1) == false)
      return false;
   maxh1 = std::max(lmxh1, rmxh1) + 1;
   minh1 = std::min(lmnh1, rmnh1) + 1;
   if (maxh1 <= 2*minh1)
      return true;
   return false;
}

bool isBalanced(nodeptr root){
   int maxh1, minh1;
   return isBalancedUtil(root, maxh1, minh1);
}



			void	clear_all(nodeptr src)
			{
				if (src != NULL)
				{
					clear_all(src->left);
					clear_all(src->right);
					//_alloc.deallocate(src->data, 1);
					alloc.destroy(src);
					alloc.deallocate(src, 1);
				}
			}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void	update_root(nodeptr x)
		{
			//if (x && x->left)
			//	std::cout << "update_root : " << x->left->data.first << std::endl;
			if (x != NULL )
			{
				update_root(x->left);
				x->root = root;
				update_root(x->right);
			}	
		}

		//  static void        inoderprint(nodeptr x)
        // {
        //     if (x != NULL)
        //     {
        //         inoderprint(x->left);
        //         std::cout << "(" << x->data.first << "), ";
		// 		if (x->root)
        //         std::cout << " its root = " << x->root->data.first << "), ";
		// 		std::cout << std::endl;
        //         // std::cout << "(" << x->right << "), ";
        //         // std::cout << "(" << x->parent << "), ";
        //         inoderprint(x->right);
        //     }
        // }


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