// Cho mot tap U gom n phan tu con goi la tap A.
//tim cac tap con nho nhat sao cho chua du cac phan tu cua U.

#include <iostream>
#include <vector>
#define M  100

using namespace std;

int n,k;
vector <int> U;

vector<int>::iterator i;

void Init()
{
	int a;
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin>>a;
		U.push_back(a);
	}
//	int b;
//	cout<<"Nhap cac so luong day con: ";
//	cin>>b;
//	while(b>0)
//	{
//		
//	}
}
void Result()
{
	cout<<"Day phan tu ";
	for(i = U.begin() ;i<U.end();i++)
	{
		cout<<*i<<" ";
	}
}
int main()
{
	Init();
	Result();
}

