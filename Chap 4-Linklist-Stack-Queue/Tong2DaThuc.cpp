#include <iostream>

using namespace std;

struct node
{
	float somu;
	float heso;
	struct node *next;
} *dathuc;

class DaThuc
{
	public:
		node *create_node(int ,int );
		void insert_end();
		void display();		
};
class Sum
{
	public:
		void init(DaThuc );
		void add(DaThuc, DaThuc, DaThuc);
};
node *DaThuc::create_node(int x,int y)
{
	struct node *temp;
	temp = new(struct node);
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
void DaThuc::insert_end()
{
	int x,y;
	struct node *temp, *s;
	cout<<"Nhap he so x: ";cin>>x;
	cout<<"Nhap so mu y: ";cin>>y;
	temp = create_node(x,y);
	if(dathuc == NULL)
	{
		dathuc = temp;
		temp->next =NULL;
	}
	s = dathuc;
	while(s->next != NULL)
	{
		s = s->next;
	}
	s->next = temp;
	temp->next = NULL;
}
void DaThuc::display()
{
	struct node *temp;
	if(dathuc == NULL)
	{
		cout<<"Danh sach rong:";
	}
	else 
	{
		temp =  dathuc;
		cout<<"Noi dung cua da thuc: "<<endl;
		while(temp != NULL)
		{
			cout<<temp->heso<<"/"<<temp->somu<<"\t";
			temp = temp->next;
		}
	}
}
void init(DaThuc &A)
{
	int n;
	cout<<"Nhap so cac so hang: ";cin>>n;
	for(int i = 0;i<n;i++)
	{
		A.insert_end();
	}
}
int main()
{
	DaThuc X,Y,Z;
	Sum K;
	init(X);
	X.display();
	init(Y);
	Y.display();

}
