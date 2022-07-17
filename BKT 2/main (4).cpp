#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<vector<char>> tab, string word, int index, int i, int j, int n, int m, vector<vector<int>> verificados, bool& resp){
  if(index == (int)word.length()){
    resp = true;
    return;
  }
  if(resp) return;
  if(i+1 < n && verificados[i+1][j] == 0 && tab[i+1][j] == word[index]){
    //cout << "Baixo" << endl;
    verificados[i+1][j] = 1;
    solve(tab, word, index+1, i+1, j, n, m, verificados, resp);
    verificados[i+1][j] = 0;
  }
  if(i-1 >= 0 && verificados[i-1][j] == 0 && tab[i-1][j] == word[index]){
    //cout << "Cima" << endl;
    verificados[i-1][j] = 1;
    solve(tab, word, index+1, i-1, j, n, m, verificados, resp);
    verificados[i-1][j] = 0;
  }
  if(j+1 < m && verificados[i][j+1] == 0 && tab[i][j+1] == word[index]){
    //cout << "Direita" << endl;
    verificados[i][j+1] = 1;
    solve(tab, word, index+1, i, j+1, n, m, verificados, resp);
    verificados[i][j+1] = 0;
  }
  if(j-1 >= 0 && verificados[i][j-1] == 0 && tab[i][j-1] == word[index]){
    //cout << "Esquerda" << endl;
    verificados[i][j-1] = 1;
    solve(tab, word, index+1, i, j-1, n, m, verificados, resp);
    verificados[i][j-1] = 0;
  }
  
}

int main()
{
    
  int n, m;
  cin >> n >> m;

  vector<vector<char>> tab;
  
  for(int i = 0 ; i < n ; i++){
    vector<char> aux2;
    for(int j = 0 ; j < m ; j++){
      char aux;
      cin >> aux;
      aux2.push_back(aux);
    }
    tab.push_back(aux2);
  }

  vector<vector<int>> verificados;
  for(int i = 0 ; i < n ; i++){
    vector<int> aux2;
    for(int j = 0 ; j < m ; j++){
      aux2.push_back(0);
    }
    verificados.push_back(aux2);
  }
  int num;
  cin >> num;
  string word = "";
  for(int j = 0 ; j < num ; j++){
    char aux;
    cin >> aux;
    word += aux;
  }

  bool resp = false;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(tab[i][j] == word[0]){
        solve(tab, word, 1, i, j, n, m, verificados, resp);
        if(resp){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  
}