#include<iostream>
#include<math.h>
using namespace std;



class node
{
public:
    int data;
    node* left;
    node* right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};


class tree
{
public:
    node* root;
    int* array;
 

    tree()
    {
        root = NULL;
    }


    int height(node* rot)
    {
        if (rot == NULL)
        {
            return -1;
        }

        int maxl = height(rot->left);
        int maxr = height(rot->right);

        if (maxl >= maxr)
            return maxl + 1;
        else
            return maxr + 1;

    }

    int max(int a, int b) { return (a > b) ? a : b; }


    void level_order(node* root)
    {
        int h = height(root)+1;
        int i;
        int s = cal_size();
        array = new int[s];

        for (int i = 0; i <= s; i++)
            array[i] = -1;


        for (i = 1; i <= h; i++)
              current_level(root, i,1);
    }

    void current_level(node* temp, int l,int val)
    {
        if (temp == NULL)
            array[val] = -1;
        if (l == 1)
        {
            if (temp == NULL)
                array[val] = -1;
            else
                array[val] = temp->data;
        }
        else if (l > 1) {
            if (temp == NULL)
            {
                current_level(NULL, l - 1, 2 * val);
                current_level(NULL, l - 1, 2 * val + 1);
            }
            else
            {
                current_level(temp->left, l - 1, 2 * val);
                current_level(temp->right, l - 1, 2 * val + 1);
            }
        }

    }

    int cal_size()
    {
        int h = height(root);
        int no_nodes = pow(2, (h + 1)) - 1;
        return no_nodes;
    }

    void display()
    {
        int s = cal_size();
        for (int i = 0; i <= s; i++)
        {
            cout << array[i] << " ";
        }

    }

    void preorder(node* temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
        return;
    }

    void insert(int val)
    {

        node* t = new node;
        t->data = val; 

        if (root == NULL)
        {
            root = t;
        }

        else
        {
            node* temp = root;

            while (temp != NULL)
            {

                if (val <= temp->data)
                {
                    if (temp->left)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = t;
                        break;
                    }
                }

                else if (val > temp->data)
                {
                    if (temp->right)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = t;
                        break;
                    }
                }
            }
        }
    }


};

class a_node
{
public:
    int data;
    a_node* Left;
    a_node* Right;
    int Height;
};

class avl
{
public:
    int* array;
    a_node *root;
   
    avl()
    {
        root = NULL;
    }

    int Height(a_node* P)
    {
        if (P == NULL)
            return -1;
        else
            return P->Height;
    }

    int Max(int i, int j)
    {
        if (i >= j)
            return i;
        else
            return j;
      
    }

    void preorder(a_node* temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->Left);
            preorder(temp->Right);
        }
        return;
    }

    a_node* DoubleRotateWithLeft(a_node* K3)
    {
        /* LL rotation between K1 and K2 */
        K3->Left = SingleRotateWithRight(K3->Left);
        /* RR rotation between K3 and K2 */
        return SingleRotateWithLeft(K3);
    }

    a_node* DoubleRotateWithRight(a_node* K1)
    {
        /* RR rotation between K3 and K2 */
        K1->Right = SingleRotateWithLeft(K1->Right);
        /* LL rotation between K1 and K2 */
        return SingleRotateWithRight(K1);
    }

    a_node* SingleRotateWithLeft(a_node* K1) {
        a_node* K2;
        K2 = K1->Left; // K1: node whose balance factor is violated
        K1->Left = K2->Right;
        K2->Right = K1;
        K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
        K2->Height = Max(Height(K2->Left), K1->Height) + 1;
        return K2; /* New root */
    }

    a_node* SingleRotateWithRight(a_node* K1) {
        a_node* K2;
        K2 = K1->Right; // K1: node whose balance factor is violated
        K1->Right = K2->Left;
        K2->Left = K1;
        K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
        K2->Height = Max(Height(K2->Right), K1->Height) + 1;
        return K2; /* New root */
    }

    a_node* Insert(int X, a_node* &T) {
        if (T == NULL) { /* Create and return a one-node tree */
            T = new  a_node;
            T->data = X;
            T->Left = T->Right = NULL;
        }
        else if (X < T->data) {
            T->Left = Insert(X, T->Left);
            if (Height(T->Left) - Height(T->Right) == 2)
                if (X < T->Left->data)
                    T = SingleRotateWithLeft(T); // RR rotation
                else
                    T = DoubleRotateWithLeft(T); // RL rotation

        }
        else if (X > T->data) {
            T->Right = Insert(X, T->Right);
            if (Height(T->Right) - Height(T->Left) == 2)
                if (X > T->Right->data)
                    T = SingleRotateWithRight(T); // LL rotation
                else
                    T = DoubleRotateWithRight(T); // LR rotation
        } /* Else X is in the tree already; we'll do nothing */
        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
        return T;
    }



    int height(a_node* rot)
    {
        if (rot == NULL)
        {
            return -1;
        }

        int maxl = height(rot->Left);
        int maxr = height(rot->Right);

        if (maxl >= maxr)
            return maxl + 1;
        else
            return maxr + 1;

    }

    void level_order(a_node* root)
    {
        int h = height(root) + 1;
        int i;
        int s = cal_size();
        array = new int[s];

        for (int i = 0; i <= s; i++)
            array[i] = -1;


        for (i = 1; i <= h; i++)
            current_level(root, i, 1);
    }

    void current_level(a_node* temp, int l, int val)
    {
        if (temp == NULL)
            array[val] = -1;
        if (l == 1)
        {
            if (temp == NULL)
                array[val] = -1;
            else
                array[val] = temp->data;
        }
        else if (l > 1) {
            if (temp == NULL)
            {
                current_level(NULL, l - 1, 2 * val);
                current_level(NULL, l - 1, 2 * val + 1);
            }
            else
            {
                current_level(temp->Left, l - 1, 2 * val);
                current_level(temp->Right, l - 1, 2 * val + 1);
            }
        }

    }

    int cal_size()
    {
        int h = height(root);
        int no_nodes = pow(2, (h + 1)) - 1;
        return no_nodes;
    }

    void display()
    {
        int s = cal_size();
        for (int i = 0; i <= s; i++)
        {
            cout << array[i] << " ";
        }

    }
};


int main()
{
    tree t1;
    t1.insert(5);
    t1.insert(3);
    t1.insert(6);
    t1.insert(10);
   t1.insert(20);
   t1.insert(21);
   t1.insert(33);
   cout << "  BST " << endl;
   cout << endl;
   cout << "  PREORDER  " << endl;
   t1.preorder(t1.root);
   cout << endl;
   cout << "  ARRAY  " << endl;
   t1.level_order( t1.root );
    t1.display();
    
    cout << endl<<endl;

    avl av;
    av.Insert(10,av.root);
    av.Insert(3, av.root);
    av.Insert(8, av.root);
    av.Insert(20, av.root);
    av.Insert(40, av.root);
    av.Insert(31, av.root);
    av.Insert(53, av.root);
    cout << "  AVL " << endl;
    cout << endl;
    cout << "  PREORDER  " << endl;
    av.preorder(av.root);
    cout << endl;
    cout << "  ARRAY  " << endl;

    av.level_order(av.root);
    av.display();



   
	return 0;
}