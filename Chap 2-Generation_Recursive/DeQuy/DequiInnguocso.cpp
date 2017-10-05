#include <iostream>

using namespace std;

int InNguoc(int n)
{
	cout<<n<<" ";
	if( n == 1) return 1;
	return InNguoc(n-1);
}
int main()
{
	int n;
	cout<<"Nhap so tu nhien: ";cin>>n;
	cout<<"Day so in nguoc la: ";InNguoc(n);
	return 0;
}
