#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
namespace neroapp {

class parser{
    std::string mystringData;
public:
    parser();
    parser(std::string s);
    std::list<int> operator()(void);
    std::list<int> parse();
};

}
#endif // PARSER_H
