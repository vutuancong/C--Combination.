#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{
	char kt;
	struct node *link;  
}*Stack;

class stack_list
{
	public:
		void push(char a);
		node *pop();
		void display();
		int priority(char a,char b);
};
void stack_list::push(char a)
{
	node *temp;	
	temp = new node;
	temp->kt = a;
	temp->link = Stack;
	Stack = temp;
}

node *stack_list::pop()
{
	node *temp;
	if(Stack == NULL) return 0;
	else
	{
		temp = Stack;
		cout<<temp->kt<<" ";
		Stack = Stack->link;
		delete temp;
 	}
	return Stack;
}
int stack_list::priority(char a,char b)
{
	int m =-1 ,n = -1 ;
	if(a == '(' || a == ')') m = 0;
	if(a == '+' || a == '-') m = 1;
	if(a == '*' || a == '/') m = 2;
	if(b == '(' || b == ')') n = 0;
	if(b == '+' || b == '-') n = 1;
	if(b == '*' || b == '/') n = 2;
	if(m>=n) return 1;
	else return 0;
}

int main()
{
	node *y;
	char str[100];
	stack_list X;
	cout<<"Nhap bieu thuc: ";
	cin>>str;
	for(int i = 0 ;i < strlen(str); i++)
	{
		if(str[i] == '(' ) X.push(str[i]);
		else if(str[i]!= '+' && str[i] != '-' && str[i] !='/' && str[i] != '*'&& str[i]!=')' &&str[i]!='(')
			cout<<str[i]<<" ";
		else if(str[i] == '+' || str[i] == '-' || str[i] =='/' || str[i] == '*')
		{
			y = Stack;
			if(X.priority(str[i],y->kt)) X.push(str[i]);
			else
			{
				y = X.pop();
				X.push(str[i]);
			}
		}
		else
		{
			y = X.pop();
			while(y->kt != '(')
			{
				y =X.pop();
			}
		}
	}
	while(Stack!=NULL)
	{
		if(Stack->kt != '(')
			cout<<Stack->kt<<" ";
		Stack = Stack->link;
	}
	
}

