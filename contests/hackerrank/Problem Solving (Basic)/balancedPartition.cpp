#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'mostBalancedPartition' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY parent
 *  2. INTEGER_ARRAY files_size
 */

void mostBalancedPartition(vector<int> parent, vector<int> files_size) {
	vector<int> possible_sums(parent.size());

	int i, index;
	i = index = parent.size() - 1;

	while(i > parent[index]) {
		possible_sums[i] = files_size[i];
		--i;
	}

	for(; i >= 0; --i) {
		possible_sums[i] = 0;

		while(i == parent[index]) {
			possible_sums[i] += possible_sums[index];
			--index;
		}

		possible_sums[i] += files_size[i];
	}

	int min_diff = INT32_MAX;

	for(int i = 1; i < possible_sums.size(); ++i) {
		min_diff = min(min_diff, abs(2*possible_sums[i] - possible_sums[0]));
	}

	cout << min_diff << endl;
}

int main() {
	freopen("output.txt", "w", stdout);

	vector<int> parent {-1, 0, 1, 2};
	vector<int> files_size {1, 4, 3, 4};

	mostBalancedPartition(parent, files_size);
	return 0;
}


// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string parent_count_temp;
//     getline(cin, parent_count_temp);

//     int parent_count = stoi(ltrim(rtrim(parent_count_temp)));

//     vector<int> parent(parent_count);

//     for (int i = 0; i < parent_count; i++) {
//         string parent_item_temp;
//         getline(cin, parent_item_temp);

//         int parent_item = stoi(ltrim(rtrim(parent_item_temp)));

//         parent[i] = parent_item;
//     }

//     string files_size_count_temp;
//     getline(cin, files_size_count_temp);

//     int files_size_count = stoi(ltrim(rtrim(files_size_count_temp)));

//     vector<int> files_size(files_size_count);

//     for (int i = 0; i < files_size_count; i++) {
//         string files_size_item_temp;
//         getline(cin, files_size_item_temp);

//         int files_size_item = stoi(ltrim(rtrim(files_size_item_temp)));

//         files_size[i] = files_size_item;
//     }

//     int result = mostBalancedPartition(parent, files_size);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }
