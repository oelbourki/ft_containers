#include "vector.hpp"
#include <vector>
using namespace std;
int     main()
{
    ft_vector <int> f(10);
    ft_vector <int> c(f);
    vector <int> v;
    // v.push_back(5);
    cout << v.empty() << endl;
    return 0;
}