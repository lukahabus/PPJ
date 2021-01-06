#include<bits/stdc++.h>
using namespace std;

string a, b, c, linenum, hidden, hln;
string output;
bool za = 0, error = 0;
map<string, string> GM, SM;

bool findNext()
{
    while(cin >> a) {
        if(a[0] != '<' && a[0] != '$')
        {
            cin >> b >> c;
            return true;
        }
    }
    return false;
}

void OP_PRIDRUZI()
{
    linenum = b;
    while(findNext() && b == linenum) {
        if(!error && a == "IDN")
        {
            if(za) {
                if(hidden == c && hln == b)
                {
                    output += "err " + linenum + " " + c + '\n';
                    error = 1;
                    break;
                }
                swap(GM[c], SM[c]);
            }

            if(!GM[c].empty())
                output += linenum + " " + GM[c] + " " + c + '\n';
            else if(!SM[c].empty())
                output += linenum + " " + SM[c] + " " + c + '\n';
            else {
                output += "err " + linenum + " " + c + '\n';
                error = 1;
            }

            if(za)
                swap(GM[c], SM[c]);
        }
    }
}

int main()
{
    while(findNext()) {
        if(a == "OP_PRIDRUZI")
        {
            OP_PRIDRUZI();
        }

        if(a == "IDN")
        {
            if(za == 0 && GM[c].empty())
                GM[c] = b;
            else if(za == 1 && SM[c].empty())
                SM[c] = b;
        }

        if(a == "KR_ZA")
        {
            za = 1;
            findNext();
            SM[c] = b;
            hidden = c;
            hln = b;
            OP_PRIDRUZI();
        }
        if(a == "KR_AZ")
        {
            za = 0;
            SM.clear();
        }

    }
    cout << output;

    return 0;
}
