#include <bits/stdc++.h>
#define SPACE 10
using namespace std;

struct tree
{
    int data;
    struct tree *leftChild;
    struct tree *rightChild;
};
typedef struct tree *node;
node root = NULL;

void printTree(node root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += SPACE;
    printTree(root->rightChild, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << endl;
    printTree(root->leftChild, space);
}

bool searchOnTree(int value)
{
    node currentNode = root;
    bool boolean = false;
    node parentNode = NULL;


    if (currentNode == NULL)
        return false;

    while (1)
    {
        if (value == currentNode->data)
        {
            boolean = true;
            break;
        }
        else if (value < currentNode->data)
        {
            currentNode = currentNode->leftChild;
        }
        else
            currentNode = currentNode->rightChild;

        if (currentNode == NULL)
        {
            break;
        }
    }

    // if(boolean)
    // {
    //     cout << value << " is in the tree."<< endl;
    // }
    // else
    // {
    //     cout << value << " is not in the tree." << endl;
    // }
    return boolean;
}

void insertNode(int value)
{
    if (!searchOnTree(value))
    {
        node newNode;
        node currentNode;
        node parentNode;

        newNode = (node)malloc(sizeof(node));
        // cout << "Enter the value to insert: ";
        newNode->data = value;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;

        if (root == NULL)
        {
            root = newNode;
            cout << "Value inserted to root!" << endl;
            printTree(root, 5);
        }
        else
        {
            currentNode = root;
            parentNode = NULL;

            while (1)
            {
                parentNode = currentNode;
                if (newNode->data < parentNode->data)
                {
                    currentNode = currentNode->leftChild;
                    if (currentNode == NULL)
                    {
                        parentNode->leftChild = newNode;
                        cout << "Value inserted to left child!" << endl;
                        printTree(root, 5);
                        return;
                    }
                }
                else
                {
                    currentNode = currentNode->rightChild;
                    if (currentNode == NULL)
                    {
                        parentNode->rightChild = newNode;
                        cout << "Value inserted to right child!" << endl;
                        printTree(root, 5);
                        return;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Item is already in the BST" << endl;
    }
    // node newNode;
    // node currentNode;
    // node parentNode;

    // newNode = (node)malloc(sizeof(node));
    // //cout << "Enter the value to insert: ";
    // newNode->data = value;
    // newNode->leftChild = NULL;
    // newNode->rightChild = NULL;

    // if(root == NULL)
    // {
    //     root = newNode;
    //     cout << "Value inserted to root!" << endl;
    //     printTree(root, 5);
    // }
    // else
    // {
    //     currentNode = root;
    //     parentNode = NULL;

    //     while(1)
    //     {
    //         parentNode = currentNode;
    //         if(newNode->data < parentNode->data)
    //         {
    //             currentNode = currentNode->leftChild;
    //             if(currentNode == NULL)
    //             {
    //                 parentNode->leftChild = newNode;
    //                 cout << "Value inserted to left child!" << endl;
    //                 printTree(root, 5);
    //                 return;

    //             }
    //         }
    //         else
    //         {
    //             currentNode = currentNode->rightChild;
    //             if(currentNode == NULL)
    //             {
    //                 parentNode->rightChild = newNode;
    //                 cout << "Value inserted to right child!" << endl;
    //                 printTree(root, 5);
    //                 return;
    //             }
    //         }
    //     }
    // }
}

void preOrderPrint(node root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->leftChild);
    preOrderPrint(root->rightChild);
}

void postOrderPrint(node root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderPrint(root->leftChild);
    postOrderPrint(root->rightChild);
    cout << root->data << " ";
}

void inOrderPrint(node root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderPrint(root->leftChild);
    cout << root->data << " ";
    inOrderPrint(root->rightChild);
}

int main()
{
    int input;
    // insertNode();
    // insertNode();
    // insertNode();
    // insertNode();

    cout << "Enter Q to quit! " << endl;
    cout << "Enter the input to insert: ";
    while (cin >> input)
    {

        insertNode(input);
        cout << "Enter the input to insert: ";
    }

    cout << "In PreOrder form: ";
    preOrderPrint(root);
    puts("");
    cout << endl;

    cout << "In postOrder form: ";
    postOrderPrint(root);
    puts("");
    cout << endl;

    cout << "In inOrderform: ";
    inOrderPrint(root);
    puts("");
    cout << endl;
    // int searchItem;
    // cout << "Enter the number to search in the BST: ";
    // cin >> searchItem;

    // searchOnTree(searchItem);
    return 0;
}