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
vector <char> used;
vector <int> p;
vector <int> edge[107];

void dfs(int s){
  used[s] = true;
  for(int i = 0; i < edge[s].size(); i++){
    int to = edge[s][i];
    if(!used[to]){
      dfs(to);
    }
  }
}

void bfs(int s){
  queue <int> q;
  q.push(s);
  for(int i = 0; i < used.size(); i++){
    used[i] = false;
  }
  used[s] = true;
  p[s] = -1;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i = 0; i < edge[v].size(); i++){
      int to = edge[v][i];
      if(used[to] == false){
        q.push(to);
        used[to] = true;
        p[to] = v;
      }
    }
  }
}

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  int n;
  cin >> n;
  used.resize(n);
  p.resize(n);
  int kek;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> kek;
      if(kek == 1){
        edge[i].pb(j);
      }
    }
  }
  int s, f;
  cin >> s >> f;
  bfs(s);
  if(used[f] == false){
    cout << -1;
    return 0;
  }
  else{
    vector <int> path;
    for(int v = f; v != -1; v = p[v]){
      path.pb(v);
    }
    if(path.size() == 1){
      cout << 0;
      return 0;
    }
    reverse(all(path));
    cout << path.size() - 1 << endl;
    for(int i = 0; i < path.size(); i++){
      cout << path[i] << ' ';
    }
  }
}
