#include <iostream>
#include <vector>

using namespace std;

long solve(vector<long>& v, vector<long>& w, int i, int p, int& n, vector<vector<long>>& memo){

  if(i == n) return 0;
  
  long resp = 0;

  if(memo[i][p] != -1){
    return memo[i][p];
  }
  // Não pegar
  resp = solve(v, w, i+1, p, n, memo);

  //Pegar
  if(p-w[i] >= 0){
    resp = max(resp, solve(v, w, i+1, p-w[i], n, memo) + v[i]);
  }

  memo[i][p] = resp;
  return resp;
}

int main() {

  int n, W;
  cin >> n >> W;

  vector<long> v(n);
  vector<long> w(n);
  
  for(int i = 0 ; i < n ; i++){
    int auxV, auxW;
    cin >> auxW >> auxV;
    v[i] = auxV;
    w[i] = auxW;
  }

  vector<vector<long>> memo(n+1, vector<long>(W+1, -1));
  
  cout << solve(v, w, 0, W, n, memo) << endl;
}