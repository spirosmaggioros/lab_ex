#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
  int N , D; cin >> N >> D;
  vector<set<string> > dict(D);
  map<string, set<int> > where;
  for(int i=0; i<N; i++){
    int d; string s;
    cin >> d >> s;
    dict[d - 1].insert(s);
    where[s].insert(d);
  }
  int largest = 0;
  for(int i=0; i<D; i++){
    if(dict[i].size() > dict[largest].size()){
      largest = i;
    }
  }
  cout << "Largest : " << largest + 1 << " with " << dict[largest].size() << " words " << endl;
  int counter = 0;
  for(auto x : where){
    if(x.second.size() == D){
      cout << x.first << endl;
      counter++;
    }
  }
  cout << counter << " words appear in all dictionaries " << endl;
  return 0;
}
