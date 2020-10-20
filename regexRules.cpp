//
// Created by jetwood on 2020/10/16.
//
#include "regexRules.h"
#include <iostream>
using namespace std;


string &code_block(string &str)
{
    return str = regex_replace(str,CODE,"\t<code> $1 </code>");
}


string &blockQuote(string& str)
{
    return str = regex_replace(str, BLACK_QUOTE, "<blockquote> $1 </blockquote>");
}


string &unordered_list(string& str)
{
    smatch m;
    string temp = regex_replace(str, UNORDERED_LIST, "\t\t<li> $1 </li>\n");
    string pref;
    string suff;
    int n = 0;
    auto pos = temp.cbegin();
    str = "";
    auto end = temp.cend();
    for (;regex_search(pos, end, m, UNORDERED_LIST_HEADER); pos=m.suffix().first) {
        pref = m.prefix().str();
        suff = m.suffix().str();
        cout << ++n << pref[pref.size()-2] << endl;
        if (pref[pref.size()-2] != '\n')
            str += (pref + "\t<ul>\n" + m.str());
        if(suff[3] != '<')
            str += (m.str() + "\n\t</ul>\n" + suff);
        else
            str += m.str();

    }
    return str;
}

string label_ol(const string &body)
{
    return "\t<li>" + body + "</li>\n";
}


string copyFile(ifstream& src){
    char c;
    string rtn("\n");
    while (src.get(c)) {
        rtn += c;
    }
    return rtn;
}

