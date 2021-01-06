#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int isKeyword(string buffer) {
    string keywords[4] = { "za", "od", "do", "az" };
    int i, flag = -1;
    for (i = 0; i < 4; ++i) {
        if (keywords[i] == buffer) {
            flag = i;
            break;
        }
    }

    return flag;
}

int main()
{
    string buffer = "", operators = "=+-*/()";
    string KR[4] = { "ZA", "OD", "DO", "AZ" };
    string OP[5] = { "PRIDRUZI", "PLUS", "MINUS", "PUTA", "DIJELI" };
    int linecnt = 1;
    char ch;
    bool p = 0;

    while (cin.get(ch)) {
        if (ch == '/' and cin.peek() == '/') {
            while (ch != '\n')
                cin.get(ch);
        }

        for (int i = 0; i < 7; i++)
            if (ch == operators[i])
                p = 1;

        if (isalnum(ch))
            buffer += ch;

        else if (ch == ' ' || ch == '\n' || p == 1) {

            if (buffer != "") {
                int kw = isKeyword(buffer);
                if (kw != -1)
                    cout << "KR_" << KR[kw] << " " << linecnt << " " << buffer << endl;
                else {
                    //isdigit(buffer[0]) ? cout << "BROJ" : cout << "IDN";
                    if(isdigit(buffer[0])) {
                        cout << "BROJ" << " " << linecnt << " ";
                        if (buffer.length() > 1) {
                            if (isdigit(buffer[1]))
                                cout << buffer << endl;
                            else {
                                cout << buffer[0] << endl;
                                cout << "IDN" << " " << linecnt << " " << buffer.erase(0, 1) << endl;
                            } 
                        }
                        else 
                            cout << buffer[0] << endl;
                    }
                    else
                        cout << "IDN" << " " << linecnt << " " << buffer << endl;
                }
                buffer = "";
                p = 0;
            }

            if (ch == '\n')
                linecnt++;
        }

        for (int i = 0; i < 5; i++)
            if (ch == operators[i])
                cout << "OP_" << OP[i] << " " << linecnt << " " << ch << endl;

        if(ch == '(')
            cout << "L_ZAGRADA " << linecnt << " " << ch << endl;

        else if (ch == ')')
            cout << "D_ZAGRADA " << linecnt << " " << ch << endl;

    }
    return 0;
}