#include <iostream>
#define M 100
using namespace std;

int X[M],A[M],n,b;
int MAX = 0;
void Init()
{
	cout<<"Nhap so luong phan tu(fx): ";cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"So thu "<<i<<":";
		cin>>A[i];
	}
	cout<<"Gia tri toi han b: ";cin>>b;
}

void Result()
{
	for(int i = 1;i<=n;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<endl;
}

void Max()
{
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
		sum += A[i]*X[i];
	}
	if(sum < b && MAX < sum )  MAX = sum ;
}

void Test()
{
	int sum = 0;
	for(int i = 1; i<=n; i++)
	{
		sum +=A[i]*X[i];
	}
	if(sum == MAX) 
	{
		cout<<MAX<<endl;
		for(int i = 1;i<=n;i++)
			cout<<X[i]<<" ";
		cout<<endl;
	}
}

void BackTrack1(int i)
{
	for(int j = 0;j<=1;j++)
	{
		X[i]=j;
		if(i == n ) 
		{
			Max();
		}
		else BackTrack1(i+1);
	}
}
void BackTrack2(int i)
{
	for(int j = 0;j<=1;j++)
	{
		X[i]=j;
		if(i == n ) 
		{
			Test();
		}
		else BackTrack2(i+1);
	}
}

int main()
{
	Init();
	BackTrack1(1);
	BackTrack2(1);
}
