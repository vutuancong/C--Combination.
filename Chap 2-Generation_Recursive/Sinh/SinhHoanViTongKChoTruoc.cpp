#include<iostream>
#define M 100
using namespace std;

int X[M],A[M],n,OK = 1,tong,k,dem;

void Init()
{
	cout<<"Nhap so luong so: ";cin>>n;
	cout<<"Nhap tong: ";cin>>tong;
	cout<<"Nhap so phan tu cua tap con: ";cin>>k;
	for(int i =1;i<=n;i++)
	{
		cout<<"Phan tu thu "<<i<<":"<<endl;
		cin>>A[i];		
	}
	for(int i = 1;i<=k;i++)
	{
		X[i]= i;
	}
}
void Generation()
{
	int i = k;
	while(X[i] == n- k +i && i>0) i--;
	if(i>0)
	{
		X[i] = X[i]+1;
		for(int j = i+1;j<=k;j++)
		{
			X[j] = X[j-1] + 1;
		}
	}
	else OK = 0;
}
void ResultGen()
{
	cout<<"Ket qua "<<++dem<<":";
	for(int i = 1;i<=k;i++)
	{
		cout<<A[X[i]]<<" ";
	}
	cout<<endl;
}
int Test()
{
	int tong1 = 0;
	for(int i = 1;i<=k;i++)
	{
		tong1 = tong1 + A[X[i]];	
	}
	if(tong1 == tong ) return 1;
	return 0; 
}
int main()
{
	Init();
	while(OK)
	{
		if(Test()==1) ResultGen();
		Generation();
	}
}


