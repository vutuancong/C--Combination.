#include <iostream>

using namespace std;

int Tong(int k)
{
	if(k<10) return k;
	else return (k%10+Tong(k/10));
}
int main()
{
	int k;
	cout<<"Nhap so tu nhien k: ";cin>>k;
	cout<<"Tong so tu nhien k la: "<<Tong(k);
}
