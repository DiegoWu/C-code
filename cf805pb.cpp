#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		string s; 
		cin>>s; 
		int cnt= 0, dif= 0; 
		map<char, int> vis; 
		for(int i=0; i<s.size(); i++){

			if(vis[s[i]]== 0) {
				vis[s[i]]= 1; 
				dif++; 
				if(dif==4){ 
					dif=1; 
					cnt++; 
					vis.clear(); 
					vis[s[i]]= 1; 
				}
			}
		}
		if(dif!= 0) cnt++; 
		cout<<cnt<<endl;
		
	}
}
