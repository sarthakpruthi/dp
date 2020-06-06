#include<iostream>
using namespace std;

long long int countbinarybottomup(long long int n,long long int dp[]){
	if(n==1) return 1;
	dp[1]=2;
	dp[2]=3;
	for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}
long long int countbinarytopdown(long long int n,long long int dp[]){
	if(n==1) return 2;
	if(n==2) return 3;
	if(dp[n]) return dp[n];
	return dp[n]=countbinarytopdown(n-1,dp)+countbinarytopdown(n-2,dp);
	
}
long long int countbinaryrecursion(int n){
	if(n==1) return 2;
	if(n==2) return 3;
	//put 0 and get answer for n-1 other values
	long long int op1=countbinaryrecursion(n-1);
	//put 1 and check for n-2 other coz at n-1 will become fixed with 0
	long long int op2=countbinaryrecursion(n-2);
	return op1+op2;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int dp[n+1]={0};
        cout<<countbinarybottomup(n,dp)<<endl;
	}
	return 0;
}
