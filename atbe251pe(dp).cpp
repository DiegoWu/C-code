#include <iostream>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

int n;
int a[300005];
ll dp[300005][2];

int main(void)
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  
  ll ans = inf;
  for(int t = 0; t <= 1; t++){
    dp[1][t] = a[1]*t, dp[1][1-t] = inf;
    
    for(int i = 2; i <= n; i++){
      dp[i][0] = dp[i-1][1];
      dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
    }
    if(t == 0) ans = min(ans, dp[n][1]);
    if(t == 1) ans = min(ans, min(dp[n][0], dp[n][1]));
  }
  cout << ans << endl;
  
  return 0;
} 

