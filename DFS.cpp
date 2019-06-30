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
int ans;

void dfs(int s){
  used[s] = true;
  ans++;
  for(int i = 0; i < edge[s].size(); i++){
    int to = edge[s][i];
    if(!used[to]){
      dfs(to);
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
  int s;
  cin >> s;
  ans = 0;
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
  dfs(s);
  cout << ans;
}
