#include<iostream>
#include<fstream>

using namespace std;

int a[100][100],n,chuaxet[100],T[100][100];
int sc = 0,DT =0;
void Init()
{
	fstream f;
	f.open("data.txt",ios::in);
	f>>n;
	for(int i = 1;i<= n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f>>a[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Result()
{
	for(int i = 1 ;i<=sc;i++)
	{
		cout<<T[i][1]<<" "T[i][2]<<endl;
	}
}
void Prim()
{
	//Cap phat;
	sc = 1;DT =0;u = 1;
	for(int i =1;i<= n;i++)
		chuaxet[i] = 1;
	int top = 1;s[top] = u;chuaxet[u] = 0;
	while(sc <n -1)
	{
		int min  =1000;
		int k,l;
		for(int i= 1;i<=top;i++)
		{
			int t = s[i];
			for(int j = 1;j<=n;j++)
			{
				if(chuaxet[j] && min>a[t][j])
				{
					min = a[t][j];
					k = t;
					l = j;	
				}
			}
		}
		DT = DT + min;
		T[sc][1] = k;T[sc] = l;
		chuaxet[l] = 0;a[k][l] = 1000;a[l][k] = 1000;
		top++;s[top] = l;
		print("\n");
	}
}
void main()
{
	Init();Prim;Result();
}
