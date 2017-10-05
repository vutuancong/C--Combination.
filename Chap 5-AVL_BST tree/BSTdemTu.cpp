#include <iostream>
#include <fstream>
using namespace std;

struct node 
{
	string kt;
	int solan;
	struct node *left;
	struct node *right;
};

class BST
{
	public:
		node *Tree;
		node *create_node(string);
		node *insert_node(node *,string);
		node *search_node(node *,string);
		void function();
		void NLR(node *);
		BST()
		{
			Tree = NULL;
		}
};
node *BST::create_node(string str)
{
	node *temp = new node;
	temp->kt = str;
	temp->solan = 1;
	temp->left = NULL;
	temp->right =NULL;
	return temp;
}
node *BST::insert_node(node *Tree,string str)
{
	if(Tree==NULL) return create_node(str);
	else
	{
		if(Tree->kt > str) Tree->left = insert_node(Tree->left,str);
		else Tree->right = insert_node(Tree->right,str);
	}
	return Tree;
}

node *BST::search_node(node *Tree,string str)
{
	if(Tree== NULL || Tree->kt == str) return Tree;
	if(Tree->kt >str) return search_node(Tree->left,str);
	else return search_node(Tree->right,str);
}

void BST::function()
{
	fstream f;
	f.open("demTu.txt",ios::in);
	string str;
	while(!f.eof())
	{
		f>>str;
//		cout<<str<<" ";
		node *temp= search_node(Tree,str);
		if(temp != NULL) temp->solan++;
		else
		Tree = insert_node(Tree,str);
	}
	NLR(Tree);
}

void BST::NLR(node *Tree)
{
	if(Tree!= NULL)
	{
		NLR(Tree->left);
		cout<<Tree->kt<<" "<<Tree->solan<<endl;
		NLR(Tree->right);
	}
}

int main()
{
	BST X;
	X.function();
}
