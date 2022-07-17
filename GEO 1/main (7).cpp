#include <iostream>
#include <vector>

using namespace std;
 
// (X[i], Y[i]) are coordinates of i'th point.
long long polygonArea(vector<pair<long long,long long>> points, long long n)
{
    // Initialize area
    long long area = 0;
 
    // Calculate value of shoelace formula
    long long j = n - 1;
    for (long long i = 0; i < n; i++)
    {
        area += (points[j].first + points[i].first) * (points[j].second - points[i].second);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area);
}
 
// Driver program to test above function
int main()
{  


  long long n;
  cin >> n;

  vector<pair<long long,long long>> points(n);
  
  for(long long i = 0 ; i < n ; i++){
    long long x,y;
    cin >> x >> y;
    points[i] = pair<long long,long long>(x,y);
  }
 
    cout << polygonArea(points, n) << endl;
}