#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define maxn 1000000000
using namespace std; 
struct p{
	int x, y;
	char g;  
}; 
bool cmp(p f, p s){
	if(f.y== s.y) return f.x< s.x; 
	return f.y<  s.y; 
}

void solve(){
	int n, a, b; 
	string z; 
	cin>>n; 
	vector<p>arr(n); 
	for(int i=0; i<n; i++){
		cin>>a>>b; 
		arr[i].x= a;
		arr[i].y= b;
	}
	cin>>z; 
	for(int i=0; i<n; i++)
		arr[i].g= z[i]; 
	sort(arr.begin(), arr.end(), cmp); 

	string ans= "No";
	for(int i=0; i<n-1; i++){
		if(arr[i].y== arr[i+1].y){
			if(arr[i].g=='R'&&arr[i+1].g== 'L') {
				ans= "Yes"; 
				 break; 
			}
		}
	}
	cout<<ans<<endl;
}


int main(){

	solve(); 
	return 0; 
}
