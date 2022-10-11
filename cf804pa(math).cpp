#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		 ll n; 
		 cin>>n;
		 if(n%2== 1) cout<<-1<<endl;
		 else cout<<n/2<<" "<<n/2<<" "<<0<<endl;
	}
}
