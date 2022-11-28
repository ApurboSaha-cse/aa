#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *nodePtr;

void printElement(nodePtr head)
{
    cout << "Elements are : "<<endl;
    for( nodePtr currentNode  = head; currentNode != NULL; currentNode = currentNode->next)
    {
        cout << currentNode->data << " " ;
    }
    cout << endl;
}

// nodePtr insertNodeAtTheBegining(nodePtr head)
// {
//     nodePtr currentNode = head;
//     nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
//     cout << "Enter the new node data to insert at the begining" << endl;
//     cin >> newNode->data;

//     // newNode->data = 4;
//     newNode->next = currentNode;
//     currentNode = newNode;
//     printElement(currentNode);
//     return currentNode;
// }

// nodePtr insertNodeAtTheEnd(nodePtr head)
// {
//     nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
//     cout << "Enter the new node data to insert at the end" << endl;
//     cin >> newNode->data;

    
//     // for(nodePtr currentNode = head; currentNode != NULL; currentNode = currentNOde->next)
//     // {

//     // }
//     nodePtr currentNode = head;

//     while(currentNode->next!= NULL)
//     {
//         currentNode = currentNode->next;
//     }
//     currentNode->next = newNode;
//     newNode->next = NULL;
//     return head;

// }

void insertNodeAtAPosition(nodePtr head, int numberOfElement)
{
    int pos;
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    cout << "Enter new node data and position: " ;
    cin >> newNode->data >> pos;


    nodePtr currentNode = head;
    if(pos == 1)
    {
        newNode->next = currentNode;
        currentNode = newNode;
        head = newNode;
    }
    else if(pos == numberOfElement +1)
    {
        while(currentNode->next!= NULL)
        {
            currentNode = currentNode->next;
        }
    currentNode->next = newNode;
    newNode->next = NULL;
    }
    else
    {
        for(int i = 2; i<pos ; i++)
        {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    
    
    // for(int i = 2; i<pos ; i++)
    // {
    //     currentNode = currentNode->next;
    // }

    // newNode->next = currentNode->next;
    // currentNode->next = newNode;
    printElement(head);


}

void deleteAElement(nodePtr head, int numberOfElement)
{
    nodePtr currentNode = head;
    int pos;
    cout << "Enter the position of the element to delete: ";
    cin >> pos;

    if(pos == 1)
    {
        currentNode = currentNode->next;
        head =currentNode;
    }
    else if(pos == numberOfElement +1)
    {
        while(currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = NULL;
    }
    else
    {
        for(int i = 2; i < pos; i++)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
    }
    printElement(head);
}

int main()
{
    int numberOfElement;
    cout << "Enter The Number of Element: ";
    cin >> numberOfElement;

    nodePtr head;
    nodePtr previousNode;

    for(int i = 0; i < numberOfElement; i++)
    {
        nodePtr currentNode = (nodePtr)malloc(sizeof(struct Node));

        if( i == 0)
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

    
    printElement(head);

    // insertNodeAtTheEnd(head);
    // printElement(head);

    // insertNodeAtTheBegining(head);
    //printElement(currentNode);

    // insertNodeAtTheEnd(head);
    // printElement(head);
    insertNodeAtAPosition(head, numberOfElement);
    
    deleteAElement(head, numberOfElement);
    

    return 0;

}