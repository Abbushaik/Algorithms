#include<iostream>
#define I 32467
using namespace std;
int res[2][10];
int edges[20][20];
void display(int V)
{
	cout<<"The Minimum Cost Spanning Tree is : ";
	for(int i=0;i<V-1;i++)
	{
		cout<<"("<<res[0][i]<<" "<<res[1][i]<<")"<<"\n";
	}
}
void unioun(int u,int v,int set[])
{
	if(set[u]<set[v])
	{
		set[u]+=set[v];
		set[v]=u;
	}
	else
	{
		set[v]+=set[u];
		set[u]=v;
	}
}
int find(int u,int set[])
{
	int x=u;
	int v=0;
	while(set[x]>0)
	{
		x=set[x];
	}
	while(u!=x)
	{
		v=set[u];
		set[u]=x;
		u=v;
	}
	return x;
}
// 7 vertices and 9 edges
void Krushkals(int ver,int edg)
{
	int set[ver+1]={-1,-1,-1,-1,-1,-1,-1,-1};
    int included[edg] {0};
	int i=0,j,u,v,min=I,k;
	while(i<ver-1)
	{
		min=I;
		u=0,v=0,k=0;
		for(int i=0;i<ver;i++)
		{
			for(int j=0;j<edg;j++)
			{
				if(included[j]==0 && edges[i][j]<min)
				{
					min=edges[i][j];
					u=i;
					v=j;
					k=j;
				}
		   }
		}
	   if(find(u,set)!=find(v,set))
	   {
		 res[0][i]=u;
		 res[1][i]=v;
		  unioun(find(u,set),find(v,set),set);
		  i++;
	    }
        included[k]=1;
	}
}
int main()
{                                                                                                                                                                                                                                                                          
	int v,u;
	cout<<"Enter no.of vertices & edges : ) : ";
	cin>>v>>u;
	for(int i=0;i<=v;i++)
	{
		for(int j=0;j<u;j++)
		{
			cin>>edges[i][j];
		}
	}	
	for(int i=0;i<=v;i++)
	{
		for(int j=0;j<u;j++)
		{
			if(edges[i][j]==0)
			   edges[i][j]=I;
		}
	}
	Krushkals(v,u);
	display(v);
	return 0;
}