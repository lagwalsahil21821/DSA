// store previous index after sorting
#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);  // for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  
  for (int i = 0; i < idx.size(); i++)
  {
    cout<< idx[i]<<"\n";
  }
}


int main(){
  vector<int> value;
  
      value.push_back(2);
      value.push_back(4);
      value.push_back(3);
  
  cout<<value.size();
  
  
  sort_indexes(value);
  

}