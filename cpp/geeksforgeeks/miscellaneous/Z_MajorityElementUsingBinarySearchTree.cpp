/*
Majority Element
    
    Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”. A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

    Examples : 
    
    Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
    
    Output : 4

    Explanation: The frequency of 4 is 5 which is greater
        than the half of the size of the array size. 

    Input : {3, 3, 4, 2, 4, 4, 2, 4}
    
    Output : No Majority Element
    
    Explanation: There is no element whose frequency is
         greater than the half of the size of the array size.  
*/

#include <iostream>
using namespace std;

struct node
{
    int key;
    int count = 0;
    struct node *left, *right;
};

struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));

    temp->key = value;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key, int &ma)
{
    if (node == NULL)
    {
        if (ma == 0)
            ma = 1;

        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key, ma);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key, ma);
    }
    else
        node->count++;

    ma = max(ma, node->count);

    return node;
}

void majorityElement(struct node *root, int s)
{
    if (root != NULL)
    {
        majorityElement(root->left, s);

        if (root->count > (s / 2))
            printf("%d \n", root->key);

        majorityElement(root->right, s);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        struct node *root = NULL;
        int ma = 0;

        for (int i = 0; i < n; ++i)
            root = insert(root, arr[i], ma);

        if (ma > (n / 2))
            majorityElement(root, n);
        else
            cout << "No majority element\n";
    }

    return 0;
}
