#include<iostream>
#include<vector>
#include<string> 
#include<algorithm> 
#include<map> 
#define ll long long 
#define INF 400005
using namespace std; 
struct edge{
	ll to, cost; 
}
int main(){

	int t; 
	cin>>t; 
	while(t--){
		int n, c= 0; 
		string s, s1; 
		map<string , int> mp, vis; 
		vector<int> dis(100); 
		for(int i=0; i<100; i++) dis[i]= INF; 
		cin>>n; 
		for(int i=0; i<n; i++) {
			int a, b; 
			cin>>s>>s1>>a>>b; 
			if(!mp[s]){ mp[s]= c, c++;} 
			if(!mp1[s1]){ mp[s1]= c, c++;} 
			
		}
		cin>>s>>s1; 
		for(int i=0; i<100; i++){
			
		}
	}
}