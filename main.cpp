#include "iostream"
#include "consts_ip.h"
#include "print_ips.h"
/******************************************************************************
     * File: print_ip
     * Description: Just printing ip address
     * Created: 2019
     * Copyright: (C) ------
     * @Author: lebllex akka Abel
     * Email: alexisvabel@gmail.com
******************************************************************************/
/**
 * @brief Entry point (main)
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments - not used
 * @param argv List of arguments - not used
 *
 * @return Program exit status
 */
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
