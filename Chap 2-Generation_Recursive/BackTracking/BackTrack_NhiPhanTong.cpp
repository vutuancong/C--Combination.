#include <iostream>
#define M 100

using namespace std;

int A[100],X[100],n,Tong;
void Init()
{
	cout<<"Nhap so luong so: ";cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"Nhap so thu "<<i<<": ";
		cin>>A[i];
	}
	cout<<"Nhap tong :";cin>>Tong;
}
int Test()
{
	int sum=0;
	for(int i = 1;i<=n;i++)
	{
		sum += A[i]*X[i];
	}
	if(sum==Tong) return 1;
	return 0;
}
void Result()
{
	for(int i = 1;i<=n;i++)
	{
		if(X[i] == 1) cout<< A[i]<<" ";
	}
	cout<<endl;
}

void BackTrack(int i)
{
	for(int j = 0 ;j<=1;j++)
	{
		X[i]=j;
		if(i == n) 
		{
			if(Test()==1) Result();
		}	
		else BackTrack(i+1);
	}
}
int main()
{
	Init();
	while(n>0)
	{
		BackTrack(1);
		n--;
	}
}
