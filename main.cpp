#include "iostream"
#include <type_traits>
#include "string"
#include "vector"
#include "list"


// something for work
//template <typename T>
//void print_ip(T value, bool bPrintPnt = true){};

template <typename T>
std::enable_if<std::is_integral<T>::value, void> print_ip(T value, bool bPrintPnt = true)
{
    static const size_t constexpr size = sizeof(T);
    for(auto i = size; i--;)
    {
        std::cout << (value >> (i << 3) & 0xFF);
        if(i) std::cout << '.';
    }
    if(bPrintPnt) std::cout << std::endl;
}

void print_ip(std::string t, bool bPrintPnt = true){
    std::cout << t;
    if(bPrintPnt) std::cout << std::endl;
}

template <typename T>
void print_ip(std::vector<T> vct, bool bPrintPnt = true){
    for(auto it = vct.begin(); it != vct.end(); ++it){
        print_ip(*it, false);
        if(it != std::prev(vct.end())) std::cout << ".";
    }
    if(bPrintPnt) std::cout << std::endl;
}

template <typename T>
void print_ip(std::list<T> lst, bool bPrintPnt = true){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}


//


int main(int argc, char ** argval)
{
    std::string str1("lili");
    std::vector<int> vct;
    std::vector<std::string> vct2;

    vct2.push_back("200");
    vct2.push_back("100");
    vct2.push_back("199");
    vct2.push_back("105");

    vct.push_back(20);
    vct.push_back(10);

    std::list<std::string> lst(10);
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(int  (2130706433));
    print_ip(long (8875824491850138409));

    print_ip(str1);
    print_ip(vct);
    print_ip(lst);
    print_ip(vct2);
	return 0;
}
