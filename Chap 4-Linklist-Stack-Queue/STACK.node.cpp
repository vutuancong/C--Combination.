#include <iostream>

using namespace std;

struct node 
{
	int info;
	struct node *link;
}*Stack;

class stack_list
{
	public: 
		void push(int &);
		void pop();
		void display();
		stack_list()
		{
			Stack = NULL;
		}
};

void stack_list::push(int &value)
{
	node *temp;
	temp = new node;
	temp->info = value;
	temp->link = Stack;
	Stack = temp;
}
void stack_list::pop()
{
	if(Stack == NULL)
	{
		cout<<"Khong co danh sach"<<endl;
	}
	else 
	{
		node *temp;
		temp = Stack;
		cout<<"Phan tu bi loai bo: "<<temp->info<<endl;
		Stack = Stack->link;
		delete temp;
	}
}
void stack_list::display()
{
	node *temp;
	temp = Stack;
	while(temp != NULL)
	{
		cout<<temp->info<<" ";
		temp = temp->link;
	}
}
int main()
{
	int m,value;
	stack_list X;
	do
	{
		cout<<"Cac thao tac tren stack"<<endl;
		cout<<"1.Dua phan tu vao stack"<<endl;
		cout<<"2.Lay phan tu ra khoi stack"<<endl;
		cout<<"3.Duyet stack"<<endl;
		cout<<"4.Thoat"<<endl;
		cout<<"Lua chon";cin>>m;
		switch(m)
		{
			case 1:
				cout<<"Nhap gia tri: ";cin>>value;
				X.push(value);break;
			case 2:
				cout<<"Loai bo phan tu dau: ";
				X.pop();
				break;
			case 3:
				cout<<"Danh sach stack la: ";
				X.display();break;
			case 4:
				exit(1);
			default:
				cout<<"Lua chon sai";
		}
	}while(m!=0);
}
