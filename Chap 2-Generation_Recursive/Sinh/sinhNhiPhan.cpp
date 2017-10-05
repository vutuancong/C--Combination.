#include <iostream>
#include <iomanip>

using namespace std;

int A[100],n,OK = 1,dem = 0;

void Init()
{
	cout<<"Nhap n: ";cin>>n;
	for(int i = 1; i<=n;i++)
		A[i] = 0;	
}

void Result()
{
	cout<<"Xau nhi phan thu "<<dem++<<":"<<setw(3);
	for(int i = 1;i <= n; i++)
		cout<<A[i];
	cout<<endl;
}
void Generation()
{
	int j = n;
	while(j > 0 && A[j]==1)
	{
		A[j] = 0;
		j--;
	}
	if(j>0) A[j] =1;
	else OK = 0;
}
int main()
{
	Init();
	while(OK)
	{
		Result();
		Generation();
	}
}
