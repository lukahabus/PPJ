#include <iostream>
#include <string>
#include <utility>
using namespace std;

string line;
string input;
string out;
int spacecnt = 0;
bool flag = 0;
string errstr;

void program();
void lista_naredbi();
void naredba();
void naredba_pridruzivanja();
void za_petlja();
void E();
void E_lista();
void T();
void T_lista();
void P();

void err() {
    flag = 1;
    if(errstr.empty())
        errstr = line;
}

void print(string s) {
    out += string(spacecnt, ' ') + "<" + s + ">\n";
    spacecnt++;
}

void gagi() {
    out += string(spacecnt, ' ') + line + "\n";
    getline(cin, line);
    input = line.substr(0, line.find(" "));
}

int main()
{
	getline(cin, line);
	input = line.substr(0, line.find(" "));
	program();

    if(!flag) {
        cout << out;
    }
    else {
        cout << "err ";
        errstr.empty() ? cout << "kraj" : cout << errstr;
    }

	return 0;
}

void program()
{
    if(input == "IDN" || input == "KR_ZA" || line.empty()) {
        print("program");
        lista_naredbi();
        spacecnt--;
    }
    else
        err();
}

void lista_naredbi()
{
    if(input == "IDN" || input == "KR_ZA") {
        print("lista_naredbi");
        naredba();
        lista_naredbi();
        spacecnt--;
    }
    else if(input == "KR_AZ" || line.empty()) {
        print("lista_naredbi");
        out += string(spacecnt, ' ') + "$\n";
        spacecnt--;
    }
    else
        err();
}

void naredba()
{
    if(input == "IDN") {
        print("naredba");
        naredba_pridruzivanja();
        spacecnt--;
    }
    else if(input == "KR_ZA") {
        print("naredba");
        za_petlja();
        spacecnt--;
    }
    else
        err();
}

void naredba_pridruzivanja()
{
    if(input == "IDN") {
        print("naredba_pridruzivanja");
        gagi();
        gagi();
        E();
        spacecnt--;
    }
    else
        err();
}

void za_petlja()
{
    if(input == "KR_ZA")
    {
        print("za_petlja");
        gagi();
        gagi();
        gagi();
        E();
        gagi();
        E();
        lista_naredbi();
        gagi();
        spacecnt--;
    }
    else
        err();
}

void E()
{
    if(input == "IDN" || input == "BROJ" || input == "OP_PLUS" || input == "OP_MINUS" || input == "L_ZAGRADA")
    {
        print("E");
        T();
        E_lista();
        spacecnt--;
    }
    else
        err();
}

void E_lista()
{
    if(input == "OP_PLUS" || input == "OP_MINUS") {
        print("E_lista");
        gagi();
        E();
        spacecnt--;
    }
    else if(input == "IDN" || input == "KR_ZA" || input == "KR_DO" || input == "KR_AZ" || input == "D_ZAGRADA" || line.empty())
    {
        print("E_lista");
        out += string(spacecnt, ' ') + "$\n";
        spacecnt--;
    }
    else
        err();
}

void T()
{
    if(input == "IDN" || input == "BROJ" || input == "OP_PLUS" || input == "OP_MINUS" || input == "L_ZAGRADA")
    {
        print("T");
        P();
        T_lista();
        spacecnt--;
    }
    else
        err();
}

void T_lista()
{
    if(input == "OP_PUTA" || input == "OP_DIJELI") {
        print("T_lista");
        gagi();
        T();
        spacecnt--;
    }
    else if(input == "IDN" || input == "KR_ZA" || input == "KR_DO" || input == "KR_AZ" || input == "OP_PLUS" || input == "OP_MINUS" || input == "D_ZAGRADA" || line.empty())
    {
        print("T_lista");
        out += string(spacecnt, ' ') + "$\n";
        spacecnt--;
    }
    else
        err();
}

void P()
{
    if(input == "OP_PLUS" || input == "OP_MINUS")
    {
        print("P");
        gagi();
        P();
        spacecnt--;
    }
    else if(input == "L_ZAGRADA")
    {
        print("P");
        gagi();
        E();
        gagi();
        spacecnt--;
    }
    else if(input == "IDN" || input == "BROJ")
    {
        print("P");
        gagi();
        spacecnt--;
    }
    else
        err();
}
