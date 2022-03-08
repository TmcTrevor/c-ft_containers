#include <iostream>
#include <vector>
using namespace std;

  
int main()
{
    vector<int> a;

    cout << a.capacity() << endl << a.size() << endl << a.max_size() << endl;
    return 0;
}