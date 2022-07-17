#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n == 1){
    cout << "NO" << endl;
  } else if(n%2 == 0){
    cout << "NO" << endl;
  } else {
    int flag = 0;
    for(int i = 3 ; i*i <= n ; i+=2){
      if(n%i == 0){
        cout << "NO" << endl;
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      cout << "YES" << endl;
    }
  }
  


}