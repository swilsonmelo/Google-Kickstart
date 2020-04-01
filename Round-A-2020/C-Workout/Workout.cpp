#include <bits/stdc++.h>


using namespace std;


int n, k, a[100005];

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 1, r = a[n-1]-a[0];
    while(l < r){
        int mid = (l+r) / 2;
        int k2 = 0;
        for(int i = 1; i < n; i++){
            int d = a[i]-a[i-1];
            // ceil(d/(n+1)) <= mid
            // d <= mid*(n-1)
            // d/mid - 1 <= n
            k2 += (d + mid - 1)/ mid - 1;
        }
        if(k2 <= k){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << "\n";

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
