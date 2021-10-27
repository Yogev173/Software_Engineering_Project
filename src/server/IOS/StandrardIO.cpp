#include "StandrardIO.h"
#include <iostream>
std::string StandardIO::receive() {
    int sizeOfMaxInput = 400;
    char input[sizeOfMaxInput];
    std::cout << "pls enter input" << std::endl;
    std::cin >> input;
    return input;
}

void StandardIO::send(std::string data) {
    std::cout << data << std::endl;
}

void StandardIO::close() {
    
}