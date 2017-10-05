#include <iostream>
#include <cstring>

using namespace std;

struct node 
{
	char str;
	struct node *link;
}*Stack;

class stack_list
{
	public:
		void push(char a);
		void pop();
		stack_list()
		{
			Stack = NULL;
		}
};
void stack_list::push(char a)
{
	node *temp;
	temp = new node;
	temp->str = a;
	temp->link = Stack;
	Stack = temp;
}
void stack_list::pop()
{
	node *temp;
	temp = Stack;
	Stack = Stack->link;
	delete temp;
}
int main()
{
	stack_list X;
	char str[100];
	cout<<"Nhap bieu thuc can kiem tra: "<<endl;
	cin.getline(str,100);
	for(int i = 0 ;i<strlen(str);i++)
	{
		if(str[i] == '{' || str[i] == '[' || str[i] == '(')
			X.push(str[i]);
		if(str[i] == '}' || str[i] == ']' || str[i] == ')')
			X.pop();		
	}
	if(Stack!= NULL) cout<<"Bieu thuc sai"<<endl;
	else cout<<"Bieu thuc dung"; 
}
