#include <iostream>
#include <fstream>

using namespace std;

int A[100][100];int n;

void Init()
{
	fstream f;
	f.open("Sodoku.txt",ios::in);
	f>>n;
	for(int i = 0;i<9;i++)
	{
		for(int j =0;j<9;j++)
		{
			f>>A[i][j];
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Result()
{
	cout<<endl;
	for(int i = 0;i<9;i++)
	{
		for(int j =0;j<9;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
int KiemTra(int x,int y, int s)
{
	int a = x /3,b = y/3;
	for(int i = a*3;i<a*3+3;i++)
	{
		for(int j =b*3;j<b*3;j++)
		{
			if(A[i][j] == s) return 0;
		}
	}
	for(int i = 0;i<9;i++)
	{
		if(A[x][i] == s ) return 0;
	}
	for(int i = 0;i<9;i++)
	{
		if(A[i][y] == s) return 0;
	}
	return 1;
}
void DeQuy(int x, int y)
{
	if(y==9 && x<8) DeQuy(x+1,0);
	if(A[x][y] == 0)
	{
		for(int s = 1;s<=9;s++)
		{
			if(KiemTra(x,y,s))
			{
				A[x][y] = s;
				if(y == 8 && x == 8)
				{	
					Result();
					break;
				}
				else DeQuy(x,y+1);
				A[x][y] = 0;
			}
		}
	}
	else DeQuy(x,y+1);
}
int main()
{
	Init();
	DeQuy(0,0);
}
