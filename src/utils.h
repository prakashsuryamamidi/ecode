#ifndef _UTILS_H
#define _UTILS_H

#include <filesystem>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace chepp {

vector<string> split(const string &express, const string &sep);

string& trim(string &s);

}

#endif
