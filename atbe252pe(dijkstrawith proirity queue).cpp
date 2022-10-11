#include<bits/stdc++.h>
#define ll long long 
#define INF 10000000005
#define maxn 200005

using namespace std; 

struct edge{
	ll  aim, cost, idx; 
}; 
int main(){
    
	ll n, m, a, b, c; 
	cin>>n>>m; 
	vector<vector<edge> >g(maxn);  
	vector<ll> dis(maxn, 1LL<<60);
	vector<int> idx(maxn); 
	
	for(int i=0; i<m; i++){
		cin>>a>>b>>c; 
		g[a-1].push_back((edge){b-1,c,i}); 
		g[b-1].push_back((edge){a-1,c,i}); 

	}
 	dis[0]= 0; 
	using P=pair<ll,int>;
	priority_queue<P,vector<P>,greater<P> > pq;
	pq.push(make_pair(0,0));
	while(!pq.empty()){
		const auto [d, v]= pq.top();
        pq.pop();
        if(dis[v]!= d) continue;
        
		for(auto[vt, c, id]: g[v]){
			//cout<<vt+1<<" "<<dis[vt]<<endl;
			if(dis[vt]> dis[v]+ c) {
				dis[vt]= dis[v]+c; 
				pq.push(make_pair(dis[vt], vt));
				idx[vt]= id; 
				//cout<<"true"<<endl;
				//cout<<vt+1<<" "<<dis[vt]<<endl;
			} 
		}
		//cout<<"next"<<endl;

	}
	for(int i=1; i<n; i++) cout<<idx[i]+1<<" "; 
	cout<<endl;
}
