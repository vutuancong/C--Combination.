#include <iostream>
#include <iomanip>
using namespace std;

int A[100],X[100],n,OK=1,dem =0;

void Init()
{
	cout<<"Nhap hoan vi cua n: ";cin>>n;
	for(int i = 1; i<=n ;i++)
		A[i] = i;
}

void Result()
{
	cout<<"Hoan vi thu "<<dem++<<":"<<setw(3);
	for(int i = 1; i<=n; i++)
	{
		cout<<A[i];
	}
	cout<<endl;
}

void Generation()
{
	int j = n - 1;
	while(j > 0 && A[j] > A[j+1])
		j--;
	if(j > 0)
	{
		int k = n;
		while(k > 0 && A[k] < A[j])
			k--;
		int t = A[k]; A[k] = A[j]; A[j] =t;
		int r = j + 1, s = n;
		while(r <= s)
		{
			t = A[r] ; A[r] = A[s]; A[s] = t;
			r++;s--;
		}
	}
	else OK = 0;
}
int main()
{
	Init();
	while(OK)
	{
		Result();
		Generation();
	}
}
