#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define PII pair<int,int>
using namespace std;

class comparator{
public:
    bool operator()(PII a, PII b){
        return(a.first-a.second < b.first-b.second);
    }
};
priority_queue<PII, vector<PII>, comparator> pq;
int main(){
    fastio
    string temp;
    long long t=0;
    cin >> temp;

    int n, sp, sm;
    cin >> n >> sp >> sm;
    n--;
    while(n--){
        int p, k, l;
        cin >> p >> k >> l;
        while(sp < p){
            if(pq.empty()){
                cout << "-1";
                return 0;
            }
            t += pq.top().second;
            sp++;
            pq.pop();
        }
        if(k < l) pq.push({k,l});
        else {
            t += l;
            sp++;
        }
    }

    while(sp < sm){
        if(pq.empty()){
            cout << "-1";
            return 0;
        }
        t += pq.top().second;
        sp++;
        pq.pop();
    }
    while(!pq.empty()){
        PII temp = pq.top();
        t += min(temp.first, temp.second);
        // cout << temp.first << " " << temp.second << endl;
        pq.pop();
    }

    cout << t;
    return 0;
}