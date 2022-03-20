#include "containers/stack.hpp"
#include "containers/vector.hpp"
#include <vector>
#include <stack>


int main()
{
    std::vector<int> a(7, 15);

    ft::stack<int, std::vector<int> > stac(a);

    const ft::stack<int, std::vector<int> > stc(a);

    if (stac == stc) 
    std::cout << "yes" << std::endl;

}