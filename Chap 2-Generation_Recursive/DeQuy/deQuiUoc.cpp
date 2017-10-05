#include <iostream>
using namespace std;

int Uoc(int a,int b)
{
	if(a == b) return a;
	else
	{
		int r = a % b; a = b; b = r;
		return (Uoc(a,b));
	}
}
int main()
{
	cout<<"Uoc chung lon nhat cua 10 , 20 la: "<<Uoc(20,10);
}
