#include <iostream>
#include <fstream>
using namespace std;

int X[100],A[100],n,k,tong = 0,dem = 0;

void Init()
{
	fstream f;
	f.open("daycon.txt",ios::in);
	f>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		f>>A[i];
	}
}
void Result()
{
	cout<<"Day con thu: "<<++dem<<": ";
	for(int i = 1;i<=n;i++)
	{
		if(X[i])
		{
			cout<<A[i]<<" ";
		}
	}
	cout<<endl;
}

void Back_Track(int i)
{
	for(int j= 0 ;j<=1;j++)
	{
		X[i] = j;
		tong = tong + X[i]*A[i];
		if(i == n)
		{
			if(tong == k) Result();
		}
		else if(tong <= k) Back_Track(i+1);
		tong = tong - X[i]*A[i];
	}
}
int main()
{
	Init();
	Back_Track(1);
}
