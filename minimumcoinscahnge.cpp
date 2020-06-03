#include<bits/stdc++.h>
using namespace std;


//time worst case n^(number of coins) space 1
int mincoinchangerecursion(int n,int coins[],int m){
	if(n==0) return 0;
	int ans=INT_MAX;
	for(int i=0;i<m;i++){
		if(n-coins[i]>=0){
		int y= mincoinchangerecursion(n-coins[i],coins,m)+1;
		ans=min(ans,y);
		}
		
	}
	return ans;
}
//top down =recursion+memoisation
//time n*number of coins   space n+1
int mincoinchangetopdown(int n,int coins[],int m,int dp[]){
	if(n==0) return 0;
	if(dp[n]) return dp[n];
	int ans=INT_MAX;
	for(int i=0;i<m;i++){
		if(n-coins[i]>=0){
			int y=mincoinchangetopdown(n-coins[i],coins,m,dp)+1;
			ans=min(ans,y);
		}
	}
	return dp[n]=ans;
}
//bottom up
//time n*number of coins space n+1
int mincoinchangebottomup(int n,int coins[],int m,int dp[]){
	dp[0]=0;
	for(int j=1;j<=n;j++){
		int ans=INT_MAX;
	for(int i=0;i<m;i++) if(j-coins[i]>=0) ans=min(ans,dp[j-coins[i]]+1);
	dp[j]=ans;
   }
   return dp[n];
}
int main() 
{
	int n=11;
	int coins[3]={1,3,10};
    int dp[n+1]={0};
    cout<<mincoinchangebottomup(n,coins,3,dp);
}
