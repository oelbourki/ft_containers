#include <iostream>
#include <vector>
#include "vector/vectorV2.hpp"
#include "pair.hpp"

#include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>


# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
# define TIME_FAC 20 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}	


void    reverse_iterator_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reverse_iterator tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::reverse_iterator ---------*/
    std::vector<int> v(3,4);
    std::reverse_iterator<std::vector<int>::iterator> rit(v.end()), rit_1(v.end() - 1);
    /*----------------------------------*/
    /*------------ ft::reverse_iterator ---------*/
    ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        ft::reverse_iterator<std::vector<int>::iterator> ob(my_rit);
        EQUAL(&(*my_rit) == &(*ob));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " riterator to const_riterator " << "] --------------------]\t\t\033[0m";
    {
		ft::vector<int> v(4,5);
		ft::vector<int>::reverse_iterator 		my_rit2(v.end());
        ft::vector<int>::const_reverse_iterator c_it, c_ob(v.end());
        c_it = my_rit2;
        EQUAL(&(*my_rit2) == &(*c_it) && (&(*my_rit2) == &(*c_ob)));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function " << "] --------------------]\t\t\033[0m";
    EQUAL((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit == rit_1) == (my_rit == my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit != rit_1) == (my_rit != my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " > operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit > rit_1) == (my_rit > my_rit1));
    std::cout << "std::" <<(rit > rit_1) << std::endl;
    std::cout << "ft::" <<  (my_rit > my_rit1)<< std::endl;

    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " >= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit >= rit_1) == (my_rit >= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " < operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit < rit_1) == (my_rit < my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " <= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit <= rit_1) == (my_rit <= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator " << "] --------------------]\t\t\033[0m";
    EQUAL(((*my_rit == *(v.end() - 1)) && (&(*my_rit) == &(*(v.end() - 1))))
    && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator " << "] --------------------]\t\t\033[0m";
    {
        std::vector<std::string> v(3, "hello");
        std::reverse_iterator<std::vector<std::string>::iterator> rit(v.end());
        ft::reverse_iterator<std::vector<std::string>::iterator> my_rit(v.end());
        EQUAL(rit->length() == my_rit->length());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << &(*my_rit) << std::endl;
    std::cout << &(*(my_rit1 - 1)) << std::endl;
    std::cout << (*rit) << std::endl;
    std::cout << (*(rit_1 - 1)) << std::endl;
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(my_rit + 1)) == &(*my_rit1)) && (&(*(rit + 1)) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " += operator " << "] --------------------]\t\t\033[0m";
	my_rit += 1;
	rit += 1;
	EQUAL((&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -= operator " << "] --------------------]\t\t\033[0m";
	my_rit -= 1;
	rit -= 1;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " [] operator " << "] --------------------]\t\t\033[0m";
	EQUAL(((my_rit[0] = 5) == 5) && (rit[0] == 5));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++rit operator " << "] --------------------]\t\t\033[0m";
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
	EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --rit operator " << "] --------------------]\t\t\033[0m";
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator (n + rit) " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator (rit1 - rit) " << "] --------------------]\t\t\033[0m";
    EQUAL(((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit++ operator " << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::vector<int>::iterator>   tmp(rit++);
        ft::reverse_iterator<std::vector<int>::iterator>    my_tmp(my_rit++);
        EQUAL((&(*tmp) == &(*(--rit))) && (&(*my_tmp) == &(*(--my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit-- operator " << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::vector<int>::iterator>   tmp(rit--);
        ft::reverse_iterator<std::vector<int>::iterator>    my_tmp(my_rit--);
        EQUAL((&(*tmp) == &(*(++rit))) && (&(*my_tmp) == &(*(++my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " *rit++ test " << "] --------------------]\t\t\033[0m";
    {
        std::vector<char> v(10);
        std::string res, my_res;
        std::reverse_iterator<std::vector<char>::iterator> start(v.end()), end(v.begin());
        ft::reverse_iterator<std::vector<char>::iterator> my_start(v.end()), my_end(v.begin());

        for(size_t i = 0; i < 10; ++i)
            v[i] = '0' + i;
        while (start != end)
            res.push_back(*start++);
        while (my_start != my_end)
            my_res.push_back(*my_start++);
        EQUAL(res == my_res);
    }
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
}


int main(){
    reverse_iterator_tests();
    return 0;
}