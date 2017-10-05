#include <iostream>

using namespace std;

struct node
{
	int info;
	int height;
	struct node *left;
	struct node *right;
};

class AVL
{
	public:
		node *Tree;
		node *create_node(int );
		node *insert_node(node *,int);
		node *search_node(node *,int );
		node *rotate_right(node *);
		node *rotate_left(node *);
		node *delete_node(node *,int);
		node *min_node_value(node *);
		int height(node *);
		int getBalance(node *);
		int max(int ,int );
		void NLR(node *);
		void LNR(node *);
		void LRN(node *);
		void function();
	AVL()
	{
		Tree = NULL;
	}
};

node *AVL::create_node(int value)
{
	node *temp;
	temp = new node;
	temp->info = value;
	temp->height = 1;
	temp->left = NULL;
	temp->right =NULL;
	return temp;
}

node *AVL::rotate_left(node *Tree)
{
	node *temp = Tree;
	if(Tree == NULL || Tree->right == NULL) return Tree;
	else
	{
		temp = Tree->right;
		Tree->right = temp->left;
		temp->left = Tree->right;
		temp->height = max(height(temp->left),height(temp->right)) + 1;
		Tree->height = max(height(temp->left),height(temp->right)) + 1;		
		return temp;
	}
}

node *AVL::rotate_right(node *Tree)
{
	node *temp = Tree;
	if(Tree == NULL) return Tree;
	if(Tree->left == NULL) return Tree;
	else
	{
		temp =Tree->left;
		Tree->left = temp->right;
		Tree->right =temp->left;
		temp->height = max(height(temp->left),height(temp->right)) + 1;
		Tree->height = max(height(temp->left),height(temp->right)) + 1;
		return temp;
	}
}
int AVL::height(node *Tree)
{
	if(Tree == NULL) return 0;
	return Tree->height;
}

int AVL::getBalance(node *Tree)
{
	if(Tree ==  NULL) return 0;
	else
	{
		return height(Tree->left) - height(Tree->right);
	}
}

int AVL::max(int a,int b)
{
	return (a > b) ? a:b;
}
void AVL::NLR(node *Tree)
{
	if(Tree != NULL)
	{
		cout<<Tree->info<<"->";
		NLR(Tree->left);
		NLR(Tree->right);
	}
}
void AVL::LNR(node *Tree)
{
	if(Tree != NULL)
	{
		LNR(Tree->left);
		cout<<Tree->info<<"->";
		LNR(Tree->right);
	}
}
void AVL::LRN(node *Tree)
{
	if(Tree != NULL)
	{
		LRN(Tree->left);
		LRN(Tree->right);
		cout<<Tree->info<<"->";
	}
}
node *AVL::insert_node(node *Tree,int value)
{
	if(Tree ==  NULL) return (create_node(value));
	else 
	{
		if(Tree->info > value) Tree->left = insert_node(Tree->left,value);
		else Tree->right = insert_node(Tree->right,value);
	}
	Tree->height = max(height(Tree->left),height(Tree->right)) + 1;
	
	int balance = getBalance(Tree);
	if(balance > 1 && value < Tree->left->info) return rotate_right(Tree);//
	if(balance < -1 && value > Tree->right->info) return rotate_left(Tree);//
	if(balance > 1 && value > Tree->left->info)
	{
		Tree->left = rotate_left(Tree);
		return rotate_right(Tree);
	}
	if(balance < -1 && value < Tree->right->info)
	{
		Tree->right = rotate_right(Tree);
		return rotate_left(Tree);
	}
}

node *AVL::min_node_value(node *Tree)
{
	int flag = Tree->info;
	if(Tree->left->info > flag) return min_node_value(Tree->left);
	else return min_node_value(Tree->right);
}

node *AVL::delete_node(node *Tree,int value)
{
	if(Tree == NULL) return Tree;
	if(Tree->info > value) Tree->left = delete_node(Tree->left,value);
	else if(Tree->info < value) Tree->right = delete_node(Tree->right,value);
	else
	{
		if(Tree->left != NULL)
		{
			node *temp = Tree;
			temp = Tree->right;
			return temp;
		}
		else if (Tree->right != NULL)
		{
			node *temp = Tree;
			temp = Tree->left;
			return temp;
		}
		node *temp = min_node_value(Tree);
		Tree->info  = temp->info;
		delete_node(Tree,temp->info);
		return Tree;		
	}
	Tree->height = max(height(Tree->left),height(Tree->right)) - 1;
	int balance  = getBalance(Tree);
	if(balance > 1 && value <Tree->left->info) return rotate_right(Tree);
	if(balance <-1 && value >Tree->right->info) return rotate_left(Tree);
	if(balance > 1 && value > Tree->left->info)
	{
		Tree->left =  rotate_left(Tree);
		return rotate_right(Tree);
	}
	if(balance < -1 && value < Tree->right->info)
	{
		Tree->right = rotate_right(Tree);
		return rotate_left(Tree);
	}
}

void AVL::function()
{
	int choice;
	int value;
	do
	{
		cout<<"Thao tac voi cay tim kiem can bang"<<endl;
		cout<<"1.Them node"<<endl;
		cout<<"2.NLR"<<endl;
		cout<<"3.LNR"<<endl;
		cout<<"4.LRN"<<endl;
		cout<<"Nhap lua chon"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:	
				cout<<"Nhap gia tri can them: ";cin>>value;
				Tree = insert_node(Tree,value);
				break;
			case 2:
				NLR(Tree);break;
			case 3:
				LNR(Tree);break;
			case 4:
				LRN(Tree);break;
				
		}
	}while(choice!= 0);
}
int main()
{
	AVL X;
	X.function();
}
