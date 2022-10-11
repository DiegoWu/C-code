#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin>>n>>a>>b; 
	n++; 
	ll ans= 0; 
	if(b>=a) ans= max(n-a, 0ll); 
	else ans= (n/a-1)*b+min(n%a, b); 

	cout<<max(ans, 0ll)<<endl;

}
