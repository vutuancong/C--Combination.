#include <iostream>

using namespace std;

struct node
{
	int info;
	struct node *left;
	struct node *right;
};

class BST
{
	public:
		node *Tree;
		node *create_node(int);
		node *insert_node(node *,int);
		node *delete_node(node *,int);
		node *search_node(node *,int);
		node *min_node_value(node*);
		void LNR(node *);
		void NLR(node *);
		void LRN(node *);
		void function();
		BST()
		{
			Tree = NULL;
		}
};

node *BST::create_node(int value)
{
	node *temp;
	temp = new node;
	temp->info = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node *BST::insert_node(node *Tree,int value)
{
	if(Tree == NULL) Tree = create_node(value);
	else
	{
		if(Tree->info >value) Tree->left = insert_node(Tree->left,value);
		else Tree->right = insert_node(Tree->right,value);
	}
	return Tree;
}
node *BST::search_node(node *Tree,int value)
{
	if(Tree == NULL || Tree->info == value) return Tree;
	else
	{
		if(value>Tree->info) return search_node(Tree->right,value);
		else return search_node(Tree->left,value);
	}
}
node *BST::min_node_value(node *Tree)
{
	int flag = Tree->info;
	if(flag >Tree->left->info) return min_node_value(Tree->right);
	else return min_node_value(Tree->left);
}
node *BST::delete_node(node *Tree,int value)
{
	if(Tree == NULL) return Tree;
	if(Tree->info < value) Tree->right = delete_node(Tree->right,value);
	else if(Tree->info > value)
		Tree->left = delete_node(Tree->left,value);
	else
	{
		if(Tree->left == NULL)
		{
			node *temp = Tree->left;
			delete Tree;
			return temp;
		}
		else if(Tree->right == NULL)
		{
			node *temp = Tree->right;
			delete Tree;
			return temp;
		}
		node *temp = min_node_value(Tree->right);
		Tree->info = temp->info;
		Tree->right = delete_node(Tree->right,temp->info);
	}
	return Tree;
}

void BST::LNR(node *Tree)
{
	if(Tree != NULL)
	{
		LNR(Tree->left);
		cout<<Tree->info<<endl;
		LNR(Tree->right);
	}
}

void BST::NLR(node *Tree)
{
	if(Tree!=NULL)
	{
		cout<<Tree->info<<endl;
		NLR(Tree->left);
		NLR(Tree->right);
	}
}
void BST::LRN(node *Tree)
{
	if(Tree!= NULL)
	{
		LRN(Tree->left);
		LRN(Tree->right);
		cout<<Tree->info<<endl;
	}
}
void BST::function()
{
	int value;
	int choice;
	do
	{
		cout<<"Thao tac voi cay nhi phan"<<endl;
		cout<<"1.Chen node"<<endl;
		cout<<"2.Xoa node"<<endl;
		cout<<"3.Tim kiem node"<<endl;
		cout<<"4.LNR"<<endl;
		cout<<"5.NLR"<<endl;
		cout<<"6.LRN"<<endl;
		cout<<"Nhap lua chon: ";cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Nhap gia tri can chen: ";cin>>value;
				Tree  = insert_node(Tree,value);break;
			case 2:
				cout<<"Xoa node"<<endl;
				cout<<"Nhap gia tri can xoa";cin>>value;
				Tree = delete_node(Tree,value);
				break;
			case 4:
				cout<<"Duyet LNR"<<endl;
				LNR(Tree);break;
			case 5:
				cout<<"Duyet NLR"<<endl;
				NLR(Tree);break;
			case 6:
				cout<<"Duyet LRN"<<endl;
				LRN(Tree);break;
			case 3:
				cout<<"Tim kiem node: ";cin>>value;
				node *temp = search_node(Tree,value);
				if(Tree == NULL) cout<<"Node "<< value<<" khong co trong cay"<<endl;
				else
					cout<<"Node "<<temp->info<<" co trong cay"<<endl;
				break;
		}
	}
	while(choice!=0);
}
int main()
{
	BST X;
	X.function();
}
