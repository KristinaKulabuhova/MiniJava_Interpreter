#ifndef PARSEREXAMPLE_ELEMENTS_H
#define PARSEREXAMPLE_ELEMENTS_H

#include "Expressions/AtExpr.h"
#include "Expressions/FieldExpr.h"
#include "Expressions/NewArrExpr.h"
#include "Expressions/NewCustomVarExpr.h"

#include "Expressions/AndExpr.h"
#include "Expressions/NotExpr.h"
#include "Expressions/OrExpr.h"

#include "Expressions/AddExpr.h"
#include "Expressions/ModExpr.h"
#include "Expressions/MulExpr.h"
#include "Expressions/DivExpr.h"
#include "Expressions/SubtractExpr.h"

#include "Expressions/EqExpr.h"
#include "Expressions/GEqExpr.h"
#include "Expressions/GreaterExpr.h"
#include "Expressions/NEqExpr.h"
#include "Expressions/LEqExpr.h"
#include "Expressions/LessExpr.h"

#include "Expressions/IdentExpr.h"
#include "Expressions/LengthExpr.h"
#include "Expressions/VarExpr.h"
#include "Expressions/NumExpr.h"
#include "Expressions/ThisExpr.h"

#include "Expressions/FalseExpr.h"
#include "Expressions/TrueExpr.h"

#include "MainElements/Class.h"
#include "MainElements/MainClass.h"
#include "MainElements/MethodInvocation.h"

#include "ExecBlocks/MethodDeclaration.h"

#include "ExecBlocks/For.h"
#include "ExecBlocks/If.h"
#include "ExecBlocks/While.h"

#include "ExecBlocks/Lvalue.h"
#include "ExecBlocks/MethodDeclaration.h"
#include "ExecBlocks/Println.h"
#include "ExecBlocks/Return.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "ExecBlocks/AssertExpr.h"
#include "ExecBlocks/Assignment.h"
#include "ExecBlocks/Block.h"
#include "ExecBlocks/ExecCode.h"

#include "Program.h"

#include "SubsidiaryClasses/Formals.h"

#endif //PARSEREXAMPLE_ELEMENTS_H
