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

    bool static isNumeric(char*);
    int getRootOpPos(char*);
};

bool expr::isNumeric(char *str)
{
    while (*str){
        if (!isdigit(*str)) return false;
        *str++;
    }
    return true;
}

class lit: public expr
{
private:
    int value;

public:
    lit (char* str) : expr(str){this->value=0;}
};

class alphanumeric : expr
{
private:
    char alphanumeric;
};

expr::expr(char* str)
{
        int pos = this->getRootOpPos(str);
        this->setOperation(str[pos]);
        char* left = new char[pos];
        for (int i = 0; i<pos;i++) {
            left[i]=str[i];
        }

        int strSize = sizeof(str)/sizeof(str[0]);

        char* right = new char[strSize-pos];
        for (int i = strSize; i<strSize;i++) {
            right[i]=str[i];
        }

        this->leftExpr = new expr(left);
        this->rightExpr = new expr(right);
}

int expr::getRootOpPos(char *str){
    int pos=0;
    while (*str) {
        if(*str == '-' || *str == '+'){
            return pos;
        }
        *str++; pos++;
    }
}

void expr::setOperation(char op){
    if (op == '+' || op == '-' || op == '*') this->op = op;
}

#endif // EXPRESSION_H_INCLUDED
