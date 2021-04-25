#include "cliutils.h"


int CLIUtils::getIntFromConsole(const QString &msg)
{
    int val;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << msg;
        std::cin >> val;
    }

    return val;
}

int CLIUtils::getBoundedFromConsole(int min, int max, const QString &msg)
{
    int val = min;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail() || val < min || val > max) {
        std::cin.clear();
        std::cin.ignore(1024,'\n');
        std::cout << "Must me in range [" << min << ", " << max<< "]. " << msg;
        std::cin >> val;
    }

    return val;
}

QString CLIUtils::getStringFromConsole(const QString &msg)
{
    std::string str;

    std::cout << msg;
    std::cin >> str;
    while (std::cin.fail()) {
        std::cout << "Error, try again. " << msg;
        std::cin >> str;
    }

    return QString(str.c_str());
}

char CLIUtils::getCharFromConsole(const QSet<char> &right, const QString &msg)
{
    char val;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail() || !(right.empty() || right.contains(val))) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Error. " << msg;
        std::cin >> val;
    }

    return val;
}
