#include<bits/stdc++.h>

#define ll long long 
#define maxn 10005
#define mp make_pair

using namespace std; 

vector<int> v; 
map<int, int> vis;  
void  query(int l, int r){
	cout<<"? "<<l<<" "<<r<<endl;
	cout.flush(); 
	for(int i=0; i<r-l+1; i++){
		int a; 
		cin>>a; 
		v.push_back(a); 
		vis[a]= 1; 
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
        int l= 1,  r= n, ans= -1;
        
		while(true){
			int mid= (r+l)/2; 
			query(l, mid); 

			vector<int> rec; 
			for(int i=l; i<=mid; i++){
				if(vis[i]== 1){
					rec.push_back(i); 
				}
			}
			v.clear(); 
			vis.clear(); 
			if(rec.size()==1){
				ans= rec[0]; 
				break; 
			}
			else if(rec.size()%2== 0) l= mid+1;
			
			else r= mid;
        
		}
		v.clear(); 
		vis.clear();
        
		cout<<"! "<<ans<<endl;
		cout.flush(); 
	}
}
