#include <iostream>
#include <vector>
using namespace std;
template<class T>
struct myalloc: allocator<T>
{
    T* allocate(int size)
    {
        std::cout << "allocate " << size << std::endl;
        return new T[size];
    }
    void deallocate(T* ptr,int size)
    {
        std::cout << "deallocate " << size << std::endl;
        delete [] ptr;
    }
};

int     main()
{
    vector<int,myalloc<int> > x;
    x.push_back(5);

}