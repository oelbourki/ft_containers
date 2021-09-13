#include "ft_stack.hpp"
using namespace std;
int main()
{
    ft::stack<int> l;
    stack<int> l1;
    deque<int> f;
    for (size_t i = 0; i < 10; i++)
    {
        l.push(i);
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << l.top() << endl;
        l.pop();
    }
    
    
}