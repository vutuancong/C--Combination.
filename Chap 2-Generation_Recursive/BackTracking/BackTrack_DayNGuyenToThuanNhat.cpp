#include <iostream>
#include <math.h>

#define M 100

using namespace std;

int A[M],X[M],n,k,chuaxet[M];

void Init()
{
	cout<<"Nhap day nguyen to thuan nhat: ";cin>>n;
	for(int i =1;i<=n;i++)
	{
		cout<<"So thu "<<i<<":";
		cin>>A[i];
	}
	cout<<"Nhap so k: ";cin>>k;
	for(int i = 1;i<=n;i++)
	{
		chuaxet[i] = 1;
	}
}
void Result()
{
	for(int i = 1;i<=n;i++)
		cout<<A[X[i]]<<" ";
	cout<<endl;
}

int NguyenTo(int n)
{
	if(n<2) return 0;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0) return 0;	
	}	
	return 1;
}

int Test()
{	
	for(int i = 1;i<=n-k+1;i++)
	{
		int tong = 0;
		for(int j = i;j<k+i;j++)
		{
			tong += A[X[j]];
		}
		if(NguyenTo(tong)==0) return 0;
	}
	return 1;
}

void BackTrack(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(chuaxet[j])
		{
			X[i] = j;
			chuaxet[j] = 0;
			if(i==n) 
			{
				if(Test() == 1) Result();
			}
			else BackTrack(i+1);
			chuaxet[j] = 1;
		}
	}
}
int main()
{
	Init();
	BackTrack(1);
}
