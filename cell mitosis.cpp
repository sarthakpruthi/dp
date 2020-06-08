#include<bits/stdc++.h>
using namespace std;

long long int cellmitosis(long long int n,long long int x,long long int y,long long int z){
	long long int dp[n+1];
	dp[0]=dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		//for i+1 go i/2 and come to i and increase to i+1
		if(i%2==0) dp[i]=min(min(dp[i/2]+x,dp[i-1]+y),dp[i/2]+x+y);
		//can't go on i/2 for odd
		else dp[i]=min(dp[(i+1)/2]+x+z,dp[i-1]+y);
	}
	return dp[n];
}
int main(){
	long long int n,x,y,z;
	cin>>n>>x>>y>>z;
	cout<<cellmitosis(n,x,y,z);
}  

