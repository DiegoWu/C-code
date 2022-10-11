#include<iostream>
#include<vector> 
#include<cmath> 
#include<algorithm>
using namespace std; 

vector<int> parent; 
int b; 
vector<int> sz; 

int find(int fa){

	if(parent[fa]== fa) return fa;
	//cout<<"hi"<<endl;
	//cout<<parent[fa]<<" "<<fa<<endl;
	return parent[fa]= find(parent[fa]);
}
void Union(int t, int e){
	int fa= find(t), fb= find(e); 
	if(fa!= fb) {
		sz[min(fb,fa)]+= sz[max(fa, fb)];
		sz[max(fa, fb)]= 0;
	}
	//cout<<"wtf"<<sz[min(fb,fa)]<<endl;
	parent[max(fb, fa)]= parent[min(fa, fb)]; 
}
void solve(){

	int a, c; 
	while(cin>>a>>b>>c){
		vector<int> seedx(b); 
		vector<int> seedy(b);
	 
		seedx[0]= (269*a+11)%103; 
		seedy[0]= (271*a+13)%97;
		for(int i=1; i<b; i++){
			seedx[i]= (269*seedx[i-1]+11)%103;
			seedy[i]= (271*seedy[i-1]+13)%97;
		}
		int cnt= 0; 
		for(int i=0; i<b; i++) {
			parent.push_back(i); 
			sz.push_back(1); 
		}
		for(int i=0; i<b-1; i++){
			for(int j=i+1; j<b; j++){
				if((pow(seedx[i]-seedx[j], 2)+ pow(seedy[i]-seedy[j], 2))<= pow(c, 2)){ 
					Union(min(i, j), max(i, j));
	
				}
			}
		}
        
		sort(sz.begin(), sz.end());
		for(int i=0; i<b; i++){
			if(sz[i]== 0) continue;
			cnt++; 
		} 
		cout<<cnt<<endl;
		for(int i=0; i<b; i++){
			if(sz[i]== 0) continue;
			cout<<sz[i]<<" "; 
		} 
		cout<<endl; 
		parent.clear(); 
		sz.clear();
	}

}

int main(){
	solve(); 
	return 0; 
}
