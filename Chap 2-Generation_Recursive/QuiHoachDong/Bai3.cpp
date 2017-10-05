#include <iostream>

using namespace std;

int F[100],n,m,v,dem = 0;
void Init(void)
{
	cout<<"Nhap n = ";cin>>n;
	for(int i = 0;i<=n;i++)
	F[i] = 0;
	F[0] = 1;
}
void Result()
{
	cout<<"\nKet qua buoc: "<<++dem<<": ";
	for(int i =0;i<=n;i++)
	cout<<F[i]<<" ";
}
int main()
{
	Init();
	for(int m =1;m<=n;m++)
	{
		Result();
		for( v = m;v<=n;v++)
		{
			F[v] = F[v] + F[v-m];
		}
	}
	Result();
	cout<<"\nKet qua: "<<F[n]<<endl;
	system("pause");return 0;
}
