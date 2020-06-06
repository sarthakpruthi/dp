#include<iostream>
using namespace std;

long long int pairbottomup(long long int n,long long int dp[]){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) dp[i]=dp[i-1]+(i-1)*dp[i-2];
	return dp[n];
}
//topdown=recursion+memoisation
//time n space n
long long int countbinarytopdown(long long int n,long long int dp[]){
	if(n<=1) return 1;
	if(dp[n]) return dp[n];
	return dp[n]=countbinarytopdown(n-1,dp)+(n-1)*countbinarytopdown(n-2,dp);
}
//time 2^n soace 1
long long int countbinaryrecursion(int n){
	if(n<=1) return 2;
	//stay single and get answer for n-1 other values
	long long int op1=countbinaryrecursion(n-1);
	//pair with n-1 (any) and check for n-2 
	long long int op2=(n-1)*countbinaryrecursion(n-2);
	return op1+op2;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int dp[n+1]={0};
        cout<<pairbottomup(n,dp)<<endl;
	}
	return 0;
}
