#include<bits/stdc++.h>

#define ll long long 
#define maxn 92233720368547
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, as=0, bs= 0, ans= 0, abss= 0; 
	cin>>n; 
	vector<string> v(n);
	for(int i=0; i<n; i++) cin>>v[i]; 

	for(int i=0; i<n; i++){
		for(int j=1; j<v[i].size(); j++){
			if(v[i][j]== 'B'&& v[i][j-1]== 'A') ans++; 

		}
		if(v[i][0]== 'B'&& v[i][v[i].size()-1]== 'A') abss++; 
		else if(v[i][0]== 'B') bs++; 
		else if(v[i][v[i].size()-1]== 'A') as++; 
	}
	if(as==0&& bs==0) cout<<max(ans, ans+abss-1)<<endl;
	else
		cout<<ans+min(as, bs)+abss<<endl;
	
}

