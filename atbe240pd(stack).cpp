#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<tuple> 
#include<stdexcept>
#include<stack> 
#include<queue> 
#define mp make_pair 
#define ll long long
#define INF 1000000001
#define mod 998244353
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> m; 
    stack<pair<int, int> > q; 
    int n, cnt= 0, pos= 0; 
    cin>>n; 
    for(int i=0; i<n; i++){
    	int a; 
    	cin>>a; 
    	if(q.empty()) {
    		m[pos]++; 
    		q.push(mp(pos, a)); 
    		cnt++; 
    		pos++; 
    	}
    	else{
    		if(q.top().second==a&&m[q.top().first]== a-1){
    			cnt-= m[q.top().first]; 
    			pos--; 
    			m[q.top().first]= 0; 
    			q.pop(); 

    		}
    		else{
    			if(q.top().second==a){
    				cnt++; 
    				m[q.top().first]++;
    			}
    			else{
    				pos++; 
    				m[pos]= 1; 
    				q.push(mp(pos, a));
    				cnt++;  
    			}
    		}
    	}
    	cout<<cnt<<endl;
    }

}
