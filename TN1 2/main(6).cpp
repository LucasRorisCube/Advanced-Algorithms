#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*int isPrime(int n){
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
  long long n;
  cin >> n;

  vector<long long> resp;
  for(long long i = 1 ; i <= n/2 ; i++){

    if(n%i == 0){
      resp.push_back(i);
    }
  }
  resp.push_back(n);
  
  for(long long num : resp) cout << num << " ";
  cout << endl;
  

}*/
#include "iostream"
#include "vector"
#include <set>
using namespace std;
 
struct primeFactorization {
 
    // to store the prime factor
    // and its highest power
    int countOfPf, primeFactor;
};

set<int> resp;
// Recursive function to generate all the
// divisors from the prime factors
void generateDivisors(int curIndex, int curDivisor,
                      vector<primeFactorization>& arr)
{
 
    // Base case i.e. we do not have more
    // primeFactors to include
    if (curIndex == (int)arr.size()) {
        //cout << curDivisor << ' ';
        resp.insert(curDivisor);
        return;
    }
 
    for (int i = 0; i <= (int)arr[curIndex].countOfPf; ++i) {
        generateDivisors(curIndex + 1, curDivisor, arr);
        curDivisor *= arr[curIndex].primeFactor;
    }
}
 
// Function to find the divisors of n
void findDivisors(int n)
{
 
    // To store the prime factors along
    // with their highest power
    vector<primeFactorization> arr;
 
    // Finding prime factorization of n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count += 1;
            }
 
            // For every prime factor we are storing
            // count of it's occurenceand itself.
            arr.push_back({ count, i });
        }
    }
 
    // If n is prime
    if (n > 1) {
        arr.push_back({ 1, n });
    }
 
    int curIndex = 0, curDivisor = 1;
 
    // Generate all the divisors
    generateDivisors(curIndex, curDivisor, arr);
}
 
// Driver code
int main()
{
    int n;
    cin >> n;
 
    findDivisors(n);

  for(int num : resp){
    cout << num << " ";
  }
  cout << endl;
    return 0;
}
