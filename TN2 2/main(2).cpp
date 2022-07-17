#include <iostream>

#include <vector>

using namespace std;

int mdc(int a, int b){
  return (b == 0)? a : mdc(b,a%b);
}

int mmc(int a, int b){
  return (a*b)/mdc(a,b);
}

int main() {

  int n;
  cin >> n;

  vector<int> vec(n);

  for(int i = 0 ; i < n ; i++){
    int aux;
    cin >> aux;
    vec[i] = aux;
  }

  int minDist = vec[1]-vec[0];
  for(int i = 2 ; i < (int)vec.size() ; i++){
    minDist = mdc(minDist, vec[i]-vec[i-1]);
  }

  cout << (vec[(int)vec.size()-1]-vec[0])/minDist - ((int)vec.size()-1) << endl;
}