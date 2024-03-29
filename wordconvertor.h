#ifndef WORDCONVERTOR_H
#define WORDCONVERTOR_H

#include "parser.h"
#include <cmath>
#include <map>

namespace neroapp {

class WordConvertor{
    std::map<int , std::string> MyDigitVariant {
         {0 , " zero" } , {1, " unu"  } , {2 , " doi"}
        ,{3 , " trei" } , {4 , " patru "} , {5 , " cinci"}
        ,{6 , " șase" } , {7 , " șapte"} , {8 , " opt"}
        ,{9 , " noua" } , {-1 , " O " }   , {10, " zece"}
        ,{11, " unsprezece "} , {-2 , " doua"}
        , {16,"șaisptezece"} ,{14,"paisprezece"}
        };
 protected:
    void Convert_to_NForm(int &a);

    std::string ConvertDigi(int num);
    std::string ConvertNumberWithTowDigi(std::list<int> &num);
    std::string ConvertNumberWithThreeDigi(std::list<int> &num);
    std::string ConvertNumberWithFourDigi(std::list<int> &num);
    std::string ConvertNumberWithFiveDigi(std::list<int> &num);
    std::string ConvertNumberWithSixDigi(std::list<int> &num);
    std::string ConvertNumberWithSevenDigi(std::list<int> &num);
    std::string ConvertNumberWithEightDigi(std::list<int> &num);
 public:

    WordConvertor ();
    std::string ConvertAll(std::list<int>);
    std::string operator()(std::list<int>);
};
}

#endif // WORDCONVERTOR_H
