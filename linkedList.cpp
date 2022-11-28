#include<bits/stdc++.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
};

typedef struct Node *nodePtr;

void print(nodePtr startNode)
{
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {
        cout << currentNode->data << " " ;
    }
    cout << endl;
}

int getMaximum(nodePtr startNode)
{
    int max = startNode->data;
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {
        if(currentNode->data > max)
        {
            max = currentNode->data;
        }
    }

    return max;
}

int getMinimum(nodePtr startNode)
{
    int min = startNode->data;
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {
        if(currentNode->data < min)
        {
            min = currentNode->data;
        }
    }

    return min;
}

int getTotal(nodePtr startNode)
{
    int total = 0;
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {
        total = total + currentNode->data;
    }

    return total;
}

double getAverage(nodePtr startNode)
{
    int  total = 0;
    int sanny = 0;
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {    
        total = total + currentNode->data;
        sanny ++;
    }
    int avg = total / sanny;
    return avg;
}

double getSinValue(nodePtr startNode)
{
    for(nodePtr currentNode = startNode; currentNode != NULL; currentNode = currentNode->next)
    {    
        cout << sin(currentNode->data) << " ";
    }
    cout << endl;
    return 0;
}


int main()
{
    int numberOfElement;
    cout << "Enter the number of Element: ";
    cin>>numberOfElement;


    nodePtr head;
    nodePtr previousNode;

    for(int i = 0; i < numberOfElement; i++)
    {
        nodePtr currentNode = (nodePtr)malloc(sizeof(struct Node));

        if(i == 0)
        {
            head = currentNode;
        }
        else
        {
            previousNode->next = currentNode;
        }

        int data;
        cout << "input [" << i + 1 << "]:";
        cin >> data;

        currentNode->data = data;
        previousNode = currentNode;
    }

    previousNode->next = NULL;

    cout << "Linked List Items: ";
    print(head);

    cout << "Maximum element is: " << getMaximum(head) << endl;
    
    cout << "Minimum element is: " << getMinimum(head) << endl;

    cout << "Total value is: " << getTotal(head) << endl;

    cout << "Average value is: " << getAverage(head) << endl;

    cout << "Sin value is: " ;
    
    getSinValue(head);


    return 0;
}
