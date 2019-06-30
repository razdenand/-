
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
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int lsearch(vector <int> a,int l, int r, int x){
  while(l + 1 < r){
    int m = (l + r) / 2;
    if(a[m] < x){
      l = m;
    }
    else{
      r = m;
    }
  }
  if(a[r] == x){
    return r;
  }
  else{
    return -1;
  }
}

int rsearch(vector <int> a,int l, int r, int x){
  while(l + 1 < r){
    int m = (l + r) / 2;
    if(a[m] <= x){
      l = m;
    }
    else{
      r = m;
    }
  }
  if(a[l] != x){
    return l;
  }
  else{
    return -1;
  }
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
  int n, x;
  cin >> n >> x;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << lsearch(a, -1, a.size(), x) <<  ' '<< rsearch(a, -1, a.size(), x);
}
