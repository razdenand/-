#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define all(a) a.begin(), a.end()
#define PI 3.141592653589793238462643383279502884197169399375105820974

typedef vector <pair <int ,int > > vpii;
typedef vector <pair <ll ,ll > > vpll;
typedef vector <pair <double ,double > > vpdd;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector <char> vc;
typedef vector <double> vd;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

vector <pair <int, int>> g[1000];
//vector <bool> used;
vi d;
vi p;
 //vc used;
int main() {
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 d.resize(n + 1);
 //int x;
 vi a(n + 1);
 for(int i = 1;i <= n; i++){
   cin >> a[i];
 }
 int m;
 cin >> m;
 for(int i = 1; i <= m; i++){
   int x, y;
   cin >> x >> y;

   g[x].pb({y, a[x]});
   g[y].pb({x, a[y]});
 }
 p.resize(n + 1);
  for(int i = 0; i <= n; i++){
    d[i] = 1e9;
  }
  vi used(n + 1);
  for(int i = 0; i <= n; i++){
    used[i] = false;
  }
   d[1] = 0;
   //p[s] = -1;
   for(int i = 1; i <= n; i++){
     int v = - 1;
     for(int j = 1; j <= n; j++){
       if(!used[j] && (v == -1 || d[j] < d[v])){
         v = j;
       }
     }
       if(d[v] == 1e9){
         break;
       }
       used[v] = true;
       for(int j = 0; j < g[v].size(); j++){
         int to = g[v][j].f;
         int len = g[v][j].s;
         if(d[v] + len < d[to]){
           d[to] = d[v] + len;
           p[to] = v;
         }
       }
     }

   if(d[n] == 1e9){
     cout << -1;
     return 0;
   }
   else{
     cout << d[n];
//  cout << path.size() + 1;
}
}
