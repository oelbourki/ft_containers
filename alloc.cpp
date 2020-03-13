// C++ program for illustration 
// of std::allocator() function 
#include <iostream> 
#include <memory> 
using namespace std; 
int main() 
{ 
  
    // allocator for integer values 
    allocator<int> myAllocator; 
  
    // allocate space for five ints 
    int* arr = myAllocator.allocate(5); 
  
    // construct arr[0] and arr[3] 
    myAllocator.construct(arr, 100); 
    arr[3] = 10; 
  
    cout << arr[3] << endl; 
    cout << arr[0] << endl; 
  
    // deallocate space for five ints 
    myAllocator.deallocate(arr, 5); 
  
    return 0; 
} 

template <class T, class A = std::allocator<T> >
class ft_vector
{
private:
    T *_arr;
    int _size;
    int _capacity;
    static const size_t _max_size = 4611686018427387903;
public:
    typedef T* iterator;
    ft_vector();
    ft_vector(unsigned int n);
    ft_vector(ft_vector const &arr);
    ~ft_vector();
    ft_vector<T> &operator=(ft_vector <T>const &arr);
    T &operator[](int i) const;
    int size() const;
    bool empty() const;
    void    push_back(T v);
    void    pop_back();
    int     capacity() const;
    void    assign(int n,const T& val);
    T& back();
    T& front();
    void    clear();
    size_t  max_size();
    void    swap(ft_vector<T> &);
    void reserve(size_t);
    void resize (size_t n, T val = 0);
    iterator begin();
    iterator end();
};