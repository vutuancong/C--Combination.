#include <iostream>
#include <list>
#include <fstream>

using namespace std;

typedef struct node
{
	float heso;
	float somu;
};

void Add(list<node> P, list<node> Q, list<node> &R)
{
	list<node>::iterator i;
	list<node>::iterator j;
	node tempP,tempQ,tempR;
	
	for(i  = P.begin(),j =Q.begin(); i!= P.end(),j!=Q.end();j++,i++)
	{
		tempP = *i;
		tempQ = *j;
		if(tempP.somu > tempQ.somu)
		{
			R.push_back(tempP);
			j--;
		}
		else if(tempP.somu < tempQ.somu)
		{
			R.push_back(tempQ);
			i--;
		}
		else if(tempP.somu == tempQ.somu)
		{
			tempR.somu = tempP.somu;
			tempR.heso = tempP.heso + tempQ.heso;
			R.push_back(tempR);
		}
	}
}
void Result(list<node> R)
{
	list<node>::iterator i;
	cout<<endl;
	cout<<"R = ";
	for( i = R.begin();i!=R.end();i++)
	{
		node temp = *i;
		cout<<temp.heso<<"x^"<<temp.somu<<" + ";
	}
	cout<<endl;
}
int main()
{
	list <node> P, Q, R;
	fstream f;
	float heso,somu;
	int n = 0, m = 0;
	f.open("dathuc.txt",ios::in);
	f>>n;
	cout<<"P = ";
	for(int i = 0 ;i<n;i++)
	{
		f>>heso>>somu;
		cout<<heso<<"x"<<"^"<<somu<<" + ";
		node temp;
		temp.heso = heso;
		temp.somu = somu;
		P.push_back(temp);
	}
	cout<<endl;
	f>>m;
	cout<<"Q = ";
	int dem = 0;
	for(int i = 0;i<m;i++)
	{
		f>>heso>>somu;
		node temp;
		temp.heso = heso;
		temp.somu = somu;
		cout<<heso<<"x"<<"^"<<somu<<" + ";
		Q.push_back(temp);
	}
	Add(P,Q,R);
	Result(R);
}
