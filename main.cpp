#include "expression.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
    char* rootExprString = argv[1];
    if (expr::isNumeric(rootExprString)) cout << rootExprString;
    else {
        expr* expression = new expr(rootExprString);
    }

   // expr* rootExpr = new
    //    expr* myExpr = new expr(rootExpr);

    //expr* test= new lit(rootExpr);


}

