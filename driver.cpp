#include "driver.hh"


Driver::Driver() : trace_parsing(false),
                   trace_scanning(false),
                   scanner(*this), parser(scanner, *this)
{}

// int Driver::Evaluate()
// {
//     // SymbolTreeVisitor visitor;
//     // visitor.Visit(program);

//     // std::shared_ptr<ScopeLayerTree> tree = visitor.GetTree();
//     // Interpreter interpreter(tree);
//     UnsetTosValue();
//     Visit(program);
//     return 0;
// }

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
//    PrintVisitor print_visitor;
    Interpreter interpreter;
    try
    {
        program->main_class->Accept(interpreter);
    }
    catch (...)
    {
        return -1;
    }
    return 0;
}

// std::shared_ptr<ScopeLayer> Driver::getScopeLayerTree() const
// {
//     SymbolTreeVisitor visitor;
//     program->Accept(visitor);
//     return visitor.GetTree();
// }
