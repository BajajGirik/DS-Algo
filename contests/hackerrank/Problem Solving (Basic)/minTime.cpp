#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY files
 *  2. INTEGER numCores
 *  3. INTEGER limit
 */

long minTime(vector<int> files, int numCores, int limit) {
	sort(files.begin(), files.end());

	long sum = 0;
	for(int i = files.size() - 1; i >= 0; --i) {
		if(limit > 0 and files[i] % numCores == 0) {
			files[i] / numCores;
			--limit;
		}

		sum += files[i];
	}

	return sum;
}

int main() {
	freopen("output.txt", "w", stdout);

	vector<int> files {1, 2, 3, 4};

	minTime(files, 4, 1);
	return 0;
}