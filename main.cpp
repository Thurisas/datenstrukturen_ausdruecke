#include "expression.h"
#include <iostream>

using namespace std;

/*_Bool string_is_number(char const *str) {
  while(*str) {
    if(!isdigit(*str)) {
      return 0;
    }
    ++str;
  }
  return 1;
}*/

int main(int argc, char * argv[])
{
    char* rootExprString = argv[1];
    if (expr::isLiteral(rootExprString)) cout << rootExprString <<endl;
    else
    {
        cout << "false"<<endl;
        expr* expression = new expr(rootExprString);
    }

   // expr::stringToInt(rootExprString);
   // expr* rootExpr = new
    //    expr* myExpr = new expr(rootExpr);

    //expr* test= new lit(rootExpr);


}

