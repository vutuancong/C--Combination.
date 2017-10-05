#include <iostream>
#define MAX 100

int X[MAX],n, dem = 0 ;
bool COT[MAX],DCXUOI[MAX],DCNGUOC[MAX];

using namespace std;

void Result()
{
	for(int i =1;i<=n;i++)
		cout<<X[i]<<" ";
	cout<<endl;
}

void Init()
{
	cout<<"Nhap n = ";cin>>n;
	for(int i = 1;i<=n;i++)
		COT[i] = 1;
	for(int i = 1;i<=2*n;i++)
	{
		DCXUOI[i] = 1;
		DCNGUOC[i] = 1;
	}
}
void Try(int i)
{
	for(int j = 1;j<=n;j++)
	{
		if(COT[j] && DCXUOI[i-j+n] && DCNGUOC[i+j-1])
		{
			X[i] = j;
			COT[j] = 0;
			DCXUOI[i-j+n] = 0;
			DCNGUOC[i+j-1] = 0;
			if(i == n) Result();
			else Try(i+1);
			COT[j] = 1;
			DCXUOI[i-j+n] = 1;
			DCNGUOC[i+j-1] = 1;
		}
	}
}
int main()
{
	Init();
	Try(1);
}
