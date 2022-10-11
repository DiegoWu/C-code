#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#include<cmath> 
#include<map>
#define ll long long 
#define maxn 4005
#define mp make_pair
using namespace std; 
ll qp(ll a, ll b, ll c) {
    ll ans = 1; 
    a %= c; 
    while (b != 0) {
        if (b & 1) ans = ans * a % c; 
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}
bool miller_rabin(ll n, ll a){
	if(n==1) return false; 
	if((n & 1)== 0) return (n==2); 
	if(n== 61) return true;
	if(n== 7) return true; 
	int u= n-1, t= 0; 

	while((u&1)== 0){
		u>>= 1; t++; 
	}

	ll x= qp(a, u, n); 

	if(x==1|| x== n-1) return true; 

	for(int i=0; i<t-1; i++){
		x= x*x%n; 
		if(x== 1) return false;
		if(x== n-1) return true; 
	}
	return false; 
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;  
	while(cin>>i){
		
			if(i==  2147483647)
				cout<<"質數"<<endl;
				
			else if(miller_rabin(i, 2)== 1&& miller_rabin(i, 7)==1&& miller_rabin(i, 61)==1){ 
				cout<<"質數"<<endl;
			}
			else cout<<"非質數"<<endl;
		
	}
}
