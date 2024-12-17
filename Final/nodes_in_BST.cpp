#include<iostream>


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
            node *right;
            node *left;

    node(int value)
    {
        info=value;
        right=NULL;
        left=NULL;
    }
};



class BST
{
    public:
            node *root;

    BST()
    {
        root=NULL;
    }

    void insertion(node *passed_root,int value)
{
        
        if(root==NULL)
        {
            root= new node(value);
            return;
        }

        if(passed_root == NULL)
        {
            passed_root = root;
        }

    if(passed_root->info==value)
    {
        cout<<"The value is already present in the tree\n"<<endl;
        return;
    }

        if(passed_root->info > value)
        {
            if(passed_root->left !=NULL)
            {
                insertion(passed_root->left,value);
                return;
            }
            else
            {
                
                passed_root->left=new node(value);
                return;

            }
        }
        
        if(passed_root->info < value)
        {
            if(passed_root->right !=NULL)
            {
                insertion(passed_root->right,value);
                return;
            }
            else
            {
                passed_root->right=new node(value);
                return;

            }
        }

    }

    int counter_node(node *passed_root)
 {
        if(root==NULL)
            return 0;

        if(passed_root==NULL)
            return 0;

        if(passed_root->left ==NULL && passed_root->right==NULL)
        {
            return 1;
        }
        int left=0;
        left+= counter_node(passed_root->left);
        int right=0;
        right+= counter_node(passed_root->right);

        return 1+left+right;
}


     int strickly_binary_tree(node *passed_root)
    {
        if(root==NULL)
            return 0;

        if(passed_root==NULL)
            return 0;

        if(passed_root->left==NULL && passed_root->right==NULL)
            return 1;

        int left=strickly_binary_tree(passed_root->left);
        int right=strickly_binary_tree(passed_root->right);

        if(left+right ==2 || left+right==0)
            return 1;
        else 
            return -2;
    }

    int stric2(node *passed_root)
    {
        if(passed_root==NULL)
            return true;

        if((passed_root->left==NULL && passed_root->right!=NULL) ||( passed_root->left!=NULL && passed_root->right==NULL) )
            return false;


        return stric2(passed_root->left) && stric2(passed_root->right);
    }

bool isCompleteBinaryTreeUtil(node* root, int index, int totalnodes)
{
    if (root == nullptr) {
        return true; // An empty node is always valid
    }

    // If index exceeds the total number of nodes, it's not complete
    if (index >= totalnodes) 
    {
        return false;
    }

    // Recursively check the left and right subtrees
    bool leftComplete = isCompleteBinaryTreeUtil(root->left, 2 * index + 1, totalnodes);
    bool rightComplete = isCompleteBinaryTreeUtil(root->right, 2 * index + 2, totalnodes);

    return leftComplete && rightComplete;
}

// // Main function to check if the binary tree is complete
// bool isCompleteBinaryTree(node* root) {
//     int totalnodes = countnodes(root); // Count the total number of nodes
//     return isCompleteBinaryTreeUtil(root, 0, totalnodes);
// }



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

int nodes_at_height(node *passed_root, int height)
{
    if(root==NULL)
    {
        return 0;
    }

    if(passed_root==NULL)
        return 0;

    if(height==1)
        return 1;

    int left=0;
    int right=0;

    left +=nodes_at_height(passed_root->left,height-1);
    right +=nodes_at_height(passed_root->right,height-1);

    return 1+left+right;
}

};


int main(void)
{
    BST obj;

    obj.insertion(obj.root,9);
    obj.insertion(obj.root,11);
    obj.insertion(obj.root,10);
    // obj.insertion(obj.root,12);
    obj.insertion(obj.root,2);
    obj.insertion(obj.root,1);
    obj.insertion(obj.root,4);

    obj.printTree(obj.root,NULL,false);

    cout<<"Number of nodes in the bst:"<<obj.counter_node(obj.root)<<endl;

    cout<<"Number of nodes at height 2 are:"<<obj.nodes_at_height(obj.root,3)<<endl;


    if(obj.stric2(obj.root))
        cout<<"The tree is strickly binary tree\n"<<endl;
    else
        cout<<"Not Strickly binary tree\n"<<endl;

    if(obj.isCompleteBinaryTreeUtil(obj.root,0,7))
        cout<<"The tree is complete binary tree\n"<<endl;
    else
        cout<<"Not complete binary tree\n"<<endl;

    return 0;

}