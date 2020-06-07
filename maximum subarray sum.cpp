#include<bits/stdc++.h>
using namespace std;
int maxsubsumspace(int a[],int n){
	int ans=INT_MIN,sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum<0) sum=0;
		if(ans<sum) ans=sum;
	}
	return ans;
}
int maxsubsum(int a[],int n){
	int dp[n]={0};
	dp[0]=a[0];
	int maxsum=a[0];
	for(int i=1;i<=n;i++){
		dp[i]+=dp[i-1]+a[i];
		maxsum=max(maxsum,dp[i]);
	}
	return maxsum;
}
int main(){
	int arr[5]={3,1,-1,-2,1};
	cout<<maxsubsumspace(arr,5);
}  

