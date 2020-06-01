#include<bits/stdc++.h>
using namespace std;
//time =3^n(worst to worst) space= 1 
int minstepsto1_recursion(int n){
	if(n==1) return 0;
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	if(n%3==0) op1= minstepsto1_recursion(n/3);
	if(n%2==0) op2= minstepsto1_recursion(n/2);
	op3=minstepsto1_recursion(n-1);
	return min(min(op1,op2),op3)+1;
}
//topdown=recursion+memoization 
//time=n+n space=n+1
int minstepsto1_topdown(int n,int dp[]){
	if(n==1) return dp[n]=0;
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	if(dp[n]) return dp[n];
	if(n%3==0 ) op1=minstepsto1_topdown(n/3,dp);
	if(n%2==0) op2=minstepsto1_topdown(n/2,dp);
	op3=minstepsto1_topdown(n-1,dp);
	return dp[n]=min(min(op1,op2),op3)+1;
}
//bottom up=> memoization w/o recursion
//time =n,space=n+1
int minstepsto1_bottomup(int n,int dp[]){
	dp[1]=0;
	int op1,op2,op3;
	for(int i=2;i<=n;i++){
		op1=op2=op3=INT_MAX;
		if(i%3==0) op1=dp[i/3];
		if(i%2==0) op2=dp[i/2];
		op3=dp[i-1];
		dp[i]=min(min(op1,op2),op3)+1;
	}
  return dp[n];
}
int main() 
{
	int n=11;
//	cout<<minstepsto1_recursion(n);
    int dp[n+1]={0};
	cout<<minstepsto1_bottomup(n,dp); 
}
