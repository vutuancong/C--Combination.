#include <iostream>
#include <math.h>
#define M 100

using namespace std;

int X[M],k,A[M],n,OK = 1;

void Init()
{
	cout<<"Nhap so luong phan tu day so: ";cin>>n;
	cout<<"Nhap bac :";cin>>k;
	for(int i = 1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<":";
		cin>>A[i];
	}
	for(int i = 1;i<=n;i++)
		X[i] = i;
}
void Generation2()
{
	int i = n -1;
	while( i> 0 && X[i] > X[i+1])
	{
		i--;
	}
	if( i > 0)
	{
		int j = n;
		while(j>0 && X[j]<X[i]) j--;
		int temp = X[i]; X[i]=X[j];X[j]=temp;
		int l=i+1,m=n;
		while(m>l)
		{
			temp = X[l]; X[l] = X[m]; X[m] = temp;
			l++;m--;
		}
	}
	else OK = 0;
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
int TestTong()
{
	for(int i =1 ;i<=n-k+1;i++)
	{
		int tong1 = 0;
		for(int j = i;j<i+k;j++)
		{
			tong1= tong1 + A[X[j]];
		}
		if(NguyenTo(tong1)==0) return 0;
	}
	return 1;
}
void Result()
{
	cout<<"Cac ket qua la:";
	for(int i = 1;i<=n;i++)
	{
		cout<<A[X[i]]<<" ";
	}
	cout<<endl;
}
int main()
{
	Init();
	while(OK)
	{
		if(TestTong()==1) Result();
		Generation2();
	}
	
}
