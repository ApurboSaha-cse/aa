#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left_child;
    struct Node *right_child;
};
typedef struct Node *node;

node root = NULL;

bool search_on_tree(int value)
{
    node current_node = root;
    bool b = false;
    node parent_node = NULL;

    if(current_node == NULL)
        return false;
    
    while(1)
    {
        if(value == current_node->data)
        {
            b = true;
            return;
        }
    }
}