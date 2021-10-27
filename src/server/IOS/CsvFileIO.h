#ifndef CSV_FILE_IO
#define CSV_FILE_IO

#include "DefaultIO.h"
#include <fstream>

class CsvFileIO : public DefaultIO{
    private:
    std::string m_path;
    std::ofstream m_fout;
    std::ifstream m_fileRead;

    public:

    void setPath(std::string path);

    CsvFileIO(std::string path);

    virtual void send(std::string str) override;

    virtual std::string receive() override;

    void close() override;

    ~CsvFileIO();
};

#endif