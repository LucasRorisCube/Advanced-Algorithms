#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

  int numCases;
  cin >> numCases;

  vector<vector<int>> answer;

  for(int i = 0 ; i < numCases ; i++){

    stack<int> init;
    
    int n;
    cin >> n;
    
    for(int j = 0 ; j < n ; j++){
      int aux;
      cin >> aux;
      init.push(aux);
    }

    vector<int> out;

    while(!init.empty()){
      out.push_back(init.top());
      init.pop();
    }

    answer.push_back(out);
    
  }
  for(auto j = answer.begin() ; j != answer.end() ; j++){
    for(auto i = (*j).begin() ; i != (*j).end() ; i++){
      cout << *i << endl;
    }
    if(j+1 != answer.end())
      cout << endl;
  }
}