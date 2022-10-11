#include<algorithm> 
#include<vector>
#include<iostream>
#include<cmath> 
#define ll long long 
#define INF 1000000000000000000
#define ceil 1000000
using namespace std; 

ll f(ll x, ll y){
	return(x*x*x+y*y*y+ x*x*y+ y*y*x); 
}
int main(){
	ll n, z= INF; 
	cin>>n; 
	int j= ceil; 
	for(int i=0; i<=ceil; i++){
		while(f(i, j)>= n&& j>=0){
			z= min(z, f(i, j)); 
			cout<<z<<endl;
			j--; 
		}
	}
	cout<<z<<endl;
}