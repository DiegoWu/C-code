#include<iostream>
#include<vector>
#include<queue> 
#define mp make_pair
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y, x1, y1, t= 0, cnt= 0; 
	string s; 
	cin>>n>>x>>y>>x1>>y1;
	vector<string>g(n); 
	int dx[4]= {1, 1, -1, -1}, dy[4]= {1, -1, 1, -1}; 
	vector<vector<int> >vis(n, vector<int>(n)); 
	for(int i=0; i<n; i++) cin>>g[i]; 
	queue<pair<int, int> > q; 
	q.push(mp(x-1, y-1)); 
	vis[x-1][y-1]= 1; 
	for(int i=0; i<4; i++)
		if(x1-1+dx[i]<0|| x1-1+dx[i]>n-1|| y1-1+dy[i]<0|| y1-1+dy[i]>n-1||g[x1-1+dx[i]][y1-1+dy[i]]== '#')
			cnt++; 
	if(cnt== 4|| abs(x-x1+y-y1)%2== 1) cout<<-1<<endl;
	else{
		while(!q.empty()){
			if(q.front().first== x1-1&&q.front().second== y1-1)break; 
			for(int i=0; i<4; i++){

				int curx= q.front().first, cury= q.front().second; 

				while(true){
					curx+= dx[i], cury+= dy[i];
					if(curx<0|| curx>n-1|| cury<0|| cury>n-1||g[curx][cury]== '#') break;
					if(vis[curx][cury]!= 0) continue; 
					if(abs(curx-x1+1+cury-y1+1)%2==1) continue; 
					q.push(mp(curx, cury)); 
					
					vis[curx][cury]= vis[q.front().first][q.front().second]+1; 
		 			if(curx== x1-1&&cury== y1-1) {t=1; break;}
				}
				if(t) break;
			}
			if(t) break; 
			q.pop(); 
		}
		if(!vis[x1-1][y1-1]) cout<<-1<<endl;
		else cout<<vis[x1-1][y1-1]-1<<endl;
	}

}