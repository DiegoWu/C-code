#include<iostream>
#include<vector> 
#include<algorithm> 
#include<cmath>
#include<bitset> 
#define ll long long 
using namespace std ;

int main(){

	ll n, l, r, ans= 0; 
	cin>>n>>l>>r; 
	bitset<60>bs(n); 
	for(int i=bs.size()-1; i>=0; i--){
		if(bs[i]){
			ll num= 1LL<< i, num1= (1LL<<(i+1))-1; 
			if(num>r||num1<l) continue; 
			if(num<l) num= l; 
			if(num1>r) num1= r; 
			ans+= num1-num+1; 
		}
	}
	cout<<ans<<endl;
}