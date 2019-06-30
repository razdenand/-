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

int partition(vi &a, int l, int r){
  int i = l;
  int j = r;
  int m = a[(l + r) / 2];
  while(i <= j){
    while(a[i] < m){
      i++;
    }
    while(a[j] > m){
      j--;
    }
    if(i >= j){
      break;
    }
    else{
      swap(a[i++],a[j--]);
    }
  }
  return j;
}

void qsort(vi &a, int l, int r){
  if(l < r){
    int m = partition(a, l, r);
    qsort(a, l, m);
    qsort(a, m + 1, r);
  }
}

int main() {
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
  int n;
  cin >> n;

  vi a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  qsort(a, 0, n - 1);
  for(int i = 0; i < n; i++){
    cout << a[i] << ' ';
  }
}
