#include<cstring> 
#include<iostream> 
#include<vector> 
#include<algorithm>
#define n 10
using namespace std;
int rec[10][10];  
vector<vector<int> > row(n, vector<int>(n));
vector<vector<int> > col(n, vector<int>(n));
vector<vector<int> > mt(n, vector<int>(n));
vector<vector<int> > fix(n, vector<int>(n));
int f= 0, ans= 0; 
void dfs(int x, int y){
	if(f){
		ans++; 
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(j) cout<<" "; 
				cout<<rec[i][j];  
			}
			cout<<endl;
		}
		cout<<endl;
		f= 0; 
	}
	int flag= 0, z= y/3, yu= y%9; 
	if(x== 8) yu++;
	if(x==y&&y==8&&fix[y][x]) f= 1;

	if(fix[y][x]) dfs((x+1)%9, yu); 

	for(int i=1; i<10; i++){
		if(fix[y][x]||f) continue; 

		if(col[y][i]|| row[x][i]||mt[x/3+z*3][i]){
			flag++; 
			continue; 
		}
		col[y][i]= 1,row[x][i]= 1, mt[x/3+z*3][i]= 1;  
		rec[y][x]= i; 
		if(x==y&&y==8) f= 1; 
		dfs((x+1)%9, yu);
		col[y][i]= 0, row[x][i]= 0, mt[x/3+z*3][i]= 0; 
	}

	if(flag== 9) return; 
}
void solve(){

	for(int i=0; i<9; i++){
		int y= i/3; 
		for(int j=0; j<9; j++) {
			cin>>rec[i][j]; 
			fix[i][j]= rec[i][j]; 
			col[i][rec[i][j]]= 1;
			row[j][rec[i][j]]= 1; 
			mt[j/3+y*3][rec[i][j]]= 1; 
		}
	}
	dfs(0, 0);
	cout<<"there are a total of "<<ans<<" solution(s)."<<endl;
}

int main(){
	solve(); 
	return 0; 
}
