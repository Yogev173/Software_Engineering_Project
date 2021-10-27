#include "CsvFileIO.h"
#include <iostream>

CsvFileIO::CsvFileIO(std::string path) {
    m_path = path;
    m_fout.open(path);
    m_fileRead.open(path);
}

void CsvFileIO::send(std::string str){
    m_fout << str << "\n";
}

void CsvFileIO::setPath(std::string path){
    m_path = path;
    m_fout.open(path);
    m_fileRead.open(path);
}

std::string CsvFileIO::receive(){
    std::string line;
    getline(m_fileRead,line);
    return line;
}

void CsvFileIO::close() {
    m_fileRead.close();
    m_fout.close();
}

CsvFileIO::~CsvFileIO(){
    m_fout.close();
    m_fileRead.close();
}