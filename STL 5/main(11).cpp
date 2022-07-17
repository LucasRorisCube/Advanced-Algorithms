#include <iostream>
#include <queue>

using namespace std;

int main() {

  int n;
  cin >> n;

  while(n != 0){
    
    priority_queue<int, vector<int>, greater<int> > p_queue;
    //priority_queue<int> p_queue;
    
    for(int i = 0 ; i < n ; i++){
      int aux;
      cin >> aux;
      p_queue.push(aux);
    }
    /*while(!p_queue.empty()){
      cout << p_queue.top() << endl;
      p_queue.pop();
    }*/
    int cost = 0;
    while((int)p_queue.size() != 1){

      int first = p_queue.top();
      p_queue.pop();
      int second = p_queue.top();
      p_queue.pop();
      int sum = first + second;
      p_queue.push(sum);
      
      cost += sum;
      
    }
    cout << cost << endl;


    cin >> n;
    }
}