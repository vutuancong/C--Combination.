#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct node
{
	int soLan;
	string str;
	int height;
	struct node* left;
	struct node* right;
};

class AVL
{
	public:
		node *Tree;
		node *create_node(string);
		node *insert_node(node *,string);
		node *left_Rotate(node *);
		node *right_Rotate(node *);
		node *search(node *,string);
		int max(int,int);
		int getBalance(node *);
		int height(node *);
		void NLR(node *);
		void function();
		AVL()
		{
			Tree = NULL;
		}
};

int AVL::height(node *Tree)
{
	if(Tree == NULL) return 0;
	return Tree->height;
}
int AVL::getBalance(node *Tree)
{
	if(Tree == NULL ) return 0;
	return (height(Tree->left) - height(Tree->right));
}
void AVL::NLR(node *Tree)
{
	if(Tree != NULL)
	{
		NLR(Tree->left);
		cout<<Tree->str<<" "<<Tree->soLan<<endl;
		NLR(Tree->right);
	}	
}

int AVL::max(int a,int b)
{
	return a > b ? a: b;
}

node *AVL::create_node(string str)
{
	node *temp;
	temp = new node;
	temp->soLan = 1;
	temp->str = str;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

node *AVL::left_Rotate(node *Tree)
{
	node *temp1,*temp2;
	temp1 = Tree->right;
	temp2 = temp1->left;
	temp1->left = Tree;
	Tree->right = temp2;
	Tree->height = max(height(Tree->left),height(Tree->right))+1;
	temp1->height = max(height(temp1->left),height(temp1->right)+1);
	return temp1;
}

node *AVL::right_Rotate(node *Tree)
{
	node *temp1,*temp2;
	temp1 = Tree->left;
	temp2 = temp1->right;
	temp1->right = temp2;
	Tree->left = temp2;
	Tree->height = max(height(Tree->left),height(Tree->right)) +1;
	temp1->height = max(height(temp1->right),height(temp1->left)) +1;
	return temp1;
}

node *AVL::insert_node(node *Tree,string str)
{
	if(Tree == NULL) return create_node(str);
	else
	{
		if(str < Tree->str) Tree->left =  insert_node(Tree->left,str);
		else Tree->right = insert_node(Tree->right,str);
	}
	Tree->height = max(height(Tree->left),height(Tree->right)) +1;	
	
	int balance = getBalance(Tree);
	
	if(balance > 1 && str < Tree->left->str)
	{
		return right_Rotate(Tree);
	}
	if(balance < -1 && str > Tree->right->str)
	{
		return left_Rotate(Tree);
	}
	if(balance > 1 && str > Tree->left->str)
	{
		Tree->left = left_Rotate(Tree);
		return right_Rotate(Tree);
	}
	if(balance <-1 && str < Tree->right->str)
	{
		Tree->right =right_Rotate(Tree);
		return left_Rotate(Tree);
	}
	return Tree;
}

node *AVL::search(node *Tree,string str)
{
	if(Tree == NULL || Tree->str ==  str) return Tree;
	else
	{
		if(Tree->str > str) return search(Tree->left,str);
		else return search(Tree->right,str);
	}
}

void AVL::function()

{
	fstream f;
	f.open("demtu.txt",ios::in );
	string str;
	while(!f.eof())
	{
		f>>str;
//		cout<<str<<" ";
		node *temp = search(Tree,str);
		if(temp == NULL) Tree = insert_node(Tree,str);
		else temp->soLan++;
	}
	NLR(Tree);
}
int main()
{
	AVL X;
	X.function();
}
