#include<bits/stdc++.h>
//#include<sstream>
using namespace std;

const string operators  = "-+*/^";
const int operatorStackMax = 100;
const int evaluationStackMax = 200;

int operatorStackTop = -1;
int evaluationStackTop = -1;

string operatorStk[operatorStackMax];
string evaluationStk[evaluationStackMax];

void push(string stk[], int& stkTop, int stkMax, string item)
{
    if((stkTop + 1) == stkMax)
    {
        cout << "Stack overflow" << endl;
        exit(1);
    }
    stkTop += 1;
    stk[stkTop] = item;
}

string pop(string stk[], int &stkTop)
{
    if(stkTop == -1)
    {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    string item = stk[stkTop];
    stk[stkTop] = "";
    stkTop -= 1;
    return item;
}

bool isOperator(string keyword)
{
    if(operators.find(keyword) != string::npos)
    {
        return true;
    }
    return false;
}

int getOperatorPrecedence(string _operator)
{
    return operators.find(_operator);
}

bool isLeftParenthesis(string keyword)
{
    if(keyword[0] == '(' )
    {
        return true;
    }
    return false;
}

bool isRightParenthesis(string keyword)
{
    if(keyword[0] == ')' )
    {
        return true;
    }
    return false;
}



int main()
{
    cout << "Enter the infix input ( separated each keyword with space ): ";
    string infix_input;
    getline(cin, infix_input);
    infix_input += " )";
    push(operatorStk, operatorStackTop, operatorStackMax, "( ");

    stringstream infixStream(infix_input);
    string keyword;

    while(infixStream >> keyword)
    {
        if(isOperator(keyword))
        {
            while(getOperatorPrecedence(keyword) <= getOperatorPrecedence(operatorStk[operatorStackTop]))
            {
                string operatorToPush = pop(operatorStk, operatorStackTop);
                push(evaluationStk, evaluationStackTop, evaluationStackMax, operatorToPush);
            }
            push(operatorStk, operatorStackTop, operatorStackMax, keyword);
        }

        else if(isLeftParenthesis(keyword))
        {
            push(operatorStk, operatorStackTop, operatorStackMax, keyword);
        }

        else if(isRightParenthesis(keyword))
        {
            while(!isLeftParenthesis(operatorStk[operatorStackTop]))
            {
                string operatorToPush = pop(operatorStk, operatorStackTop);
                push(evaluationStk, evaluationStackTop, evaluationStackMax, operatorToPush);
            }
            pop(operatorStk, operatorStackTop);
        }
        
        else
        {
            push(evaluationStk, evaluationStackTop, evaluationStackMax, keyword);
        }
    }

    for(int i = 0; i <= evaluationStackTop; i++)
    {
        cout << evaluationStk[i] << " ";
    }
    cout << endl;



    return 0;
}
