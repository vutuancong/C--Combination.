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
		node *create(int );
		node *pop();
		node *push(int);
		node *Stack;
		void ReInit();
		void Init();
		void DFS(int);
		void Canhcau();
		A()
		{
			Stack = NULL;
		}
};
node *A::create(int value)
{
	node *temp = new node;
	temp->next = NULL;
	temp->info =value;
	return temp;
}
node *A::push(int value)
{
	if(Stack ==  NULL) return create(value);
	else
	{
		node *temp = create(value);
		temp->next = Stack;
		return temp;
	}
}

node *A::pop()
{
	if(Stack == NULL) return 0;
	else
	{
		int i = 1;
		node *temp, *s;
		s = Stack;
		temp = s->next;
		delete s;
		return temp;
	}
}
void A::Init()
{
	fstream f;
	f.open("canhcau.txt",ios::in);
	f>>n;
	cout<<n<<endl;
	for(int i =1;i<=n;i++)
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
	for(int i =1;i<=n;i++)
		chuaxet[i] = 1;
}
void A::DFS(int u)
{
	Stack = push(u);
//	cout<<u<<" ";
	chuaxet[u] = 0;
	while(Stack!= 0)
	{
		int info = Stack->info;
		Stack = pop();
		for(int i = 1;i<=n;i++)
		{
			if(a[info][i] && chuaxet[i])
			{
//				cout<<i<<" ";
				Stack = push(info);
				Stack = push(i);
				chuaxet[i] = 0;
				break;
			}
		}
	}
}
void A::Canhcau()
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i < j && a[i][j])
			{
				a[i][j] = 0;
				a[j][i] = 0;
				DFS(1);
				for(int k = 1;k<=n;k++)
				{
					if(chuaxet[k]) 
					{
						cout<<"Canh cau: "<<"("<<i<<" "<<j<<")"<<endl;
						break;
					}
				}
				a[i][j] = 1;
				a[j][i] = 1;
			}
			ReInit();
		}
	}
}
int main()
{
	A X;
	X.Init();
	X.ReInit();
	X.Canhcau();
}
