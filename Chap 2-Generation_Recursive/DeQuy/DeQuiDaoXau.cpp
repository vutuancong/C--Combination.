#include <iostream>
#include <cstring>
using namespace std;

char DaoXau(char a[],int n)
{
	cout<<a[n];
	if(n==0) return a[0];
	return DaoXau(a,n-1);
} 
int main()
{
	char a[100];
	cout<<"Nhap xau ki tu: ";cin.getline(a,100);
	cout<<"Xau sau khi dao: ";DaoXau(a,strlen(a)-1);
}
