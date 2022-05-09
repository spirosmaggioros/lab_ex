#include "bits.h"//#include <bits/stdc++.h>

using namespace std;

bool sortbyfirst(const tuple<int, string, string , int , int>& a, const tuple<int ,string,string, int, int>& b)
{
    return (get<0>(a) < get<0>(b));
}

bool sortbysecond(const tuple<int, string, string , int , int>& a, const tuple<int ,string,string, int, int>& b)
{
    return (get<1>(a) < get<1>(b));
}

bool sortbythird(const tuple<int, string, string , int , int>& a, const tuple<int ,string,string, int, int>& b)
{
    if(get<2>(a) == get<2>(b)){
        return get<1>(a) < get<1>(b);
    }
    return (get<2>(a) < get<2>(b));
}
bool sortbyfourth(const tuple<int, string, string , int , int>& a, const tuple<int ,string,string, int, int>& b)
{
    if(get<3>(a) == get<3>(b)){
        if(get<2>(a) == get<2>(b)){
            return get<1>(a) < get<2>(b);
        }
        else
        {
            return get<2>(a) < get<2>(b);
        }
    }
    return (get<3>(a) < get<3>(b));
}
bool sortbyfifth(const tuple<int, string, string , int , int>& a, const tuple<int ,string,string, int, int>& b)
{
    if(get<4>(a) == get<4>(b)){
        if(get<3>(a) == get<3>(b)){
            if(get<2>(a) == get<2>(b)){
                return get<1>(a) < get<2>(b);
            }
        }
        else
        {
            return get<2>(a) < get<2>(b);
        }
    }
    return (get<4>(a) < get<4>(b));
}

int main(){
    int N; cin >> N;
    vector<tuple<int ,string,string , int,int> > v;
    for(int i=0; i<N; i++){
        int id , a1, a2; string name,surname;
        cin >> id >> name >> surname;
        cin >> a1 >> a2;
        v.push_back(make_tuple(id,name,surname,a1,a2));
    }
    int T; cin >> T;
    for(int i=0; i<T; i++){
        string what , order; int many;
        cin >> what >> order >> many;
        cout << "Query: " << what << " " << order << " " << many << endl;
        cin.ignore();
        if(what == "id"){
            if(order == "asc"){
                int counter = 0;
                sort(v.begin() , v.end(), sortbyfirst);
                for(auto x : v){
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(x) << " " << get<1>(x) << " " <<get<2>(x) << " " << get<3>(x) << " " << get<4>(x) << endl;
                    counter++;
                }
            }
            else if(order == "desc"){
                int counter = 0 ;
                sort(v.begin(),v.end(),sortbyfirst);
                for(auto it = v.size(); it >=0; it--){
                    if(counter == 0){
                        it--;
                    }
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(v[it]) << " " << get<1>(v[it]) << get<2>(v[it]) << get<3>(v[it]) << get<4>(v[it]) << endl;
                    counter++;
                }
            }
        }
        else if(what == "name"){
            if(order == "asc") {
                sort(v.begin(), v.end(), sortbythird);
                int counter = 0;
                for (auto x: v) {
                    if (counter == many) {
                        break;
                    }
                    cout << get<0>(x) << " " << get<1>(x) << " " <<get<2>(x) << " " << get<3>(x) << " " << get<4>(x) << endl;
                    counter++;
                }
            }
            else if(order == "desc"){
                sort(v.begin() , v.end() , sortbythird);
                int counter = 0;
                for(auto it = v.size(); it >=0; it--){
                    if(counter == 0){
                        it--;
                    }
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(v[it]) << " " << get<1>(v[it]) << " " <<get<2>(v[it]) << " " <<get<3>(v[it]) << " " << get<4>(v[it]) << endl;
                    counter++;
                }
            }
        }
        else if(what == "year"){
            if(order == "asc"){
                sort(v.begin() , v.end() ,sortbyfourth);
                int counter = 0;
                for(auto x : v){
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(x) << " " << get<1>(x) << " " <<get<2>(x) << " " << get<3>(x) << " " << get<4>(x) << endl;
                    counter++;
                }
            }
            else if(order == "desc"){
                sort(v.begin() , v.end() , sortbyfourth);
                int counter = 0;
                for(auto it = v.size(); it >=0; it--){
                    if(counter == 0){
                        it--;
                    }
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(v[it]) << " " << get<1>(v[it]) << " " <<get<2>(v[it]) <<" " <<get<3>(v[it]) << " " << get<4>(v[it]) << endl;
                    counter++;
                }
            }
        }
        else if(what == "salary"){
            if(order == "asc"){
                sort(v.begin() , v.end() ,sortbyfifth);
                int counter = 0;
                for(auto x : v){
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(x) << " " << get<1>(x) << " " <<get<2>(x) << " " << get<3>(x) << " " << get<4>(x) << endl;
                    counter++;
                }
            }
            else if(order == "desc"){
                sort(v.begin() , v.end() , sortbyfifth);
                int counter = 0;
                for(auto it = v.size(); it >=0; it--){
                    if(counter == 0){
                        it--;
                    }
                    if(counter == many){
                        break;
                    }
                    cout << get<0>(v[it]) << " " << get<1>(v[it]) << " " <<get<2>(v[it]) <<" " <<get<3>(v[it]) << " " << get<4>(v[it]) << endl;
                    counter++;
                }
            }
        }
    }
}
