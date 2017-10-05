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
	node *Queue;
	node *create_node(int);
	node *push(int);
	node *pop();
	int a[100][100];
	int n, m;
	int chuaxet[100];
	void load_data();
	void BFS();
	A()
	{
		Queue = NULL;
	}
};

node *A::create_node(int a)
{
	node *temp;
	temp = new node;
	temp->next = NULL;
	temp->info = a;
	return temp;
}

node *A::pop()
{
	node *temp = Queue;
	Queue = temp->next;
	delete temp;
	return Queue;
}

node *A::push(int a)
{
	node *temp = Queue;
	if (Queue == NULL) return create_node(a);
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create_node(a);
		return Queue;
	}
}

void A::load_data()
{
	int c,b;
	fstream f;
	f.open("danhsachcanh.txt", ios::in);
	f >> n >> m;
	cout << n << m << endl;
	for(int i = 1;i<=m;i++)
	{
		f>>b>>c;
		a[b][c] = 1;
		a[c][b] = 1;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			f >> a[i][j];
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for (int i = 1; i <= n; i++)
		chuaxet[i] = 1;
}
void A::BFS()
{
	Queue = push(1);
	cout << 1 << " ";
	chuaxet[1] = 0;
	while (Queue != NULL)
	{
		int info = Queue->info;
		Queue = pop();
		for (int i = 1; i <= n; i++)
		{
			if (chuaxet[i] && a[info][i] == 1)
			{
				cout << i << " ";
				chuaxet[i] = 0;
				Queue = push(i);
			}
		}
	}
}
int main()
{
	A X;
	X.load_data();
	X.BFS();
}
