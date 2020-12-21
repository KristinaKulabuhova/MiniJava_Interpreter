#include "Program.h"

Program::Program(std::string program_name, std::vector<VarDeclList*> var_declarations, ExecCode *executable_code) :
program_name(std::move(program_name)), var_declarations(std::move(var_declarations)), executable_code(executable_code) {}

Program::~Program() {
    for (const auto& decl : var_declarations) {
        delete decl;
    }
    delete executable_code;
}
