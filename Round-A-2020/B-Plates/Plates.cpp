#include <bits/stdc++.h>


using namespace std;


int n, k ,p, a[55][35];
int dp[55][1505];


void solve(){
    cin >> n >> k >> p;
    int b;
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin >> b;
            a[i][j] = a[i][j-1] + b;
        }
    }
    for(int i = 1; i <= n; i++ ){
        for(int j = 0; j <= p; j++){
            dp[i][j] = 0;
            for(int x = 0; x <= min(j,k); x++){
                dp[i][j] = max(dp[i][j], a[i][x] + dp[i-1][j-x]);
            }
        }
    }
    /*
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= p; j++){
            cout << dp[i][j] << " " ;
        }
        cout << "\n" ;
    }*/
    cout << dp[n][p] << "\n";
}

int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    int t;
    cin >> t;
    int i = 1;
    while(t--){
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}
