#include <iostream>
using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
};

class Binary_Tree
{
	public:
		node *Tree;
		node *create_node();
		void make_root();
		void add_left(node *,int );
		void add_right(node *,int );
		void delete_left(node *,int);
		void delete_right(node *,int);
		void delete_tree(node *);
		void node_left_right(node *);
		void left_node_right(node *);
		void left_right_node(node *);
		void function();
		Binary_Tree()
		{
			Tree = NULL;
		}
};

node *Binary_Tree::create_node()
{
	node *temp;
	temp = new node;
	if(temp== NULL)
	{
		cout<<"Khong du bo nho de chua";
		return 0 ;
	}
	else
	{
		int value;
		cout<<"Nhap gia tri moi: ";cin>>value;
		temp->info = value;
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
}
void Binary_Tree::make_root()
{
	if(Tree != NULL)
	{
		cout<<"Da xay dung cay "<<endl;
	}
	else
	{
		node *temp;
		temp = create_node();
		Tree = temp;
		temp->left = NULL;
		temp->right = NULL;
	}
}
void Binary_Tree::add_left(node *Tree,int value)
{
	if(Tree!= NULL) 
	{
		node *temp;
		if(Tree->info == value)
		{
			if(Tree->left != NULL)
			{
				cout<<"Node "<<value<<" da co node trai"<<endl;
				return;
			}
			else
			{
				temp = create_node();
				Tree->left = temp;
				return;
			}
		}
		add_left(Tree->left,value);
		add_left(Tree->right,value);
	}
}
void Binary_Tree::add_right(node *Tree,int value)
{
	if(Tree!=NULL)
	{
		if(Tree->info ==  value)
		{
			if(Tree->right!= NULL)
			{
				cout<<"Da co gia tri"<<endl;
				return;
			}
			else
			{
				Tree->right = create_node();
				return;
			}
		}
		add_right(Tree->right,value);
		add_right(Tree->left,value);
	}
}
void Binary_Tree::delete_left(node *Tree,int value)
{
	if(Tree!= NULL)
	{
		if(Tree->info == value)
		{
			if(Tree->left == NULL)
			{
				cout<<"Khong co node de xoa"<<endl;
				return;
			}
			else if((Tree->left)->left != NULL || (Tree->left)->right!= NULL)
			{
				cout<<"Node "<<value<<" co cay con trai"<<endl;
				return;
			}
			else
			{
				node *temp;
				temp = Tree->left;
				Tree->left = NULL;
				delete temp;
				return;
			}
		}
		delete_left(Tree->left,value);
		delete_left(Tree->right,value);
	}
}
void Binary_Tree::delete_right(node *Tree,int value)
{
	if(Tree!= NULL)
	{
		if(Tree->info == value)
		{
			if(Tree->right == NULL)
			{
				cout<<"Node "<<value<<" khong co node phai"<<endl;
				return;
			}
			else if(Tree->right->right != NULL || Tree->right->left != NULL)
			{
				cout<<"Node "<<value<<" dang la node cha"<<endl;
				return;
			}
			else
			{
				node *temp;
				temp = Tree->right;
				Tree->right =NULL;
				delete temp;
				return;
			}
		}
	}
}
void Binary_Tree::delete_tree(node *Tree)
{
	if(Tree != NULL)
	{
		delete_tree(Tree->left);
		delete_tree(Tree->right);
		cout<<"Node da duoc giai phong "<<Tree->info<<endl;
		delete(Tree);
	}
}
void Binary_Tree::node_left_right(node *Tree)
{
	if(Tree!= NULL)
	{
		cout<<Tree->info<<" "<<endl;
		node_left_right(Tree->left);
		node_left_right(Tree->right);
	}
}
void Binary_Tree::left_node_right(node *Tree)
{
	if(Tree!= NULL)
	{
		left_node_right(Tree->left);
		cout<<Tree->info<<" "<<endl;
		left_node_right(Tree->right);
	}
}
void Binary_Tree::left_right_node(node *Tree)
{
	if(Tree!= NULL)
	{
		left_right_node(Tree->left);
		left_node_right(Tree->right);
		cout<<Tree->info<<" "<<endl;
	}
}
void Binary_Tree::function()
{
	int choice,value;
	do
	{
		cout<<"Thao tac voi cay nhi phan"<<endl;
		cout<<"1.Tao node goc cho cay"<<endl;
		cout<<"2.Tao node trai cho cay"<<endl;
		cout<<"3.Tao node phai cho cay"<<endl;
		cout<<"4.Loai bo node ben trai"<<endl;
		cout<<"5.Loai bo node ben phai"<<endl;
		cout<<"6.Xoa Cay"<<endl;
		cout<<"7.Duyet cay theo thu tu truoc"<<endl;
		cout<<"8.Duyet cay theo thu tu giua"<<endl;
		cout<<"9.Duyet cay theo thu tu sau"<<endl;
		cout<<"10.Thoat"<<endl;
		cout<<"Lua chon: ";cin>>choice;
		switch(choice)
		{
			case 1:
				make_root();break;
			case 2:
				cout<<"Nhap gia tri them tai node: ";cin>>value;
				add_left(Tree,value);break;
			case 3:
				cout<<"Nhap gia tri them tai node: ";cin>>value;
				add_right(Tree,value);break;
			case 4:
				cout<<"Nhap gia tri them tai node: ";cin>>value;
				delete_left(Tree,value);break;
			case 5:
				cout<<"Nhap gia tri them tai node: ";cin>>value;
				delete_right(Tree,value);break;
			case 6:
				delete_tree(Tree);break;
			case 7:
				node_left_right(Tree);break;
			case 8:
				left_node_right(Tree);break;
			case 9:
				left_right_node(Tree);break;
			case 10:
				exit(1);
		}
	}while(choice != 0);	
}
int main()
{
	Binary_Tree T;
	T.function();
}
