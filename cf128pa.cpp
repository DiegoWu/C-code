#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<bitset> 
#include<map>
#define ll long long 
#define INF 1000000001
#define mod 998244353
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; 
	cin>>t; 
	while(t--){
		int l1, r1, l2, r2; 
		cin>>l1>>r1>>l2>>r2; 
		if(l2> r1||r2<l1){
			cout<<l1+l2<<endl;
		}
		else cout<<max(l1, l2)<<endl;
		
	}
}
