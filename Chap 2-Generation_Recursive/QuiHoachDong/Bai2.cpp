#include <iostream>
using namespace std;

int F0[100],F[100],n,m,v,dem = 0;

void Init()
{
	cout<<"Nhap n = ";cin>>n;
	for(int i = 0;i<=n;i++)
	F0[i] = 0;
	F0[0] = 1;
}
void Result(void)
{
	cout<<"\n Ket qua buoc "<<++dem<<":";
	for(int i =0;i<=n;i++)
	cout<<F0[i]<<" ";
}
void Replace(void)
{
	for(int i= 0;i<=n;i++)
	F0[i] = F[i];
}

int main()
{
	Init();
	for(m = 1;m<=n;m++)
	{
		for(v = 0;v<=n;v++)
		{
			if(v<m) F[v] = F0[v];
			else
			F[v] = F0[v] + F[v-m];
		}
		Result(); Replace();
	}
	Result();
	cout<<"\nKet qua: "<<F[n]<<endl;
	system("pause");return 0;
}
