#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
void print(vector<int> currentPath){
  for( int aux : currentPath){
      cout << aux << " ";
    }
    cout << endl;
}

int abs(int num){
  if(num > 0) return num;
  else return -num;
}

int calc(unordered_map<int, int>& heights, int init, int end){
  
  return abs(heights[init] - heights[end]);
}

void explore(unordered_map<int, int>& heights, unordered_map<int, int>& dist, int current){
  if(current == 0){
    dist[0] = 0;
    return;
  }
  if(current == 1){
    dist[1] = calc(heights, 0, 1);
    return;
  }
  
  if(dist[current-1] == -1) explore(heights, dist, current-1);
  if(dist[current-2] == -1) explore(heights, dist, current-2);
  
  dist[current] = min(dist[current-1]+calc(heights, current-1, current), dist[current-2]+calc(heights, current, current-2));
  
}

int main() {

  unordered_map<int, int> dist;
  
  int n;
  cin >> n;

  unordered_map<int, int> heights;
  int aux;
  for( int i = 0 ; i < n ; i++){
    cin >> aux;
    heights[i] = aux;
    dist[i] = -1;
  }

  explore(heights, dist, n-1);
  cout << dist[(int)heights.size()-1] << endl;
}