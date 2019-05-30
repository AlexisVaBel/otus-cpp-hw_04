#include "iostream"
#include <type_traits>
#include "string"
#include "vector"
#include "list"

/******************************************************************************
     * File: print_ip
     * Description: Just printing ip address
     * Created: 2019
     * Copyright: (C) ------
     * Author: lebllex akka Abel
     * Email: alexisvabel@gmail.com
******************************************************************************/


static const char  C_MINUS_1                = -1;
static const short SH_ZERO                  = 0;
static const int   I_SOME_VALUE             = 2130706433;
static const long  L_SOME_VALUE             = 8875824491850138409;
static const std::string STR_SOME_VALUE     = "8.8.8.8";



template <typename T>
struct  having_tail :  std::false_type  { } ;

template <typename T ,  typename ... Args>
struct  having_tail <std::vector<T , Args ...>>  :  std::true_type  { } ;

template <typename T ,  typename ... Args>
struct  having_tail <std::list<T , Args ...>>    :  std::true_type  {} ;

template <typename T>
typename std::enable_if_t <!having_tail<T>::value> print_ip(T t){
    std::cerr << "nothing implemented here" << std::endl;
}
//for ints chars and so on
// char 0xFF -
template <typename T>
void print_ip(std::enable_if_t <std::is_integral<T>::value,T> t){
    size_t size = sizeof (T);
    for(size_t i = size; i--;){
        std::cout << ((t >> (i<<3)) & 0xff);
        if(i) std::cout << ".";
    }
    std::cout << std::endl;
}

// for strings
template<>
void print_ip<std::string>(std::string str){
    std::cout <<str <<std::endl;
}

//for vectors and lists
template <typename U>
typename std::enable_if_t <having_tail<U>::value> print_ip(U t){
    for(auto it = t.begin(); it != t.end(); ++it){
        std::cout << *it;
        if(it != std::prev(t.end())) std::cout << ".";

    }
    std::cout << std::endl;
}
// tuple .. not enough time

int main(int argc, char ** argval)
{
    std::vector<int> vct;
    std::list<std::string> lst;
    lst.push_back(std::string("127"));
    lst.push_back(std::string("0"));
    lst.push_back(std::string("0"));
    lst.push_back(std::string("2"));

    vct.push_back(192);
    vct.push_back(168);
    vct.push_back(1);
    vct.push_back(1);


    print_ip<char>  (C_MINUS_1);
    print_ip<short> (SH_ZERO);
    print_ip<int>   (I_SOME_VALUE);
    print_ip<long>  (L_SOME_VALUE);

    print_ip<std::string>(STR_SOME_VALUE);
    print_ip<std::vector<int>>(vct);
    print_ip<std::list<std::string>>(lst);


	return 0;
}
