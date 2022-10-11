#include<iostream>
#include<vector>

using namespace std; 
void solve(){
	int z= 0; 
	int n; 
	vector<int>vis(2002); 
	while(true){	

		if(z== 0){

			cin>>n; 
		}
		else {
			for(int i=1; i<n*2+2; i++){
				if(vis[i]== 0) {
					cout<<i<<endl; 
					cout<< flush; 
					vis[i]= 1; 
					break; 
				}
			}
			int res; 
			cin>>res; 
			if(vis[res]== 1) break;
			else vis[res]= 1; 
		}
		z++; 
	}

}

int main(){
	solve(); 
}