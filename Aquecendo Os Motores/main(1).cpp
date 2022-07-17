#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<string> firstName;
  vector<string> firstIP;
  vector<string> secondName;
  vector<string> secondIP;
  for(int i = 0 ; i < n ; i++){
    string auxString;
    cin >> auxString;
    firstName.push_back(auxString);

    cin >> auxString;
    firstIP.push_back(auxString);
  }

  for(int i = 0 ; i < m ; i++){
    string auxString;
    cin >> auxString;
    secondName.push_back(auxString);

    cin >> auxString;
    auxString.pop_back();
    secondIP.push_back(auxString);
  }

  for(long unsigned int i = 0 ; i < secondName.size() ; i++){
    string auxName;
    for(long unsigned int j = 0 ; j < firstName.size() ; j++){
      //cout << secondIP[i] << "/" << firstIP[i] << endl;
      if(secondIP[i] == firstIP[j]){
        auxName = firstName[j];
        break;
      }
    }
    cout << secondName[i] << " " << secondIP[i] << "; #" << auxName << endl; 
  }

  
}