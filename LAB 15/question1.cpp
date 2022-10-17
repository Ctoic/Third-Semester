#include<iostream>
using namespace std ;

class Node
{
public:
    int data ;
    Node* left ;
    Node* right ;
    Node()   {

    {
        data = 0;
        left = NULL;
        right  = NULL;

    }
    }

};
       void Insert(int val)   

   {
       Node* newnode = new Node() ;
       Node* tempptr ;
       newnode->data  = val;
       newnode->left = NULL;
       newnode->right = NULL;

};
class BST
{
    public:
    Node* rootptr ;
       void Insert(int val)
   {
       Node* newnode = new Node() ;
       Node* tempptr ;
       newnode->data  = val;
       newnode->left = NULL;
       newnode->right = NULL;
   

       if(rootptr == NULL)
       {
           tempptr= newnode;
       }


       if(rootptr == NULL)
       {
           rootptr= newnode;


       if(rootptr == NULL)
       {
           rootptr= newnode;

       }
       else 
       {
           tempptr = rootptr ;
           while(tempptr!=NULL)
           {
               if(tempptr->data > val)
               {
                   if(tempptr->left)
                   {
                       tempptr = tempptr->left;

                   }
                   else
                   {
                       tempptr = newnode;
                       break;

                   }
               }
               else if(tempptr->data < val)
               {
                   if(tempptr->right)
                   {
                       tempptr = tempptr->right;

                   }
                   else 
                   {
                       tempptr = newnode;
                       break;
                   }
               }

               else 
               {
                   cout<<"No diplicates are allowed :("<<endl;

               }

           }
        
               }
       }
       
   }

    void Display(Node* rootptr)
    

    {
        Display(rootptr->left);
        cout<<rootptr->data;
         Display(rootptr->right);


    }
       
       

};


int main()
{
    BST tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);

    tree.Display(tree.rootptr);
    
    return 0;
}