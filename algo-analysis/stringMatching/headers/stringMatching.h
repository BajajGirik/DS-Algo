#ifndef STRINGMATCHING_H
#define STRINGMATCHING_H

#include <bits/stdc++.h>

#define RABIN_BASE 26

bool naive_string_matching(std::string, std::string);
std::vector<int> lps_formation(std::string);
bool krunth_morris_prat_string_matching(std::string, std::string);
bool rabin_karp_string_matching(std::string, std::string);

#endif