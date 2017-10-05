#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	int so;
	struct node *link;
}*Stack;

class stack_list
{
public:
	void push(int a);
	node *pop();
	int action(int, int, char);
	stack_list()
	{
		Stack = NULL;
	}
};
void stack_list::push(int a)
{
	node *temp;
	temp = new node;
	temp->so = a;
	temp->link = Stack;
	Stack = temp;
}
node *stack_list::pop()
{
	node *temp;
	if (Stack == NULL) return 0;
	else
	{
		temp = Stack;
		Stack = Stack->link;
		delete temp;
	}
	return Stack;
}
int stack_list::action(int a, int b, char tt)
{
	if (tt == '+') return (a + b);
	if (tt == '-') return (a - b);
	if (tt == '*') return (a * b);
	if (tt == '/') return (a / b);
}
int main()
{
	char str[100];
	int TH1, TH2, kq;
	stack_list X;
	cout << "Nhap bieu thuc: ";
	cin.getline(str, 100);
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j<strlen(str); j++)
			{
				str[j] = str[j + 1];
			}

		}
	}
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] != '+' && str[i] != '-'&& str[i] != '*' && str[i] != '/') X.push(str[i] - '0');
		else
		{
			TH2 = Stack->so;
			X.pop();
			TH1 = Stack->so;
			X.pop();
			kq = X.action(TH1, TH2, str[i]);
			X.push(kq);
		}
	}
	cout << "Ket qua: " << Stack->so << endl;
	system("pause");
}
