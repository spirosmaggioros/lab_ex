#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
  Graph(int n) : letters(n) {
    this -> V = n;
    adj = new vector<int>[V];
  }
  void addEdge(int a , int b){
    adj[a].push_back(b);
  }
  void addLetter(int a, char u){
    letters[a] = u;
  }
  int solve(){
    vector<bool> visited(V , false);
    int counter = 0;
    dfs(visited , counter);
    return counter;
  }
  void dfs(vector<bool> &visited , int &counter){
   for(int i = 0; i<V; i++){
       for(auto it2 = adj[i].begin(); it2 != adj[i].end(); it2++){
         if(letters[*it2] == letters[i]){
           for(auto it3 = adj[*it2].begin(); it3 != adj[*it2].end(); it3++){
             if(!visited[*it3] && letters[*it3] == letters[*it2]){
               counter++;
             }
             else{
               continue;
             }
           }
         }
         else continue;
       }
     }
   }
private:
  vector<int> *adj;
  vector<int> letters;
  int V;
};

int main(){
  int K , M; cin >> K >> M;
  Graph g(K);
  for(int i=0; i<K; i++){
    char c;  cin >> c;
    g.addLetter(i, c);
  }
  for(int i=0; i<M; i++){
    int a,  b; cin >> a >> b;
    g.addEdge(a , b);
  }
  cout << g.solve() <<'\n';
}
