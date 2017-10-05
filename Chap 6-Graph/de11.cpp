#include <iostream>;
#include <fstream>

using namespace std;

void Display(int n,int A[][100])
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Init()
{
	fstream f;
	f.open("dske.txt",ios::in);
	int n,a,b,A[100][100];
	f>>n;
	for(int i = 1; i<= n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f>>a>>b;
			if(a == j || b == j ) A[i][j] = 1;
			else A[i][j] = 0;
		}
	}
	Display(n,A);
}
int main()
{
	Init();
}
