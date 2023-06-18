/*Shaik Abbu*/
#include<iostream>
using namespace std;
#define I 32467
int cost[20][20];
int res[2][10];
void display(int V)
{
	cout<<"The  Graph with Edges and Vertices is : ";
	int sum=0;
	cout<<"\n";
	for(int i=0;i<V-2;i++)
	{
		int val=cost[res[0][i]][res[1][i]];
		cout<<"["<<res[0][i]<<" "<<res[1][i]<<"]"<<"-->"<<val;
		sum+=val;
		cout<<"\n";
	}
	cout<<"Total Cost is : "<<sum;
}
void PrimsMST(int V,int near[])
{
	int n=V-1;
	int u,v,i,j,min=I,k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cost[i][j]<min && cost[i][j]!=0)
			{
				min=cost[i][j];
				u=i;
				v=j;
			}
		}
	}
	res[0][0]=u;
	res[1][0]=v;
	near[u]=0;
	near[v]=0;
	for(i=1;i<=n;i++)
	{
		if(near[i]!=0)
		{
		 if(cost[i][u]<cost[i][v])
			near[i]=u;
		 else
			 near[i]=v;
		}
	}
	for(i=1;i<n-1;i++)
	{
		min=I;
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0 && cost[j][near[j]]<min)
			{
				min=cost[j][near[j]];
				k=j;
			}
		}
		res[0][i]=k;
		res[1][i]=near[k];
		near[k]=0;
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
				near[j]=k;
		}
	}
	cout<<"\n";
}
int main()
{
	  int V;
	  cout<<"Enter no.of Vertices and Edges : ";
	  cin>>V;	 
	  int near[V];
	  for(int i=0;i<V;i++)
	  {
	  	for(int j=0;j<V;j++)
	  	{
	  		cin>>cost[i][j];
	  	}
	  }
	  for(int i=0;i<V;i++)
	  {
	  	for(int j=0;j<V;j++)
	  	{
	  		if(cost[i][j]==0)
	  		    cost[i][j]=I;
	  	}
	  }
	  PrimsMST(V,near);
	  display(V);
	return 0;
}
