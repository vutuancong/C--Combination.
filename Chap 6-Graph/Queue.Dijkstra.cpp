#include <iostream>
#include <fstream>
using namespace std;

struct node 
{
	int v;
	int weight;
	struct node *next;
};

class A
{
	public:
		int n;
		int a[100][100];
		int truoc[100];
		node *create(int,int);
		node *push(int,int);
		node *pop();
		node *Queue;
		void dijkstra();
		void Init();
		A()
		{
			Queue = NULL;
		}
};

node *A::create(int v,int weight)
{
	node *temp = new node ;
	temp->v = v;
	temp->weight = weight;
	temp->next = NULL;
	return temp;
}
node *A::pop()
{
	if(Queue == NULL) return 0 ;
	else
	{
		node *temp;
		temp = Queue->next;
		delete Queue;
		return temp;
	}
}
node *A::push(int v,int weight)
{
	node *temp;
	if(Queue == NULL) return create(v,weight);
	else if(Queue->weight > weight)
	{
		temp = create(v,weight);
		temp->next = Queue;
		return temp;
	}
	else if(Queue->weight <= weight)
	{
		temp = create(v,weight);
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

void A::Init()
{
	fstream f;
	f.open("dijkstra.txt",ios::in);
	f>>n;
	cout<<n<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f>>a[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	Queue = push(1,0);
	truoc[1] = 1;
	for(int i = 2;i<=n;i++)
	{
		Queue = push(i,a[1][i]);
		truoc[i] = 1;
	}
}
void A::dijkstra()
{
	
	Queue=  pop();
	while(Queue != 0)
	{
		for(int i = 1;i<= n;i++)
		{
			int weight = Queue->weight;
			int v = Queue->v;
			Queue = pop();
			if(Queue->weight > weight + a[v][i])
			{
				Queue->weight = weight + a[v][i];
				truoc[Queue->v] = v;
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		cout<<"Duong di ngan nhat tu dinh "<<1<<"->"<<i<<": ";
		while(truoc[i]!= 1)
		{
			int m = truoc[i];
			cout<<m<<" ";
			i = m;
		}
		cout<<endl;
	}
}
int main()
{
	A X;
	X.Init();
	node *s = X.Queue;
	while(s!= NULL)
	{
		cout<<s->v<<" "<<s->weight<<endl;
		s = s->next;
	}
	X.dijkstra();
}
