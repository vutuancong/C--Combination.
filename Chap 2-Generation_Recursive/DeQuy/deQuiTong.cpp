#include <iostream>
using namespace std;

//tinh tong bang de quy

int Tong(int n)
{
	if(n == 0) return 0;
	return (n + Tong(n-1));
}

int main()
{
	cout<<"Tong cua 5 la: "<<Tong(5);
}
