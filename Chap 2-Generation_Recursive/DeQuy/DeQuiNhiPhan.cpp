#include <iostream>

using namespace std;

int NhiPhan(int n)
{
	if(n == 0) return 0;
	return(n%2 + 10*NhiPhan(n/2));
}
int main()
{
	int n;
	cout<<"Nhap so tu nhien n:";cin>>n;
	cout<<"So sau khi doi la: "<<NhiPhan(n);
}
