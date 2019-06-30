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

struct g{
  int a, b, v;

};
bool comp(g a, g b){
  return a.v < b.v;
}
vpii res;
int main() {
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 int n, m;
 cin >> n >> m;
 int ans = 0;
 vector <g> a(m + 1);
 for(int i = 1; i <= m; i++){
   //int a, b, v;
   cin >> a[i].a >> a[i].b >> a[i].v;
 }
 vi tree(n + 1);
 for(int i = 1; i <= n; i++){
   tree[i] = i;
 }
 sort(all(a), comp);
 for(int i = 1; i <= m; i++){
   int l = a[i].a;
   int r = a[i].b;
   int v = a[i].v;
   if(tree[l] != tree[r]){
     ans += v;

     int news = tree[l];
     int old = tree[r];
     for(int j = 1; j <= n; j++){
       if(tree[j] == old){
         tree[j] = news;
       }
     }
   }
 }
 cout << ans;

}
