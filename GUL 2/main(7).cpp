#include <iostream>
#include <vector>

using namespace std;

int main() {

  long long n;
  cin >> n;

  for(long long i = 0 ; i < n ; i++){

    string expression;
    cin >> expression;

    long long prevNumber = 0;
    long long prevPart = 0;
    vector<long long> product;
    for(char c : expression){
      if(c >= '0' && c <= '9'){
        if(prevPart == 0){
          prevPart = (int)c -48;
        } else {
          prevPart = 10 * prevPart + (int)c -48;
        }
        
      } else {
        if(c == '+'){
          prevNumber += prevPart;
          prevPart = 0;
        } else {
          
          if(prevNumber == 0){
            product.push_back(prevPart);
          } else {
            prevNumber += prevPart;
            product.push_back(prevNumber);
          }
          prevPart = 0;
          prevNumber = 0;
        }
      }
    }

    if(prevNumber != 0){
      product.push_back(prevNumber+prevPart);
      prevPart = 0;
    }
    if(prevPart != 0){
      product.push_back(prevPart);
    }
    

    long long totalProduct = 1;
    for (long long num : product){
      totalProduct *= num;
    }

    long long num = 0;
    long long prevNum = 0;
    vector<long long> sum;
    for(long long i = 0 ; i < (int)expression.length() ; i++){
      char c = expression[i];
      if(c >= '0' && c <= '9'){
        if(num == 0){
          num = (int)c - 48;
        } else {
          num = 10 * num + (int)c - 48;
        }
      } else {
        if(c == '*'){
          if(prevNum == 0){
            prevNum = num;
            num = 0;
          } else {
            prevNum *= num;
            num = 0;
          }
        } else {
          if(prevNum != 0){
            sum.push_back(prevNum*num);
            //cout << "Coloquei prevNum " << prevNum << endl;
          } else {
            //cout << "Coloquei num " << num << endl;
            sum.push_back(num);
          }
          prevNum = 0;
          num = 0;
        }
      }
    }
    if(prevNum != 0){
      sum.push_back(prevNum*num);
      num = 0;
    }
    if(num != 0){
      sum.push_back(num);
    }

    long long totalSum = 0;

    for (long long num : sum){
      totalSum += num;
    }

    cout << "The maximum and minimum are " << totalProduct << " and " << totalSum << "." << endl;
    
  }
}
