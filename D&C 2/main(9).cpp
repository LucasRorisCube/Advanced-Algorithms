#include <iostream>
#include <vector>
#include <set>

using namespace std;
int max(vector<int> array){
  int max = array[0];
  for(int num : array){
    if(num > max){
      max = num;
    }
  }
  return max;
}

int min(vector<int> array){
  int min = array[0];
  for(int num : array){
    if(num < min){
      min = num;
    }
  }
  return min;
}

long long sum(vector<int> array){
  long long sum = 0;
  for(int num : array){
    sum += num;
  }
  return sum;
}

bool equalVec(vector<int> array){
  int n = array[0];
  for(int num : array){
    if(num != n) return false;
  }
  return true;
}

bool verifyVec(long long num, vector<int> sumRequireds, vector<int>& resps){
  bool flag = true;
  for(int i = 0 ; i < (int)sumRequireds.size() ; i++){
    if(sumRequireds[i] == num){
      resps[i] = 1;
    } else if(num > sumRequireds[i]){
      flag = false;
    }
  }
  return flag;
}

void test2(vector<int> array, set<long long>& sums){
  
  int mid = (max(array)+min(array))/2;
  
  long long sumA = sum(array);
  
  sums.insert(sumA);

  //if(equalVec(array)){
  //  return;
  //}
  vector<int> left, right;
  for(int num : array){
    if(num <= mid){
      left.push_back(num);
    } else {
      right.push_back(num);
    }
  }
  if((int)left.size() == 0 || (int)right.size() == 0) return;
  test2(left, sums);
  test2(right, sums);

}

int main() {

  int t;
  cin >> t;

  for(int i = 0 ; i < t ; i++){

    int n, q;
    cin >> n >> q;

    vector<int> array;
    for(int j = 0 ; j < n ; j++){
      int aux;
      cin >> aux;
      array.push_back(aux);
    }

    set<long long> sums;
    
    test2(array, sums);
    for(int j = 0 ; j < q ; j++){
      int sumRequired;
      cin >> sumRequired;

      if(sums.find(sumRequired) != sums.end())
        cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}