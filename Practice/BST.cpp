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
    
    public:
    node(int value)
    {
        info=value;
        left=NULL;
        right=NULL;
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

   void insertion(node *root2,int value)
   {
         
    if(root2==NULL)
        {
            root = new node(value);
            return;
        }

    if(root2->info == value)
    {
        cout<<"\nValue cannot be repeat in the BST . Value already exist in BST.\n";
        return;
    }
    if(root2->info >value)
        {
            if(root2->left ==NULL)
            {
                root2->left=new node(value);
                return;
            }
            else
            {
               insertion(root2->left,value);
               return;
            }

        }
    if(root2->info<value)
    {
        if(root2->right ==NULL)
        {
            root2->right= new node(value);
            return;
        }
        else
        {
            
            insertion(root2->right,value);
            return;
        }
    }

    

   }

   bool searching_BST(node *root2,int value)
   {
        if(root==NULL)
        {
            cout<<"The BST is empty\n";
            return false;
        }

        if(root2==NULL)
        {
            cout<<"The value does not exist in the BST"<<endl;
            return false;
        }

        if(root2->info == value)
        {
            cout<<"The value exist in the BST"<<endl;
            return true;
        }

        if(root2->info> value)
        {
            searching_BST(root2->left,value);
            return true;
        }
        
        if(root2->info < value)
        {
            searching_BST(root2->right,value);
            return true;
        }

    
   }



node* getSuccessor(node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node* Deletion_process(node *root2, int value)
    {
        if(root == NULL)
        {
            cout<<"\nThe list is empty "<<endl;
            return NULL;
        }

        if(root2->info> value)
            root2->left=Deletion_process(root2->left,value);
        else if(root2->info< value)
            root2->right=Deletion_process(root2->right,value);

        else
        {
            node *Required;
           if(root2->right==NULL)
            {
                Required=root2->left;
                delete root2;
                return Required;
            }
            if(root2->left==NULL)
            {
                Required=root2->right;
                delete root2;
                return Required;
            }
            
                
            node *curr = getSuccessor(root2);
            root2->info=curr->info;
            root2->right=Deletion_process(root2->right,curr->info);
            
                        
            
           
        }
      return root2;
    }

    void pre_order(node *n)
    {
        if(n==NULL)
        {
            return;
        }
        cout<<n->info<<" ";
        pre_order(n->left);
        pre_order(n->right);
    }

    int Height_BST(node  *root2, int level)
    {
        int left=level,right=level;
        if(root ==NULL)
        {
            return -1;
        }
        if((root2->left ==NULL && root2->right==NULL))
        {
            return level;
        }

        if(root2->left==NULL)
        {
             right=Height_BST(root2->right,level+1);
        }
        else if(root2->right==NULL)
        {
             left=Height_BST(root2->left,level+1);

        }
        else
        {
         left=Height_BST(root2->left,level+1);
         right=Height_BST(root2->right,level+1);
         }
        if(left>right)
        {
            return left;
        }
        else
            return right;
    }
};


bool Strickly_binary_tree(node *n)
{ 
    if(n==NULL)
        return false;

    if(n->left ==NULL && n->right==NULL) 
    {
        return true;
    }
    if(n->left !=NULL && n->right!=NULL)
    {
        bool left=Strickly_binary_tree(n->left);
        if(left == false)
        {
            return false;
        }
        bool right=Strickly_binary_tree(n->right);
        if(left && right)
        {
            return true;
        }
        else
            return false;
    }

    return false;
}

bool complete_binary_tree(node *n)
{
    if(n==NULL)
    {
        return false;
    }

    

    if(n->left!=NULL && n->right!=NULL)
    {
        bool left=complete_binary_tree(n->left);
        if(left==false)
        {
            return false;
        }
        bool right=complete_binary_tree(n->right);
        if(left && right)
        {
            return true;
        }
        else
            return false;

    }
    if(n->left == NULL && n->right==NULL)
    {
        return true;
    }
    if(n->left == NULL && n->right!=NULL)
    {
        return false;
    }
}
bool printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return false;
    
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

int main()
{

    //By creating object we create a empty BST Task 1
    BST Obj1,obj2;
    Obj1.insertion(Obj1.root,50);
    Obj1.insertion(Obj1.root,30);
    Obj1.insertion(Obj1.root,20);
    Obj1.insertion(Obj1.root,40);
    Obj1.insertion(Obj1.root,95);
    Obj1.insertion(Obj1.root,90);
    Obj1.insertion(Obj1.root,10);
    Obj1.insertion(Obj1.root,130);
    Obj1.insertion(Obj1.root,120);
    Obj1.insertion(Obj1.root,110);
    Obj1.insertion(Obj1.root,45);
    Obj1.insertion(Obj1.root,30);
    Obj1.insertion(Obj1.root,140);
    Obj1.insertion(Obj1.root,123);

    
    printTree(Obj1.root,NULL,false); 

    //BST is Empty as no insertion in obj2
    if(obj2.root==NULL)
    {
        cout<<"The BST is empty"<<endl;
    }

//Tast 3 Searching Item in the BST
Obj1.searching_BST(Obj1.root,900);


//Deleting the value 
 Obj1.Deletion_process(Obj1.root,30);




//Traversing
Obj1.pre_order(Obj1.root);
Obj1.insertion(Obj1.root,30);
cout<<"\n\n\n"<<endl;
printTree(Obj1.root,NULL,false);

//Height of BST
cout<<"\nHeight of the BST is "<<Obj1.Height_BST(Obj1.root,1);


cout<<"The Given tree is:";
if(!Strickly_binary_tree(Obj1.root))
{
cout<<"Not strickly binary tree"<<endl;
}
else
{
    cout<<"Strickly binary tree"<<endl;
}
    return 0;
}

