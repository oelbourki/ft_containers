#include <iostream>
#include <map>
#include "map.hpp"


#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 4 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
typedef ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ft_const_iter_def;

#define TEST_CASE(fn)                                                                                                             \
    cout << GREEN << "\t======================================================================================" << RESET << endl; \
    cout << endl;                                                                                                                 \
    cout << BLUE << "\t   Running " << #fn << " ... \t\t\t\t\t\t" << RESET << std::endl;                                          \
    fn();                                                                                                                         \
    cout << endl;                                                                                                                 \
    cout << GREEN << "\t======================================================================================" << RESET << endl;
using namespace std;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

// template <class InputIterator1, class InputIterator2>
//   bool compareMaps ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,InputIterator2 first3 )
// {
//   while (first1!=last1) {
//     if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
//       return false;
//     ++first1; ++first2;
//   }
//   return true;
// }
bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};




void testModifiers()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method "
              << "] --------------------]\t\t\033[0m";

    {
        bool cond(false);
        // erasing all the elements in the map;
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();
            m1.erase(m1.begin(), m1.end());
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.erase(ft_m1.begin(), ft_m1.end());
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
//         std::map<char, int> m;
//         ft::map<char, int> ft_m;
//         std::map<char, int>::iterator it;
//         ft::map<char, int>::iterator ft_it;

//         // insert some values:
//         ft_m['a'] = 10;
//         ft_m['b'] = 20;
//         ft_m['c'] = 30;
//         ft_m['d'] = 40;
//         ft_m['e'] = 50;
//         ft_m['f'] = 60;

//         m['a'] = 10;
//         m['b'] = 20;
//         m['c'] = 30;
//         m['d'] = 40;
//         m['e'] = 50;
//         m['f'] = 60;

//         cond = m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
// EQUAL(cond);
//         it = m.find('b');
//         ft_it = ft_m.find('b');

//         cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
//         EQUAL(cond);
//         m.erase(it);       // erasing by iterator
//         ft_m.erase(ft_it); // erasing by iterator

//         cond = cond && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
// EQUAL(cond);
//         int ret = m.erase('c');       // erasing by key
//         int ft_ret = ft_m.erase('c'); // erasing by key

//         cond = cond && ret == ft_ret && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
// EQUAL(cond);
//         it = m.find('e');
//         ft_it = ft_m.find('e');

//         cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();
// EQUAL(cond);
//         m.erase(it, m.end());          // erasing by range
//         ft_m.erase(ft_it, ft_m.end()); // erasing by range

//         cond = cond && m.empty() == ft_m.empty() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
// EQUAL(cond);
//         /* ---------- Testing some edge cases ---------- */

//         std::map<int, std::string> m2;
//         ft::map<int, std::string> ft_m2;

//         for (size_t i = 0; i < 1e5; i++)
//         {
//             m2.insert(std::make_pair(i, "string1"));
//             ft_m2.insert(ft::make_pair(i, "string1"));
//         }

//         std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
//         ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

//         m2.erase(m2.begin());
//         ft_m2.erase(ft_m2.begin());

//         cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

//         m2.erase(it2->first);
//         ft_m2.erase(ft_it2->first);

//         cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());
// EQUAL(cond);
cond = 1;
        std::map<int, std::string> m3;
        ft::map<int, std::string> ft_m3;
        std::vector<int> vec;
        std::vector<int> ft_vec;
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e6);

        for (size_t i = 0; i < 1e6; i++)
        {
            m3.insert(std::make_pair(i, "string1"));
            ft_m3.insert(ft::make_pair(i, "string1"));
        }
  std::cout << "size:"<<m3.size() << "|" <<ft_m3.size()<<"|"<< (m3.size() == ft_m3.size()) << std::endl;
  std::cout << "cmp:"<< compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()) << std::endl;

        for (size_t i = 1e4; i > 0; --i)
        {
            // int n = distr(generator);
            // int ret1 = m3.erase(n);
            // int ret2 = ft_m3.erase(n);
           int ret1 = m3.erase(i);
            int ret2 = ft_m3.erase(i);
            // if (ret1 != ret2)
            // {
            //     cond = false;
            //     break;
            // }
        }
        for (size_t i = 1e4; i > 0; --i)
        {
            // int n = distr(generator);
            // int ret1 = m3.erase(n);
            // int ret2 = ft_m3.erase(n);
           int ret1 = m3.erase(i);
            int ret2 = ft_m3.erase(i);
            // if (ret1 != ret2)
            // {
            //     cond = false;
            //     break;
            // }
        }
  std::cout << "cmp:"<< compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()) << std::endl;

  std::cout << "size:"<<m3.size() << "|" <<ft_m3.size()<<"|"<< (m3.size() == ft_m3.size()) << std::endl;

        if (!m3.empty())
        {
            m3.erase(m3.begin(), m3.end());
            // m3.erase(m3.begin(), m3.end());
        }
  // std::cout << "size:"<<m3.size() << "|" <<ft_m3.size()<<"|"<< (m3.size() == ft_m3.size()) << std::endl;

        if (!ft_m3.empty())
        {
            ft_m3.erase(ft_m3.begin(), ft_m3.end());
            // ft_m3.erase(ft_m3.begin(), ft_m3.end());
        }
        cond = cond && (m3.size() == ft_m3.size() && compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));
  std::cout << "size:"<<m3.size() << "|" <<ft_m3.size()<<"|"<< (m3.size() == ft_m3.size()) << std::endl;
  std::cout << "cmp:"<< compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()) << std::endl;

        EQUAL(cond);
    }
}


int main(){
testModifiers();
        // ft::map<char, int> ft_m;
        // ft::map<char, int>::iterator ft_it;

        // // insert some values:
        // ft_m['a'] = 10;
        // ft_m['b'] = 20;
        // ft_m['c'] = 30;
        // ft_m['d'] = 40;
        // ft_m['e'] = 50;
        // ft_m['f'] = 60;
        // ft_m.clear();
        // std::cout << ft_m.size() << std::endl;
        // // ft_m.clear();

        // system("leaks a.out");
  return 0;
}