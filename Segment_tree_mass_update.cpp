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

vi t, tAdd;
vl a;

void build(vl a, int v, int tl, int tr){
  if(tl == tr){
    t[v] = a[tl];
  }
  else{
    int tm = (tl + tr) / 2;
    build(a, 2 * v + 1, tl, tm);
    build(a, 2 * v + 2, tm + 1, tr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

void push(int v, int tl, int tr){
  if(tAdd[v] != 0){
    t[v] = (tr - tl + 1) * tAdd[v];
    if(tl != tr){
      tAdd[2 * v + 1] += tAdd[v];
      tAdd[2 * v + 2] += tAdd[v];
    }
    tAdd[v] = 0;
  }
}

int sum(int v, int tl, int tr, int l, int r){
  push(v, tl, tr);
  if(r < tl || tr < l){
    return 0;
  }
  if(l <= tl && tr <= r){
    return t[v];
  }
  else{
    int tm = (tl + tr) / 2;
    return sum(2 * v + 1, tl, tm, l, r) + sum( 2 * v + 2, tm + 1, tr, l, r);
  }
}

void update(int v, int tl, int tr, int l, int r, int val){
  push(v, tl, tr);
    if(r < tl || tr < l){
      return;
    }
    if(l <= tl && tr <= r){
      tAdd[v] = val;
      push(v, tl, tr);
    }
    else{
      int tm = (tl + tr) / 2;
      update(2 * v + 1, tl, tm, l, r, val);
      update(2 * v + 2, tm + 1, tr, l, r, val);
      t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
  }

  int main() {
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
     int m;
     scanf("%d %d\n",&n, &m );
     a.resize(n);
     t.resize(4 * n);
     tAdd.resize(4 * n);
    // tAdd.resize(4 * n);
      for (int i = 0; i < n; i++){
          scanf("%lld\n", &a[i]);
      }
      //vector <int> t(4*n);
      build(a, 0, 0, n - 1);
    //  build(a);
      //long long x, y;

      for(int i = 0; i < m; i++){
        int x;
      scanf("%d",&x);
        if(x == 2){
          ll d, c, kek;
          scanf("%lld %lld %lld\n",&d, &c, &kek);
          update(0, 0, n - 1, d - 1, c - 1, kek);
        }
        else{
          ll d, c;
            scanf("%lld %lld\n",&d, &c);
            ll ans = sum(0, 0, n - 1, d - 1, c - 1);
            printf("%lld\n",ans);

        }
      }
    }
