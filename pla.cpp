#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using bldg = pair<long long, long long>;  


vector<bldg> merge (vector<bldg>& v){
    vector<bldg> merged;
    bldg last_bldg = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (last_bldg.second == v[i].second)
        {
            last_bldg.first += v[i].first;
        }
        else
        {
            merged.push_back(last_bldg);
            last_bldg = v[i];
        }
    }
    merged.push_back(last_bldg);
    return merged;
}


long long count_posters(vector<bldg>& buildings)
{
    //stack of heights
    vector<long long> h = {0};
    long long last = 0;
    long long posters = 0; 
    for (auto b : buildings)
    {
        while (h.back() > b.second)
        {
            posters += 1;
            h.pop_back();
        }
        if (h.back() < b.second)
            h.push_back(b.second);
    }
    return posters + h.size() - 1;
} 

int main(){
    int n;
    scanf("%d", &n);
    // list of length and heigh of buildings
    vector<bldg> b;
    b.reserve(n);
    for (int i = 0; i < n; ++i)
    {   
        long long d, w;
        scanf ("%lld %lld", &d, &w);
        b.push_back({d,w});
    }
    b = move(merge(b));
    long long posters = count_posters(b);
    printf("%lld\n", posters);
}