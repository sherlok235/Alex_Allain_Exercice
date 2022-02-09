#include "wordconvertor.h"

int main() {

    while(1){
        std::string nice;
        std::cin>>nice;

       neroapp:: parser a{nice};
       neroapp::WordConvertor Convert;
        std::cout<<Convert.ConvertAll(a.parse())<<std::endl;
    }


    return 0;
}
// 1  unu +
// 10 zece +
// 100 o suta +
// 1000 o mie
// 10 000 zece mii
// 100 000 o suta de mii
// 1 000 000 o mie de mii
// 10 000 000 zece mi de mii
// 100 000 000 o suta mii de mii
// 1 000 000 000 un miliard
