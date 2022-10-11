#include<bits/stdc++.h>

#define ll long long 
#define maxn  9223372036854775807
#define mp make_pair
 
using namespace std; 


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; 
	cin>>n>>q; 
	string s; 
	cin>>s; 
	int pos= 0; 
	while(q--){
		int a, b; 
		cin>>a>>b;
		pos%= n; 
		if(a==2) {
			int z= b-(pos%n); 
			//int z= (b-pos)%n; 
			if(z<= 0) z+= n;
			//cout<<z<<endl;
			cout<<s[z-1]<<endl;
			
		}
		else pos+= b; 
	}
}

