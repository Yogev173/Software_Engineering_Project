#include "../../src/server/IOS/CsvFileIO.h"

int main(){
    CsvFileIO* io = new CsvFileIO("data/Iris_result.csv");
    io->send("TEST\n");
    delete io;
    return 0;
}