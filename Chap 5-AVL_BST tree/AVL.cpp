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
		node *rightRotate(node *);
		node *leftRotate(node *);
		node *deleteNode(node *,int );
		node *insert(node * ,int );
		node *search(node *,int );
		node *minNodeValue(node *);
		int max(int ,int );
		int getBalance(node *);
		int height(node *);
		void function();
		void NLR(node *);
		void LNR(node *);
		void LRN(node *);
		AVL()
		{
			Tree= NULL;
		}
};

node *AVL::leftRotate(node *Tree)
{
	node *temp1 = Tree->right;
	node *temp2 = temp1->left;
	temp1->left = Tree;
	Tree->right = temp2;
	Tree->height = max(height(Tree->left),height(Tree->right)) + 1;
	temp1->height = max(height(temp1->left),height(temp1->right)) + 1;
	return temp1;
	
}

node *AVL::rightRotate(node *Tree)
{
	node *temp1 = Tree->left;
	node *temp2 = temp1->right;
	Tree->left = temp2;
	temp1->left = temp2;
	Tree->height = max(height(Tree->left),height(Tree->right)) + 1;
	temp1->height =max(height(temp1->left),height(temp1->right)) +1;
	return temp1;
}
node *AVL::insert(node *Tree,int value)
{
	if(Tree == NULL) return create_node(value);
	else
	{
		if(Tree->info > value) Tree->left = insert(Tree->left, value);
		else Tree->right = insert(Tree->right ,value);
	}
	Tree->height = max(height(Tree->left),height(Tree->right)) +1;
	int balance = getBalance(Tree);
	if(balance > 1 && value < Tree->left->info)
	{
		return rightRotate(Tree);
	}
	if(balance < -1 && value > Tree->right->info)
	{
		return leftRotate(Tree);
	}
	if(balance > 1 && value > Tree->left->info)
	{
		Tree->left = leftRotate(Tree);
		return rightRotate(Tree);
	}
	if(balance < -1 && value > Tree->right->info)
	{
		Tree->right =rightRotate(Tree);
		return leftRotate(Tree);
	}
	cout<<height(Tree->left)<<" "<<height(Tree->right)<<endl;
	return Tree;
}

node *AVL::minNodeValue(node *Tree)
{
	int flag = Tree->info;
	if(Tree->info > flag)	return minNodeValue(Tree->left);
	return minNodeValue(Tree->right);
	
}

node *AVL::deleteNode(node *Tree,int value)
{
	if(Tree == NULL) return Tree;
	if(value < Tree->info) Tree->left = deleteNode(Tree->left,value);
	else if( value >Tree->info) Tree->right = deleteNode(Tree->right,value);
	else
	{
		if(Tree->left == NULL || Tree->right ==NULL)
		{
			node *temp = Tree->left ? Tree->left: Tree->right;
			if(temp = NULL)
			{
				temp = Tree;
				Tree = NULL;
			}
			else Tree = temp;
			delete(temp);
		}
		else
		{
			node *temp = minNodeValue(Tree);
			Tree->info = temp->info;
			Tree->right = deleteNode(Tree->right,temp->info);
		}
	}
	if(Tree == NULL) return Tree;
	Tree->height = max(height(Tree->left),height(Tree->right)) + 1;
	int balance = getBalance(Tree);
	if(balance > 1 && getBalance(Tree->left) >= 0)
	return rightRotate(Tree);
	if(balance < -1 && getBalance(Tree->right) >= 0)
	return leftRotate(Tree);
	if(balance > 1 && getBalance(Tree->right) > 0)
	{
		Tree->right = rightRotate(Tree);
		return leftRotate(Tree);
	}
	if(balance < -1 && getBalance(Tree->left) > 0)
	{
		Tree->left = leftRotate(Tree);
		return leftRotate(Tree);
	}
	return Tree;
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
void AVL::LRN(node *Tree)
{
	if(Tree!= NULL)
	{
		NLR(Tree->left);
		NLR(Tree->right);
		cout<<Tree->info<<"->";
	}
}
void AVL::LNR(node *Tree)
{
	if(Tree!= NULL)
	{
		LNR(Tree->left);
		cout<<Tree->info<<"->";
		LNR(Tree->right);
	}
}

node *AVL::create_node(int value)
{
	node *temp;
	temp=  new node;
	temp->height = 1;
	temp->info = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int AVL::height(node *Tree)
{
	if(Tree == NULL) return 0;
	return Tree->height;	
}

int AVL::max(int a,int b)
{
	return (a>b) ? a : b;
}

int AVL::getBalance(node *Tree)
{
	if(Tree == NULL) return 0;
	return (height(Tree->left) - height(Tree->right));
}

node *AVL::search(node *Tree,int value)
{
	if(Tree == NULL || Tree->info == value ) return Tree;
	else
	{
		if(value < Tree->info)
		return search(Tree->left,value);
		else 
		return search(Tree->right,value);
	}
}

void AVL::function()
{
	int choice;
	int value;
	node *temp;
	do
	{
		cout<<"Thao tac cay AVL"<<endl;
		cout<<"1.Nhap node vao cay"<<endl;
		cout<<"2.NLR"<<endl;
		cout<<"3.LNR"<<endl;
		cout<<"4.LRN"<<endl;
		cout<<"5.Tim kiem 1 node"<<endl;
		cout<<"6.Xoa node"<<endl;
		cout<<"Nhap lua chon: ";cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Nhap gia tri vao node: ";cin>>value;
				Tree = insert(Tree,value);break;
			case 2:
				cout<<"Hien thi node theo NLR"<<endl;
				NLR(Tree);break;
			case 3:
				cout<<"Hien thi node theo LNR"<<endl;
				LNR(Tree);break;
			case 4:
				cout<<"Hien thi node theo LRN"<<endl;
				LRN(Tree);break;
			case 6:
				cout<<"Nhap gia tri can xoa: ";cin>>value;
				Tree = deleteNode(Tree,value);break;
			case 5:
				cout<<"Nhap gia tri tim kiem: ";cin>>value;
				node *temp = search(Tree,value);
				if(temp == NULL) cout<<"Khong co "<<value<<" trong cay"<<endl;
				else cout<<"Co gia tri "<<temp->info<<" trong cay"<<endl;
				break;
		}
		
	}while(choice != 0);
}
int main()
{
	AVL X;X.function();
}
