#include<iostream>
#include<vector>
#include<string> 
#include<unordered_map> 
using namespace std; 
int main(){
	int n, m; 
	string ans= "yes"; 
	cin>>m>>n; 
	unordered_map<string, string> mm(m+1); 
	for(int i=0; i<n; i++){
		int u, v;
		cin>>u>>v;  
		string s, s1; 
		s= to_string(u), s1= to_string(v); 
		if(mm[s]== s1||u==v){
			ans= "Yes"; 
			break; 
		}
		mm[s]= s1; 
		mm[s1]= s; 
	}
	cout<<ans<<endl;
}
