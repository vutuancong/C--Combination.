#include <iostream>
#include <fstream>

using namespace std;

int A[100][100],pre[100],n,D[100];

void Read_data()
{
	fstream f;
	f.open("dothi.txt",ios::in);
	f>>n;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			int m;
			f>>m;
			if(m == 0) A[i][j] = 9999;
			else if(i == j)
			A[i][j] = 0;
			else A[i][j] = m;
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 1;i<=n;i++)
	{
		D[i] = A[1][i];
		pre[i] = 1;
	}
	D[1] = 0;
}
void Loop()
{
	for(int k = 1;k<=n-2;k++)
	{
		for(int v = 1;v<=n;v++)
		{
			for(int u = 1;u<=n;u++)
			{
				if(D[v] > D[u] + A[u][v])
				{
					D[v]  = D[u] +  A[u][v];
					pre[v] = u;
				}
			}
		}
	}
}
void Result()
{
	for(int i  = 2; i<= n;i++)
	{
		int m = i;
		cout<<"Do dai tu "<<1<<" den "<<i<<":";
		cout<<1<<" ";
		while(pre[m]!= 1)
		{
			cout<<pre[m]<<" ";
			m = pre[m];
		}
		cout<<i<<" ";
		cout<<endl;
	}
}
int main()
{
	Read_data();
	Loop();
	Result();
}
