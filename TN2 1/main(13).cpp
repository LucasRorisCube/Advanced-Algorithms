#include <iostream>
#include <vector>

using namespace std;

int isEmpty(vector<int> vec){
  int flag = 0;
  for(int i = 0 ; i < (int)vec.size() ; i++){
    if(vec[i] != -1){
      flag += 1;
      if(flag == 2)
        return 0;
    }
  }
  return 1;
}

void printVec(vector<int> vec){
  for(int num : vec) cout << num << " ";
  cout << endl;
}

int main() {

  int t;
  cin >> t;

  for(int i = 0 ; i < t ; i++){

    int n;
    cin >> n;

    vector<int> vec(n,-1);

    int resp = 0;
    for(int j = 0 ; j < n ; j++){
      int aux;
      cin >> aux;
      if(aux%3 != 0)
        vec[j] = aux;
      else resp += 1;
    }
    while(!isEmpty(vec)){
      //printVec(vec);
      int flag = 0;
      for(int j = 0 ; j < (int)vec.size() ; j++){
        for(int k = 0 ; k < (int)vec.size() ; k++){
          if(vec[j] > -1 && vec[k] > -1 && (vec[j]+vec[k])%3 == 0){
            resp += 1;
            //cout << "Aumentei: " << j << "/" << k << endl;
            vec[j] = -1;
            vec[k] = -1;
            flag = 1;
          }
        }
      }
      if(flag == 0){

        int aux1 = -1;
        int aux2 = -1;
        for(int k = 0 ; k < (int)vec.size() ; k++){
          if(vec[k] > -1){
            if(aux1 > -1){
              aux2 = k;
              break;
            } else aux1 = k;
          }
        }

        vec[aux1] += vec[aux2];
        vec[aux2] = -1;
      }
    }

    cout << resp << endl;
  }
}