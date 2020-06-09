#include<bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int y){
	if(y==0) return 1;
	long long int ans=power(x,y/2);
	if(y%2==0 ) return ans*ans%1000000007;
	else return x*ans*ans%1000000007;
}
long long int balipairs(long long int n,long long int oo,long long int ee,long long int oe){
     if(ee==n) return 0;
     //even's and odd's even times that make even
     if(oe==0&&oo%2==0) return 0;
     //even's and odd's odd times make odd
     else if(oe==0&&oo%2!=0) return power(2,n)%1000000007;
     //sum before oe will either be even or odd so we have "one way" only even->odd or odd->even to get odd
     return power(2,n-1)%1000000007;
}
int main(){
	long long int n,l,r,ee=0,oo=0,oe=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(l%2==0&&r%2==0) ee++;
		else if(l%2!=0&&r%2!=0) oo++;
		else oe++;
	}
	cout<<balipairs(n,oo,ee,oe);
}  

