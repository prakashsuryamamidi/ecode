#include "ecode.h"
#include "utils.hh"

#include <algorithm>

namespace chepp {

#define chepp_ops_warpper(name) [this](string &str) -> string & {return name(this,str);}

static string &op_set(ecode *obj,string &str) {
    auto vec = split(str,"=");
    obj -> vars[trim(vec[0])] = trim(vec[1]);
    str = "";
    return str;
}

static string &op_upper(ecode *obj, string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

static string &op_lower(ecode *obj, string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


ecode::ecode() {
    this -> ops["set"] = chepp_ops_warpper(op_set);
    this -> ops["upper"] = chepp_ops_warpper(op_upper);
    this -> ops["lower"] = chepp_ops_warpper(op_lower);
}
    
string &ecode::eval(string &str) {
    auto prefix = string::npos;
    while ((prefix = str.find("$#<")) != string::npos) {
        auto suffix = str.find(">",prefix + 3);
        auto express = str.substr(prefix + 3,suffix - (prefix + 3));
        auto exp = split(express, "|");
        auto buffer = trim(exp[0]);
        if (buffer.empty()) {
            buffer = "";
        } else if (buffer[0] == '$') {
            buffer = vars[trim(buffer).erase(0,1)];
        }
        for (int i = 1; i != exp.size(); i++) {
            auto op = this -> ops[trim(exp[i])];
            if (op) {
                buffer = op(buffer);
            }
        }
        str = str.replace(prefix,suffix - prefix + 1,buffer);
    }
    return str;
}

}

