/*Shaik Abbu*/
#include<iostream>
using namespace std;
#define I 32467
int cost[10][10];
int dist[20]={I};
void Dijkistra(int s,int n)
{
    int i,j,u,v,min=I,cnt=1;
    int vis[n+1]={0};
    for(int i=1;i<=n;i++)
    {  
    	dist[i]=cost[s][i];
    }
    vis[s]=1;
    dist[s]=0;
    while(cnt<=n)
    {
    	min=I;
    	for(int i=1;i<=n;i++)
    	{
    		if(vis[i]==0 && dist[i]<min)
    		{
    			min=dist[i];
    			v=i;
    		}
    	}
    	vis[v]=1;
    	for(j=1;j<=n;j++)
    	{
    		if(!vis[j] &&cost[v][j]!=I && dist[j]>dist[v]+cost[v][j])
    			dist[j]=dist[v]+cost[v][j];
    	}
    	++cnt;
    }
}
int main()
{
	int n;
	cout<<"Enter no.of vertices ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=I;
		}
	}
	int s;
	cout<<"Enter source : ";
	cin>>s;
	Dijkistra(s,n);
	cout<<"The Single Sources shortest path is : ";
	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
			cout<<"("<<s<<" "<<i<<")"<<"-->"<<dist[i]<<"\n";
	}
	return 0;
}
