#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &hist)
{
    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> s;
  
    int max_area = 0; // Initialize max area
    int tp; // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar
  
    // Run through all bars of given histogram
    int i = 0;
    while (i < hist.size()) {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
  
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else {
            tp = s.top(); // store the top index
            s.pop(); // pop the top
  
            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top
                = hist[tp]
                  * (s.empty() ? i : i - s.top() - 1);
  
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
  
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        area_with_top
            = hist[tp] * (s.empty() ? i : i - s.top() - 1);
  
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
  
    return max_area;
}

int main(){
    int t,a,p,l;
    bool isyes;
    cin >> t >> a;
    while(t--){
        cin >> p >> l;
        isyes=false;
        vector<vector<int>> map(l);

        for(int i=0; i<l; i++){
            string temp;
            cin >> temp;
            for(int j=0; j<p; j++){
                map[i].push_back(!(temp[j]-'0'));
            }
        }
        int max_area = getMaxArea(map[0]);

        for(int i=1; i<l; i++){
            for(int j=0; j<p; j++){
                if(map[i][j])
                    map[i][j] += map[i-1][j];
            }
            max_area = max(max_area, getMaxArea(map[i]));
            if(max_area >= a){
                isyes = true;
                break;
            }
        }
        if(isyes)
            cout << "IYA\n";
        else
            cout << "TIDAK\n";
    }
    return 0;
}