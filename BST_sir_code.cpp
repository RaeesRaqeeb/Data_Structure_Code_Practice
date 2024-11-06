#include <iostream>
#include <conio.h>
#include <stdlib.h>

// struct node
// {
//     int info;
//     node *left, *right;
    
// };
class node
{
    private:
        int info;
        node *left;
        node *right;
    
    public:
    node(int value)
    {
        info=value;
        left=NULL;
        right=NULL;
    }
};
class bin_search_tree
{
private:
    node *temp;

public:
    node *root;
    int number;
    bin_search_tree();
    void options();
    void b_search_tree(node *);
    void in_order(node *);
};

int main()
{
    clrscr();
    char ch;
    bin_search_tree obj;
    while (4)
    {
        obj.options();
        ch = getch();
        switch (ch)
        {
        case '1':
            clrscr();
            cout << "\n Enter number to add in a tree... \n";
            cin >> obj.number;
            obj.b_search_tree(obj.root);
            break;

        case '2':
            clrscr();
            obj.in_order(obj.root);
            break;
        case '3':
            exit(0);
            break;
        default:
            exit(0);
            break;
        } // end of switch.
    } // end of while.
} //-----------------------------------------------

bin_search_tree ::bin_search_tree()
{
    root = temp = NULL;
}
//--------------------------------------------------------

void bin_search_tree ::b_search_tree(node *temp) // b_search_tree(int val)
{
    if (root == NULL)
    {
        temp = new node; // root = new node(val);
        temp->info = number;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return;
    }

    if (temp->info == number)
    {
        cout << " \n Given number is already present in tree.\n";
        return;
    }

    if (temp->info > number)
    {
        if (temp->left != NULL)
        {
            b_search_tree(temp->left);
            return;
        }
        else
        {
            temp->left = new node; // temp->left = new node(val);
            temp->left->info = number;
            temp->left->left = NULL;
            temp->left->right = NULL;
            return;
        }
    }

    if (temp->info < number)
    {
        if (temp->right != NULL)
        {
            b_search_tree(temp->right);
            return;
        }
        else
        {
            temp->right = new node; // temp->right = new node(val);
            temp->right->info = number;
            temp->right->left = NULL;
            temp->right->right = NULL;
            return;
        }
    }

} //-------------------- Insertion Function Ends --------------------------

void bin_search_tree ::options()
{
    cout << "\n\n ************** Select Option *****************.\n";
    cout << "\n Enter any of choices.\n";
    cout << "\n 1 : Adding (inserting) node in BST.\n";
    cout << "\n 2 : Print the whole BST .\n";
    cout << "\n 3 : Quitting the Program.\n";
} //--------------------------------------------------------------
void bin_search_tree ::in_order(node *temp)
{
    if (root == NULL)
    {
        cout << " Tree is empty.\n";
        return;
    }
    if (temp->left != NULL)
        in_order(temp->left);
    cout << temp->info << " ";
    if (temp->right != NULL)
        in_order(temp->right);
    return;
} //---------------------------- PROGRAM ENDS HERE ---------------------------------------