#include <iostream>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;

int n,k,X[MAX], dem = 0, OK = TRUE;

void Init(void)
{
	cout <<"\n Nhap n = ";cin>>n;
	k = 1; X[k] = n;
}
void Result(void)
{
	cout<<"\n Cach chia "<<++dem<<":";
	for(int i = 1;i<=k;i++)
		cout<<X[i]<<" ";
}
void Next_Division(void)
{
	int i = k,j,R,S,D;
	while(i > 0 && X[i]==1) i--;
	if(i>0)
	{
		X[i] = X[i] - 1;
		D = k - i + 1;
		R = D / X[i];
		S = D % X[i];
		k = i;
	}
	if(S>0)
	{
		k = k + 1; X[k] = S;
	}
	else OK = 0;	
}
int main()
{
	Init();
	while(OK)
	{
		Result();
		Next_Division();
	}
	return 0;
}
