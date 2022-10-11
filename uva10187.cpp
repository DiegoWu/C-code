#include<iostream>
#include<vector>
#include<map> 
#include<queue> 
#include<algorithm>
#include<stdexcept> 
#define mp make_pair 
#define ll long long
#define INF 100000
#define mod 998244353
#define maxn 1001
using namespace std;
struct edge{
	int to, time, arr; 
}; 
struct weight{
	int node, st, bld; 
}; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin>>t; 
    while(t--){
    	vector<vector<edge> > g(maxn); 
    	//using P= pair<int, int>;  
    	priority_queue<weight, vector<weight>, greater<weight> > pq; 
    	map<string, int> m; 
    	vector<int> blood(maxn); 
    	for(int i=0; i<maxn; i++) blood[i]= INF; 
    	int n, c= 0; 
    	string s, e; 
    	cin>>n; 
    	for(int i=0; i<n; i++){
    		string st, end; 
    		int time, time1; 
    		cin>>st>>end>>time>>time1; 
    		if(time<18|| time+time1>30) continue; 
    		if(!m[st]) {m[st]= c, c++;}
    		if(!m[end]) {m[end]= c, c++;}  

    		g[m[st]].push_back((edge){m[end], time, time+time1}); 
    		
    	}
    	cin>>s>>e; 
    	pq.push((weight){m[s], 18,  0}); 
    	blood[m[s]]= 0; 
    	while(!pq.empty()){
    		const auto [v, be, d]= pq.top(); 
    		pq.pop(); 
    		if(blood[v]!= d) continue; 
    		int bld= 0; 
    		for(auto [to, st, end]: g[v]){
    			
    			if(blood[to]> blood[v]+ bld) {
    				if(be<= st) {
    					blood[to]= blood[v]+bld; 
    					if(st+end>30) pq.push((weight){to, st+end-30,  blood[to]}); 
    					else pq.push((weight){to, st+end-30,  blood[to]}); 
    				}
    			}
    		}
    	}
    	
    	cout<<blood[m[e]]<<endl; 
    }
   
    
}
