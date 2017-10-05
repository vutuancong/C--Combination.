#include <iostream>

using namespace std;
int X[100],n;
void Result();
void Try(int i)
{
	for(int j = 0;j<=1;j++)
	{
		X[i] = j;
		if(i == n ) Result();
		else Try(i+1);
	}
}
void Result()
{
	for(int i = 1;i<=n;i++)
		cout<<X[i]<<" ";
	cout<<endl;
}
int main()
{
	cout<<"Nhap xau nhi phan n = ";cin>>n;
	cout<<"Ket qua la: "<<endl;
	Try(1);
}
