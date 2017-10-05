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
		int a[100][100],n,chuaxet[100];
		node *Stack;
		node *create(int );
		node *pop();
		node *push(int );
		void Init();
		void ReInit();
		void DFS(int );
		void DinhTru();
		A()
		{
			Stack = NULL;
		}
};

node *A::create(int value)
{
	node *temp = new node;
	temp->next = NULL;
	temp->info = value;
	return temp;
}
node *A::push(int value)
{
	node *temp;
	if(Stack == NULL) return create(value);
	else
	{
		temp = create(value);
		temp->next = Stack;
		return temp;
	}
}
node *A::pop()
{
	if(Stack == 0) return 0;
	else
	{
		node *s = Stack;
		Stack = s->next;
		delete s;
		return Stack;
	}
}
void A::Init()
{
	fstream f;
	f.open("data.txt",ios::in);
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
}
void A::ReInit()
{
	for(int i = 1;i<=n;i++)
	{
		chuaxet[i] = 1;
	}
}
void A::DFS(int u)
{
	Stack = push(u);
	cout<<u<<" ";
	chuaxet[u] = 0;
	while(Stack!= 0)
	{
		int info = Stack->info;
		Stack = pop();
		for(int i = 1;i<=n;i++)
		{
			if(chuaxet[i] && a[info][i])
			{
				cout<<i<<" ";
				chuaxet[i] = 0;
				Stack = push(info);
				Stack = push(i);
				break;
			}
		}
	}
}

void A::DinhTru()
{
	for(int i =1 ;i<=n;i++)
	{
		ReInit();		
		chuaxet[i] = 0;
		if(i == 1) 
		{
			DFS(2);
			for(int j = 1;j<=n;j++)
			{
				if(chuaxet[j])
				{
					cout<<"Dinh tru: "<<i<<endl;
					break;
				}
			}
		}
		else
		{
			DFS(1);
			for(int j = 1;j<=n;j++)
			{
				if(chuaxet[j])
				{
					cout<<"Dinh tru: "<<i<<endl;
					break;
				}
			}
		}
		cout<<endl;
	}
}

int main()
{
	A X;
	X.Init();
	X.DinhTru();
}
