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
		int n,sc;
		int chuaxet[100];
		int a[100][100];
		node *Stack;
		node *create_node(int);
		node *push(int );
		node *pop();
		void DFS();
		void load_data();
		void function();
		A()
		{
			Stack = NULL;
		}
};

void A::load_data()
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

void A::DFS()
{
	Stack = push(1);
	chuaxet[1] = 0;
	while(Stack!= 0)
	{
		int info = Stack->info;
		Stack = pop();
		for(int i = 1 ;i<=n;i++)
		{
			if(chuaxet[i] && a[info][i] == 1)
			{
				cout<<"("<<info<<" "<<i<<")"<<" ";
				sc++;
				chuaxet[i] = 0;
				Stack = push(info);
				Stack = push(i);
				break;
			}
		}
	}
	if(sc<n-1) cout<<"Do thi khong lien thong";
}

node *A::create_node(int a)
{
	node *temp;
	temp = new node;
	temp->next = 0;
	temp->info = a;
	return temp;
}

node *A::push(int a)
{
	if(Stack == 0) return create_node(a);
	else
	{
		node *s = create_node(a);
		s->next = Stack;
		return s;
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
int main()
{
	A X;
	X.load_data();
	X.DFS();	
}
