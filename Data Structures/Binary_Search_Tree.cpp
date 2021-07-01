/*

*******MAIN MENU*******
1. Insert Element into Binary Search Tree
2. Search Element in BST
3. Preorder Traversal of BST
4. Maximum Element in BST
5. Minimum Element in BST
6. Delete Element from BST
7. Find Maximum Height of BST
8. Find Total Number of nodes in BST     
9. EXIT

    TEST CASE:
        1. Insert: 50
        1. Insert: 24
        1. Insert: 75
        1. Insert: 33
        1. Insert: 60
        1. Insert: 15
        1. Insert: 40

            Tree Looks Like
                    50
                /        \
            24             75
        /    \          / 
        15      33      60
                \
                    40   
        

        2. Search Element in BST
            Enter Data to be searched: 60
            Data is Found in Tree!
        3. Pre Order Traversal
            50  24  15  33  40  75  60
        4. Maximum Element in BST 
            Maximum Element: 75
        5. Minimum Element in BST
            Minimum Element: 15
        6. Delete Element from BST
            Enter Element to be Deleted: 33
        3. Pre Order Traversal
            50  24  15  40  75  60
        7. Find Maximum Height of BST
            Maximum Height: 4
        8. Find Total Number of nodes in BST
            Total Number of Nodes: 7

*/

#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    bstnode *left;
    int data;
    bstnode *right;
} * root;

void insert()
{
    int data;
    bstnode *newnode = new bstnode();
    cout << "Enter Data to be inserted: ";
    cin >> data;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    bstnode *temp = root;
    if (temp == NULL)
    {
        root = newnode;
        return;
    }
    while (1)
    {
        if (temp->data >= newnode->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newnode;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newnode;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

void search()
{
    int num, flag = 0;
    bstnode *temp = root;
    if (temp == NULL)
    {
        cout << "Tree is Empty!"<<endl;
        return;
    }
    cout << "Enter Data to be searched: ";
    cin >> num;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            flag = 1;
            break;
        }
        else if (temp->data >= num)
        {
            temp = temp->left;
        }
        else if (temp->data < num)
        {
            temp = temp->right;
        }
    }
    if (flag == 1)
    {
        cout << "Data is Found in Tree!"<<endl;
    }
    else
    {
        cout << "Data not Found"<<endl;
    }
}

void preorder_traversal(bstnode *temp)
{
    if (temp == NULL)
    {
        return;
    }
    cout << temp->data << "\t";
    preorder_traversal(temp->left);
    preorder_traversal(temp->right);
}

void max_element()
{
    bstnode *temp = root;
    if (temp == NULL)
    {
        cout << "Tree is Empty!"<<endl;
    }
    else if (temp->right == NULL)
    {
        temp = temp;
    }
    else
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
    }
    cout << "Maximum Element: " << temp->data << endl;
}

void min_element()
{
    bstnode *temp = root;
    if (temp == NULL)
    {
        cout << "Tree is Empty!"<<endl;
        return;
    }
    else if (temp->left == NULL)
    {
        temp = temp;
    }
    else
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
    }
    cout << "Minimum Element: " << temp->data << endl;
}

void remove(bstnode *temp, bstnode *ptr)
{
    if (temp->left == NULL && temp->right == NULL)
    {
        if (ptr->left == temp)
        {
            ptr->left = NULL;
        }
        else
        {
            ptr->right = NULL;
        }
        free(temp);
    }
    else if (temp->right != NULL && temp->left == NULL)
    {
        if (ptr->data < temp->data)
        {
            ptr->right = temp->right;
        }
        else if (ptr->data >= temp->data)
        {
            ptr->left = temp->right;
        }
        free(temp);
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        if (ptr->data < temp->data)
        {
            ptr->right = temp->left;
        }
        else if (ptr->data >= temp->data)
        {
            ptr->left = temp->left;
        }
        free(temp);
    }

    else if (temp->right != NULL && temp->left != NULL)
    {
        bstnode *ptr1;
        ptr = temp->right;
        while (ptr->left != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->left;
        }
        int n = ptr->data;
        ptr1->left = NULL;
        free(ptr);
        temp->data = n;
    }
}

void delete_element()
{
    int num, flag = 0;
    bstnode *temp = root, *ptr;
    if (temp == NULL)
    {
        cout << "Tree is Empty!"<<endl;
        return;
    }
    cout << "Enter Element to be Deleted: ";
    cin >> num;
    if (temp->data == num)
    {
        root = NULL;
        return;
    }
    while (temp != NULL)
    {

        if (temp->data == num)
        {
            flag = 1;
            remove(temp, ptr);
            return;
        }
        else if (temp->data >= num)
        {
            ptr = temp;
            temp = temp->left;
        }
        else if (temp->data < num)
        {
            ptr = temp;
            temp = temp->right;
        }
    }
    if (flag == 0)
    {
        cout << "Element is not present in tree to delete!"<<endl;
    }
}

int height_bst(bstnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height_bst(root->left);
    int rightheight = height_bst(root->right);
    if (leftheight >= rightheight)
        return (leftheight + 1);
    else
        return (rightheight + 1);
}

int total_number_nodes(bstnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftnode = total_number_nodes(root->left);
    int rightnode = total_number_nodes(root->right);
    return (leftnode + rightnode + 1);
}

int main()
{
    int n;
    do
    {
        cout << "\n*******MAIN MENU*******" << endl;
        cout << "1. Insert Element into Binary Search Tree" << endl;
        cout << "2. Search Element in BST" << endl;
        cout << "3. Preorder Traversal of BST" << endl;
        cout << "4. Maximum Element in BST" << endl;
        cout << "5. Minimum Element in BST" << endl;
        cout << "6. Delete Element from BST" << endl;
        cout << "7. Find Maximum Height of BST" << endl;
        cout << "8. Find Total Number of nodes in BST" << endl;
        cout << "9. EXIT" << endl;
        cout << "Enter any one option: ";
        cin >> n;
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            preorder_traversal(root);
            break;
        case 4:
            max_element();
            break;
        case 5:
            min_element();
            break;
        case 6:
            delete_element();
            break;
        case 7:
        {
            int height = height_bst(root);
            cout << "Maximum Height: " << height << endl;
        }
        break;
        case 8:
        {
            int node_num = total_number_nodes(root);
            cout << "Total Number of Nodes: " << node_num << endl;
        }
        break;
        case 9:
            return 0;
        }
    } while (n < 10);

    return 0;
}
