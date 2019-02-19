#include <filesystem>
#include <iostream>

#include "ecode.h"

using namespace std;
using namespace chepp;

int main() {
    ecode p;
    
    p.ops["echo"] = [&p](string &s) -> string &{cout << s << endl;return s;};
    
    string buf("sdafsf$#<asdasdasd | upper>");
    cout << p.eval(buf) << endl;
    //cout << p.vars["test"] << endl;
    return 0;
}
