#include<bits/stdc++.h>

#define ll long long 
#define maxn  9223372036854775807
#define mp make_pair
 
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n;
	int z= 21, x; 
	if(n>=60) z++; 
	x= n%60; 
	if(x<10) cout<<z<<":"<<0<<x<<endl;
	else cout<<z<<":"<<x<<endl;
}
