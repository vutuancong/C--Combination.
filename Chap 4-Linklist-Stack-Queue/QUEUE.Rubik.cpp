#include <iostream>

using namespace std;
char truoc[256];

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b= temp;
}

void Init(int S[])	
{
	for(int i = 0;i<8;i++)
		S[i] = i+1;
}

void A(int S[])
{
	for(int i = 0,k = 8;i<8, k >= 0;i++,k--)
		S[i] = k;
}

void B(int S[])
{
	swap(S[0],S[3]);
	swap(S[1],S[3]);
	swap(S[2],S[3]);
	
	swap(S[4],S[7]);
	swap(S[4],S[6]);
	swap(S[4],S[5]);
}

void C(int S[])
{
	swap(S[5],S[6]);
	swap(S[1],S[5]);
	swap(S[2],S[5]);
}

void display(int S[])
{
	for(int i = 0;i<8;i++)
	{
		cout<<S[i]<<" ";
	}
	cout<<endl;
}
struct node 
{
	int str;
	int Arr[100];
	struct node *next;
}*Queue;

class list_queue
{
	public:
		void push(int a,int A[100] );
		void pop();
		void display();
		list_queue()
		{
			Queue = NULL;
		}
};

void list_queue::push(int a, int A[100])
{
	node *temp;
	temp = new node;
	temp->str =a;
	for(int i = 0;i<8;i++)
	{
		temp->Arr[i] = A[i];
	}
	temp->next =NULL;
	if(Queue == NULL)
	{
		Queue = temp;
		temp->next = NULL;
	}
	else
	{
		node *s =  Queue;
		while(s->next != NULL)
		{
			s = s->next;
		}
		s->next =temp;
		temp->next = NULL;
	}
}

void list_queue::pop()
{
	if(Queue==NULL) 
	{
		cout<<"Danh sach trong"<<endl;
		return;
	}
	node *temp=  Queue;
	Queue = temp->next;
	delete temp;
}

void list_queue::display()
{
	node *temp = Queue;
	while(temp!= NULL)
	{
		cout<<temp->str<<" ";
		temp = temp->next;
	}
}
int kiemTra(int a[],int b[])
{
	for(int i= 0, j = 0;i<8,j<8;j++,i++)
	{
		if(a[i]!=b[j]) return 0;
	}
	return 1;
}
int main()
{
	list_queue X;
	node *tempA,*tempB,*tempC;
	int truoc[255];
	int End[100];
	int Start[100];
	cout<<"Nhap trang thai ket thuc: ";
	for(int i = 0;i<8;i++)
	{
		cin>>End[i];
		Start[i] = i+1;
	}
	X.push(83,Start);
	while(Queue!=NULL)
	{
		tempA = Queue;
		tempB= Queue;
		tempC= Queue;
		
		X.pop();
		cout<<tempA->str;
		A(tempA->Arr);
		if(kiemTra(tempA->Arr,End)) break;
		X.push(65,tempA->Arr);
		truoc[tempA->str] = 65;
		B(tempB->Arr);
		if(kiemTra(tempB->Arr,End)) break;
		X.push(66,tempB->Arr);
		truoc[tempB->str] = 66;
		C(tempC->Arr);
		if(kiemTra(tempC->Arr,End)) break;
		X.push(67,tempC->Arr);
		truoc[tempC->str] = 67;
	}
	
}
