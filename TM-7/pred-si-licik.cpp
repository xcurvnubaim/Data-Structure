#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct tr{
    int id, c;
};

int main(){
    string str;
    stack<tr> a;
    queue<tr> b;

    bool look=1; // 0: A ; 1:B
    int a_untung, b_untung;
    a_untung = b_untung = 0; 

    while(cin >> str && str!="CLOSED"){
        if(str=="STEAL"){
            if (look)
            {
                if (b.empty()) 
                    cout << "TOKO B KOSONG\n";  
                else
                {
                    b_untung -= b.front().c;
                    b.pop();
                }
            } else {
                if (a.empty()) 
                    cout<< "TOKO A KOSONG\n";  
                else
                {
                    a_untung -= a.top().c;
                    a.pop();
                }
            }
        } else if(str=="TRADE"){
            look = !look;
        } else {
            tr temp;
            cin >> temp.id >> temp.c;
            if(look){
                b.push(temp);
                b_untung += temp.c;
            } else {
                a.push(temp);
                a_untung += temp.c;
            }
        }
    }

    cout << "TOKO A :\n";
    if (a.empty()) cout << "\nTOKO A SEPI :(\n\n";
    else
    {
        while (!a.empty())
        {
            cout << a.top().id << " " << a.top().c << endl;
            a.pop();
        }
    }
    cout << "TOKO A UNTUNG : " << a_untung << endl;

    cout << "TOKO B :\n";
    if (b.empty()) cout << "\nTOKO B SEPI :(\n";
    else
    {
        while (!b.empty())
        {
            cout << b.front().id << " " << b.front().c << endl;
            b.pop();
        }
    }
    cout << "TOKO B UNTUNG : " << b_untung << endl;
    
    return 0;
}