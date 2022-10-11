#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		ll n, k; 
		cin>>n>>k; 
		if(k%2==1){
			cout<<"YES"<<endl;
			for(ll i=1; i<=n; i+=2){
				cout<<i<<" "<<i+1<<endl;
			}
		}
		else if(k==2){
			cout<<"YES"<<endl;
			for(ll i=1; i<=n; i+=2){
				if((i+1+2)%4==0) cout<<i+1<<" "<<i<<endl;
				else cout<<i<<" "<<i+1<<endl;
			}
		}
		else if((2+k)%4!= 0) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			for(ll i=1; i<=n; i+=2){
				if((i+1+k)%4==0) cout<<i+1<<" "<<i<<endl;
				else cout<<i<<" "<<i+1<<endl;
			}
		}
	}
}
