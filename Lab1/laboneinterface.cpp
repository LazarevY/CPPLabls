#include "laboneinterface.h"
#include <string.h>
#include <iostream>
#include <string>

#include "mysnprintf.h"

LabOneInterface::LabOneInterface()
{

}


void LabOneInterface::runDemo()
{
    int value;
    char symbol;
    char str[64];

    std::cout << "Enter your integer: ";
    std::cin >> value;

    std::cout << "Enter your char: ";
    std::cin >> symbol;

    std::cout << "Enter your word: ";
    std::cin.ignore();
    std::cin.getline(str, 63);

    char formatted[256] = "";

    int limit = 256;

    int code = my_snprintf(formatted, 256, "Integer : %d, char: %c, string: %s", value, symbol, str);

    std::cout << "Custon function result: '" << formatted << "' with code " << code << std::endl;

    memset(formatted, '\0', limit);

    code = snprintf(formatted, limit, "Integer : %d, char: %c, string: %s", value, symbol, str);

    std::cout << "Std function result:    '" << formatted << "' with code " << code << std::endl;



    std::cout << "Use n limit as 12: " << std::endl;

    limit = 12;

    memset(formatted, '\0', 256);

    code = my_snprintf(formatted, limit, "Integer : %d, char: %c, string: %s", value, symbol, str);

    std::cout << "Custon function result: '" << formatted << "' with code " << code << std::endl;

    memset(formatted, '\0', 256);

    code = snprintf(formatted, limit, "Integer : %d, char: %c, string: %s", value, symbol, str);

    std::cout << "Std function result:    '" << formatted << "' with code " << code << std::endl;



}
