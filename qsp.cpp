#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main(){
  int N; cin >> N;
  list<int> Q;
  stack<int> S;
  for(int i=0; i<N; i++){
    int x; cin >> x;
    Q.push_back(x);

  }
  string commands; cin >> commands;
  for(char cmd : commands){
    switch(cmd){
      case 'Q':
      if(Q.empty()){
        cout << "error" << endl;//or throw -> error...
        exit(0);
      }
      S.push(Q.front());
      Q.pop_front(); break;
      case 'S':
      if(S.empty()){
        cout << "error" << endl;
        exit(0);
      }
      Q.push_back(S.top());
      S.pop(); break;
      case 'P':
      for(int x : Q){
        cout << x << " ";
      }
      cout << endl;
      break;
    }
  }
}
