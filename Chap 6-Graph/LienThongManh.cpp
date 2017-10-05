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
		int n,a[100][100],chuaxet[100];
		node *create(int );
		node *push(int);
		node *pop();
		node *Stack;
		void Init();
		void DFS(int );
		void lienThong();
		void ReInit();
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
	if(Stack == NULL) return create(value);
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
		node *temp,*s = Stack;
		temp = s->next;
		delete(s);
		return temp;
	}
}
void A::Init()
{
	fstream f;
	f.open("lienThong.txt",ios::in);
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
	chuaxet[u] = 0;
	while(Stack !=  NULL)
	{
		int info = Stack->info;
		Stack = pop();
		for(int  i = 1 ;i<=n;i++)
		{
			if(a[info][i] && chuaxet[i])
			{
				chuaxet[i] = 0;
				Stack = push(info);
				Stack = push(i);
				break;
			}
		}
	}
}
void A::lienThong()
{
	int flag = 0;
	for(int i = 1;i<=n;i++)
	{
		ReInit();
		cout<<endl;
		DFS(i);
		for(int j = 1;j<=n;j++)
		{
			if(chuaxet[j]) 
			{
				cout<<"Do thi lien thong yeu";
				flag = 1;
				break;
			}
		}
	}
	if(flag == 0) cout<<"Do thi lien thong manh";
}
int main()
{
	A X;
	X.Init();
	X.ReInit();
	X.DFS(1);
	X.lienThong();
}
