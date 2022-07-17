#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {

  string input = "-1";

  while(true){
    getline(cin, input);
    if(input == "0"){
      break;
    }
    
    map<string, set<string, greater<string>>> allProjects;
    string currentProject;
    while(input != "1"){
      if(islower(input[0])){
        allProjects[currentProject].insert(input);
      } else {
        set<string, greater<string>> auxSet;
        currentProject = input;
        allProjects[currentProject] = auxSet;
      }
      
      getline(cin, input);
    }
  
    vector<string> allNames;
    vector<string> namesToRemove;
    
    for (auto it = allProjects.begin() ; it != allProjects.end() ; it++){
      for (auto itr = it->second.begin(); itr != it->second.end(); itr++) {
        if(find(allNames.begin(), allNames.end(), (string)*itr) != allNames.end()){
          namesToRemove.push_back(*itr);
        } else {
          allNames.push_back(*itr);
        }
      }
    }
  
    for (auto it = allProjects.begin() ; it != allProjects.end() ; it++){
      for (string name : namesToRemove) {
        it->second.erase(name);
      }
    }
  
    map<int, vector<string>> output;
  
    for (auto it = allProjects.begin() ; it != allProjects.end() ; it++){
      output[it->second.size()].push_back(it->first);
    }
  
    /*for (auto it = allProjects.begin() ; it != allProjects.end() ; it++){
      cout << it->first << ": ";
      for (auto itr = it->second.begin(); itr != it->second.end(); itr++) {
        cout << *itr << " ";
      }
      cout << endl;
    }*/
  
    for (auto it = output.rbegin() ; it != output.rend() ; it++){
      for (string project : it->second) {
        cout << project << " " << it->first << endl;
      }
    }
  }
}