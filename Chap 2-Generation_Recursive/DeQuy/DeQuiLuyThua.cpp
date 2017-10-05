#include <iostream>

using namespace std;

int LuyThua(int x,int n)
{
	if(n==1) return x;
	if(n==0) return 1;
	return x*LuyThua(x,n-1);
}
int main()
{
	int n,x;
	cout<<"Nhap so tu nhien x: ";cin>>x;
	cout<<"Nhap so n: ";cin>>n;
	cout<<"x^n = ";cout<<LuyThua(x,n);
	return 0;
}
