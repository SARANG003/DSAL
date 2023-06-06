/* PROBLEM STATEMENT: Dictionary stores keywords  &  its  meanings.  Provide facility for
 adding  new  keywords, deleting keywords, updating values of any entry. Also, display 
 whole data sorted in ascending or descending order. Find how many maximum comparisons
  may require for finding any keyword. Use height balance tree and find the complexity 
  for finding a keyword.*/

  
#include <iostream>
#include <string.h>
using namespace std;
class dict
{
    dict *root, *node, *left, *right, *tree1;
    string s1, s2;
    int flag, flag1, flag2, flag3, cmp;

public:
    dict()
    {
        flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, cmp = 0;
        root = NULL;
    }
    void input();
    void create_root(dict *, dict *);
    void check_same(dict *, dict *);
    void input_display();
    void display(dict *);
    void input_remove();
    dict *remove(dict *, string);
    dict *findmin(dict *);
    void input_find();
    dict *find(dict *, string);
    void input_update();
    dict *update(dict *, string);
};

void dict::input()
{
    node = new dict;
    cout << "\nEnter the keyword:\n";
    cin >> node->s1;
    cout << "Enter the meaning of the keyword:\n";
    cin.ignore();
    getline(cin, node->s2);
    create_root(root, node);
}

void dict::create_root(dict *tree, dict *node1)
{
    int i = 0, result;
    char a[20], b[20];
    if (root == NULL)
    {
        root = new dict;
        root = node1;
        root->left = NULL;
        root->right = NULL;
        cout << "\nRoot node created successfully" << endl;
        return;
    }
    for (i = 0; node1->s1[i] != '\0'; i++)
    {
        a[i] = node1->s1[i];
    }
    for (i = 0; tree->s1[i] != '\0'; i++)
    {
        b[i] = tree->s1[i];
    }
    result = strcmp(b, a);
    check_same(tree, node1);
    if (flag == 1)
    {
        cout << "The word you entered already exists.\n";
        flag = 0;
    }
    else
    {
        if (result > 0)
        {
            if (tree->left != NULL)
            {
                create_root(tree->left, node1);
            }
            else
            {
                tree->left = node1;
                (tree->left)->left = NULL;
                (tree->left)->right = NULL;
                cout << "Node added to left of " << tree->s1 << "\n";
                return;
            }
        }

        else if (result < 0)
        {
            if (tree->right != NULL)
            {
                create_root(tree->right, node1);
            }
            else
            {
                tree->right = node1;
                (tree->right)->left = NULL;
                (tree->right)->right = NULL;
                cout << "Node added to right of " << tree->s1 << "\n";
                return;
            }
        }
    }
}

void dict::check_same(dict *tree, dict *node1)
{
    if (tree->s1 == node1->s1)
    {
        flag = 1;
        return;
    }

    else if (tree->s1 > node1->s1)
    {
        if (tree->left != NULL)
        {
            check_same(tree->left, node1);
        }
    }
    else if (tree->s1 < node1->s1)
    {
        if (tree->right != NULL)
        {
            check_same(tree->right, node1);
        }
    }
}

void dict::input_display()
{
    if (root != NULL)
    {
        cout << "The words entered in the dictionary are:\n\n";
        display(root);
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

void dict::display(dict *tree)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        cout << tree->s1 << " = " << tree->s2 << "\n\n";
    }
    else
    {
        if (tree->left != NULL)
        {
            display(tree->left);
        }
        cout << tree->s1 << " = " << tree->s2 << "\n\n";
        if (tree->right != NULL)
        {
            display(tree->right);
        }
    }
}

void dict::input_remove()
{
    char t;
    if (root != NULL)
    {
        cout << "\nEnter a keyword to be deleted:\n";
        cin >> s1;
        remove(root, s1);
        if (flag1 == 0)
        {
            cout << "\nThe word '" << s1 << "' has been deleted.\n";
        }
        flag1 = 0;
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

dict *dict::remove(dict *tree, string s3)
{
    dict *temp;
    if (tree == NULL)
    {
        cout << "\nWord not found.\n";
        flag1 = 1;
        return tree;
    }
