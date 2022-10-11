#include<iostream>
#include<vector>
#define ll long long 

using namespace std; 

int main(){
	int n, k, m; 
	while(cin>>n>>k>>m&&n&&k&&m){
		int cnt= 0, ans, re= 0, plus, st= 1, ori_n= n, need= n-m; 
		while(true){
			//if(cnt==n-m) break; 
			if(n/k>= need){
				ans= (st+k*(need)-1)%ori_n; 
				break; 
			}
			re= n%k, plus= n/k; 
			st= re+n;
			cnt+= plus; 
			n= n-plus+re; 
			need-= cnt;

		}
		cout<<ans<<endl;
	}
}