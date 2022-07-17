#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(vector<vector<int>> matrix){
  for(int i = 0 ; i < (int)matrix.size() ; i++){
    for(int j = 0 ; j < (int)matrix[i].size() ; j++){
      //cout << width(3) << matrix[i][j] << " ";
      printf("%3d ", matrix[i][j]);
    }
    cout << endl;
  }
}

string recovery(vector<vector<int>> matrix, string str){
  int i = 0, j = 0;

  string resp = "";
  while(i < (int)matrix.size()-1 && j < (int)matrix[i].size()-1){
    if(matrix[i][j] == matrix[i+1][j]){
      i++;
    } else if(matrix[i][j] == matrix[i][j+1]){
      j++;
    } else if(matrix[i][j] == 1+matrix[i+1][j+1]){
      resp += str[i];
      i++;
      j++;
    }
  }
  return resp;
}

long solve(string& first, string& second, int i, int j, vector<vector<int>>& solutions){

  if(i >= (int)first.size() || j >= (int)second.size()){
    solutions[i][j] = 0;
    return solutions[i][j];
  } 

  if(solutions[i][j] != -1) return solutions[i][j];
  
  long answer = max(solve(first, second, i+1, j, solutions), solve(first, second, i, j+1, solutions));
  if(first[i] == second[j]){
    answer = max(answer, 1+solve(first, second, i+1, j+1, solutions));
  }

  solutions[i][j] = answer;
  return answer;
}

int main() {

  string first, second;

  cin >> first;
  cin >> second;

  /*if(first.size() < second.size()){
    string aux = first;
    first = second;
    second = aux;
  }*/
  
  vector<vector<int>> solutions((int)first.size()+1, vector<int>((int)second.size()+1,-1));

  
  //best = solve(first, second, (int)first.size(), (int)second.size(), lenghtOfLetters);
  solve(first, second, 0, 0, solutions);
  

  //cout << best << endl;

  //print(solutions);

  cout << recovery(solutions, first) << endl;
}