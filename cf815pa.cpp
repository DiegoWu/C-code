#include<bits/stdc++.h> 
#define ll long long 
#define ld long double 
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
		ll a, b, c, d; 
		ld e, f; 
		cin>>a>>b>>c>>d; 
	
		e= (ld)a/(ld)b, f= (ld)c/(ld)d; 
		if(e== f) cout<<0<<endl;
		else if(a==0|| d== 0|| b==0|| c==0) cout<<1<<endl;
		else if(max((a*d), (b*c))%min((b*c), a*d)== 0) cout<<1<<endl;
		else cout<<2<<endl;
	}
}
