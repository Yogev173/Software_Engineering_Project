#ifndef SERVER_IOS_STANDART_IO__H
#define SERVER_IOS_STANDART_IO__H

#include "DefaultIO.h"

class StandardIO : public DefaultIO{
    public:
    void send(std::string data) override;
    std::string receive() override;
    void close() override;
};

#endif //SERVER_IOS_STANDART_IO__H