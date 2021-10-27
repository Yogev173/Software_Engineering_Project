#ifndef SERVER_IOS_DEFAULT_IO__H
#define SERVER_IOS_DEFAULT_IO__H

#include <string>
class DefaultIO{
    private:

    public:
    virtual std::string receive() = 0;
    virtual void send(std::string data) = 0;
    virtual void close() = 0;

};
#endif //SERVER_IOS_DEFAULT_IO__H