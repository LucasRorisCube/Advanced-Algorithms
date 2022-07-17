#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
6
1 3 1 2 1 2
*/
void explore(unordered_map<int, int>& bestToZero, int current, vector<int>& vec){
  if(current == 0){
    bestToZero[0] = 1;
    return;
  }

  if(bestToZero[current-1] == -1) explore(bestToZero, current-1, vec);
  
  for(int i = 1 ; current-i >= 0 ; i++){
    if(vec[current] > vec[current-i]){
      bestToZero[current] = max(bestToZero[current], bestToZero[current-i] + 1);
    }
  }
  if(bestToZero[current] == -1) bestToZero[current] = 1;
  
  
}

int main() {

  int n;
  cin >> n;

  vector<int> vec;
  unordered_map<int, int> bestToZero;
  for( int i = 0 ; i < n ; i++){
    int aux;
    cin >> aux;
    vec.push_back(aux);
    bestToZero[i] = -1;
  }

  explore(bestToZero, n-1, vec);
  cout << bestToZero[n-1] << endl;
}