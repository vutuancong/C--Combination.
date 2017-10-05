#include <iostream>
#include <fstream>
using namespace std;

struct node 
{
	int weight;
	int start;
	int end;
	struct node * next;
};

class A
{
	public:
		int n,T = 1,DT;
		int a[100][100];
		node *Queue;
		node *push(int,int,int);
		node *pop();
		node *create(int,int,int);
		void Init();
		int check(int ,int);
		void Kruskal();
		A()	
		{
			Queue = NULL;
		}
};
node *A::create(int start,int end ,int weight)
{
	node *temp = new node;
	temp->start = start;
	temp->end = end;
	temp->weight = weight;
	temp->next = NULL;
	return temp;
}
node *A::pop()
{
	if(Queue == NULL) return 0;
	else
	{
		node *temp;
		temp = Queue->next;
		delete Queue;
		return temp;
	}
}
node *A::push(int start,int end,int weight)
{
	node *temp;
	if(Queue == NULL) return create(start,end,weight);
	else if(Queue->weight > weight)
	{
		temp = create(start,end,weight);
		temp->next = Queue;
		return temp;
	}
	else if(Queue->weight <= weight)
	{
		temp = create(start,end,weight);
		node *s = Queue,*p;
		while(s!= NULL && s->weight <= temp->weight)
		{
			p = s;
			s = s->next;	
		}
		p->next = temp;
		temp->next =s;
		return Queue;
	}
}

int A::check(int start,int end)
{
	int flag = 0;
	for(int i = 1;i<=T;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(a[i][j] == end)
			{
				flag = 1;
				break;
			}
		}
	}
	if(flag == 1)
	{
		for(int i = 1;i<=T;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(a[i][j] == start) return 0;
			}			
		}
	}
	return 1;
}

void A::Init()
{
	int m;
	fstream f;
	f.open("kruskal.txt",ios::in);
	f>>n;
	cout<<n<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f>>m;
			if(m!=0 && j>i)	Queue = push(i,j,m);	
			cout<<m<<" ";
		}
		cout<<endl;
	}
}

void A::Kruskal()
{
	while(T<= n - 1 && Queue!= NULL)
	{
		int start = Queue->start;
		int end = Queue->end;
		int weight = Queue->weight;
		Queue= pop();
		if(check(start,end))
		{
			a[T][start] = end;
			DT = DT + weight;
			T++;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(a[i][j]) cout<<"("<<j<<" "<<a[i][j]<<")"<<endl;
		}
	}
	cout<<"DT: "<<DT<<endl;
}
int main()
{
	A X;
	X.Init();
	node *s;
	s = X.Queue;
	while(s!= NULL)
	{
		cout<<s->start<<" "<<s->end<<" "<<s->weight<<endl;
		s = s->next;
	}
	cout<<"Cay khung nho nhat: "<<endl;
	X.Kruskal();
}
