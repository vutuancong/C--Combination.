#include<iostream>

using namespace std;

int GiaiThua(int n)
{
	if(n == 0 ) return 1;// dieu kien dung 0! = 1
	return(n*GiaiThua(n-1));
}
int main()
{
	cout<<"Giai thua cua 5 la:"<<GiaiThua(5)<<endl;
}

