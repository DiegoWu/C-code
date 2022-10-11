#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<sstream>
#define ll long long 
#define INF 100000000000
using namespace std; 

int main(){
	int n, kk, a, node= 0; 
	string data;
	stringstream ss; 
	while(cin>>n>>kk){
		ss.str(""); 
		ss.clear(); 
		vector<ll> cost(n); 
		vector<int>v;
		vector<int> vis(100); 
		vector<ll> p(100);
		vector<ll> d(100);
		int adj[5][100][100]= {0};  
		ll aj[100][100]= {INF}; 
		for(int j=0; j<100; j++) {
			d[j]= INF; 
			p[j]= j; 
		}
		for(int i=0; i<n; i++)
			cin>>cost[i]; 
		for(int k=0; k<n; k++){
			int num;
			cin.ignore(); 
			getline(cin, data); 
			ss.clear();
			ss << data;
			while (true){ 
				if(ss.fail()) break; 
				ss>> num;
				v.push_back(num); 
			}
			for(int i=0; i<v.size()-2; i++){
				for(int j=i+1; j<v.size()-1; j++){
					adj[k][v[i]][v[j]]= cost[k]; 
					adj[k][v[j]][v[i]]= cost[k];
					aj[v[i]][v[j]]= min(aj[v[i]][v[j]], cost[k]); 
					aj[v[j]][v[i]]= min(cost[k], aj[v[j]][v[i]]);
				}
			}
			v.clear();
		}
		d[0]= 0;
		for(int i=0; i<100; i++){
			ll cc= INF; 
			for(int j=0; j<100; j++){
				if(vis[j]) continue; 
				if(d[j]< cc) {
					cc= d[j]; 
					node= j; 
				}
			}
			vis[node]= 1; 
			p[node]= 0; 
			for(int k=0; k<n; k++){
				for(int j=0; j<100; j++){
					if(!adj[k][node][j]||vis[j]) continue; 
					if(d[j]> abs(adj[k][node][j]*(node-j))+d[node]){
						if(p[j]== j) d[j]= abs(adj[k][node][j]*(node-j))+d[node];
						else if(aj[p[node]][node]!= adj[k][node][j]) 
							d[j]= abs(adj[k][node][j]*(node-j))+d[node]+60; 
						else d[j]= abs(adj[k][node][j]*(node-j))+d[node]; 
						p[j]= node; 
						aj[node][j]= adj[k][node][j]; 
					}
				}
			}n
	 
			cout<<node<<" "<<d[node]<<endl;
		}
		if(d[kk]== INF) cout<<"IMPOSSIBLE"<<endl;
		else cout<<d[kk]<<endl; 
	}
}