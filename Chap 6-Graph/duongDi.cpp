#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int info;
	struct node *next;
};

class A
{
	public:
		int n,a[100][100],chuaxet[100],truoc[100],l,m;
		node *create(int );
		node *push(int);
		node *pop();
		node *Queue;
		void Init();
		void ReInit();
		void BFS(int );
		A()
		{
			Queue = NULL;
		}
};

node *A::create(int value)
{
	node *temp = new node;
	temp->info = value;
	temp->next = NULL;
	return temp;
}
node *A::pop()
{
	if(Queue== NULL) return 0;
	else
	{
		node *temp;
		temp = Queue->next;
		delete(Queue);
		return temp;
	}
}
node *A::push(int value)
{
	node *temp, *s;
	s = Queue;
	if(Queue == NULL) return create(value);
	while(s->next!= NULL)
	{
		s = s->next;
	}
	temp = create(value);
	s->next = temp;
	return Queue;
}

void A::Init()
{
	fstream f;
	f.open("duongDi.txt",ios::in);
	f>>l>>m;
	cout<<l<<m<<endl;
	f>>n;
	cout<<n<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			f>>a[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void A::ReInit()
{
	for(int i = 1;i<=n ;i++)
	{
		chuaxet[i] = 1;
	}
}
void A::BFS(int u)
{
	Queue = push(u);
	chuaxet[u] = 0;
	truoc[u] = 0;
//	cout<<u<<" ";
	while(Queue!= NULL)
	{
		int info = Queue->info;
		Queue = pop();
		for(int i =1;i<=n;i++)
		{
			if(chuaxet[i] && a[info][i])
			{
//				cout<<i<<" ";
				chuaxet[i] = 0;
				Queue = push(i);
				truoc[i] = info;
			}
		}
	}
}
int main()
{
	A X;
	X.Init();
	X.ReInit();
	X.BFS(X.l);
	
	while(X.truoc[X.m] != X.l)
	{
		cout<<X.truoc[X.m]<<" ";
		X.m = X.truoc[X.m];
		if(X.truoc[X.m] == 0) break;
	}
}
