#include<iostream>
#include<climits>
using namespace std;
void printmst(int parent[],int graph[5][5])
{
	cout<<"Edge\t weight\n";
	for(int i=1;i<5;i++)
	cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
}
int minkey(int key[],bool mstset[])
{
	int min=INT_MAX,min_index;
	
	for(int v=0;v<5;v++)
	{
		if(!mstset[v]&&key[v]<min)
		min=key[v],min_index=v;
		
	}
	return min_index;
}



void primmst(int graph[5][5])
{
	int parent[5];
	int key[5];
	bool mstset[5];
	
	for(int i=0;i<5;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(int count=0;count<5-1;count++)
	{
		int u=minkey(key,mstset);
		mstset[u]=true;
		
		for(int v=0;v<5;v++)
		{
			if(graph[u][v]&&!mstset[v]&&graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	printmst(parent,graph);
}
int main()
{
	int graph[5][5]=
	{
	{0,2,0,6,0},
	{2,0,3,8,5},
	{0,3,0,0,7},
	{6,8,0,0,9},
	{0,5,7,9,0},
};
primmst(graph);
return 0;
}

