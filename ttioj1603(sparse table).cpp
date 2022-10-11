#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 
#define maxn 100000
using namespace std; 

vector<vector<long long> > sp(18, vector<long long> (maxn));
vector<vector<long long> > sp1(18, vector<long long> (maxn));

vector<long long>  arr(maxn); 
void solve(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		long long er;
		cin>>er;
		arr[i]= er; 
	}
	for(int i=0; i<18; i++){
		for(int j=0; j<n-(1<<i)+1; j++){
			if(i== 0) sp[i][j]= arr[j];
			else sp[i][j]= min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	} 
	
	for(int i=0; i<18; i++){
		for(int j=0; j<n-(1<<i)+1; j++){
			if(i== 0) sp1[i][j]= arr[j];
			else sp1[i][j]= max(sp1[i-1][j], sp1[i-1][j+(1<<(i-1))]);
		
		}
	}
	while(m--){
		int x, y; 
		cin>>x>>y; 
		int a= min(x, y); 
		int b= max(x, y); 
		int z=log2(b-a+1);
		
		if(log2(b-a+1)== int(log2(b-a+1))) cout<< sp1[z][a-1]- sp[z][a-1]<<endl;
		else cout<<max(sp1[z][a-1], sp1[z][b-(1<<z)])- min(sp[z][a-1], sp[z][b-(1<<z)])<<endl;
		
	}
}

int main(){

	solve(); 
	return 0; 
}