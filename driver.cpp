#include "driver.hh"

Driver::Driver() : trace_parsing(false),
                   trace_scanning(false),
                   scanner(*this), parser(scanner, *this)
{
}

int Driver::parse(const std::string &f)
{
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();
    return res;
}

void Driver::scan_begin()
{
    scanner.set_debug(trace_scanning);
    if (file.empty() || file == "-")
    {
    }
    else
    {
        stream.open(file);
        std::cout << file << std::endl;
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end()
{
    stream.close();
}

int Driver::executeProgram() const
{
    PrintVisitor print_visitor;
    ScopeTreeVisitor scope_tree_visitor;
    GarbageCollector collector;
    //Interpreter interpreter;
    try
    {
        program->Accept(scope_tree_visitor);
        program->Accept(print_visitor);
    }
    catch (...)
    {
        return -1;
    }
    program->Accept(collector);
    return 0;
}
