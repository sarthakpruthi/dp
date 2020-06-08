#include<bits/stdc++.h>
using namespace std;
//optimised time n space n+1
int laddersliding(int n,int k,int dp[]){
	dp[0]=dp[1]=1;
//	int sum_k=2;
//	for(int i=2;i<=k;i++) {
//		dp[i]+=sum_k;
//		sum_k+=dp[i];
//	}
//	int st=0;
//	sum_k-=dp[st++];
//	for(int i=k+1;i<=n;i++){
//		dp[i]=sum_k;
//	  sum_k+=dp[i]-dp[st++];	
//	}
//more optimised
   for(int i=2;i<=k;i++) dp[i]=2*dp[i-1];
   for(int i=k+1;i<=n;i++) dp[i]=2*dp[i-1]-dp[i-1-k];
    
	return dp[n];
}

//time n^2 space n
int ladderbottomup(int n,int k){
	int dp[n+1]={0};
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++) if(i-j>=0) dp[i]+=dp[i-j]; else break;
	}
	return dp[n];
}
//topdown-recursion+memoisation
//time n^2 space n
int laddertopdown(int n,int k,int dp[]){
	if(n==0||n==1) return 1;
	if(dp[n]) return dp[n];
	for(int i=1;i<=k;i++){
		if(n-i>=0) dp[n]+=laddertopdown(n-i,k,dp);
	}
	return dp[n];
}
//time n^(n-k+1) space 1
int ladderrecursion(int n,int k){
	if(n==0||n==1) return 1;
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0) ans+=ladderrecursion(n-i,k);
	}
	return ans;
}
int main(){
	int n=7,k=4;
	int dp[n+1]={0};
	cout<<laddersliding(n,k,dp);
}  

