#pragma once

#include <map>
#include <string>
#include <fstream>

#include "scanner.h"
#include "parser.hh"
#include "Program.h"
#include "Visitors/Interpreter.h"
#include "Visitors/PrintVisitor.h"
#include "Visitors/ScopeTreeVisitor.h"
#include "Visitors/GarbageCollector.h"

class Driver
{
public:
   friend class Scanner;

public:
   Driver();
   ~Driver();

   int parse(const std::string &f);

   void scan_begin();
   void scan_end();

   int executeProgram() const;

public:
   std::ifstream stream;
   Program *program = nullptr;
   bool trace_parsing;
   bool trace_scanning;
   yy::location location;
   std::string file;
   Scanner scanner;
   yy::parser parser;
};