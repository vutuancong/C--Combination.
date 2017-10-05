#include <iostream>

using namespace std;

int A[100],n,k,OK = 1;
static int dem = 0;

void Init()
{
	cout<<"Nhap n : ";cin>>n;
	k = 1;
	A[k] = n;
}

void Result()
{
	cout<<"So luong la "<<++dem<<":";
	for(int i = 1;i <= k;i++)
		cout<<A[i];
	cout<<endl;
}

void Generation()
{
	int i = k,R,S,D;
	while(A[i] == 1 && i >0) i--;
	if(i> 0)
	{
		A[i] = A[i] - 1;
		D = k - i + 1;
		R = D/A[i];
		S = D%A[i];
		k = i;
		if(S > 0)
		{
			k = k + S;
			A[k] = A[k] +1;
		}
		if( R > 0)
		{
			for(int j = i+1;j<= i+R;j++)
				A[j]= A[i];
			k+=R;
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
