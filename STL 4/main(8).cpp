#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  for(int i = 0 ; i < n ; i++){

    int m;
    cin >> m;

    vector<int> list;
    for(int j = 0 ; j < m ; j++){
      int aux;
      cin >> aux;
      list.push_back(aux);
    }

    vector<int> current;
    int max = 0;
    int counter = 0;
    for(int k = 0 ; k < (int)list.size() ; k++){
      while(find(current.begin()+counter, current.end(), list[k]) != current.end()){
        //current.erase(current.begin());
        counter += 1;
      }
      current.push_back(list[k]);
      if((int)current.size() - counter > max){
        max = (int)current.size() - counter;
      }
    }
    cout << max << endl;
  }
}