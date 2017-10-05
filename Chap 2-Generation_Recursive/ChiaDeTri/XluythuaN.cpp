#include <iostream>

using namespace std;

int power(int x, int n)
{
	if(n == 0) return 1;
	if(n%2 == 0)
		return power(x,n/2)*power(x,n/2);
	else
		return x*power(x,n/2)*power(x,n/2);
}
int main()
{
	int x,n;
	cout<<"Nhap x, n";cin>>x>>n;
	cout<<"Ket qua x^n la: "<<power(x,n)<<endl;
}
