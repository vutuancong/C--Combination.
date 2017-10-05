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
	int a[100][100], n, CE[100], m = 1;
	node *Stack;
	node *create(int);
	node *pop();
	node *push(int);
	int check();
	void load_data();
	void Euler();
	A()
	{
		Stack == NULL;
	}
};
int A::check()
{
	for (int i = 1; i <= n; i++)
	{
		int tong1 = 0, tong2 = 0;
		for (int j = 1; j <= n; j++)
		{
			tong1 += a[i][j];
			tong2 += a[j][i];
		}
		if (tong1 != tong2) return 0;
	}
	return 1;
}
node *A::create(int a)
{
	node *temp = new node;
	temp->info = a;
	temp->next = 0;
	return temp;
}
node *A::pop()
{
	node *temp, *s = Stack;
	temp = s->next;
	delete s;
	return temp;
}
node *A::push(int value)
{
	if (Stack == NULL) return create(value);
	else
	{
		node *temp = create(value);
		temp->next = Stack;
		return temp;
	}
}
void A::load_data()
{
	fstream f;
	f.open("Eulercohuong.txt", ios::in);
	f >> n;
	cout << n << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f >> a[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void A::Euler()
{
	Stack = push(1);
	while (Stack != 0)
	{
		int s = Stack->info;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[s][i])
			{
				Stack = push(i);
				a[s][i] = 0;
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			CE[m++] = s;
			Stack = pop();
		}
	}
	for (int i = m - 1; i >= 1; i--)
		cout << CE[i] << " ";
}

int main()
{
	A X;
	X.load_data();
	if (X.check())
	{
		cout << "Chu trinh Euler doi voi do thi co huong: " << endl;
		X.Euler();
	}
	else cout << "Do thi vo huong khong la Euler" << endl;
}
