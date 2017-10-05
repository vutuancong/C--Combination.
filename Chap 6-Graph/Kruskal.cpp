#include <iostream>
#include <fstream>

using namespace std;

struct Edge
{
	int src;
	int dest;
	int weight;
};

struct Graph
{
	int V, E;
	Edge *edge;
};

Graph *createGraph(int V,int E)
{
	Graph  *graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}
struct subset
{
	int parent;
	int rank;
};
int find(subset subsets[],int i)
{
  	if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void sort(Graph *graph)
{
	int E = graph->E-1;
	for(int i = 1;i<E;i++)
	{
		for(int i = j+1;j<E;j++)
		{
			if(graph->edge[i].weight > graph->edge[j].weight)
			{
				Edge temp = graph->edge[i];
				graph->edge[i] = graph->edge[j];
				graph->edge = temp;
			}
		}
	}
}
void KruskalMST(Graph *graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 1,i =1;
	int FOPT = 0;
	sort(graph);
	subset *subset =new subset[V];
	for(int v =1;v<=V;v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while(e< V -1)
	{
		Edge next_edge  = graph->edge[i++];
		int x = find(subsets,next_edge.src);
		int y = find(subsets,next_edge.dest);
		if(x!=y)
		{
			result[e++] = next_edge;
			FOPT = FOPT + next_edge.weight;
			Union(subsets,x,y);
		}
	}
	if(e<V-1)
	{
		cout<<"\n Do thi khong lien thong";
	}
	else
	{
		cout<<"\nDo dai nho nhat: "<<FOPT;
		cout<<"\nTap canh cay khung";
		for(int i = 1;i<e;i++)
		{
			cout<<""
		}
	}
}
