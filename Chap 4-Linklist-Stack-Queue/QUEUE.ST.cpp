#include <iostream>
#include <math.h>
#include <fstream>

#define MAX 10000

using namespace std;

int A[MAX],k = 0,truoc[MAX],chuaxet[MAX];

struct node 
{
	int info;
	struct node *next;
}*Queue;

class queue_list
{
	public:
		void push(int a);
		void pop();
		void display();
		queue_list()
		{
			Queue = NULL;
		}
};
int soNguyenTo(int n)
{
	if(n<2) return 0;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0) return 0;
	}
	return 1;
}
void queue_list::push(int a)
{
	node *temp;
	temp = new node;
	temp->info  = a;
	temp->next = NULL;
	if(Queue == NULL)
	{
		Queue = temp;
		temp->next = NULL;
	}
	else
	{
		node *s = Queue;
		while(s->next != NULL)
		{
			s = s->next;
		}
		s->next =temp;
		temp->next = NULL;
	}
}
void queue_list::pop()
{
	node *temp;
	temp = Queue;
	Queue = temp->next;
	delete temp;
}
void queue_list::display()
{
	node *temp = Queue;
	if(Queue == NULL) 
	{
		cout<<"Khong co danh sach hien thi"<<endl;
		return;
	}
	else
	{
		while(temp != NULL)
		{
			cout<<temp->info<<" ";
			temp = temp->next;
		}
	}
}
int kiemTra(int a,int b)
{
	int m,n,dem = 0;
	while(a>0)
	{
		m = a %10;
		n = b %10;
		if(m != n) dem++;
		a = a/10;
		b = b/10;
	}
	if(dem == 1) return 1;
	return 0;
	
}
int main()
{
	int u;
	queue_list X;
	for(int i = 1000;i<=9999;i++)
	{
		if(soNguyenTo(i))
		{
			A[k++] = i;
			chuaxet[i] = 1;
		}
	}
	X.push(1033);
	chuaxet[1033] = 0;
	while(Queue!=NULL)
	{
		u = Queue->info;
		X.pop();
		for(int v = 0;v<k;v++)
		{
			if(chuaxet[A[v]] && kiemTra(u,A[v]))
			{
				X.push(A[v]);
				chuaxet[A[v]] = 0;
				truoc[A[v]] = u;
			}
		}
	}
	if(truoc[8179] == 0)
	{
		cout<<"Khong tim duoc duong di"<<endl;
	}
	else
	{
		cout<<"8179"<<" ";
		int num = truoc[8179];
		while(num != 1033)
		{
			cout<<num<<" ";
			num = truoc[num];
		}
		cout<<"1033"<<endl;
	}
}
