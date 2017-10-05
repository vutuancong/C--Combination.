#include  <iostream>
#define M 100

using namespace std;

int A[M],X[M],n,OK = 1,MAX=0,m;

void Init()
{
	cout<<"Nhap so luong phan tu: ";cin>>n;
	cout<<"Nhap gioi han gia tri lon nhat: ";cin>>m;
//	cin.ignore();
	for(int i= 1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<":";
		cin>>A[i];		
	}
	cout<<endl;
	for(int i = 1;i<=n;i++)
	{
		X[i] = 0;
	}
}

void Generation()
{
	int i = n;
	while(X[i]==1 && i>0)
	{
		X[i]=0;i--;
	}
	if(i>0)
	{
		X[i]=1;
	}
	else OK =0;
}
void Result()
{
	cout<<"Tong lon nhat: "<<MAX<<":";
	for(int i = 1;i<=n;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<endl;
}
void TongMax()
{
	int max_=0;
	for(int i =1;i<=n;i++)
	{
		max_ += A[i]*X[i];
	}
	if(max_ > MAX && max_ <= m) MAX = max_;
}
int Test()
{
	int tong1=0;
	for(int i = 1;i<=n;i++)
	{
		tong1+=A[i]*X[i];
	}
	if(tong1 == MAX) return 1;
	return 0;
}

int main()
{
	Init();
	while(OK)
	{
		TongMax();
//		ResultGen();
		Generation();
	}
	OK = 1;
	for(int i = 1;i<=n;i++)
	{
		X[i] = 0;
	}
	while(OK)
	{
		if(Test()==1) Result();
		Generation();
	}
}
