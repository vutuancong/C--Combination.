#include <iostream>

using namespace std;

int F(int m, int v)
{
	if(m == 0)
	{
		if(v == 0) return 1;
		else return 0;
	}
	else
	if(m > v) return F(m-1,v);
	else return(F(m-1,v) + F(m,v - m));
}
int main()
{
	int n;
	cout<<"\n Nhap n: ";cin>>n;
	cout<<"\n Ket qua:"<<F(n,n)<<endl;
}
