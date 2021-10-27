
//
// Created by moboustt on 19/8/2021.
//

// you should include your path to this files

#include "map.hpp"       // your map path.
// #include "../vVector.hpp" // your Vector path.
#include "pair.hpp"  // path to ft::pair.
// #include "map-test-helper.hpp"
#include <map>

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

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};


void reverse_iterator_tests(void)
{
    /*------------ std::reverse_iterator ---------*/
    std::map<int, char> m;
    for (int i = 0; i < 1e2; i++)
        m.insert(std::make_pair(i, 'A'));

    std::reverse_iterator<std::map<int, char>::iterator> rit(m.end()), rit_1(--m.end());

    ft::reverse_iterator<std::map<int, char>::iterator> my_rit(m.end()), my_rit1(--m.end());
    /*----------------------------------*/
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        ft::reverse_iterator<std::map<int, char>::iterator> ob(my_rit);
        EQUAL(*my_rit == *ob);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " riterator to const_riterator "
              << "] --------------------]\t\t\033[0m";
    {
        ft::map<int, char> my_m;
        for (int i = 0; i < 1e2; i++)
            my_m.insert(ft::make_pair(i, 'A'));

        ft::map<int, char>::reverse_iterator my_rit2(my_m.end());
        ft::map<int, char>::const_reverse_iterator c_it(my_rit2), c_ob(my_m.end());
        c_it = my_rit2;
        // c_it = c_ob;

        EQUAL(my_rit2->first == c_it->first && my_rit2->first == c_ob->first);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function "
              << "] --------------------]\t\t\033[0m";
    EQUAL((rit->first == (rit_1.base()->first)) && (my_rit->first == my_rit1.base()->first));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((rit == rit_1) == (my_rit == my_rit1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((rit != rit_1) == (my_rit != my_rit1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL(((my_rit->first == (--m.end())->first) && ((my_rit->first) == ((--m.end())->first))) && ((rit->first == (--m.end())->first) && ((rit->first) == ((--m.end())->first))));

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((((*my_rit).first == (*(--m.end())).first) && (((*my_rit).first) == ((*(--m.end())).first))) && (((*rit).first == (*(--m.end())).first) && ((*(rit)).first) == ((*(--m.end())).first)));

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++rit operator "
              << "] --------------------]\t\t\033[0m";
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
    EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --rit operator "
              << "] --------------------]\t\t\033[0m";
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
    EQUAL((my_rit->first == (--my_rit1)->first) && (rit->first == (--rit_1)->first));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit++ operator "
              << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::map<int, char>::iterator> tmp(rit++);
        ft::reverse_iterator<std::map<int, char>::iterator> my_tmp(my_rit++);
        EQUAL(tmp->first == (--rit)->first && my_tmp->first == (--my_rit)->first);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit-- operator "
              << "] --------------------]\t\t\033[0m";
    {
        rit++;
        my_rit++;
        std::reverse_iterator<std::map<int, char>::iterator> tmp(rit--);
        ft::reverse_iterator<std::map<int, char>::iterator> my_tmp(my_rit--);
        EQUAL(tmp->first == (++rit)->first && my_tmp->first == (++my_rit)->first);
    }
}

void testOperations()
{
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " find method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     bool cond(true);
    //     {
    //         time_t start, end, diff;
    //         /*------------------ std::maps ---------------------*/
    //         std::map<int, std::string> m1;
    //         ft::map<int, std::string> ft_m1;
    //         for (size_t i = 0; i < 1e6; i++)
    //         {
    //             m1.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, "string2"));
    //         }

    //         start = get_time();

    //         for (size_t i = 1e1; i < 1e5; i += 10)
    //             m1.find(i);

    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::Maps ---------------------*/
    //         ualarm(diff * 1e3, 0);
    //         for (size_t i = 1e1; i < 1e5; i += 10)
    //             ft_m1.find(i);
    //         ualarm(0, 0);
    //         /*----------------------------------------------------*/
    //     }

    //     std::vector<int> vec;
    //     std::vector<int> ft_vec;
    //     std::random_device randDev;
    //     std::mt19937 generator(randDev());
    //     std::uniform_int_distribution<int> distr(0, 1e8);

    //     std::map<int, std::string> m1;
    //     ft::map<int, std::string> ft_m1;
    //     std::map<int, std::string>::iterator it;
    //     ft::map<int, std::string>::iterator ft_it;

    //     for (size_t i = 0; i < 1e6; i++)
    //     {
    //         m1.insert(std::make_pair(i, "string2"));
    //         ft_m1.insert(ft::make_pair(i, "string2"));
    //     }

    //     for (size_t i = 0; i < 1e6; i++)
    //     {
    //         int n = distr(generator);
    //         it = m1.find(n);
    //         ft_it = ft_m1.find(n);
    //         if (it == m1.end() && ft_it == ft_m1.end())
    //             continue;
    //         if (it == m1.end() && ft_it != ft_m1.end())
    //         {
    //             cond = false;
    //             break;
    //         }
    //         else
    //         {
    //             vec.push_back(it->first);
    //             ft_vec.push_back(ft_it->first);
    //         }
    //     }

    //     std::map<char, int> m;
    //     ft::map<char, int> ft_m;
    //     std::map<char, int>::iterator it2;
    //     ft::map<char, int>::iterator ft_it2;

    //     m['a'] = 50;
    //     m['b'] = 100;
    //     m['c'] = 150;
    //     m['d'] = 200;

    //     ft_m['a'] = 50;
    //     ft_m['b'] = 100;
    //     ft_m['c'] = 150;
    //     ft_m['d'] = 200;

    //     it2 = m.find('b');
    //     ft_it2 = ft_m.find('b');

    //     cond = cond && it2->first == ft_it2->first && it2->second == ft_it2->second;

    //     if (it2 != m.end())
    //         m.erase(it2);
    //     if (ft_it2 != ft_m.end())
    //         ft_m.erase(ft_it2);

    //     cond = cond && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     EQUAL(cond && vec == ft_vec);
    // }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " count method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     bool cond;
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         bool res, ft_res;

    //         std::map<int, std::string> m;
    //         ft::map<int, std::string> ft_m;
    //         for (size_t i = 0; i < 1e6; ++i)
    //         {
    //             m.insert(std::make_pair(i, "value"));
    //             ft_m.insert(ft::make_pair(i, "value"));
    //         }
    //         start = get_time();
    //         res = m.count(1e6 - 10);
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

    //         ualarm(diff * 1e3, 0);
    //         ft_res = ft_m.count(1e6 - 10);
    //         ualarm(0, 0);
    //         cond = ft_res == res;
    //     }
    //     std::map<int, std::string> m;
    //     ft::map<int, std::string> ft_m;
    //     int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
    //     for (size_t i = 0; i < 9; ++i)
    //     {
    //         m.insert(std::make_pair(arr[i], "value"));
    //         ft_m.insert(ft::make_pair(arr[i], "value"));
    //     }
    //     cond = (cond && (m.count(65) == ft_m.count(65) && m.count(300) == ft_m.count(300)));
    //     EQUAL(cond);
    // }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " lower_bound method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.lower_bound(1e5)->first;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft_res = ft_m.lower_bound(1e5)->first;
            ualarm(0, 0);
            cond = ft_res == res;
        }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        cond = (cond && (m.lower_bound(15)->first == ft_m.lower_bound(15)->first));
        cond = (cond && (m.lower_bound(65)->first == ft_m.lower_bound(65)->first));
        cond = (cond && (m.lower_bound(63)->first == ft_m.lower_bound(63)->first));
        cond = (cond && (m.lower_bound(120)->first == ft_m.lower_bound(120)->first));
        cond = (cond && (m.lower_bound(70)->first == ft_m.lower_bound(70)->first));

        cond = (cond && (c_m.lower_bound(15)->first == c_ft_m.lower_bound(15)->first));
        cond = (cond && (c_m.lower_bound(65)->first == c_ft_m.lower_bound(65)->first));
        cond = (cond && (c_m.lower_bound(63)->first == c_ft_m.lower_bound(63)->first));
        cond = (cond && (c_m.lower_bound(120)->first == c_ft_m.lower_bound(120)->first));
        cond = (cond && (c_m.lower_bound(70)->first == c_ft_m.lower_bound(70)->first));
        EQUAL(cond);
    }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " upper_bound method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     bool cond;
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         int res, ft_res;

    //         std::map<int, std::string> m;
    //         ft::map<int, std::string> ft_m;
    //         for (size_t i = 0; i < 1e6; ++i)
    //         {
    //             m.insert(std::make_pair(i, "value"));
    //             ft_m.insert(ft::make_pair(i, "value"));
    //         }
    //         start = get_time();
    //         res = m.upper_bound(1e5)->first;
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

    //         ualarm(diff * 1e3, 0);
    //         ft_res = ft_m.upper_bound(1e5)->first;
    //         ualarm(0, 0);
    //         cond = ft_res == res;
    //     }
    //     std::map<int, std::string> m;
    //     ft::map<int, std::string> ft_m;
    //     int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
    //     for (size_t i = 0; i < 9; ++i)
    //     {
    //         m.insert(std::make_pair(arr[i], "value"));
    //         ft_m.insert(ft::make_pair(arr[i], "value"));
    //     }
    //     std::map<int, std::string> const c_m(m.begin(), m.end());
    //     ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
    //     cond = (cond && (m.upper_bound(15)->first == ft_m.upper_bound(15)->first));
    //     cond = (cond && (m.upper_bound(65)->first == ft_m.upper_bound(65)->first));
    //     cond = (cond && (m.upper_bound(63)->first == ft_m.upper_bound(63)->first));
    //     cond = (cond && (m.upper_bound(120)->first == ft_m.upper_bound(120)->first));
    //     cond = (cond && (m.upper_bound(70)->first == ft_m.upper_bound(70)->first));
    //     cond = (cond && (m.upper_bound(150)->first == ft_m.upper_bound(150)->first));

    //     cond = (cond && (c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first));
    //     cond = (cond && (c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first));
    //     cond = (cond && (c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first));
    //     cond = (cond && (c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first));
    //     cond = (cond && (c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first));
    //     cond = (cond && (c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first));
    //     EQUAL(cond);
    // }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " equal_range method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     bool cond;
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         iter_def res;
    //         ft_iter_def ft_res;

    //         std::map<int, std::string> m;
    //         ft::map<int, std::string> ft_m;
    //         for (size_t i = 0; i < 1e6; ++i)
    //         {
    //             m.insert(std::make_pair(i, "value"));
    //             ft_m.insert(ft::make_pair(i, "value"));
    //         }
    //         start = get_time();
    //         res = m.equal_range(1e5);
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

    //         ualarm(diff * 1e3, 0);
    //         ft_res = ft_m.equal_range(1e5);
    //         ualarm(0, 0);
    //         cond = (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first);
    //     }
    //     iter_def res;
    //     ft_iter_def ft_res;
    //     const_iter_def c_res;
    //     ft_const_iter_def ft_c_res;
    //     std::map<int, std::string> m;
    //     ft::map<int, std::string> ft_m;
    //     int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
    //     for (size_t i = 0; i < 9; ++i)
    //     {
    //         m.insert(std::make_pair(arr[i], "value"));
    //         ft_m.insert(ft::make_pair(arr[i], "value"));
    //     }
    //     std::map<int, std::string> const c_m(m.begin(), m.end());
    //     ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());

    //     res = m.equal_range(15);
    //     ft_res = ft_m.equal_range(15);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(65);
    //     ft_res = ft_m.equal_range(65);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(63);
    //     ft_res = ft_m.equal_range(63);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(120);
    //     ft_res = ft_m.equal_range(120);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(70);
    //     ft_res = ft_m.equal_range(70);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(150);
    //     ft_res = ft_m.equal_range(150);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));

    //     c_res = c_m.equal_range(15);
    //     ft_c_res = c_ft_m.equal_range(15);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(65);
    //     ft_c_res = c_ft_m.equal_range(65);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(63);
    //     ft_c_res = c_ft_m.equal_range(63);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(120);
    //     ft_c_res = c_ft_m.equal_range(120);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(70);
    //     ft_c_res = c_ft_m.equal_range(70);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(150);
    //     ft_c_res = c_ft_m.equal_range(150);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     EQUAL(cond);
    // }
}


void testIterators()
{
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*-------------------------------------- time limit test -----------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         /*------------------ std::maps ---------------------*/
    //         std::map<int, std::string> m1;
    //         ft::map<int, std::string> ft_m1;
    //         for (size_t i = 0; i < 1e6; i++)
    //         {
    //             m1.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, "string2"));
    //         }

    //         start = get_time();
    //         m1.begin();
    //         m1.end();
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::Maps ---------------------*/
    //         ualarm(diff * 1e3, 0);
    //         ft_m1.begin();
    //         ft_m1.end();
    //         ualarm(0, 0);
    //         /*----------------------------------------------------*/
    //     }
    //     /*------------------------------------------------------------------------------------------*/
    //     /*------------------ std::maps ---------------------*/
    //     std::map<int, std::string> m1;
    //     ft::map<int, std::string> ft_m1;

    //     for (size_t i = 0; i < 10; i++)
    //     {
    //         m1.insert(std::make_pair(i, "string2"));
    //         ft_m1.insert(ft::make_pair(i, "string2"));
    //     }

    //     std::map<int, std::string> const m2(m1.begin(), m1.end());
    //     ft::map<int, std::string> const ft_m2(ft_m1.begin(), ft_m1.end());

    //     /*-----------------------------------------------------*/
    //     /*------------------ ft::Maps ---------------------*/
    //     /*----------------------------------------------------*/
    //     /*------------------ strings to store the results ----*/
    //     std::string res, ft_res, c_res, c_ft_res;
    //     /*----------------------------------------------------*/
    //     for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
    //         res += it->second;
    //     for (std::map<int, std::string>::const_iterator rit = m2.begin(); rit != m2.end(); ++rit) // fill c_res from const m1
    //         c_res += rit->second;

    //     for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
    //         ft_res += it->second;
    //     for (ft::map<int, std::string>::const_iterator rit = ft_m2.begin(); rit != ft_m2.end(); ++rit) // fill c_ft_res from const ft_m1
    //         c_ft_res += rit->second;
        
    //     int arr[] = {12, 82, 37, 64, 15};
    //     ft::map<int, int> end_test;
    //     for(size_t i = 0; i < 5; ++i)
    //         end_test.insert(ft::make_pair(arr[i], i));
    //     ft::map<int, int>::iterator eit = end_test.end();
    //     eit--;
    //     EQUAL(res == ft_res && c_res == c_ft_res && eit->first == 82);
    // }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
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
            m1.rbegin();
            m1.rend();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.rbegin();
            ft_m1.rend();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1;
        ft::map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        ft::map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        /*-----------------------------------------------------*/
        /*------------------ ft::Maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
            res += it->second;
        for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
            c_res += rit->second;

        for (ft::map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;
        for (ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
            c_ft_res += rit->second;
        int arr[] = {12, 82, 37, 64, 15};
        ft::map<int, int> end_test;
        for(size_t i = 0; i < 5; ++i)
            end_test.insert(ft::make_pair(arr[i], i));
        ft::map<int, int>::reverse_iterator rit = end_test.rend();
        rit--;
        EQUAL(res == ft_res && c_res == c_ft_res && rit->first == 12);
    }
}
int main(){

    // reverse_iterator_tests();
    // testOperations();
    // testIterators();
    
    return 0;
}