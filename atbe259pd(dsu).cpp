#include<bits/stdc++.h>

#define ld long double
#define maxn 3005
#define mod 1000000007
#define mp make_pair

using namespace std; 
ld x, y, xx1, yy1; 
int start, eend; 
int pr[maxn]; 
bool xx(ld x1,ld y1,ld r1, ld x2,ld y2,ld r2) { 
	ld s; 
	s = sqrt(((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1))); 
	if(s<=r2+r1&&s>=abs(r2-r1)) return true; 
	else return false; 
}
struct p{
	ld x, y, c; 
}; 
string ans= "No"; 

int find(int fa){
	if(pr[fa]== fa) return fa; 
	return pr[fa]= find(pr[fa]); 
}
void Union(int a, int b){
	int fa= find(a), fb= find(b); 
	pr[fa]= pr[fb]; 

}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n; 
	
	cin>>x>>y>>xx1>>yy1; 
	vector<p> v(maxn); 
	for(int i=0; i<maxn; i++) pr[i]= i; 
	for(int i=0; i<n; i++){
		ld a, b, c; 
		cin>>a>>b>>c; 
		if(sqrt((x-a)*(x-a)+(y-b)*(y-b))== c) start= i; 
		if(sqrt((xx1-a)*(xx1-a)+(yy1-b)*(yy1-b))== c) eend= i;
		v[i].x= a, v[i].y= b, v[i].c= c; 
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(xx(v[i].x, v[i].y, v[i].c, v[j].x, v[j].y, v[j].c)== 1){
				//cout<<i<<" "<<j<<endl;
				Union(min(i, j), max(i, j)); 
			}
		}
	}

	if(find(pr[start])==find(pr[eend])) ans= "Yes"; 
	cout<<ans<<endl;
}


