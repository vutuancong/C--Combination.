#include <iostream>
#define MAX 100
using namespace std;

typedef struct queue
{
	int inp = -1;
	int out = -1;
	int node[MAX];
};

class Queue
{
	public:
		void push(queue &);
		void pop(queue &);
		void display(queue);
};

void Queue::push(queue &S)
{
	int value;
	if(S.inp == MAX - 1)
	{
		cout<<"Tran du lieu"<<endl;
	}
	else
	{
		if(S.out == -1)
		{
			S.out = 0;
			cout<<"Gia tri node";cin>>value;
			S.inp = S.inp + 1;
			S.node[S.inp] = value;
		}
	}
}
void Queue::pop(queue &S)
{
	if(S.out == -1|| S.out>S.inp)
	{
		cout<<"Hang doi rong"<<endl;
		return;
	}
	else
	{
		cout<<"Node duoc lay ra: "<<S.node[S.out]<<endl;
		S.out = S.out+1;
	}
}
void Queue::display(queue S)
{
	if(S.out == -1)
	{
		cout<<"Hang doi rong"<<endl;
	}
	else 
	{
		cout<<"Noi dung cua hang doi "<<endl;
		for(int i = S.out;i<=S.inp;i++)
		{
			cout<<S.node[i]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	queue S;
	int choice;Queue X;
	do
	{
		cout<<"1.Dua phan tu vao hang doi"<<endl;
		cout<<"2.Lay phan tu ra khoi hang doi"<<endl;
		cout<<"3.Duyet cac phan tu cua node"<<endl;
		cout<<"4.Thoat"<<endl;
		cout<<"Lua chon";cin>>choice;
		switch(choice)
		{
			case 1:
				X.push(S);break;
			case 2:
				X.pop(S);break;
			case 3:
				X.display(S);break;
			case 4:
				exit(1);
			default:
				cout<<"Lua chon sai"<<endl;break;
		}
	}while(choice!=0);
}

