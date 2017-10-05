#include <iostream>
#include <fstream>

using namespace std;

struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};
struct AdjList
{
	AdjListNode *head;
};
class Graph
{
	private:
		int V;
		AdjList *array;
	public:
		Graph(int V)
		{
			this->V = V;
			for(int i = 0 ;i<V;i++)
				array[i].head = NULL;
		}
		AdjListNode* newAdjListNode(int dest);
		void addEdge(int src, int dest);
		void printGrapb();
};
AdjListNode *Graph::newAdjListNode(int dest)
{
	AdjListNode *newNode = new AdjListNode;
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
void Graph::addEdge(int src,int dest)
{
	AdjListNode *newNode;
	newNode = newAdjListNode(dest);
	newNode->next = array[src].head;
	array[src].head = newNode;
	newNode = newAdjListNode(src);
	newNode->next = array[dest].head;
	array[dest].head = newNode;
}
void Graph::printGrapb()
{
	int v;
	for(v = 0; v<V;v++)
	{
		AdjListNode* pCrawl = array[v].head;
		cout<<"\nDanh sach ke dinh"<<v<<"\n head";
		while(pCrawl)
		{
			cout<<"->"<<pCrawl->dest;
			pCrawl = pCrawl->next;
		}
		cout<<endl;
	}
}
int main()
{
	ifstream fp("dothi.txt",ios::in);
	int n,m,dau,cuoi;
	fp>>n>>m;
	Graph gh(n+1);
	for(int i = 1;i<=m;i++)
	{
		fp>>dau>>cuoi;
		gh.addEdge(dau,cuoi);
	}
	fp.close();
	gh.printGrapb();
}
