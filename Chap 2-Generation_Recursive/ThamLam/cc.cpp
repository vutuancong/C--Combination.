#include<iostream>
using namespace std;
int main()
{
	int S[4],i=4;
	int n=87648;
	while(n>0)
	{
		S[i--]= n%10;
		n = n/10;
	}
	for(int i = 0 ; i<5;i++)
	{
		cout<<S[i]<<"\t";
	}
}
