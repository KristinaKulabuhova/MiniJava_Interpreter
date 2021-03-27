#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"

#include "Program.h"
//#include "Visitors/Interpreter.h"
#include "Visitors/PrintVisitor.h"

class Driver {
 public:
    Driver();
    int parse(const std::string& f);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    Program* program;

    int executeProgram() const;
 private:
    std::ifstream stream;

};
