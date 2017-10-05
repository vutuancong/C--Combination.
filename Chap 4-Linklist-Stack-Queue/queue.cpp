#include <iostream>
#include <list>
#include <fstream>
#include <stack>

using namespace std;

class Graph
{
	private:
		int V;// so dinh cua do thi
		list <int> *adj;// con tro den cac mang cac danh sach ke adj
		bool *chuaxet;
	public:
		Graph(int V);// Contructor chua lop
		void addEdge(int v, int w);//them canh (u,w) vao do thi
		void BFS(int u);// Thuat toan BFS dua vao hang doi;
}

Graph::Graph(int V)
{
	this->V = V;// Thiet lap V = 0 ,1,2...V-1
	adj = new list<int>[V];
	chuaxet = new bool[V];//Thiet lap trang thai cac dinh deu chua xet
	for(int u = 0;u<V;u++)
	{
		chuaxet[u] = 1;
	}
}
void Graph::addEdge(int v, int w)// them canh (v,w) vao do thi
{
	adj[v].push_back(w);//them w vao list(v) neu la do thi co huong
	adj[w].push_back(v);// them v vao list(w) neu la do thi vo huong
}
void Graph::BFS(int u)
{
	list<int> queue;//tao hang doi rong
	queue.push_back(u);//dua u vao hang doi
	chuaxet[u] = 0;//ghi nhan u da xet
	list<int>::iterator t;
	while(!queue.empty())
	{
		int s = queue.front();//lay s o dau hang doi
		cout<<s<<" ";//tham dinh s
		queue.pop_front();//loai s ra khoi hang doi
		for(t = adj[s].begin();t!=adj[s].end();++t)// duyet cac dinh thuoc list
		{
			if(chuaxet[*t]) // neu dinh t chua xet
			{
				queue.push_back(*t);// dua t vao hang doi
				chuaxet[*t] = 0;//xac nhan da xet
			}
		}
	}
}
int main()
{
	ifstream fp("dothi.in",ios::in );
	int n,m,dau,cuoi;
	fp>>n>>m;//doc so dinh va so canh cua do thi
	Graph gh(n+1);//Khoi tao do thi voi V = 1,2,..n
	for(int i = 1;i<= m;i++)// chuyen do thi thanh bieu dien danh sach ke
	{
		fp>>dau>>cuoi;//doc 1 canh
		gh.addEdge(dau,cuoi)//them 1canh vao do thi
	}
	fp.close();
	cout<<"\nKet qua duye: ";gh.BFS(5);
}
