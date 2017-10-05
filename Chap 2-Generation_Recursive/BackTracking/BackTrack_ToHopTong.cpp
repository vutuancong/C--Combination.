#include <iostream>
#define M 100

using namespace std;

int A[M],n,X[M],Tong,k;


void Init()
{
	cout<<"Nhap so luong phan tu: ";cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<":";
		cin>>A[i];
	}
	cout<<"Nhap tong :";cin>>Tong;
	cout<<"Nhap so luong phan tu con: ";cin>>k;
}
void Result()
{
	for(int i = 1;i<=k;i++)
	{
		cout<<A[X[i]]<<" ";
	}
	cout<<endl;
}
int Test()
{
	int sum = 0;
	for(int i = 1;i<=k;i++)
	{
		sum += A[X[i]];
	}
	if(sum == Tong) return 1;
	else return 0;
}
void BackTrack(int i)
{
	for(int j=X[i-1]+1;j<=n-k+i;j++)
	{
		X[i]=j;
		if(i==k)
		{
			if(Test()==1) Result();
		}
		else BackTrack(i+1);
	}
}

int main()
{
	Init();
	BackTrack(1);
}
