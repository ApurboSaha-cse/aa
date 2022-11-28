#include<bits/stdc++.h>
using namespace std;

const int operatorMax = 100;
const int evaluationMax = 200;

int operatorStackTop = -1;
int evaluationStackTop = -1;
string operators = "+-*/^";

string operatorStk[operatorMax];
string evaluationStk[evaluationMax];

void push(string stk[], int& stkTop, int stkMax, string item)
{
    if(stkTop + 1 == stkMax)
    {
        cout << "Stack overflow."<< endl;
        exit(1);
    }

    stkTop++;
    stk[stkTop] = item;
}

string pop(string stk[], int& stkTop)
{
    
    if(stkTop == -1)
    {
        cout << "Stack underflow." << endl;
        exit(2);
    }
    string item = stk[stkTop];
    stkTop--;


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
    if(keyword[0] == '(')
    {
        return true;
    }
    return false;
}

bool isRightParenthesis(string keyword)
{
    if(keyword[0] == ')')
    {
        return true;
    }
    return false;
}

// void isVariable(string keyword)
// {
//     if((keyword >= 'A' && keyword <= 'Z') || (keyword >= 'a' && keyword <= 'z') )
//     {
//         cout << "Enter the value of " << keyword << ": ";
//         string aa = keyword;
//         cin >> aa;
//         //return aa;
//     }
    
    
// }

void infixToPostfix(string infixInput)
{
    infixInput += " )";

    push(operatorStk, operatorStackTop, operatorMax, "( ");

    stringstream infixStream(infixInput);
    string keyword;

    while(infixStream >> keyword)
    {
        if(isOperator(keyword))
        {
            while(getOperatorPrecedence(keyword) <= getOperatorPrecedence(operatorStk[operatorStackTop]))
            {
                string operatorToPush = pop(operatorStk, operatorStackTop);
                push(evaluationStk, evaluationStackTop, evaluationMax, operatorToPush);
            }
            push(operatorStk, operatorStackTop, operatorMax, keyword);
        }

        else if(isLeftParenthesis(keyword))
        {
            push(operatorStk, operatorStackTop, operatorMax, keyword);
        }
        
        else if(isRightParenthesis(keyword))
        {
            while(!isLeftParenthesis(operatorStk[operatorStackTop]))
            {
                string operatorToPush = pop(operatorStk, operatorStackTop);
                push(evaluationStk, evaluationStackTop, evaluationMax, operatorToPush);
            }
            pop(operatorStk, operatorStackTop);
        }

        // else if(isVariable(keyword))
        // {
        //     push(evaluationStk, evaluationStackTop, evaluationMax, keyword);
        // }

        else
        {
            push(evaluationStk, evaluationStackTop, evaluationMax, keyword);
        }
    }

    for(int i = 0; i <= evaluationStackTop; i++)
    {
        cout << evaluationStk[i] << " ";
    }
    cout << endl;
}


int main()
{
    cout << " Enter the input separated with space: ";
    string infixInput;
    getline(cin, infixInput);

    infixToPostfix(infixInput);
    


    return 0;
}