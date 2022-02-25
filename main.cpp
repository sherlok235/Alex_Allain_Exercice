#include <ctype.h>
#include <algorithm>
#include "wordconvertor.h"

bool isNotValid(std::string);

int main() {
    std::cout<< "for exit input a non number data \n";

    while(1){
        std::string nice;
        std::cout<<"input a number: ";
        std::cin>>nice;

        if (isNotValid(nice))
            return 0;

        neroapp::parser a{nice};
        neroapp::WordConvertor Convert;
        std::cout<<Convert.ConvertAll(a.parse())<<std::endl<<std::endl;
    }

    return 0;
}

bool isNotValid(std::string Validate_this){
    return !std::all_of(Validate_this.begin(),Validate_this.end(),[](char const &c){
        return isdigit(c);
    });
}


// 1  unu     --------------------- +
// 10 zece    --------------------- +
// 100 o suta       --------------- +
// 1000 o mie       --------------- +
// 10 000 zece mii  --------------- +
// 100 000 o suta de mii    ------- +
// 1 000 000 o mie de mii
// 10 000 000 zece mi de mii
// 100 000 000 o suta mii de mii
// 1 000 000 000 un miliard
