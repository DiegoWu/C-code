#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		if(n==1) cout<<1<<endl;
		else{
			vector<int> rec; 
			for(int i=n; i>=2; i-=2){
				rec.push_back(i-1), rec.push_back(i); 
			}
			if(n%2==1) rec.push_back(1); 
			reverse(rec.begin(), rec.end()); 
			for(int i=0; i<rec.size(); i++) cout<<rec[i]<<" ";
			cout<<endl;
		}
	}
}