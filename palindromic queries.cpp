#include<bits/stdc++.h>
using namespace std;
long long int dp[10005][10005];
long long int palindrome(string str,long long int l,long long int r){
	if(l>=r) return dp[l][r]=1;
	if(dp[l][r]!=-1) return dp[l][r];
	if(str[l]!=str[r]) return 0;
	return dp[l][r]=palindrome(str,l+1,r-1);
}
int main () {
	long long int n;
	cin>>n;
	string str;
	cin>>str;
	long long int t;
	for(int i=0;i<=n;i++){
	   for(int j=0;j<=n;j++) dp[i][j]=-1;}
	   cin>>t;
	while(t--){
     long long int l,r;
     cin>>l>>r;
      palindrome(str,l-1,r-1);
	  if(dp[l-1][r-1]==1) cout<<"YES"<<endl;
	  else cout<<"NO"<<endl; 
	}
	return 0;
}
