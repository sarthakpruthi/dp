#include<iostream> 
using namespace std;

//also other way is general formula 2nCn/(n+1)
unsigned int catalanformula(unsigned int n){
	if(n<=1) return 1;
	unsigned long int ans=1;
	 
	for(int i=0;i<n;i++){
		ans*=2*n-i;
		ans/=i+1;
	} 
    return ans/(n+1);	
}

//time n^2 space n+1
unsigned long int catalanbottomup(unsigned int n,unsigned long int dp[]){
	if(n<=1) return 1;
	dp[0]=dp[1]=1;
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n;i++){
			dp[j]+=dp[i-1]*dp[j-i];
		}
	}
	return dp[n];
}
 //time n*n space n
unsigned long int catalantopdown(unsigned int n,unsigned long int dp[]){
	if(n<=1) return 1;
	
	if(dp[n]) return dp[n];
	
	unsigned long int ans=0;
	for(int i=1;i<=n;i++)  ans+=catalantopdown(i-1,dp)*catalantopdown(n-i,dp);
	
	return dp[n]=ans;
}
//time 2^n space 1
unsigned long int catalanrecursion(unsigned int n) 
{ 
    if (n <= 1) return 1; 
    unsigned long int res = 0; 
    for (int i=2; i<=n; i++)  res += catalanrecursion(i-1)*catalanrecursion(n-i); 
    return res; 
} 
int main() 
{ 
    int n;
    cin>>n;
    //unsigned long int dp[n+1]={0};
    cout << catalanformula(n); 
    return 0; 
} 
