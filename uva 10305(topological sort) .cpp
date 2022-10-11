#include<iostream>
#include<vector>
#include<deque> 
using namespace std; 
#define N 101
int main(){
	int n, m, a, b; 
	while(cin>>n>>m){
		vector<vector<bool> > adj(N, vector<bool>(N));
		vector<int> ref(N); 
		for(int i=0; i<m; i++){
			cin>>a>>b; 
			adj[a][b]= 1;
		}
		for(int i=1; i<n+1; i++)
			for(int j=1; j<n+1; j++) 
				if(adj[i][j]) ref[j]++; 
		deque<int> Q;
		for(int i=1; i<n+1; i++)
			if(!ref[i]) Q.push_back(i); 
		
		for(int k=1; k<n+1; k++){
			if(Q.empty()) break; 

			int st= Q.front(); Q.pop_front(); 
			ref[st]= -1; 
			cout<<st<< " "; 

			for(int i=1; i<n+1; i++){
				bool f= false; 
				if(adj[st][i]) {
					ref[i]--; 
					f= true; 
				}
				if(!ref[i]&&f) Q.push_back(i); 
			}
		}
		cout<<endl; 
	}
}