#include<bits/stdc++.h>
using namespace std;
//time=2^n space=1
int fibrec(int n){
	if(n==0||n==1) return n;
	int ans=fibrec(n-1)+fibrec(n-2);
	return ans;
}
//time n+(n-2) space=n+1
int fibtopdown(int n,int dp[]){
	if(n==0 or n==1) return n;
	//look up
	if(dp[n]) return dp[n];
	int ans=fibtopdown(n-1,dp)+fibtopdown(n-2,dp);
	//save before returning
	return dp[n]=ans;
}
//time n space n+1
int fibbottomup(int n){
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}
//time n space 1
int fibbottomupspaceoptimised(int n){
	if(n==0 or n==1) return n;
	//coz we need last 2 values and not the complete array to compute current value
	int a=0,b=1,c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
//matrix exponentiation  time log(n)  
int main()
{
	int n;
	 cin>>n;
	 //cout<<fibrec(n);
	 int dp[n+1]={0};
	 //cout<<fibtopdown(n,dp);
	 //cout<<fibbottomup(n);
	 cout<<fibbottomupspaceoptimised(n);
}
