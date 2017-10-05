// Noi day sao cho chi phi noi day la be nhat .
// Biet chi phi noi bang do dai cua day.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int  L[100],n,OPT = 0;

struct compare
{
	bool operator()(int &a, int &b)
	{
		return a > b;
	}
};
priority_queue<int,vector<int>,compare> pq;

void Init()
{
	cout<<"Nhap so doan day can noi: ";
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cout<<"Nhap doan day thu "<<i+1<<":";
		cin>>L[i];
	}
	for(int i = 0;i<n;i++)
	{
		pq.push(L[i]);
	}
}

void Ropes()
{
	while(pq.size() >1)
	{
		int First = pq.top();pq.pop();
		int Second = pq.top();pq.pop();
		OPT += (First + Second);
		pq.push(First + Second);
	}
}
void Result()
{
	for(int i = 0;i<n;i++)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

int main()
{
	Init();
	Ropes();
	cout<< OPT <<endl;
}
