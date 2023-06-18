/* Shaik Abbu */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,w;
	cin>>n>>w;
	int wt[n],val[n];
	for(auto &it:wt)
		cin>>it;
	for(auto &it:val)
		cin>>it;
	int dp[n+1][w+1];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(wt[i-1]<=j)
			{
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][w];
	return 0;
}