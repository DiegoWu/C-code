#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#define mod 998244353
#define ll long long 
using namespace std;

int main(){
	ll x, ans= 1; 
	cin>>x; 
	queue<ll> q; 
	q.push(x);  


	if(x<=100){
		while(!q.empty()){
			ll z= q.front()/2, zz= q.front()/2+1; 
			if(q.front()%2== 0) zz= z; 
		
			q.pop(); 
			if(z==2||z==3||z==4) {ans*= z, ans%= mod,  z= 0;} 
			if(zz==2||zz==3||zz==4) {ans*= zz, ans%= mod, zz= 0;}
			if(zz) q.push(zz); 
			if(z) q.push(z);  

		}
		cout<<ans<<endl;

	}
	
}