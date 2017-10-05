#include <iostream>

using namespace std;

struct node 
{
	int info;
	struct node *link;
}*Queue;

class queue_list
{
	public:
		void push(int );
		void pop();
		void display();
};

void queue_list::push(int a)
{
	node *temp;
	temp = new node;
	temp->info = a;
	temp->link = Queue;
	Queue = temp;
}

void queue_list::pop()
{
	node *temp;
	temp = Queue;
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	cout<<"Gia tri loai bo: "<<temp->info<<endl;
	temp->link =NULL;
	delete temp;
}
void queue_list::display()
{
	node *temp;
	temp = Queue;
	while(temp!= NULL)
	{
		cout<<temp->info<<" ";
		temp = temp->link;
	}
}
int main()
{
	int a;
	int choice;
	queue_list X;
	do
	{
		cout<<"Cac thao tac: "<<endl;
		cout<<"1.Nhap them node"<<endl;
		cout<<"2.Lay node cuoi"<<endl;
		cout<<"3.Hien thi queue"<<endl;
		cout<<"4.Thoat"<<endl;
		cout<<"Lua chon"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Nhap node can them: ";cin>>a;
				X.push(a);break;
			case 2:
				cout<<"Lay node cuoi: ";
				X.pop();break;
			case 3:
				cout<<"Danh sach queue: ";
				X.display();break;
			case 4:
				exit(1);	
		}	
	}while(choice!=0);
}
