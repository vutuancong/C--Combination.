#include <iostream>
#include <fstream>

using namespace std;

typedef struct node
{
	float somu;
	float heso;
	struct node *next;
}*DaThuc;
class CongDaThuc
{
	public:
		node* create_node(int ,int );
		void Insert_end(struct node &,int ,int);
		void Nhap(DaThuc &,DaThuc &,int &,int &);
		void Cong(DaThuc ,DaThuc ,DaThuc &);
		void Display(DaThuc );
};
node* CongDaThuc::create_node(int x,int y)
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

void CongDaThuc::Insert_end(struct node &A, int x, int y)
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

void CongDaThuc::Display(DaThuc A)
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

void CongDaThuc::Nhap(DaThuc &A,DaThuc &B,int &n,int &m)
{
	int x,y;
	cout<<"Nhap so luong 1: ";
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>x>>y;
		Insert_end(A,x,y);
	}
	cout<<"Nhap so luong 2: ";
	cin>>m;
	for(int i = 0 ;i<m;i++)
	{
		cin>>x>>y;
		Insert_end(B,x,y);
	}
}
void CongDaThuc::Cong(DaThuc A,DaThuc B,DaThuc &C)
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
	CongDaThuc X;
	int n,m;
	node* R = NULL;
	node* P= NULL;
	node* Q = NULL;	
	X.Nhap(Q,P,n,m);
	X.Display(Q);
	X.Display(P);
	X.Cong(P,Q,R);
	if(m>n) X.Display(R);
	else X.Display(R);
}

