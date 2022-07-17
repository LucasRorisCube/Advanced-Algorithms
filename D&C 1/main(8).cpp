#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int coin;
  cin >> coin;
  cout << (int)(-1/2.0 + sqrt(1+8*coin)/2.0) << endl;
}

// n^2 + n - 2*coin = 0
// -1/2 + sqrt(1+8*coin)/2