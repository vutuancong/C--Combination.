#include <iostream>

using namespace std;

int X[100],n,chuaxet[100]={1};

void Init()
{
	for(int i = 1;i<=n;i++)
		chuaxet[i] = 1;
}
void Result()
{
	for(int i = 1;i<=n;i++)
		cout<<X[i]<<" ";
	cout<<endl;	
}

void Try(int i)
{
	for(int j =1;j<=n;j++)
	{
		if(chuaxet[j])
		{
			X[i] = j;chuaxet[j]=0;
			if(i==n) Result();
			else Try(i+1);
			chuaxet[j]=1;
		}
	}
}
int main()
{
	cout<<"Nhap hoan vi cua n phan tu: ";cin>>n;
	Init();
	Try(1);
}
