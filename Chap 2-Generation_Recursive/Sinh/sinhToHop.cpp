#include <iostream>
#include <iomanip>

using namespace std;
int A[100], n, OK = 1, dem = 0,k;
int X[100];
void Init()
{
	cout<<"Nhap to hop chap k cua n phan tu: ";cin>>k>>n;
	for(int i = 1 ; i <=k  ;i++)
		X[i] = i;
	cout<<"Nhap so phan tu "<<endl;
	for(int i =1;i<=n;i++)
	{
		cout<<"Phan tu thu "<<i<<":";
		cin>>A[i];
	}
}

void Result()
{
	cout<<"Ket qua thu : "<<dem++<<setw(3);
	for(int i = 1;i<=k;i++)
		cout<<X[i]<<" ";
	for(int i = 1 ; i <= k;i++)
		cout<<A[X[i]]<<" ";
	cout<<endl;
}

void Generation()
{
	int j = k;
	while(j > 0 && X[j] == n - k + j)
		j--;
	if(j > 0 )
	{
		X[j] = X[j] + 1;
		for(int i = j + 1; i<=n; i++)
			X[i] = X[i - 1] + 1;
	}
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
