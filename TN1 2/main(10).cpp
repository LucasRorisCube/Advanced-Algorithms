#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> resp;
  for(long long i = 1 ; i *i <= n ; i++){

    if(n%i == 0){
      resp.push_back(i);
      if(i*i != n) resp.push_back(n/i);
    }
  }

  sort(resp.begin(), resp.end());
  
  for(long long num : resp) cout << num << " ";
  cout << endl;
  

}