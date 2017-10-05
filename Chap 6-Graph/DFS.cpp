#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int info;
	struct node *next;
};

class STACK
{
	public:
		int n;
		int chuaxet[100];
		int a[100][100];
		node *Stack;
		node *create_node(int);
		node *push(int );
		node *pop();
		void DFS();
		void load_data();
		void function();
		STACK()
		{
			Stack = NULL;
		}
};
node *STACK::create_node(int a)
{
	node *temp;
	temp = new node;
	temp->next = 0;
	temp->info = a;
	return temp;
}

node *STACK::push(int a)
{
	if(Stack == 0) return create_node(a);
	else
	{
		node *s = create_node(a);
		s->next = Stack;
		return s;
	}
}

node *STACK::pop()
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

void STACK::load_data()
{
	fstream f;
	f.open("data.txt",ios:: in);
	f>>n;
	cout<<n;
	for(int i = 1 ;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f>>a[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 1;i<=n;i++)
		chuaxet[i] = 1;
} 

void STACK::DFS()
{
	Stack = push(1);
	cout<<1<<" ";
	chuaxet[1] = 0;
	while(Stack!= 0)
	{
		int info = Stack->info;
		Stack = pop();
		for(int i = 1 ;i<=n;i++)
		{
			if(chuaxet[i] && a[info][i] == 1)
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

int main()
{
	STACK A;
	A.load_data();
	A.DFS();	
}
