#include<iostream>
#include<string>

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node
{
    public:
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

node* parent(node* curr, node* p, node* par)
{
    if(curr == NULL)
        return NULL;

    if (curr == p)
    {
        return par;
    }
    else
    {
        node *t = NULL;
        t = parent(curr->left, p, curr);
        if(t!= NULL)
            return t;
        else
        {
            t = parent(curr->right, p, curr);
            return t;
        }
    }
}

node* sibling(node* root, node* p)
{
    node* par = parent(root, p, NULL);

    if (par->left == p)
        return par->right;
    else 
        return par->left;
}

void deleteTree(node* leaf)
{
    // root = NULL;
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

int getLevel(node *ptr, int val, int level)
{
    if (ptr == NULL)
        return -1;
    if (ptr->info == val)
        return level;

    int l = getLevel(ptr->left, val, level + 1);
    int r = getLevel(ptr->right, val, level + 1);

    if (l != -1)
        return l;
    else 
        return r;
}
int maxDepth(node* n)  
{  
    if (n == NULL)  
        return -1;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void preOrder(node *n) {
    if (n == NULL)
        return;
    
    cout<<n->info<<" ";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}



bool Is_indentical(node *one, node *two)
{
    if(one == NULL && two == NULL)
    {

        return false;
    }
    if(one == NULL || two == NULL)
    {

        return true;
    }

    if(one->info == two->info)
    {
        return Is_indentical(one->left,two->left) && Is_indentical(one->right,two->right);
    
    }
    else
    {
        return false;
    }
}


int divisor_checker(node *n, node *n2)
{
    if (n ==NULL)
    {
        return 0;
    }
    if(n2== NULL)
    {
        return 0;
    }
    int left=divisor_checker(n,n2->left);
    int right=divisor_checker(n,n2->right);

    if(n->info % n2->info == 0)
    {
        return left+right+1;
    }
    else
    {
        return left+right;
    }
}
// Recursive function to print binary tree
// It uses inorder traversal


//  difference between sum of all nodes present at odd and even levels in a binary tree


int Eterator(node *n, int level)
{
    if (n==NULL)
    {
        return 0;

    }

    if(level==0)
    {
        return n->info;
    }

    int left=Eterator(n,level-1);
    int right=Eterator(n,level-1);

    return left+right;
}

int Difference_even_odd(node *n, int &diff, int level) {
    if (n == NULL)
        return 0;

    if (level % 2 == 0)
     {
        diff += n->info;
    }
    else {
        diff -= n->info;
    }
    Difference_even_odd(n->left, diff,level+1);
    Difference_even_odd(n->right, diff, level+1);
    return 0;
}

bool only_child_Trees(node *n)
{
    if(n==NULL)
    {
        return false;
    }
    bool left=false;
    bool right=false;
    if(n->left!=NULL && n->right!=NULL)
    {
        return false;
    }
    else if(n->left==NULL && n->right==NULL)
    {
        return true;
    }
    else
    {
        left=only_child_Trees(n->left);
        right=only_child_Trees(n->right);
    }

    if(left || right)
    {
        return true;
    }
    else if (!left && !right )
    {
        return false;
    }
}


bool child_sum(node *n)
{
    if(n==NULL)
    {
        return false;
    }
    if(n->left == NULL  && n->right == NULL)
    {
        return  true;
    }
    if(n->left ==NULL || n->right==NULL)
    {
        return false;
    }
    bool left;
    bool right;
    int value=n->left->info;
    int value2=n->right->info;
    if(value + value2== n->info)
    {
         left=child_sum(n->left);
         right=child_sum(n->right);
    }
    else 
    {
        return false;
    }

    if(left && right)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

bool inverter(node *n,node *l, node *r)
{
    if (n==NULL)
    {
        return false;
    }

    if(l == NULL  && r == NULL)
    {
        return true;
    }
    if(l ==NULL || r==NULL)
    {
        return false;

    }

    int temp=l->info;
    l->info=r->info;
    r->info=temp;

    bool l2=inverter(n,l->left,r->right);
    bool r2=inverter(n, l->right,r->left);

    if(l2 && r2)
    {
    // printTree(n,NULL,false);

        return true;

    }
    else 
    {
        return false;
    }

}

//Diameter of tree
int Diameter_of_tree(node *n, int &D)
{
    if(n==NULL)
    {
        return 0;
    }
    if (n->left==NULL && n->right!=NULL)
    {
        D+= Diameter_of_tree(n->right,D);
        return D;
    }
    else if(n->right==NULL && n->left!=NULL)
    {
        D+= Diameter_of_tree(n->left,D);
        return D;
    }
    int l=maxDepth(n->left);
    int r=maxDepth(n->right);
    D+=l+r;
    return D+1;
}


//   sum of root to leaf digits in a binary tree
int Sum_of_nodes_digits(node *n, int num)
{
    if(!n)
    {
        return 0;
    }

    num= num*10 + n->info;

    if(!n->left &&  !n->right)
    {
        return num;
    }
    
    return Sum_of_nodes_digits(n->left,num) + Sum_of_nodes_digits(n->right,num);
}


bool are_cousins(node *root,node *node1, node *node2)
{
    if((getLevel(node1,node1->info,1) == getLevel(node2, node2->info,1)) && (parent(root,node1,NULL) !=parent(root,node2,NULL)))
    {
        cout<<"The given Nodes are cousins"<<endl;
    }
    else
    {
        cout<<"The given nodes are not cousins"<<endl;
    }

}

//My get level function
int getLevel_2(node *root, int value, int level)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->info==value)
    {
        return level;
    }

    int l=getLevel_2(root->left,value,level+1);
    if(l!=0)
    {
        return l;

    }
    else
    {
        int r=getLevel_2(root->right,value,level+1);
        return r;
    }

}


bool Child_1_or_not(node *root)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->left!=NULL && root->right!=NULL)
    {
        return false;
    }
    if(root->left !=NULL)
    {
        return Child_1_or_not(root->left);
    }
    if(root->right !=NULL)
    {
        return Child_1_or_not(root->right);
    }
    
}

bool child_2_or_not(node *root)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->left!=NULL && root->right!=NULL)
    {
        bool l=child_2_or_not(root->left);
        bool r=child_2_or_not(root->right);
        return l && r;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    if(root->left ==NULL || root->right==NULL)
    {
        return false;
    }
    
}

int printLevel(node* root, int level, int count)
{
    if (root == nullptr) {
        return false;
    }
 
    if (level == 1)
    {
        
        // return true if at least one node is present at a given level
        return root->info;
    }
 
    int left = printLevel(root->left, level - 1,count);
    int right = printLevel(root->right, level - 1,count);
    
    if(left-right == root->info)
    {
        count++;
    }
    return count;
}
 
// Function to print level order traversal of a given binary tree
void levelOrderTraversal(node* root)
{
    // start from level 1 — till the height of the tree
    int level = 1;
 
    // run till printLevel() returns false
    while (printLevel(root, level,0)) {
        level++;
    }
}
int main() 
{
// {
//     node *root = new node(5);
//     root->left = new node(2);
//     root->right = new node(7);
//     root->right->left = new node(3);
//     root->right->right = new node(9);
//     root->left->left = new node(6);
//     root->left->left->right = new node(1);

//     printTree(root, NULL, false);
    
//     // Find Parent
//     node *n = parent(root, root->left->left, NULL);
//     cout<<"Parent is: "<<n->info<<endl;

//     // Find sibling
//     node *sib = sibling(root, root->right->left); //sibling of 3 (which is 9)
//     cout<<"Sibling of 3 is: "<<sib->info<<endl;

//     // Level of a node
//     cout<<"Level of 9: "<<getLevel(root, 9, 0)<<endl;

//     // Depth of the tree
//     cout<<"Depth of the tree: "<<maxDepth(root)<<endl;
//     // deleteTree(root);
//     root = NULL;

//     // Tree Traversals (PreOrder, InOrder, PostOrder) [Start]
//     node *order2 = NULL;
//     order2 = new node(1);
//     order2->left = new node(2);
//     order2->right = new node(3);
//     order2->left->left = new node(4);

//     printTree(order2,NULL,false);
//     //printTree(root, NULL, false);
//     cout<<"PreOrder"<<endl;
//     preOrder(order2);
//     cout<<endl;
//     cout<<"InOrder"<<endl;
//     inOrder(order2);
//     cout<<endl;
//     cout<<"PostOrder"<<endl;
//     postOrder(order2);


//     node *root =new node(12);
//     root->left = new node(2);
//     root->right = new node(6);
//     root->right->left = new node(3);
//     root->right->right = new node(4);
//     root->left->left = new node(5);
//     root->left->left->right = new node(1);

//     node *order=new node (1);
//     order->right = new node(7);
//     order->right->left = new node(3);
//     order->right->right = new node(3);
//     order->right->left->right = new node(1);

//     //identical
//     cout<<maxDepth(root)<<" -- "<<maxDepth(order)<<endl;
//     if(maxDepth(root) == maxDepth(order))
//     { 
//     if(Is_indentical(root,order))
//     {
//         cout<<"The two trees are equal"<<endl;
//     }
//     else
//     {
//         cout<<"The two trees are not equal"<<endl;
//     }
//     }
//     else
//     {
//         cout<<"\nThe tree are not equal";
//     }



// // difference between sum of all nodes present at odd and even levels in a binary tree
// int diff=0;
// Difference_even_odd(order,diff,0);
// cout<<" difference between sum of all nodes present at odd and even levels in a binary tree :"<<diff<<endl;



// //Checking the tree nodes have only one child node
// if(only_child_Trees(order))
// {
//     cout<<"Tree has one child node for each node"<<endl;
// }
// else 
// {
//     cout<<"The tree has more then one child for a node"<<endl;
// }
// printTree(order,NULL,false);


//     node *root2 =new node(12);
//     root2->left = new node(4);
//     root2->right = new node(8);
//     root2->right->left = new node(6);
//     root2->right->right = new node(2);
//     root2->left->right = new node(1);

// printTree(root2,NULL,false);
// if(child_sum(root2))
// {
//     cout<<"This tree is satisfying the children sum property:"<<endl;
// }
// else
// {
//     cout<<"This tree is not satisfying the children sum property"<<endl;
// }

// //Inverting the tree

//     node *root3 =new node(12);
//     root3->right = new node(8);
//     root3->right->left = new node(6);
//     root3->right->right = new node(2);
//     root3->right->left->left = new node(5);
//     root3->right->left->right = new node(7);
//     root3->right->right->left = new node(3);
//     root3->right->right->right = new node(10);

// cout<<"Before inversion"<<endl;
// printTree(root3,NULL,false);

// if(inverter(root3,root3->left,root3->right))
// {
//     cout<<"After Inversion"<<endl;
//     printTree(root3,NULL,false);

// }
// else    
// {
//     cout<<"Invertion of this tree is not possible"<<endl;
// }



// //diameter of tree
// int diameter=0;
// cout<<"Diameter of the given tree is:"<<Diameter_of_tree(root3,diameter);


// sum of root to leaf digits in a binary tree
    node *root4 =new node(25);
    root4->right = new node(8);
    root4->right->left = new node(6);
    root4->right->right = new node(2);
    root4->right->left->left = new node(5);
    root4->right->left->right = new node(7);
    root4->right->right->left = new node(3);
    root4->left= new node(9);
    root4->left->left = new node(4);
    root4->left->right = new node(1);
    root4->right->right->right= new node(90);
//     root3->right->right->right = new node(10);
cout<<"Sum of the digits of the each nodes of the tree through different path:"<<Sum_of_nodes_digits(root4,0)<<endl;
printTree(root4,NULL,false);


//Finding Couzin
are_cousins(root4,root4->left->left,root4->right->right);

cout<<"Level of :"<<root4->right->left->info<<" is:"<<getLevel_2(root4,root4->right->left->info,0);
    //Finding the number of divisor of root present in the tree
cout<<"Number of divisors of root present in the tree are :"<<divisor_checker(root4,root4)-1<<endl ;

node *root5= new node (50);
root5->left= new node (23);
root5->left->left=new node(24);
root5->left->left->left=new node(50);
root5->right= new node(25);
root5->left->left->right=new node(25);

printTree(root5,NULL,false);

cout<<":"<<Child_1_or_not(root5);
cout<<":"<<child_2_or_not(root4);


cout<<levelOrderTraversal(root5)<<endl;
    return 0;
}

