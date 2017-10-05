#include <iostream>
#include <fstream>

using namespace std;

typedef struct node
{
	float somu;
	float heso;
	struct node *next;
}*DaThuc;

node *create_node(int x,int y)
{
	node *temp;
	temp = new node;
	if(temp == NULL)
	{
		cout<<"Khong du khong gian nho"<<endl;
		return 0;
	}
	else
	{
		temp->heso = x;
		temp->somu = y;
		temp->next = NULL;
	}
	return temp;
}

void Insert_end(DaThuc &A, int x, int y)
{
	node *temp, *s;
	temp = create_node(x,y);
	if(A == NULL)
	{
		A = temp;
		temp->next =NULL;
	}
	else 
	{
		s = A;
		while(s->next!= NULL)
		{
			s = s->next;
		}
		s->next = temp;
		temp->next =NULL;
	}
}

void Display(DaThuc A,int n)
{
	node *temp;
	if(A == NULL)
	{
		cout<<"Danh sach rong:";
	}
	else 
	{
		temp =  A;
		cout<<"\nNoi dung cua da thuc: "<<endl;
		while(temp != NULL)
		{
			if(temp->somu == 1)
				cout<<temp->heso<<"x";
			else if(temp->somu == 0)
				cout<<temp->heso;
			else
				cout<<temp->heso<<"x^"<<temp->somu;
			temp = temp->next;
			if(temp!= NULL && temp->heso >0)
				cout<<" + ";
		}
	}
}

void Init(DaThuc &A,DaThuc &B,int &n,int &m)
{
	fstream f;
	f.open("dathuc.txt",ios::in);
	int x,y;
	f>>n;
	for(int i = 0;i<n;i++)
	{
		f>>x>>y;
		Insert_end(A,x,y);
	}
	f>>m;
	for(int i = 0 ;i<m;i++)
	{
		f>>x>>y;
		Insert_end(B,x,y);
	}
}
void Add(DaThuc A,DaThuc B,DaThuc &C)
{
	DaThuc temp1 = A;
	DaThuc temp2 = B;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->somu > temp2->somu)
		{
			Insert_end(C,temp1->heso,temp1->somu);
			temp1 = temp1->next;
		}
		else if(temp1->somu < temp2->somu)
		{
			Insert_end(C,temp2->heso,temp2->somu);
			temp2 = temp2->next;
		}
		else 
		{
			Insert_end(C,temp1->heso + temp2->heso,temp1->somu);
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	while(temp1!= NULL)
	{
		Insert_end(C,temp1->heso,temp1->somu);
		temp1 = temp1->next;
	}
	while(temp2!= NULL)
	{
		Insert_end(C,temp2->heso,temp2->somu);
		temp2 = temp2->next;
	}
}
int main()
{
	int n,m;
	node* P= NULL;
	node* Q = NULL;
	Init(Q,P,n,m);
	Display(Q,n);
	Display(P,m);
	node* R = NULL;
	Add(P,Q,R);
	if(m>n)Display(R,m);
	else Display(R,n);
}

