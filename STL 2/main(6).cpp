#include <iostream>
#include <queue>
#include <vector>

using namespace std;




int main() {

  int numCases;
  cin >> numCases;

  for(int i = 0 ; i < numCases ; i++){
    
    int n;
    int m;
    cin >> n >> m;
//1 7 5 9 3
    // 3 1 5
    queue<pair<int,int>> queue;
    priority_queue<int> pq;
    
    for(int j = 0 ; j < n ; j++){
      int aux;
      cin >> aux;
      queue.push(pair<int,int>(aux,j));
      pq.push(aux);
    }

    int time = 0;
    while(!queue.empty()){

      if(queue.front().first >= pq.top()){
        time += 1;
        if(queue.front().second == m)
          cout << time << endl;
        pq.pop();
        queue.pop();
      
      } else {
        auto aux = queue.front();
        queue.pop();
        queue.push(aux);
      }
      
    }
  }
}