#include <iostream>
#include <vector>

using namespace std;

int maximun(vector<int> vec){
  int max = 0;
  for(int i = 0 ; i < (int)vec.size() ; i++){
    if(vec[i] > max){
      max = vec[i];
    }
  }
  return max;
}

void solve(vector<vector<int>>& matrix, vector<vector<int>>& solution, int line){

  if(line == 0){
    solution[line][0] = matrix[line][0];
    solution[line][1] = matrix[line][1];
    solution[line][2] = matrix[line][2];

    return;
  }

  solve(matrix, solution, line-1);

  solution[line][0] = matrix[line][0] + max(solution[line-1][1], solution[line-1][2]);
  solution[line][1] = matrix[line][1] + max(solution[line-1][0], solution[line-1][2]);
  solution[line][2] = matrix[line][2] + max(solution[line-1][0], solution[line-1][1]);
  


  return;
}

int main() {

  int n;
  cin >> n;

  vector<vector<int>> matrix(n);
  vector<vector<int>> solution(n);
  for(int i = 0 ; i < n ; i++){

    vector<int> aux2(3);
    vector<int> aux3(3);
    for(int j = 0 ; j < 3 ; j++){
      int aux;
      cin >> aux;
      aux2[j] = aux;
      aux3[j] = -1;
    }

    matrix[i] = aux2;
    solution[i] = aux3;
  }
  
  solve(matrix, solution, n-1);

  cout << maximun(solution[n-1]) << endl;

}

/*
int main() {

  int n;
  cin >> n;

  int matrix[n][3];
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < 3 ; j++){
      int aux;
      cin >> aux;
      matrix[i][j] = aux;
    }
  }

  int resp = 0;
  int prev = -1;
  for(int i = n-1 ; i >= 0 ; i--){
    int max = -1;
    int index = -1;
    for(int j = 0 ; j < 3 ; j++){
      if(j == prev) continue;
      if(matrix[i][j] >= max){
        max = matrix[i][j];
        index = j;
      }
    }

    resp += max;
    prev = index;
  }

  cout << resp << endl;

  
}
*/