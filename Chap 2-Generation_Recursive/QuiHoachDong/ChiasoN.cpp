#include <iostream>

using namespace std;

int main()
{
	int n,F[100][100];
	cout<<"Nhap n: ";cin>>n;
	for(int i = 0;i<n;i++)
	{
		F[0][i] = 0;
	}
	F[0][0] = 1;
	for(int m = 1;m<=n;m++)
	{
		for(int v = 0;v<=n;v++)
		{
			if(m>v) F[m][v] = F[m-1][v];
			else 
			F[m][v] = F[m-1][v] + F[m][v - m];
		}
	}
	cout<<"Gia tri:"<<F[n][n];
}
