#include<bits/stdc++.h> 
#define ll long long 
#define maxn 1003
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n, m; 
	cin>>n>>m; 
	vector<string> v; 
	int rec[10], remain[10]; 
	string s, a="", ans= ""; 

	for(int j=1; j<=9; j++){
		s= ""; 
		for(int i=1; i<=n; i++){
			if(i==1) {
				rec[j]= j%m; 
				remain[j]= j%m; 
			}
			else{
				remain[j]= (remain[j]*10)%m; 
				rec[j]= (rec[j]+ remain[j])%m; 
			}

			s+= to_string(j); 
			if(rec[j]==0) {
				a= s; 
			}
		}
		if(ans.size()<= a.size()) ans= a; 
	}
	if(ans=="") cout<<-1<<endl;
	else cout<<ans<<endl;
	
}
