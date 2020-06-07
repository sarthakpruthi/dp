#include<bits/stdc++,h>
using namespace std;
//1d
int count( int S[], int m, int n ) 
{ 
    int table[n+1]; 
    memset(table, 0, sizeof(table)); 
    table[0] = 1; 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 
//2d
int countagain(int coins[],int m,int n){
	int table [n+1][n+1];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=n;j++){
			if(j==0) table[i][j]=1;
			//if coins i is greater than we need to exclude the current coin value and copy the previous coins value 
			else if(j-coins[i]<0) table[i][j]=table[i-1][j];
			//here we have 2 choices either to include(copy the value by subtracting coin i value) the coin or to exclude(copy the previous coin value) the coin
			else table[i][j]=table[i-1][j]+table[i][j-coins[i]];
		}
		return table[i][j];
	}
}
int main() {
	long long int n,m;
	cin>>n>>m;
	long long int coins[m];
	for(int i=0;i<m;i++) cin>>coins[i];
	cout<<coinchange(coins,m,n);
	return 0;
}
