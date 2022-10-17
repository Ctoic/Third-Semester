#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class node
{
public:
	string url;
	string data;
	node* right;
	node* left; 


	node()
	{
		right = NULL;
		left = NULL;
	}


};



class bst
{

public:

	node* root;

	bst()
	{
		root = NULL;
	}


	void insert(string tok,string ur)
	{
		
		node* temp = new node;
		temp->data = tok;
		temp->url = ur;

		node* curr = root;
		bool attached = false;

		if (curr == NULL)
		{
			root = temp;
		}

		else
		{

			while (curr != NULL && !attached)
			{
				if (temp->data < curr->data )
				{
					
					if (curr->left != NULL)
					{
						curr = curr->left;
					}
					else
					{
						curr->left = temp;
						attached = true;
					}
				}   

				else if (temp->data >= curr->data )
				{
					
					if (curr->right != NULL)
					{
						curr = curr->right;
					}
					else
					{
						curr->right = temp;
						attached = true;
					}
				}

 			}
		}
	}


	void search(string token)
	{
		node* curr = root;
		int count = 1;
		bool found = false;
		while (curr)
		{

			if (token == curr->data)
			{
				cout << count << "> ";
				cout << curr->url << endl;
				curr = curr->right;
				count++;
				found = true;
			}

			else if (token < curr->data)
			{
					curr = curr->left;
			}

			else if (token >= curr->data)
			{
				curr = curr->right;
			}

		}

		if (!found)
			cout << "NOT FOUND" << endl;

	}

	};

	void makeDeletion(node*& nodePtr) 
	{
		node* tempNodePtr; // Temperary pointer
		if (nodePtr->right == NULL) { // case for leaf and one (left) child
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left; // Reattach the left child
			delete tempNodePtr;
		}
		else if (nodePtr->left == NULL) { // case for one (right) child
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right; // Reattach the right child
			delete tempNodePtr;
		}
		else { // case for two children.
			tempNodePtr = nodePtr->right; // Move one node to the right
			while (tempNodePtr->left) { // Go to the extreme left node
				tempNodePtr = tempNodePtr->left;
			}
			tempNodePtr->left = nodePtr->left; // Reattach the left subtree
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right; // Reattach the right subtree
			delete tempNodePtr;
		}
	}


	void deleteNode(string token, node*& nodePtr)
	{
		if (nodePtr == NULL) // node does not exist in the tree
			return;	//cout << token << "not found.\n";
		else if (token < nodePtr->data)
			deleteNode(token, nodePtr->left); // find in left subtree
		else if (token > nodePtr->data)
			deleteNode(token, nodePtr->right); // find in right subtree
		else// if (token == nodePtr->data)
		{
			makeDeletion(nodePtr); // actually deletes node from BST
			if (nodePtr)
				deleteNode(token, nodePtr);
		}

	}


void display(node* root)
{
	if (root != NULL)
	{
		display(root->left);
		cout << root->data << " ";
		display(root->right);
	}
}




int main()
{

	string url, text, skip;
	string token,link,file_name;

	int pos_space;

	bst tree;


	cout << "ENTER FILE NAME" << endl;
	cin >> file_name;

	fstream file;
	file.open(file_name, ios::in);

		if (file)
		{


		while (file)
			{
				getline(file, url);
				getline(file, text);
				getline(file, skip);

				string link;
				pos_space = url.find(' ', 0);
				url.erase(0, ++pos_space);
				link = url;
	
				while (text != "\n")
				{
					pos_space = text.find(' ', 0);
					token = text.substr(0, pos_space);
					text.erase(0, ++pos_space);

					if (pos_space )
					{
						tree.insert(token, link);
					}

					else
						break;
				}
				
			}
		}

		else 
		{
			cout << "UNABLE TO OPEN FILE" << endl;
			return 0;
		}

		int optn;

		do {
			cout << endl;
			cout << endl;
			cout << endl;

			cout << "ENTER 1 TO SEARCH WORD" << endl;
			cout << "ENTER 2 TO DELETE WORD" << endl;
			cout << "ENTER 3 TO DISPLAY BST" << endl;
			cout << "ENTER 4 TO EXIT" << endl;

			cin >> optn;

			if (optn == 1)
			{
				string wrd;

				cout << "ENTER WORD TO SEARCH" << endl;
				cin >> wrd;
				tree.search(wrd);
			}

			else if (optn == 2)
			{
				string wrd;

				cout << "ENTER WORD TO DELETE" << endl;
				cin >> wrd;

				deleteNode(wrd, tree.root);

			}

			else if (optn == 3)
			{
				display(tree.root);

			}

			else
				return 0;

		} while (optn != 4);

	return 0;
}