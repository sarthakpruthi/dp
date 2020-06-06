#include<iostream> 
using namespace std;


//time n space n
int tillingbottomup(int n,int m,int dp[]){
	for(int i=0;i<=n;i++){
		
		if(i<m) dp[i]=1;
		else if(i==m) dp[i]=2;
		else dp[i]=dp[i-1]+dp[i-m];
	}
	return dp[n];
}

//topdown=recursove +memoisation
//time n^2 space n
int tillingtopdown(int n,int m,int dp[]){
	
	if(n<m) return 1;
	if(n==m) return 2;
	if(dp[n]) return dp[n];
	return dp[n]=tillingtopdown(n-1,m,dp)+tillingtopdown(n-m,m,dp);
}
//time 2^n space 1
int tillingrecursion(int n,int m){
	if(n<m) return 1;
	if(n==m) return 2;
	return tillingrecursion(n-1,m)+tillingrecursion(n-m,m);
	
}
int main() 
{ 
    int n,m;
    cin>>n>>m;
    int dp[n+1]={0};
   cout<<tillingbottomup(n,m,dp);  
} 
