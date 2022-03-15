#include "parser.h"
namespace neroapp {

parser::parser(){}

parser::parser(std::string s):mystringData(s){}

std::list<int> parser::parse(){
    std::list<int> myparsnum;
    int startNum = std::stoi(mystringData);

    if (startNum == 0){
        myparsnum.push_front(0);
        return myparsnum;
    }

    for(int i = 0 ; startNum !=0;i++){
        myparsnum.push_front(startNum%10);
        startNum/=10;
    }

   return myparsnum;
}
}
