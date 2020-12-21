cmake_minimum_required(VERSION 3.17)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

project(ParserExample)
set(
        HEADERS
        ${ParserExample_SOURCE_DIR}/driver.hh
        ${ParserExample_SOURCE_DIR}/parser.hh
)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(
        MyParser
        parser.y
        ${ParserExample_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        ParserExample
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        Visitors/ForwardDeclarations.h
        Visitors/Visitor.h
        Expressions/NotExpr.h
        Expressions/NotExpr.cpp
        Expressions/OrExpr.h
        Expressions/OrExpr.cpp
        Expressions/AndExpr.h
        Expressions/AndExpr.cpp
        Expressions/NEqExpr.h
        Expressions/NEqExpr.cpp
        Expressions/EqExpr.h
        Expressions/EqExpr.cpp
        Expressions/GeqExpr.h
        Expressions/GeqExpr.cpp
        Expressions/LeqExpr.h
        Expressions/LeqExpr.cpp
        Expressions/GreaterExpr.h
        Expressions/GreaterExpr.cpp
        Expressions/LessExpr.h
        Expressions/LessExpr.cpp
        Expressions/ConstExpr.h
        Expressions/ConstExpr.cpp
        Expressions/IdentExpr.h
        Expressions/IdentExpr.cpp
        Expressions/AddExpr.h
        Expressions/AddExpr.cpp
        Expressions/SubtractExpr.cpp
        Expressions/SubtractExpr.h
        Expressions/DivExpr.h
        Expressions/DivExpr.cpp
        Expressions/ModExpr.h
        Expressions/ModExpr.cpp
        Expressions/MulExpr.h
        Expressions/MulExpr.cpp
        MainElements/Assignment.h
        MainElements/Assignment.cpp
        MainElements/If.h
        MainElements/If.cpp
        BaseElements/BaseExecBlock.h
        MainElements/ExecCode.h
        MainElements/ExecCode.cpp
        MainElements/While.h
        MainElements/While.cpp
        MainElements/For.h
        MainElements/For.cpp
        MainElements/Read.h
        MainElements/Read.cpp
        MainElements/Write.h
        MainElements/Write.cpp
        Visitors/Interpreter.h
        Visitors/Interpreter.cpp
        VarDeclList/VarDeclList.h
        VarDeclList/VarDeclList.cpp
        Visitors/Elements.h
        Program.h
        Program.cpp
)
target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})