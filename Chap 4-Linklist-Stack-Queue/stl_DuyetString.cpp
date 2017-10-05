#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

typedef struct node
{
	string word;
	int soLan;
};
list<node> X;
list<node>::iterator i;

int kiemTra(string a,int &n)
{
	int count = 0;
	for(i = X.begin();i!=X.end();i++)
	{
		node temp = *i;
		if(temp.word == a) return count;
		count++; 
	}
	return n+1;
}
void Fix_node(int n)
{
	int count = 0;
	for(i =X.begin(),count = 0;i!=X.end();i++,count++)
	{
		if(count == n)
		{
			node temp = *i;
			X.erase(i);
			temp.soLan++;
			X.push_back(temp);
			break;
		}
	}
}
void Display()
{
	for(i = X.begin();i!=X.end();i++)
	{
		node temp = *i;
		cout<<temp.word<<" "<<temp.soLan<<endl;
	}
}
int main()
{
	fstream f;
	string a;
	int flag = 0,n = 0;
	f.open("vanban.txt",ios::in);
	while(!f.eof())
	{
		f>>a;
		flag = kiemTra(a,n);
		if(flag > n)
		{
			node temp;
			temp.soLan = 1;
			temp.word = a;
			X.push_back(temp);
			n = flag;
		}
		else Fix_node(flag);
	}
	Display();
}
