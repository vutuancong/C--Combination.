#include <iostream>
#include <conio.h>
#define MAX 5
using namespace std;

typedef struct STK
{
	int top;
	int node[MAX];
};
class STACK
{
	public:
		STK s;
		void push(STK &s);
		int pop(STK s);
		void display(STK s);
		STACK(void)
		{
			s.top =-1;
		}
};
void STACK::push(STK &s)
{
	int value;
	if(s.top == (MAX - 1))
	{
		cout<<"Tran Stack"<<endl;
		return;
	}
	else
	{
		cout<<"Nhap phan tu: ";cin>>value;
		s.top = s.top +1;
		s.node[s.top] = value;
	}	
}
int STACK::pop(STK s)
{
	int value;
	if(s.top == -1)
	{
		cout<<"Stack rong"<<endl;
		return (INT_MIN);
	}
	else
	{
		value = s.node[s.top];
		cout<<"Phan tu bi loai: "<<s.node[s.top]<<endl;
		s.top = s.top -1;
	}
	return value;
}
void STACK::display(STK s)
{
	if(s.top == -1)
	{
		cout<<"Khong co gi de duyet"<<endl;
		return;
	}
	else
	{
		cout<<"\nNoi dung stack: "<<endl;
		for(int i = s.top;i>=0;i--)
			cout<<s.node[i]<<" ";
	}
	getch();
}
int main()
{
	STACK X;
	STK s;
	int choice;
	cout<<"CAC THAO TAC TREN STACK \n";
	do
	{
		system("cls");
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Lua chon";cin>>choice;
		switch(choice)
		{
			case 1: X.push(s);break;
			case 2: X.pop(s);break;
			case 3: X.display(s);break;
			case 4: exit(1);
			default:
				cout<<"Lua chon sai";break;
		}
	}
	while(choice!=0);
	
}
