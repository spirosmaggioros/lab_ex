#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

#define MAXN 2147483647

long double distance(long double x1,long double y1, long double x2, long double y2)
{
    return sqrt(powl(x2 - x1, 2) + powl(y2 - y1, 2));
}

int main(){
    int N; cin >> N;
    map<string , set<pair<float , float>> > m;
    for(int i=0; i<N; i++){
        float x , y; string str; cin >> x >> y >> str;
        m[str].insert(make_pair(x,y));
    }
    int T; cin >> T;
    for(int i=0; i<T; i++){
        float x1 , y1; cin >> x1 >> y1;
        cout << fixed << setprecision(0) << x1 << " " << y1 << endl;
        double min = MAXN;
        for(auto z : m){
            for(auto it = z.second.begin(); it != z.second.end(); it++){
                if(distance(x1,y1,it->first,it->second) < min && distance(x1,y1,it->first,it->second) >= 0){
                    min = distance(x1,y1,it->first,it->second);
                }
            }
            cout << "  " << z.first << " ";
            cout << fixed << setprecision(3) << min << endl;
            min= MAXN;
        }
    }
}
