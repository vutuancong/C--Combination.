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
		node *search_node(node *,int );
		node *insert_node(node *,int );
		node *delete_node(node *,int );
		node *min_value_node(node *);
		void LRN(node *);
		void LNR(node *);
		void NLR(node *);
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
	if(Tree == NULL) return create_node(value);
	else
	{
		if(Tree->info > value) Tree->left = insert_node(Tree->left,value);
		else Tree->right = insert_node(Tree->right,value);
	}
	return Tree;
}

node *BST::search_node(node *Tree,int value)
{
	if(Tree == NULL || Tree->info == value) return Tree;
	if(Tree->info < value) return search_node(Tree->right,value);
	return search_node(Tree->left,value);
}

void BST::NLR(node *Tree)
{
	if(Tree!=  NULL)
	{
		cout<<Tree->info<<endl;
		NLR(Tree->left);
		NLR(Tree->right);
		
	}
}

void BST::LNR(node *Tree)
{
	if(Tree!= NULL)
	{
		LNR(Tree->left);
		cout<<Tree->info<<endl;
		LNR(Tree->right);
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

node *BST::min_value_node(node *Tree)
{
	int flag = Tree->info;
	if((Tree->left)->info > flag) return min_value_node(Tree->left);
	return min_value_node(Tree->right);	
}

node *BST::delete_node(node *Tree,int value)
{
	if(Tree == NULL) return Tree;
	if(value < Tree->info) Tree->left = delete_node(Tree->left,value);
	else if(value > Tree->info)  Tree->right = delete_node(Tree->right,value);
	else
	{
		if(Tree->left == NULL)
		{
			node *temp = Tree->right;
			delete Tree;
			return temp;
		}
		else
		{
			if(Tree->right == NULL)
			{
				node *temp = Tree->left;
				delete(Tree);
				return temp;
			}
		}
		node *temp = min_value_node(Tree->right);
		Tree->info = temp->info;
		Tree->right = delete_node(Tree->right,temp->info);
	}
	return Tree;
}
void BST::function()
{
	int choice,value;
	do
	{
		cout<<"Thao tac voi cay nhi phan"<<endl;	
		cout<<"1.Them 1 gia tri"<<endl;
		cout<<"2.Tim kiem 1 gia tri"<<endl;
		cout<<"3.Duyet theo Node-Left-Right"<<endl;
		cout<<"4.Duyet theo Left-Node-Right"<<endl;
		cout<<"5.Duyet theo Left-Right-Node"<<endl;
		cout<<"6.Xoa node"<<endl;
		cout<<"-Nhap lua chon: ";cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Gia tri can them: ";cin>>value;
				Tree = insert_node(Tree,value);break;
			case 2:
				node *temp;
				cout<<"Nhap gia tri tim kiem ";cin>>value;
				temp = search_node(Tree,value);
				if(temp== NULL) cout<<"Khong co gia tri "<<value<<" tren cay"<<endl;
				else
				cout<<"Node "<<temp->info<<" co tren cay"<<endl;
				break;
			case 3:
				NLR(Tree);break;
			case 4:
				LNR(Tree);break;
			case 5:
				LRN(Tree);break;
			case 6:
				cout<<"Nhap gia tri can xoa ";cin>>value;
				delete_node(Tree,value);break;
		}
	}while(choice != 0);
}

int main()
{
	BST X;
	X.function();
}
