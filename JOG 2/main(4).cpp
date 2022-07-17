#include <iostream>
#include <vector>

using namespace std;
//https://acm.njupt.edu.cn/

int main() {

  int t;
  cin >> t;

  for(int i = 0 ; i < t; i++){

    int n;
    cin >> n;

    vector<int> array(n);

    for(int j = 0 ; j < n ; j++) cin >> array[j];

    int resp = array[0];
    for(int j = 1 ; j < n ; j++){
      resp = resp ^ array[j];
    }

    if(resp == 0) cout << 1 << endl;
    else cout << 0 << endl;

  }
}