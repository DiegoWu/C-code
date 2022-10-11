#include<iostream>
#include<vector>
#include<string> 
#include<deque> 
using namespace std; 

int main(){
	string s; 
	vector<string>v; 
	
	while(cin>>s&&s!="#") v.push_back(s); 
	vector<vector<int> > vis(v.size()+1, vector<int>(v.size()+1)); 
	vector<vector<int> > adj(26, vector<int> (26)); 
	vector<int> vs(26);
	vector<int> ref(26); 
	for(int k=0; k<20; k++){
		for(int i=0; i<v.size()-1; i++){
			if(k>=v[i].size()) continue; 
			for(int j=i+1; j<v.size(); j++){
				if(k>=v[j].size()||vis[i][j]) continue; 
				if(k!= 0){
					if(v[j][k-1]!= v[i][k-1]) {
						vis[i][j]= 1;
						continue; 
					}
				}
				if(v[i][k]== v[j][k]) continue; 
				adj[v[i][k]-65][v[j][k]-65]= 1;
				vs[v[i][k]-65]= 1; 
				vs[v[j][k]-65]= 1; 
			}
		}
	}
	deque<int> q; 
	for(int i=0; i<26; i++)
		for(int j=0; j<26; j++) 
			if(adj[i][j]) 
				ref[j]++; 
			
	while(true){
		for(int j=0; j<26; j++) if(!ref[j]&& vs[j]) q.push_back(j); 
		if(q.empty()) break; 
		int st= q.front(); q.pop_front(); 
		ref[st]= -1; 
		cout<<char(st+65);
    
		for(int j=0; j<26; j++)
			if(adj[st][j]) ref[j]--; 

		}
	cout<<endl;
}
