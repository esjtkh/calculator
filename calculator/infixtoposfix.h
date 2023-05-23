#ifndef INFIXTOPOSFIX_H
#define INFIXTOPOSFIX_H
#include<string>
#include<stack>
#include<QString>
#include<QStack>
#include<QChar>
#include <QtMath>
using namespace std;
class infixTOposfix
{
public:
    int precedant(string ch);
    string calculate_Postfix(stack<string>final);
    stack<string> infixToPostfix(QString s,infixTOposfix &itp);
    QString infixToPostfixx(QString s);
    stack<string> calculate_digits(string tmp,stack<string> res);
    stack<string>oper;
    bool valid(string);
    infixTOposfix();
};

#endif // INFIXTOPOSFIX_H
