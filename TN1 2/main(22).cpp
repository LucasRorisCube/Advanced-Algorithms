#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int isPrime(int n){
  if(n == 1){
    return 0;
  } else if(n%2 == 0){
    return 0;
  } else {
    for(int i = 3 ; i <= sqrt(n) ; i+=2){
      if(n%i == 0){
        return 0;
      }
    }
    return 1;
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> resp;
  for(int i = 1 ; i <= n ; i++){
    //if(!isPrime(i)) continue;

    if(n%i == 0){
      resp.push_back(i);
    }
  }
  
  for(int num : resp) cout << num << " ";
  cout << endl;
  

}