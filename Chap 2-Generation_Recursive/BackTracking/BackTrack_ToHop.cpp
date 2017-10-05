#include <iostream>

using namespace std;

int n,k,X[100];

void Result()
{
	for(int i = 1;i<=k;i++)
		cout<<X[i]<<" ";
	cout<<endl;
}
void Try(int i)
{
	for(int j = X[i-1]+1;j<n - k + i;j++)
	{
		X[i] = j;
		if(i == k) Result();
		else Try(i+1);
	}
}
int main()
{
	cout<<"Nhap to hop chap k cua n phan tu: ";cin>>k>>n;
	Try(1);
}
