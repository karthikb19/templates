#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\033[0m" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr<<"\033[1;31m"<< "LINE "<<__LINE__<<": -> [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__) 
#else
#define dbg(...) 19
#endif

#define int int64_t

void solve(int tt){

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1; cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        solve(tt);    
    }
}
