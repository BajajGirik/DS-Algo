#include "../headers/utils.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/input.txt","r", stdin);
	freopen("IO/q4/output.txt","w", stdout);
}

int main() {
	file_i_o();

	auto v = input_data();

	bucket_sort_analysis(v);

	return 0;
}