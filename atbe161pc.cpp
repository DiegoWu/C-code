#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n; 
	vector<string> v(n), ans; 
	map<string, int> m; 
	for(int i=0; i<n; i++){
		cin>>v[i]; 
	}
	for(int i=0; i<n; i++){
		if(m[v[i]]== 0) ans.push_back(v[i]); 
		else ans.push_back(v[i]+'('+to_string(m[v[i]])+')'); 
		m[v[i]]++;
	}
	for(int i=0; i<n; i++) cout<<ans[i]<<endl;
}
