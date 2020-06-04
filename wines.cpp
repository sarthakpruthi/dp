#include<bits/stdc++.h>
using namespace std;

//time n^2 space n^2
int winestopdown(int wines[],int n,int i,int j,int y,int dp[][100]){
	if(i>j) return 0;
	if(dp[i][j]) return dp[i][j];
	int op1=wines[j]*y+winestopdown(wines,n,i,j-1,y+1,dp);
	int op2=wines[i]*y+winestopdown(wines,n,i+1,j,y+1,dp);
	return dp[i][j]=max(op1,op2);
}
//time 2^n space 1
int winesrecursion(int wines[],int n,int i,int j,int y){
	if(i>j) return 0;
	int op1=wines[j]*y+winesrecursion(wines,n,i,j-1,y+1);
	int op2=wines[i]*y+winesrecursion(wines,n,i+1,j,y+1);
	return max(op1,op2);	
}
int main() 
{
	int wines[]={2,3,5,1,4};
	int n=sizeof(wines)/sizeof(int);
    int dp[100][100]={0};
    int i=0,j=n-1,y=1;
    cout<<winestopdown(wines,n,i,j,y,dp);
}
