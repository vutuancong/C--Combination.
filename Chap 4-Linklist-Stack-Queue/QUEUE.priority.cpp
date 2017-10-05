#include <iostream>

using namespace std;

struct node 
{
	int info;
	int priority;
	struct node *link;
}*Queue;

class queue_priority
{
	public:
		void push(int a);
		void pop_top();
		void display();
		void pop_end();
		queue_priority()
		{
			Queue = NULL;			
		}
};
void queue_priority::push(int a)
{
	node *temp,*ptr,*s;
	temp = new node;
	temp->info = a;
	temp->priority = a;
	if(Queue == NULL)
	{
		Queue = temp;
		temp->link = NULL;
		return;
	}
	else
	{
		if(temp->priority <= Queue->priority)
		{
			s = Queue;
			Queue = temp;
			Queue->link = s;
		}
		else
		{
			s = Queue;
			while(s != NULL && s->priority < temp->priority)
			{
				ptr = s;
				s = s->link;
			}
			ptr->link = temp;
			temp->link = s;	
		}
	}
}
void queue_priority::pop_end()
{
	node *s,*ptr;
	s = Queue;
	while(s->link!= NULL)
	{
		ptr = s;
		s = s->link;
	}
	cout<<"Phan tu bi xoa : ";cout<<s->info<<endl;
	ptr->link = NULL;
}
void queue_priority::pop_top()
{
	node *s = Queue;
	cout<<"Phan tu bi xoa: "<<Queue->info<<endl;
	Queue = s->link;
	delete s;
}
void queue_priority::display()
{
	node *s;
	s = Queue;
	while(s!= NULL)
	{
		cout<<s->info<<" ";
		s = s->link;
	}
	cout<<endl;
}
int main()
{
	int n,a,first,second, Fopt;
	cout<<"Nhap so luong day noi: ";
	cin>>n;
	queue_priority X;
	for(int i = 0 ;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i+1<<endl;
		cin>>a;
		X.push(a);
	}
	X.display();
	while(Queue->link != NULL)
	{
		first = Queue->info;
		X.pop_top();
		second = Queue->info;
		X.pop_top();
		Fopt = Fopt + first + second;
		X.push(first + second);
		X.display();
	}
	cout<<"Fopt = "<<Fopt;
}
