#include<iostream>
#include<map>
#include<unordered_map>
#include<queue> 
#include<string> 
#define ll long long 
using namespace std; 

int main(){
	ll x; 
	int n;
	cin>>n>>x; 
	queue<ll> q; 
	map<ll, int> m; 

	m[x]= 0; 
	q.push(x); 

	while(!q.empty()){
		ll dgt= q.front(); 
		
		q.pop(); 
		string s= to_string(dgt);
		if(s.size()==n){
			cout<<m[dgt]<<endl;
			return 0; 
		}
		for(auto i: s){
			
			if(i== '1'|| i== '0') continue; 
			ll temp= dgt* int(i-'0');  
			if(m.count(temp)) continue; 
			m[temp]= m[dgt]+1;
			q.push(temp); 
		}
	}
	cout<<-1<<endl;
}