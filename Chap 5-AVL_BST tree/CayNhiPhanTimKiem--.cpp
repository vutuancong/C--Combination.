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
		node *min_node_value(node *);
		node *search_node(node *, int);
		node *delete_node(node *,int);
		node *insert_node(node *,int);
		node *rotateleft(node *);
		node *rotateright(node *);
		void NLR(node *Tree);
		void LNR(node *Tree);
		void LRN(node *Tree);
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
	node *temp,*s;
	temp = s = Tree;
	if(Tree == NULL) 
	{
		Tree = create_node(value);
		return Tree;
	}
	while(temp->info != value && s!= NULL)
	{
		temp = s;
		if(temp->info < value)
			s = temp->right;
		else
			s = temp->left;
	}
	if(temp->info == value) return Tree;
	if(value >temp->info ) temp->right = create_node(value);
	else temp->left = create_node(value);
	return Tree;
}
node *BST::search_node(node *Tree, int value)
{
	node *temp = Tree;
	while(temp!= NULL)
	{
		if(temp->info == value) return temp;
		if(temp->info > value) temp = temp->left;
		else temp = temp->right;
	}
	return temp;
}
void BST::NLR(node *Tree)
{
	if(Tree!= NULL)
	{
		cout<<Tree->info<<"->";
		NLR(Tree->left);
		NLR(Tree->right);
	}
}
void BST::LNR(node *Tree)
{
	if(Tree!=  NULL)
	{
		LNR(Tree->left);
		cout<<Tree->info<<"->";
		LNR(Tree->right);
	}
}
void BST::LRN(node *Tree)
{
	if(Tree!=  NULL)
	{
		LRN(Tree->left);
		LRN(Tree->right);
		cout<<Tree->info<<"->";
	}
}
node *BST::min_node_value(node *Tree)
{
	int flag = Tree->info;
	if(flag > (Tree->right)->info) return min_node_value(Tree->right);
	return min_node_value(Tree->left);
}
node *BST::delete_node(node *Tree,int value)
{
	if(Tree == NULL) return Tree;
	else
	{
		if(value<Tree->info) Tree->left = delete_node(Tree->left,value);
		else if(value>Tree->info) Tree->right = delete_node(Tree->right,value);
		else
		{
			if(Tree->left== NULL)
			{
				node *temp = Tree->right;
				delete Tree;
			 	return temp;
			}
			else if(Tree->right == NULL )
			{	
				node *temp = Tree->left;
				delete Tree;
				return temp;
			}
			node *temp = min_node_value(Tree);
			Tree->info = temp->info;
			delete_node(Tree->right,temp->info);
		}
	}
}

node *BST::rotateleft(node *Tree)
{
	node *temp = Tree;
	if(Tree == NULL) return Tree;
	else if(Tree->right == NULL) return Tree;	
	else
	{
		temp = Tree->right;
		Tree->right = temp->left;
		temp->left = Tree;
		return temp;
	}
}

node *BST::rotateright(node *Tree)
{
	node *temp = Tree;
	if(Tree == NULL) return Tree;
	else if(Tree->left == NULL) return Tree;
	else
	{
		temp = Tree->left;
		Tree->left = temp->right;
		temp->right = Tree;
		return temp;
	}
}

void BST::function()
{
	int choice;
	int value;
	do
	{
		cout<<"Thao tac voi cay nhi phan tim kiem"<<endl;
		cout<<"1.Them node"<<endl;
		cout<<"2.Tim kiem node"<<endl;
		cout<<"3.NLR"<<endl;
		cout<<"4.LNR"<<endl;
		cout<<"5.LRN"<<endl;
		cout<<"6.Xoa 1 node"<<endl;
		cout<<"7.Xoay trai"<<endl;
		cout<<"8.Xoay phai"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Nhap them gia tri moi: ";
				cin>>value;
				Tree = insert_node(Tree,value);break;
			case 3:
				NLR(Tree);break;
			case 4:
				LNR(Tree);break;
			case 5:
				LRN(Tree);break;
			case 6:
				cout<<"Nhap node can xoa: ";
				cin>>value;
				Tree = delete_node(Tree,value);
				break;
			case 7:
				Tree =  rotateleft(Tree);break;
			case 8:
				Tree = rotateright(Tree);break;
			case 2:
				cout<<"Nhap gia tri can tim: ";
				cin>>value;
				node *temp =  search_node(Tree,value);
				if(temp->info == value) cout<<"Gia tri "<<value<<" co trong node"<<endl;
				else cout<<"Gia tri "<<value<<"khong co trong node"<<endl;
				break;
	
		}
		
	}while(choice != 0);
}
int main()
{
	BST X;
	X.function();
}
