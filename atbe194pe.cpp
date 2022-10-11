#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n, m;
	cin>>n>>m; 
	vector<int> v(n); 
	for(int i=0; i<n; i++) cin>>v[i]; 

	map<int, int> mm; 
	set<int> st; 

	for(int i=0; i<m; i++) mm[v[i]]++; 
	for(int i=0; i<n+1; i++) st.insert(i); 
	for(int i=0; i<m; i++)  st.erase(v[i]);
	
	int sm= *st.begin(); 

	for(int i=m; i<n; i++){
		mm[v[i]]++, mm[v[i-m]]--; 
		if(mm[v[i-m]]<= 0) mm[v[i-m]]= 0, st.insert(v[i-m]);
		st.erase(v[i]);
		sm= min(sm, *st.begin()); 
	}
	cout<<sm<<endl;
}
