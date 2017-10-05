#include <iostream>
#include <fstream>

using namespace std;

struct node 
{
	int info;
	struct node *left;
	struct node *right;
}*Tree;

class BST
{
	public:
		node *create(int value);
		node *insert_node(node *,int);
		void NLR(node *Tree,int value,int &);
		BST()
		{
			Tree = NULL;
		}
};
node *BST::create(int value)
{
	node *temp = new node;
	temp->info = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node *BST::insert_node(node *Tree,int value)
{
	if(Tree == NULL) return create(value);
	else
	{
		if(value <Tree->info) Tree->left = insert_node(Tree->left,value);
		else
		Tree->right = insert_node(Tree->right,value);
	}
	return Tree;
}
void BST::NLR(node *Tree,int value,int &dem)
{
	if(Tree != NULL) 
	{
		if(Tree->info == value) dem++;
		NLR(Tree->left,value,dem);
		NLR(Tree->right,value,dem);
	}
}
void function()
{
	int n,m,flag = 0;
	fstream f;
	f.open("baitap.txt",ios::in);
	f>>n;
	for(int i = 0;i<n;i++)
	{
		flag = 0;
		f>>m;
		BST X;
		for(int j = 0;j<m;j++)
		{
			int dem = 0,value;
			f>>value;
			Tree = X.insert_node(Tree,value);
			X.NLR(Tree,value,dem);
			if(dem > m/2) 
			{
				flag = 1;
				cout<<"YES"<<endl;
				break;
			}
		}
		if(flag == 0) cout<<"NO"<<endl;
	}
}
int main()
{
	function();
}
