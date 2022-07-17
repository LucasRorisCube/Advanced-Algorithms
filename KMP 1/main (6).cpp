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
  for(int num : rt) cout << num << " ";
  cout << endl;
}

void computeLPSArray(string pattern, vector<int>& rt)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    rt[0] = 0; // lps[0] is always 0
    int M = (int)pattern.size();
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            rt[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = rt[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                rt[i] = 0;
                i++;
            }
        }
    }
}


/*int main() {

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
          j = rt[j-1];
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
  
}*/

int main() {

  int t;
  cin >> t;

  for(int c = 0; c < t ; c++){

    string str;
    string pattern;
    cin >> str >> pattern;

    vector<int> rt((int)pattern.length());
    
    //geraRT(pattern, rt);
    computeLPSArray(pattern, rt);
    vector<int> indexs;
    int tamText = (int)str.size();
    int tamPattern = (int)pattern.size();
    int i = 0;
    int j = 0;
    while(i < tamText){
      
      if(str[i] == pattern[j]){
        i++;
        j++;
      }
      if(j == tamPattern){
        indexs.push_back(i-j+1);
        j = rt[j-1];
      } else {
        if(i < tamText && pattern[j] != str[i]){
          if(j != 0) j = rt[j-1];
          else i++;
        }
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