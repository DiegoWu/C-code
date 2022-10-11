#include<iostream> 
#include<vector>
#include<algorithm> 
#define maxn 9223372036854775807
using namespace std; 
vector<long long> ori; 
int ans= 0; 

void merge(int front, int mid, int end){
	vector<long long > left; 
	vector<long long > right; 
	for(int i=front; i<mid+1; i++) left.push_back(ori[i]); 
	for(int i=mid+1; i<end+1; i++) right.push_back(ori[i]);   
	left.push_back(maxn); 
	right.push_back(maxn); 
	
	int idxleft= 0, idxright= 0;
	
	for(int i=front; i<end+1; i++){
		if(left[idxleft]<= right[idxright]){
			ori[i]= left[idxleft]; 
			idxleft++; 
		}
		else{
			ori[i]= right[idxright]; 
			//cout<<"i: "<<i<<"hello"<<endl;
			idxright++; 
			ans+= left.size()-1-idxleft; 
			//cout<<ans<<endl;
		}
	}

}
void mergesort(int front, int end){
	int mid= (front+end)/2; 
	if(front< end){ 
		mergesort(front, mid); 
		mergesort(mid+1, end); 
		merge(front, mid, end); 
	}
}
void solve(){
	int n, cnt= 1; 
	while(cin>>n&&n){
		for(int i=0; i<n; i++){
			int a; 
			cin>>a; 
			ori.push_back(a); 
		}
		mergesort(0, n-1);
		for(int i=0; i<n; i++) cout<<ori[i]<<" ";
		cout<<endl;
		cout<<"Case #"<<cnt<<": "<<ans<<endl;
		cnt++; 
		ori.clear();
		ans= 0;
	}
}

int main(){

	solve(); 
	
	return 0; 
}