#include <iostream>  
#include <vector>  
#include <map>  
#include <set>  
  
using namespace std;  
  
int main(){  
  string str;  
  map<char , set<string> > words;  
  map<char, int> count;  
  map<char , string> longest , shortest;  
  while(cin >> str){  
    char init = str[0];  
    words[init].insert(str);  
    count[init]++;  
    if(count[init] == 1 || str.size() > longest[init].size() || (str.size() == longest[init].size() && str < longest[init])){  
      longest[init] = str;  
    }  
    if(count[init] == 1 || str.size() < shortest[init].size() || (str.size() == shortest[init].size() && str < shortest[init])){  
      shortest[init] = str;  
    }  
  }  
  for(char initial = 'a'; initial <= 'z'; initial++){  
    if(count[initial] > 0){  
      cout << initial << ": " << count[initial] << " word(s), " << words[initial].size() << " unique word(s), longest '"  
      << longest[initial] << "' and shortest '" << shortest[initial] <<"'" << endl;  
    }  
  }  
 }
