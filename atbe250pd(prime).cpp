#include<iostream>
#include<cmath> 
#include<vector> 
#define maxn 1000000
#define ll long long 
using namespace std; 

vector<int> notprime(maxn+1); 
vector<int> numprime(maxn+1); 
void e_sieve(){
	notprime[1]= 1;
	numprime[1]= 1;  
	for(int i=2; i<sqrt(maxn+1); i++){
		if(!notprime[i]){
			for(int j= i*2; j<=maxn; j+= i){
				notprime[j]= 1; 
				numprime[j]= 1; 
			}
		}
	}
	numprime[2]= 1; 
	for(int i=3; i<maxn+1; i++)
		numprime[i]+= numprime[i-1];
	
	
}
int main(){
	ll n, ans= 0; 
	cin>>n; 
	e_sieve(); 
	for(int i=3; pow(i, 3)<=n; i++){
		//cout<<"i: "<<i<<endl;
		if(!notprime[i]){
			if((ll)(n/pow(i, 3))<=1) continue;
			ll x= min((ll)(i-1), (ll)(n/pow(i, 3))); 
			//cout<<numprime[x]<<endl;
			ans+= x-numprime[x]; 
			//cout<<"value: "<<ans<<endl;
		}
	}
	cout<<ans<<endl; 
}