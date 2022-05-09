#include "bits.h"//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool sortbyprice(const tuple<string,int,int> &a , const tuple<string,int,int> &b){
    if(get<2>(a)== get<2>(b)){
        return get<1>(a) < get<1>(b);
    }
    return get<2>(a) < get<2>(b);
}

bool sortbytime(const pair<string,int> &a , const pair<string,int> &b ){
    return a.first < b.first;
}

int main(){
    int T; cin >> T;
    vector<pair<string,int>> v;
    vector<tuple<string, int, int>>t2;
    for(int i=0; i<T; i++){
        string a; cin >> a;
        int b; cin >> b;
        v.emplace_back(make_pair(a, b));
    }
    int N; cin >> N;
    for(int i=0; i<N; i++){
        string a; cin >> a;
        int b , c; cin >> b >> c;
        t2.emplace_back(make_tuple(a,b,c));
    }
    sort(t2.begin() , t2.end() , sortbyprice);
    sort(v.begin() ,v.end() , sortbytime);
    for(auto x : v){
        int sum = 0 , price = 0;
        for(auto z : t2){
            if(get<0>(z) == x.first) {
                sum += get<1>(z);
                price += get<1>(z) * get<2>(z);
                if (sum > x.second) {
                    price -= get<1>(z) * get<2>(z);
                    price += (x.second - get<1>(z)) * get<2>(z);
                    get<1>(z) -= x.second - get<1>(z);
                    break;
                }
                if (sum == x.second) {
                    get<1>(z) = 0;
                    break;
                }
                get<1>(z) = 0;
            }
        }
        if(sum < x.second){
            cout << x.first << " IMPOSSIBLE" << endl;
        }
        else
        {
            cout << x.first << " " << price << endl;
        }
    }
}
