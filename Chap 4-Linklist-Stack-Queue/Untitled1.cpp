#include <iostream>

using namespace std;

struct node 
{
	int info;
	int priority;
	struct node *link;
}*Queue;

class priority_queue
{
	public:
		void pop_end();
		void push(int a);
		void pop_top();
		void display();
};
void priority_queue::display()
{
	node *temp;
	temp = Queue;
	while(temp!=NULL)
	{
		cout<<temp->info<<" ";
		temp =temp->link;
	}
}
void priority_queue::push(int a)
{
	node *temp;
	temp = new node;
	temp->info = a;
	temp->priority =a;
	if(Queue == NULL)
	{
		Queue = temp;
		temp->link =NULL;
	}
	if(Queue->priority>temp->priority)
	{
		node *s;
		s = Queue;
		Queue = temp;
		Queue->link = s;
	}
	else
	{
		node *s, *ptr;
		s = Queue;
		while(s->priority>=temp->priority && s != NULL)
		{
			ptr = s;
			s = s->link;
		}
		if(s->link == NULL)
		{
			s->link = temp;
			temp->link =NULL;
		}
		else
		{
			ptr->link = temp;
			temp->link = s;
		}
	}
}

void priority_queue::pop_end()
{
	node *temp;
	temp = new node;
	if(Queue!=NULL) 
	{
		cout<<"Danh sach rong";
		return;
	}
	else
	{
		temp = Queue;
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = NULL;
		cout<<"Phan tu bi loai: "<<temp->info<<endl;
		delete temp;
	}
}

void priority_queue::pop_top()
{
	node *temp;
	temp = Queue;
	if(Queue == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	else 
	{
		temp = temp->link;
		Queue =temp;
		delete temp;
	}
}

int main()
{
	int n,info,Fopt,first,second;
	priority_queue X;
	cout<<"So luong day: ";cin>>n;
	for(int i = 0;i<n;i++)
	{
		cout<<"Nhap info: ";cin>>info;
		X.push(info);
	}
	X.display();
//	while(Queue->link != NULL)
//	{
//		first = Queue->info;
//		X.pop_top();
//		second = Queue->info;
//		X.pop_top();
//		Fopt = first + second;
//		X.push(Fopt);
//	}
//	cout<<"Chi phi noi day: "<<Fopt<<endl;
}
