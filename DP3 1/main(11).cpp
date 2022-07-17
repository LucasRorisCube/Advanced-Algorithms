#include <iostream>
#include <vector>
#include <map>

using namespace std;

long calculate(string str, map<char,long>& lenghtOfLetters){
  long total = 0;
  for(char c : str){
    total += lenghtOfLetters[c];
  }
  return total;
}

long solve(string& first, string& second, int i, int j, map<char,long>& lenghtOfLetters, vector<vector<int>>& solutions){

  if(i >= (int)first.size() || j >= (int)second.size()){
    solutions[i][j] = 0;
    return solutions[i][j];
  } 

  if(solutions[i][j] != -1) return solutions[i][j];
  
  long answer = max(solve(first, second, i+1, j, lenghtOfLetters, solutions), solve(first, second, i, j+1, lenghtOfLetters, solutions));
  if(first[i] == second[j]){
    answer = max(answer, lenghtOfLetters[first[i]]+solve(first, second, i+1, j+1, lenghtOfLetters, solutions));
  }

  solutions[i][j] = answer;
  return answer;
}

int main() {

  int n, m;
  cin >> n >> m;

  map<char,long> lenghtOfLetters;
  for(int i = 0 ; i < 26 ; i++){
    int aux;
    cin >> aux;
    lenghtOfLetters['a'+i] = aux;
  }

  string first, second;

  cin >> first;
  cin >> second;

  vector<vector<int>> solutions(m+1, vector<int>(n+1,-1));

  if(first.size() < second.size()){
    string aux = first;
    first = second;
    second = aux;
  }

  long best = 0;
  
  //best = solve(first, second, (int)first.size(), (int)second.size(), lenghtOfLetters);
  best = solve(first, second, 0, 0, lenghtOfLetters, solutions);
  

  cout << best << endl;
}