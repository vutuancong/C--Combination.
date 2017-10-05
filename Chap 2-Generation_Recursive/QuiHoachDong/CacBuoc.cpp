#include <iostream>

using namespace std;

int F[100], F0[100],n,dem=0;

void Init()
{
	cout<<"Nhap so n: ";cin>>n;
	for(int i =0;i<=n;i++)
	{
		F0[i]= 0;
	}
	F0[0] =1;
}
void Result()
{
	cout<<"Ket qua thu "<<dem+1<<":";
	for(int i = 0 ;i<=n;i++)
	{
		cout<<F0[i]<<" ";
	}
	cout<<endl;
}
void Replace()
{
	for(int i = 0;i<=n;i++)
	{
		F[i] = F0[i];
	}
}
int main()
{
	Init();
	for(int m = 1;m<=n;m++)
	{
		for(int v = 0;v<=n;v++)
		{
			if(m>v) F[v] = F0[v-1];
			else F[v] = F0[v] + F[v - m];
		}
		Result();
		Replace();
	}
	Result();
	cout<<"Ket qua: "<<F[n];
}
