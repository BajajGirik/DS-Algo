#include "../headers/stringMatching.h"
#include <bits/stdc++.h>

bool naive_string_matching(std::string s, std::string pattern) {
	int s_len = s.size();
	int pat_len = pattern.size();

	for(int i=0; i<s_len; ++i) {
		int tempi = i;
		int j = 0;
		while(tempi<s_len and s[tempi] == pattern[j]) {
			++tempi;
			++j;

			if(j>=pat_len) return true;
		}
	}

	return false;
}

std::vector<int> lps_formation(std::string pattern) {
	int len = 0;
	std::vector<int> lps(pattern.size(), 0);

	for(int i=1; i<pattern.size(); ++i) {
		if(pattern[i] == pattern[len]) {
			++len;
			lps[i] = len;
		} else {
			while(len > 0 and pattern[i] != pattern[len]) {
				len = lps[len-1];
			}

			if(len != 0) {
				++len;
				lps[i] = len;
			} else {
				lps[i] = 0;
			}
		}
	}

	return lps;
}

bool krunth_morris_prat_string_matching(std::string s, std::string pattern) {
	std::vector<int> lps = lps_formation(pattern);

	int j = -1;
	for(int i=0; i<s.size(); ++i) {
		if(pattern[j+1] == s[i]) ++j;
		else {
			while(j>0 and pattern[j] != s[i])
				j = lps[j-1];

			if(j == 0) j = -1;
		}

		if(j+1 == pattern.size()) return true;
	}

	return false;
}

bool rabin_karp_string_matching(std::string s, std::string pattern) {
	int n = s.size();
	int m = pattern.size();
	int prev_hash = 0;
	int pat_hash = 0;
	int max_pow = 1;

	for(int i=0; i<m; ++i) {
		pat_hash = (pat_hash * RABIN_BASE) % INT_MAX;
		pat_hash = (pat_hash + (pattern[i] - 'a' + 1)) % INT_MAX;

		prev_hash = (prev_hash * RABIN_BASE) % INT_MAX;
		prev_hash = (prev_hash + (s[i] - 'a' + 1)) % INT_MAX;

		max_pow = (max_pow * RABIN_BASE) % INT_MAX;
	}

	if(prev_hash == pat_hash) {
		int i = 0;
		while(i<m and pattern[i] == s[i]) ++i;
		
		if(i == m) return true;
	}

	for(int i=m; i<n; ++i) {
		int f_val = s[i-m] - 'a' + 1;
		int c_val = s[i] - 'a' + 1;
		f_val = f_val * max_pow;

		int curr_hash = ((prev_hash - f_val)*RABIN_BASE + c_val) % INT_MAX;
		if(curr_hash == pat_hash) {
			int j=0;
			while(j<m and s[i-m+j] == pattern[j]) ++j;

			if(j == m) return true;
		}
	}

	return false;
}