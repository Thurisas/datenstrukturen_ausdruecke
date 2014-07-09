#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

class expr
{
private:
    expr* leftExpr;
    expr* rightExpr;

    char op;


public:
    expr();
};

class numeric : expr
{
private:
    int numeric;
};

class alphanumeric : expr
{
private:
    char alphanumeric;
};


#endif // EXPRESSION_H_INCLUDED
