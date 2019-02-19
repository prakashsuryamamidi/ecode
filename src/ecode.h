#ifndef _ECODE_H
#define _ECODE_H

#include <string>
#include <functional>
#include <map>

using namespace std;

namespace chepp {

class ecode {
public:
    ecode();
    ecode(const ecode &) = delete;
    ~ecode() = default;
public:
    string &eval(string &str);
public:
    map<string,string> vars;
    map<string,function<string&(string&)>> ops;
};

}

#endif
