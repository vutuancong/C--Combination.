#include <iostream>
#include <fstream>
using namespace std;

int A[100][100],n;

void Init()
{
	fstream f;
	f.open("Sodoku.txt",ios::in);
	f>>n;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			f>>A[i][j];
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}


int DieuKien(int x,int y, int s)
{
	for(int i = 0;i<9;i++)
	{
		if(A[x][i] == s) return 0;
	}
	for(int i = 0;i<9;i++)
	{
		if(A[i][y] == s) return 0;
	}
	int a = x/3,b = y/3;
	for(int i = 3*a; i<3*a+3; i++)
	{
		for(int j =3*b; j<3*b+3; j++)
		{
			if(A[i][j] == s) return 0;
		}
	}
	return 1;
}

void Result()
{
	cout<<endl;
	for(int i = 0;i<9;i++)
	{
		for(int j = 0;j<9;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}	
}
void DeQuy(int x,int y)
{
	if(y == 9)
	{
		if(x == 8)
		{
			Result();
			exit(0);
		}
		else
		{
			DeQuy(x+1,0);
		}
	}
	else if(A[x][y] == 0)
	{
		for(int s = 1;s<=9;s++)
		{
			if(DieuKien(x,y,s))
			{
				A[x][y] = s;
				DeQuy(x,y+1);
				A[x][y] = 0;
			}
		}
	}
	else
	DeQuy(x,y+1);
}
int main()
{
	
	Init();
	DeQuy(0,0);
	Result();
}

