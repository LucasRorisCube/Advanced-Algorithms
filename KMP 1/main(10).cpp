/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int t;
  cin >> t;

  for(int i = 0; i < t ; i++){

    string str;
    string pattern;
    cin >> str >> pattern;

    vector<int> indexs;
    for(int j = 0 ; j < (int)str.length() ; j++){

      int flag = 0;
      for(int k = 0 ; k < (int)pattern.length() ; k++){
        if(str[j+k] != pattern[k]){
          flag = 1;
          break;
        }
      }
      if(flag == 0){
        indexs.push_back(j+1);
      }
      
    }

    if((int)indexs.size() != 0){
      cout << (int)indexs.size() << endl;
      for(int index = 0 ; index < (int)indexs.size() ; index++){
        if(index == 0) cout << indexs[index];
        else cout << " " << indexs[index];
      }
      cout << endl << endl;
    } else {
      cout << "Not Found" << endl << endl;
    }
  }
}
*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void geraRT(string pattern, vector<int>& rt){
  
  rt[0] = 0;

  int tamStr = (int)pattern.size();

  //int tam = 6;
  for(int tam = 1 ; tam <= tamStr ; tam++){
    int i = 0;
    int len = 0;
    while(i < tam){
      string subStringInit = pattern.substr(0,i);
      string subStringFinal = pattern.substr(tam-i,i);
      //cout << subStringInit << "/" << subStringFinal << endl;
      if(subStringInit == subStringFinal){
        if(i > len) len = i;
      }
      i++;
    }
    //cout << "Coloquei " << len << endl;
    rt[tam-1] = len;
  }
  //for(int num : rt) cout << num << " ";
  //cout << endl;
}


int main() {

  int t;
  cin >> t;

  for(int c = 0; c < t ; c++){

    string str;
    string pattern;
    cin >> str >> pattern;

    vector<int> rt((int)pattern.length());
    
    geraRT(pattern, rt);

    vector<int> indexs;
    int tamText = (int)str.size();
    int i = 0;
    int j = 0;
    while(i < tamText){
      
      if(str[i] == pattern[j]){
        if(j == (int)pattern.size()-1){
          indexs.push_back(i-j+1);
          j = rt[j];
          //i--;
          
        } else{
          j++;
        }
        
      } else {
        j = rt[j];
      }
      
      i++;
    }

    if((int)indexs.size() != 0){
      cout << (int)indexs.size() << endl;
      for(int index = 0 ; index < (int)indexs.size() ; index++){
        if(index == 0) cout << indexs[index];
        else cout << " " << indexs[index];
      }
      cout << endl << endl;
    } else {
      cout << "Not Found" << endl << endl;
    }
    
  }
  
}