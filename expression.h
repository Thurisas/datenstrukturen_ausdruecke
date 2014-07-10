#ifndef EXPRESSION_H_INCLUDED
#include <iostream>
#define EXPRESSION_H_INCLUDED

class expr
{
private:
    expr* leftExpr;
    expr* rightExpr;

    char op;

    void setOperation(char op);

public:
    expr(char* str);
    ~expr();
    bool static isNumeric(char*);
    bool static isLiteral(char*);
    int static stringToInt(char*);
    int getRootOpPos(char*);
};

expr::~expr()
{
    if(this->leftExpr)delete this->leftExpr;
    if(this->rightExpr)delete this->rightExpr;
}

bool expr::isLiteral(char *str)
{
    int i=0;
    while(str[i])
    {
    if(str[i]=='+'||str[i]=='/'||str[i]=='*') return false;
    i++;
    }
    return true;
}

bool expr::isNumeric(char *str)
{
    while (*str){
        if (!isdigit(*str)) return false;
        *str++;
    }
    return true;
}

int expr::stringToInt(char *str)
{
    int number=0,i=0;
    while(str[i])
    {
    number += str[i]-48;
    number *=10;
    i++;
    }
    number /=10;
    return number;
}

class number : public expr
{
private:
    int value;

public:
    number (char* str) : expr(str)
    {
    this->value=expr::stringToInt(str);
    }
};
class letters : public expr
{
private:
    char letter;
public:
    letters (char* str) : expr(str)
    {
    this->letter=*str;
    }
};

expr::expr(char* str)
{
    if(isLiteral(str)) std::cout << str;
    else
    {
        int pos = this->getRootOpPos(str);
        this->setOperation(str[pos]);

        char* left = new char[pos];
        for (int i = 0; i<pos;i++)
        {
            left[i]=str[i];
        }
        if(isNumeric(left)) this->leftExpr = new number(left);
        else if(isLiteral(left)&&!(isNumeric(left))) this->leftExpr = new letters(left);
        else
        {
            this->leftExpr =  new expr(left);
        }

        int strSize = sizeof(str)/sizeof(str[0]);
        char* right = new char[strSize-pos];
        for (int i = strSize; i<strSize;i++)
        {
            right[i-strSize]=str[i];
        }
        if(isNumeric(right)) this->rightExpr = new number(right);
        else if(isLiteral(right)&&!(isNumeric(right))) this->rightExpr = new letters(right);
        else
        {
            this->rightExpr =  new expr(right);
        }

        delete[] left;
        delete[] right;
    }
}

int expr::getRootOpPos(char *str){
    int pos=0;
    while (*str)
    {
        if(*str == '-' || *str == '+'){
            return pos;
        }
        *str++; pos++;
    }

}

void expr::setOperation(char op)
{
    if (op == '+' || op == '-' || op == '*') this->op = op;
}

#endif // EXPRESSION_H_INCLUDED
