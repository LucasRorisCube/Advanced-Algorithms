#include <iostream>


using namespace std;
//https://acm.njupt.edu.cn/

int main() {

  int n;
  cin >> n;

  for(int i = 0 ; i < n ; i++){

    string str;
  
    cin >> str;

    int mode = 0; //0 is Alice, 1 is Bob
    for(int j = 0; j < (int)str.length(); j++){
      if(mode == 0){
        if(str[j] == 'a') str[j] = 'b';
        else str[j] = 'a';
        mode = 1;
      } else {
        if(str[j] == 'z') str[j] = 'y';
        else str[j] = 'z';
        mode = 0;
      }
      
    }
    
    cout << str << endl;
  }
}