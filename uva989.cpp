#include<cstring> 
#include<iostream> 
#include<vector> 
#include<algorithm>
#define n 10
using namespace std;
vector<vector<int> > m(n, vector<int>(n)); 
vector<vector<int> > row(n, vector<int>(n));
vector<vector<int> > col(n, vector<int>(n));
vector<vector<int> > mt(n, vector<int>(n));
vector<vector<int> > fix(n, vector<int>(n));
int f= 0, ans= 1, nn, gg= 0; 
void dfs(int x, int y){

	int flag= 0, z= y/nn, yu= y%(nn*nn); 
	if(x== nn*nn-1) yu++;
	if(x==y&&y==nn*nn-1&&fix[y][x]) f= 1;
	if(fix[y][x]) dfs((x+1)%(nn*nn), yu); 

	for(int i=1; i<nn*nn+1; i++){
		if(f||fix[y][x]) continue; 

		if(col[y][i]|| row[x][i]||mt[x/nn+z*nn][i]){
			flag++; 
			continue; 
		}
		col[y][i]= 1,row[x][i]= 1, mt[x/nn+z*nn][i]= 1;  
		m[y][x]= i; 
		dfs((x+1)%(nn*nn), yu); 

		col[y][i]= 0, row[x][i]= 0, mt[x/nn+z*nn][i]= 0; 
	}
	if(x==y&&y==nn*nn-1&&flag!= nn*nn) f= 1;
	if(flag== nn*nn) return; 

}
void solve(){
	while(cin>>nn){ 
		if(gg++) cout<<endl;
		for(int i=0;i<n; i++){
			for(int j=0; j<n; j++){
				col[i][j]= 0; 
				row[i][j]= 0; 
				mt[i][j]= 0; 
				fix[i][j]= 0; 
				f= 0; 
			}
		}
		for(int i=0; i<nn*nn; i++){
			int y= i/nn; 
			for(int j=0; j<nn*nn; j++) {
				cin>>m[i][j]; 
				fix[i][j]= m[i][j]; 
				if(m[i][j]== 0) continue; 
				col[i][m[i][j]]++;
				row[j][m[i][j]]++; 
				mt[j/nn+y*nn][m[i][j]]++; 
			}
		}
		dfs(0, 0);

		if(!f) cout<<"NO SOLUTION"<<endl; 
		else{
			for(int i=0; i<nn*nn; i++){
				for(int j=0; j<nn*nn; j++){
					if(j) cout<<" ";
					cout<<m[i][j]; 
				}
				cout<<endl;
			}
		}
	}
}
int main(){
	solve(); 
	return 0; 
}