#include <bits/stdc++.h>

using namespace std;

struct trie
{
    trie* child[26];
    int cnt = 0;

};

int n, k, ans;
string a[1000005];
trie* root;

void insert(string &s ){
    trie* curr = root;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        int reqd = ch - 'A';
        if( ! curr -> child[reqd] ){
            curr -> child[reqd] = new trie();
        }
        curr = curr -> child[reqd];
    }
    curr -> cnt++;
}

void dfs(trie* curr, int lvl){
    for(int i = 0; i <= 25; i++){
        if( curr -> child[i] ){
            dfs( curr -> child[i], lvl + 1 );
            curr -> cnt += curr -> child[i] -> cnt;
        }
    }
    while( curr -> cnt >= k){
        curr -> cnt -= k;
        ans += lvl;
    }
}

int main(){

    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    int t;
    cin >> t;
    int tc = 1;
    while(t--){
        ans = 0;
        root = new trie();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            insert(a[i]);
        }
        dfs(root,0);
        cout << "Case #" << tc << ": " << ans << "\n";
        tc++;

    }
    return 0;
}
