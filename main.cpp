#include <bits/stdc++.h>//for reverse
#include <iostream>
#include <list>
#include <map>

class parser{
std::string mystringData;
public:
parser(){}
parser(std::string s):mystringData(s){}

std::list<int> parse(){
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
};

class WordConvertor{
    parser pars;
    std::map<int , std::string> MyDigitVariant {
         {0 , " zero" } , {1, " unu"  } , {2 , " doi"}
        ,{3 , " trei" } , {4 , " patru"} , {5 , " cinci"}
        ,{6 , " șase" } , {7 , " șapte"} , {8 , " opt"}
        ,{9 , " noua" } , {-1 , " O " }   , {10, " zece"}
        ,{11, " unsprezece "} , {-2 , " doua"}
        , {16,"șaisptezece"} ,{14,"paisprezece"}
        };
    std::map <int ,std::string >cantity{
        {3,"sute"},{4,"mii"},{7,"milioane"} , {-7,"milion"}
    };
 protected:
    void Convert_to_NForm(int &a){
        if (a==1||a==2)
            a*=(-1);
    }
    std::string ConvertDigi(int num){
        return MyDigitVariant[num] ;
    }

std::string ConvertNumberWithTowDigi(std::list<int> & num){
    std::string ConcatDigi;
    for(auto i : num)
        ConcatDigi+=std::to_string(i);

    if (std::stoi(ConcatDigi)==10||std::stoi(ConcatDigi)==11)
        return ConvertDigi(std::stoi(ConcatDigi));
    if(std::stoi(ConcatDigi) > 11 && std::stoi(ConcatDigi) < 20){
        std::string tmp { ConcatDigi[1] };
        return ConvertDigi(std::stoi(tmp)) +"sprezece ";
    }

        Convert_to_NForm(num.front());

     std::string myresult;
     bool is_zeci=false;
     if (num.front() != 0){
         is_zeci=true;
         myresult = ConvertDigi(num.front()) +"zeci ";
     }
    num.erase(num.begin());
    if(num.front()==0){
        return myresult;
    }
     //Convert_to_NForm(num.front());
//    num.front() == 1 ? num.front()*=(-1) :num.front() ;
    if (is_zeci)
    return (myresult+"si"+ConvertDigi(num.front()));

    return (myresult+ConvertDigi(num.front()));
}

std::string ConvertNumberWithThreeDigi(std::list<int> &num){

    Convert_to_NForm(num.front());
    std::string temp = ConvertDigi(num.front());
    int n =num.front();
    num.pop_front();
    if (n == -1){
        return (temp+" sută " + ConvertNumberWithTowDigi(num));
    }
    return (temp +" sute "+ ConvertNumberWithTowDigi(num));

}
 public:

WordConvertor (){}

std::string ConvertAll(std::list<int> mynumber)
    {
        switch (mynumber.size()) {
        case 1:
            return ConvertDigi(mynumber.front());
            break;
        case 2:
            return ConvertNumberWithTowDigi(mynumber);
            break;
        case 3:
            return ConvertNumberWithThreeDigi(mynumber);
        }
        return "Eror";
    }
};

int main() {

    while(1){
        std::string nice;
        std::cin>>nice;

        parser a{nice};
        WordConvertor Convert;
        std::cout<<Convert.ConvertAll(a.parse())<<std::endl;
    }


    return 0;
}
// 1  unu +
// 10 zece +
// 100 o suta
// 1000 o mie
// 10 000 zece mii
// 100 000 o suta de mii
// 1 000 000 o mie de mii
// 10 000 000 zece mi de mii
// 100 000 000 o suta mii de mii
// 1 000 000 000 un miliard
