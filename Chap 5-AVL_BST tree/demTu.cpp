#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct node 
{
	string str;
	int soLan;
	struct node *left;
	struct node *right;	
};
class Tu
{
	public:
		node *Tree;
		node *create_node(string ,int );
		node *search_node(node *,string);
		node *insert_node(node *,string);
		int size_node(node *);
		void NLR(node *);
		void function();
		void result();
		Tu()
		{
			Tree = NULL;
		}
};
node *Tu::create_node(string str,int value)
{
	node *temp;
	temp =  new node;
	temp->str = str;
	temp->soLan = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node *Tu::insert_node(node *Tree,string str)
{
	if(Tree == NULL) return Tree = create_node(str,1);
	else
	{
		if(Tree->str > str) Tree->left = insert_node(Tree->left,str);
		else Tree->right = insert_node(Tree->right,str);	
	}
	return Tree;
}
node *Tu::search_node(node *Tree,string str)
{
	if(Tree== NULL || Tree->str  ==  str) return Tree;
	if(Tree->str >str) return search_node(Tree->left,str);
	return search_node(Tree->right,str);
}
void Tu::NLR(node *Tree)
{
	if(Tree!= NULL)
	{
		cout<<Tree->str<<" "<<Tree->soLan<<endl;
		NLR(Tree->left);
		NLR(Tree->right);
	}
}
void Tu::function()
{
	node *temp;
	string str;
	fstream f;
	f.open("demtu.txt",ios::in);
	while(!f.eof())
	{
		f>>str;
		cout<<str<<" ";
		temp = search_node(Tree,str);
		if(temp != NULL) temp->soLan++;
		else Tree = insert_node(Tree,str);
	}
	NLR(Tree);
}
int main()
{
	Tu X;
	X.function();
}
