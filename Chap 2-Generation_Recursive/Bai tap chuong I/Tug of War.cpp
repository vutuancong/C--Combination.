#include <iostream>

using namespace std;

int A[100],n;

int Min=100,X[100];

void Init()
{
	cout<<"Nhap so n: ";cin>>n;
	for(int i = 0;i<n;i++)
	{
		cout<<"Nhap so thu "<<i+1<<":";
		cin>>A[i];
	}
}
void Result()
{
	cout<<endl;
	cout<<"Hai mang can tim la: "<<endl;
	for(int i = 0;i<n;i++)
	{
		if(X[i] == 1) cout<<A[i]<<" ";
	}
	cout<<endl;
	for(int i = 0;i<n;i++)
	{
		if(X[i] == 0) cout<<A[i]<<" ";
	}
	
}
void MinArr()
{
	int a1=0,a0=0;
	int min_= 0;
	int tong =0;
	for(int i = 0;i<n;i++)
	{
		if(X[i] == 1) a1 += X[i]*A[i];
		tong = tong + A[i];
	}
	a0 = tong - a1;
	if(a0 > a1) min_ = a0 - a1;
	else min_ = a1 - a0;
	if(min_ < Min) Min = min_;
}
void Nhi_Phan1(int i )
{
	for(int j =0;j<=1;j++)
	{
		X[i] = j;
		if(i == n )
		{
			int dem0 = 0;
			for(int i = 0;i<n;i++)
			{
				if(X[i] == 0) dem0+=1;
			}
			if(dem0 == n/2)
			MinArr();
		} 
		else Nhi_Phan1(i+1);
	}
}
void Test()
{
	int a1=0,a0=0;
	int min_= 0;
	int tong =0;
	for(int i = 0;i<n;i++)
	{
		if(X[i] == 1) a1 += X[i]*A[i];
		tong = tong + A[i];
	}
	a0 = tong - a1;
	if(a0 > a1) min_ = a0 - a1;
	else min_ = a1 - a0;
	if(min_ == Min) 
	{
		Result();
//		exit(0);
	}
}
void Nhi_Phan2(int i )
{
	for(int j =0;j<=1;j++)
	{
		X[i] = j;
		if(i == n )
		{
			int dem0 = 0;
			for(int i = 0;i<n;i++)
			{
				if(X[i] == 0) dem0+=1;
			}
			if(dem0 == n/2)
			{
				Test();
			}
		}
		else Nhi_Phan2(i+1);
	}
}
int main()
{
	Init();
	Nhi_Phan1(0);
	Nhi_Phan2(0);
}
