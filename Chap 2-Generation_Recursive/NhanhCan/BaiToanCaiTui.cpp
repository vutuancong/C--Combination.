#include <iostream>

using namespace std;
int X[100],A[100],C[100],Xopt[100];
float Fopt = 0,cost = 0,weight = 0;
int b,n;
void Init()
{
	cout<<"Nhap khoi luong tui: ";cin>>b;
	cout<<"Nhap so luong do vat: ";cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"Nhap do vat thu: "<<i<<":";
		cin>>A[i];
		cout<<"Gia tri su dung cua do vat thu: "<<i<<":";
		cin>>C[i];
	}
}
void Result()
{
	cout<<"So luong do vat: "<<n<<endl;
	cout<<"Trong luong tui: "<<b<<endl;
	cout<<"Gia tri su dung toi u:"<<Fopt<<endl;
	cout<<"Phuong an toi u:";
	for(int i = 1;i<=n;i++)
	{
		cout<<Xopt[i]<<" ";
	}
	cout<<endl;
}
void Update()
{
	if(cost > Fopt) 
	{
		Fopt = cost;
		for(int i = 1;i<=n;i++)
		{
			Xopt[i] = X[i]; 
		}
		cout<<endl;
	}
}
void Back_Track(int k)
{
	int t = ((b - weight)/A[k]);
	for(int j = t;j>=0;j--)
	{
		X[k] = j;
		cost = cost + C[k]*X[k];
		weight = weight + A[k]*X[k];
		if(k == n) Update();
		else if(cost + (C[k+1]*((b-weight)/A[k+1]))> Fopt)
			Back_Track(k+1);
		cost = cost - C[k]*X[k];
		weight = weight - A[k]*X[k];
	}
}
int main()
{
	Init();
	Back_Track(1);
	Result();
}
