#include <iostream>

using namespace std;

int A[100],n,OK = 1,tong = 0,X[100],k=0;

void Init()
{
	cout<<"Nhap tong:";cin>>tong;
	cout<<"Nhap so luong so: ";cin>>n;
	k= n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"So thu "<<i<<":";
		cin>>A[i];
		cout<<endl;
	}
}
void Generation()
{
	int i = k;
	while(X[i] == 1 && i > 0) 
	{
		X[i] = 0;i--;
	}
	if(i > 0)
	{
		X[i]  = 1;
	}
	else OK = 0;
}
int Test()
{
	int sum = 0;
	for(int i = 1;i<=k;i++)
		sum+=A[i]*X[i];
	if(sum == tong ) return 1;
	else return 0;
}
void ResultGen()
{
	for(int i = 1;i<=k;i++)
		cout<<X[i]<<" ";
	cout<<endl;
}
void Result()
{
	for(int i = 1;i<=k;i++)
	{
		if(X[i] == 1) cout<< A[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	Init();
	while(k>0)
	{
		while(OK)
		{
//			ResultGen();
			if(Test()) Result();
			Generation();
		}
		k--;OK = 1;
	}
}
