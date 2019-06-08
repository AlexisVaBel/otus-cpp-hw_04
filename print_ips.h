#ifndef PRINT_IPS_H
#define PRINT_IPS_H
#include <type_traits>
#include "string"
#include "vector"
#include "list"
/******************************************************************************
     * File: print_ips
     * Description: Template functions for printing ips
     * Created: 2019
     * Copyright: (C) ------
     * @Author: lebllex akka Abel
     * Email: alexisvabel@gmail.com
******************************************************************************/


/**
 * @brief struct for detecting vector or list
 * as std::vector<T, allocator> - so used <T, ... Args>
 *
 *
 * @param int, std::string, std::vector<T>, std::list<T>
 *
 * @return void, have side effects like std::cout
 */


template <typename T>
struct  having_tail :  std::false_type  { } ;

template <typename T ,  typename ... Args>
struct  having_tail <std::vector<T , Args ...>>  :  std::true_type  { } ;

template <typename T ,  typename ... Args>
struct  having_tail <std::list<T , Args ...>>    :  std::true_type  {} ;

/**
 * @brief basic template for non vector or list
 * and not for integral
 */
template <typename T>
typename std::enable_if_t <!having_tail<T>::value> print_ip(T t){
    std::cerr << "nothing implemented here" << std::endl;
}

/**
 * @brief basic template for integral type - char, short, int, long...
 */
template <typename T>
void print_ip(std::enable_if_t <std::is_integral<T>::value,T> t){
    size_t size = sizeof (T);
    for(size_t i = size; i--;){
        std::cout << ((t >> (i<<3)) & 0xff);
        if(i) std::cout << ".";
    }
    std::cout << std::endl;
}

/**
 * @brief basic template for strings
 */
template<>
void print_ip<std::string>(std::string str){
    std::cout <<str <<std::endl;
}

/**
 * @brief basic template for vector or lists
 */
template <typename U>
typename std::enable_if_t <having_tail<U>::value> print_ip(U t){
    for(auto it = t.begin(); it != t.end(); ++it){
        std::cout << *it;
        if(it != std::prev(t.end())) std::cout << ".";

    }
    std::cout << std::endl;
}
/**
 * @brief tuple not used (
 */



#endif // PRINT_IPS_H
