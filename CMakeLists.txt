cmake_minimum_required(VERSION 3.16)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

project(mini_java)
set(
        HEADERS
        ${mini_java_SOURCE_DIR}/driver.hh
        ${mini_java_SOURCE_DIR}/parser.hh
)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(
        MyParser
        parser.y
        ${mini_java_SOURCE_DIR}/parser.cpp
#        COMPILE_FLAGS -Wcounterexamples
        DEFINES_FILE ${mini_java_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${mini_java_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        mini_java
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
        Expressions/GEqExpr.h
        Expressions/GEqExpr.cpp
        Expressions/LEqExpr.h
        Expressions/LEqExpr.cpp
        Expressions/GreaterExpr.h
        Expressions/GreaterExpr.cpp
        Expressions/LessExpr.h
        Expressions/LessExpr.cpp
    
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
        Expressions/LengthExpr.h
        Expressions/LengthExpr.cpp
        ExecBlocks/Assignment.h
        ExecBlocks/Assignment.cpp
        ExecBlocks/If.h
        ExecBlocks/If.cpp
        BaseElements/BaseExecBlock.h
        ExecBlocks/ExecCode.h
        ExecBlocks/ExecCode.cpp
        ExecBlocks/While.h
        ExecBlocks/While.cpp
   
   
        Visitors/Interpreter.h
        Visitors/Interpreter.cpp
        ExecBlocks/MethodDeclaration.h
        ExecBlocks/MethodDeclaration.cpp
        ExecBlocks/VariableDeclaration.h
        ExecBlocks/VariableDeclaration.cpp
        MainElements/MainClass.h
        MainElements/MainClass.cpp
        MainElements/Class.h
        MainElements/Class.cpp
        SubsidiaryClasses/DeclarationList.h
        SubsidiaryClasses/DeclarationList.cpp
        Expressions/TrueExpr.cpp
        Expressions/TrueExpr.h
        Expressions/FalseExpr.cpp
        Expressions/FalseExpr.h
        SubsidiaryClasses/ClassDeclarationList.cpp
        SubsidiaryClasses/ClassDeclarationList.h
        SubsidiaryClasses/Formals.cpp
        SubsidiaryClasses/Formals.h
        Program.h
        Program.cpp ExecBlocks/Block.cpp

        Expressions/FieldExpr.cpp
        Expressions/FieldExpr.h
        ExecBlocks/AssertExpr.cpp
        ExecBlocks/AssertExpr.h
        ExecBlocks/Return.cpp
        ExecBlocks/Return.h
        ExecBlocks/Println.cpp
        ExecBlocks/Println.h
        MainElements/MethodInvocation.cpp
        MainElements/MethodInvocation.h
        BaseElements/BaseDeclaration.h
        SubsidiaryClasses/ExprList.cpp
        SubsidiaryClasses/ExprList.h
        Visitors/AllIncludes.h
        
        Expressions/NumExpr.cpp
        Expressions/NumExpr.h
        Expressions/AtExpr.cpp
        Expressions/VarType.cpp
        Expressions/VarType.h
        Expressions/AtExpr.h
        Expressions/NewArrExpr.cpp
        Expressions/NewArrExpr.h
        Expressions/NewCustomVarExpr.cpp
        Expressions/NewCustomVarExpr.h

        Expressions/SimpleType.cpp
        Expressions/SimpleType.h

        Visitors/PrintVisitor.cpp
        Visitors/PrintVisitor.h

        symbols/StFunction.h
        symbols/StFunction.cpp
)    
target_include_directories(mini_java PRIVATE ${mini_java_SOURCE_DIR})