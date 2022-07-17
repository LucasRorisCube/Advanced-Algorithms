#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node {
  int count = 0;
  int end = 0;
  map<char, node> next;
};

void printTrie(node trie){
  for(auto i = trie.next.begin() ; i != trie.next.end() ; i++){
    cout << i->first << ": " << trie.count << "/"<< trie.end << endl;
    
    printTrie(i->second);
  }
}

void insert_trie(node* trie, string word, int currentLetter){

  (*trie).count++;
  if(currentLetter < (int)word.length()){
    insert_trie(&((*trie).next[word[currentLetter]]), word, currentLetter+1);
  } else {
    (*trie).end++;
  }
  


  
  /*auto it = (*trie).next.find(word[currentLetter]);
  if(it == (*trie).next.end()){
    
    node newNode;
    insert_trie(&newNode, word, currentLetter+1);
    (*trie).next[word[currentLetter]] = newNode;
    
  } else {
    insert_trie(&(it->second), word, currentLetter+1);
  }*/
}

void delete_trie(node* trie, string word, int currentLetter){

  (*trie).count--;
  if(currentLetter < (int)word.length()){
    delete_trie(&((*trie).next[word[currentLetter]]), word, currentLetter+1);
  } else {
    (*trie).end--;
  }
  


  
  /*auto it = (*trie).next.find(word[currentLetter]);
  if(it == (*trie).next.end()){
    
    node newNode;
    insert_trie(&newNode, word, currentLetter+1);
    (*trie).next[word[currentLetter]] = newNode;
    
  } else {
    insert_trie(&(it->second), word, currentLetter+1);
  }*/
}

int search_trie(node* trie, string word, int currentLetter){

  if(currentLetter == (int)word.size()){
    return (*trie).count;
  }

  if((*trie).next.count(word[currentLetter]) > 0){
    return ((*trie).next.count(word[currentLetter])) ? search_trie(&((*trie).next[word[currentLetter]]), word, currentLetter+1) : 0;
  } else {
    return 0;
  }


  /*
  if(currentLetter < (int)word.length()){
    
    return search_trie(&((*trie).next[word[currentLetter]]), word, currentLetter+1);
    
  } else {
    return true;
  }*/
  


  
  /*auto it = (*trie).next.find(word[currentLetter]);
  if(it == (*trie).next.end()){
    
    node newNode;
    insert_trie(&newNode, word, currentLetter+1);
    (*trie).next[word[currentLetter]] = newNode;
    
  } else {
    insert_trie(&(it->second), word, currentLetter+1);
  }*/
}



int main() {

  node* initTrie = new node();
  
  int n;
  cin >> n;

  for(int i = 0 ; i < n ; i++){

    int mode;
    cin >> mode;
    
    string aux;
    cin >> aux;

    switch(mode){
      case 1:
        insert_trie(initTrie, aux, 0);
        break;
      case 2:
        delete_trie(initTrie, aux, 0);
        break;
      case 3:
        cout << search_trie(initTrie, aux, 0) << endl;
        break;
    }
    

  }

}