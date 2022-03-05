#include "wordconvertor.h"
namespace neroapp {

WordConvertor::WordConvertor(){}

void WordConvertor::Convert_to_NForm(int &a){
    if (a==1||a==2)
        a*=(-1);
}

std::string WordConvertor::ConvertDigi(int num){
    return MyDigitVariant[num] ;
}

std::string WordConvertor::ConvertNumberWithTowDigi(std::list<int> & num){
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
    if (is_zeci)
    return (myresult+"si"+ConvertDigi(num.front()));

    return (myresult+ConvertDigi(num.front()));
}

std::string WordConvertor::ConvertNumberWithThreeDigi(std::list<int> &num){

    Convert_to_NForm(num.front());
    std::string temp = ConvertDigi(num.front());
    int n =num.front();
    num.pop_front();
    if (n==0)
        return ConvertNumberWithTowDigi(num);
    if (n == -1){
        return (temp+" sută " + ConvertNumberWithTowDigi(num));
    }
    return (temp +" sute "+ ConvertNumberWithTowDigi(num));

}

std::string WordConvertor::ConvertNumberWithFourDigi(std::list<int> &num) {

    if (num.front()==0){
        num.pop_front();
        return ConvertNumberWithThreeDigi(num);
    }
    std::string ss ,connection_word{" mii"};
    if (num.front()==1)
        connection_word=" mie";
    Convert_to_NForm(num.front());
    ss=ConvertDigi(num.front());
    num.pop_front();

    return ss+connection_word+ConvertNumberWithThreeDigi(num);

}

std::string WordConvertor::ConvertNumberWithFiveDigi(std::list<int> &num) {

    std::string result;

    if(num.front()==0){
        num.pop_front();
        return ConvertNumberWithFourDigi(num);
    }


        std::list<int> temp{};
        temp.push_back(num.front());
        num.pop_front();
        temp.push_back(num.front());
        num.pop_front();
        int save_it = temp.front();//save this value because in next line  this value will be deleted
        result = ConvertNumberWithTowDigi(temp);

        if( 1 < save_it){
            return result+" de mii"+ConvertNumberWithThreeDigi(num);
        }


    return result+" mii"+ConvertNumberWithThreeDigi(num);
}

std::string WordConvertor::ConvertNumberWithSixDigi(std::list<int> &num){

    if (num.front()==0){
        num.pop_front();
        return ConvertNumberWithFiveDigi(num);
    }
    std::string rez = ConvertNumberWithThreeDigi(num);
    num.pop_front();
    return  (rez + " de mii " + ConvertNumberWithThreeDigi(num));


}

std::string  WordConvertor::ConvertNumberWithSevenDigi(std::list<int> &num){

    std::string temp{};
    if (num.front()==1){
        temp = "un milion ";
        num.pop_front();
        return temp + ConvertNumberWithSixDigi(num);
    }
    Convert_to_NForm(num.front());
    temp=ConvertDigi(num.front());
   //+ num.pop_front();
    return temp + " milioane " + ConvertNumberWithSixDigi(num);
}

std::string WordConvertor::ConvertAll(std::list<int> mynumber) {

       std::string ConcatDigi;
       for(auto i : mynumber)
            ConcatDigi+=std::to_string(i);
       size_t size=std::log10(std::stoi(ConcatDigi))+1; // how many digi have this number
       if (std::stoi(ConcatDigi)==0)
           size=1;

        switch (size) {
        case 1:
            return ConvertDigi(mynumber.front());
            break;
        case 2:
            return ConvertNumberWithTowDigi(mynumber);
            break;
        case 3:
            return ConvertNumberWithThreeDigi(mynumber);
            break;
        case 4:
            return ConvertNumberWithFourDigi(mynumber);
            break;
        case 5 :
            return ConvertNumberWithFiveDigi(mynumber);
            break;
        case 6:
            return ConvertNumberWithSixDigi(mynumber);
            break;
        case 7:
            return ConvertNumberWithSevenDigi(mynumber);
        }
        return "Eror";
    }
}
