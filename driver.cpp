#include "driver.hh"



Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
    stream.close();
}

int Driver::executeProgram() {
    Interpreter interpreter(program->var_declarations);
    std::cout << "Executing program \"" << program->program_name << "\"...\n";
    try {
        program->executable_code->Accept(interpreter);
    } catch (const MultiDeclError& exception) {
        std::cout << "\n" << exception.what() << "\n";
        return -1;
    } catch (const UndefRefError& exception) {
        std::cout << "\n" << exception.what() << "\n";
        return -1;
    } catch (const WrongBinaryOperandsError& exception) {
        std::cout << "\n" << exception.what() << "\n";
        return -1;
    } catch (const ExpectedBoolError& exception) {
        std::cout << "\n" << exception.what() << "\n";
        return -1;
    } catch (const ExpectedIntError& exception) {
        std::cout << "\n" << exception.what() << "\n";
        return -1;
    }
    return 0;
}

