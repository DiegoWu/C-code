#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

	int n, z= 0, p= 0, p1= 1, ans= 0, buf= 0, x= n; 
	cin>>n; 
	string s; 
	vector<int> vis; 
	cin>>s; 
	while(p1<n){
		if(s[p1]== 'R'){
			int z= 0; 
			p= p1- 1; 
			p1++;
			while(true){ 
				if(p<0|| p1>=n)  break; 
				if(s[p]== 'A'&& s[p1]=='C') {
					p--, p1++; 
					z++;  
				}
				else {
					p1--; 
					break; 
				}
			}
			if(z) {
				vis.push_back(z); 
			}
		}
		p1++; 
	}
	if(vis.size()) sort(vis.begin(), vis.end()); 
	for(int i=0; i<vis.size(); i++){
		if(vis[i]==1) {
			buf++;
			ans++; 
		}
		else if(vis[i]==2) ans+= 2;
		else {
			x= i; 
			break; 
		}
	}
	if(x){
		for(int i=x; i< vis.size(); i++){
			if(!buf)
				ans+= 2; 
			else if(buf>=vis[i]-2) {
				ans+= vis[i]; 
				buf-= vis[i]-2; 
			}
			else{
				ans+= buf+2; 
				buf= 0; 
			}
		}
	}
	cout<<ans<<endl;

}