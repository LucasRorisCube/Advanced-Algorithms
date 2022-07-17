#include <iostream>
#include <queue>

using namespace std;
int main() {

  int n;
  int m;
  cin >> n >> m;

  while(n != 0 && m != 0){
    
    priority_queue<int, vector<int>, greater<int> > headsDragon;
    for(int i = 0 ; i < n ; i++){
  
      int aux;
      cin >> aux;
      headsDragon.push(aux);
      
    }
  
    priority_queue<int, vector<int>, greater<int> > heightKnights;
    for(int i = 0 ; i < m ; i++){
  
      int aux;
      cin >> aux;
      heightKnights.push(aux);
      
    }
  
    int gold = 0;
    int dontCanKill = 0;
    while(!headsDragon.empty()){
      if(heightKnights.empty()){
        dontCanKill = 1;
        break;
      }
      if(heightKnights.top() >= headsDragon.top()){
        gold += heightKnights.top();
        heightKnights.pop();
        headsDragon.pop();
      } else {
        heightKnights.pop();
      }
    }
    
    if(dontCanKill){
      cout << "Loowater is doomed!" << endl;
    } else {
      cout << gold << endl;
    }
    
    cin >> n >> m;
  }
}

/*
2 3
5
4
7
8
#include <iostream>

using namespace std;
int main() {

  int n;
  cin >> n;

  for(int i = 0 ; i < n ; i++){

    string expression;
    cin >> expression;

    cout << expression << endl;

    
    
  }
}
*/