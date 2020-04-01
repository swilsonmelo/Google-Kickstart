#include <bits/stdc++.h>

using namespace std;


int n, b, a[1000000];


void solve(){
    cin >> n >> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if( b >= a[i]){
            ans++;
            b -= a[i];
        }
    }
    cout << ans << "\n";

}

int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int c = 1;
    while (t--){
        cout << "Case #" << c << ": ";
        solve();
        c++;
    }

}
