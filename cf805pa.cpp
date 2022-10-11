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
		string m;
		cin>>m;
		int z= stoi(m); 
		int x= 1,s= 1, ans; 
		while(true){
			if(s== m.size()){
				ans= z-x; 
				break; 
			}
			x*= 10; 
			s+= 1;
		}
		cout<<ans<<endl;
	}
}
