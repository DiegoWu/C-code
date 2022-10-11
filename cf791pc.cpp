#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
using ii = pair<int, int>;
#define F first
#define S second
void solve()
{
    int n, q;
    cin>>n>>q;
    set<int> row, col;
    vector<int> cnt1(n+1, 0), cnt2(n+1, 0);
    for(int i=1; i<=n; i++){
        row.insert(i);
        col.insert(i);
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int x, y;
            cin>>x>>y;
            if(cnt1[x] == 0){
                row.erase(row.find(x));
            }
            if(cnt2[y] == 0){
                col.erase(col.find(y));
            }
            cnt1[x]++; cnt2[y]++;
            
        }
        else if(t == 2){
            int x, y;
            cin>>x>>y;
            cnt1[x]--; cnt2[y]--;
            if(cnt1[x] == 0){
                row.insert(x);
            }
            if(cnt2[y] == 0){
                col.insert(y);
            }
        }
        else{
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            if(*row.lower_bound(x1) > x2 || *col.lower_bound(y1) > y2){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }

        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t =1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
