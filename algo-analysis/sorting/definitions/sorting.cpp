#include "../headers/sorting.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/input.txt","r", stdin);
	freopen("IO/output.txt","w", stdout);
}

vi input_data() {
	vi v;
	
	ll temp;
	while(cin >> temp) {
		v.pb(temp);
	}

	return v;
}

void print_data(vi arr) {
	cout << "Array contents: " << endl;
	for(auto x: arr) {
		cout << x << " ";
	}
	cout << endl;
}

void bubble_sort(vi arr) {
	clock_t start = clock();
	ll comparisons = 0, swaps = 0;

	loop(i, 0, arr.size()) {
		loop(j, 0, arr.size()-i-1) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				++swaps;
			}

			++comparisons;
		}
	}

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Bubble Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << comparisons << endl;
	cout << "No. of swaps: " << swaps << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void insertion_sort(vi arr) {
	clock_t start = clock();
	ll comparisons = 0, swaps = 0;

	loop(i, 0, arr.size()) {
		ll value = arr[i];
		ll j = i-1;
		while(j >= 0 and arr[j] < value) {
			arr[j+1] = arr[j];
			--j;
			++comparisons;
			++swaps;
		}
		arr[j + 1] = value;
	}

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Insertion Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << comparisons << endl;
	cout << "No. of swaps: " << swaps << endl;
	cout << "Execution Time: " << (double)(end-start)/ (double)CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void selection_sort(vi arr) {
	clock_t start = clock();
	ll comparisons = 0, swaps = 0;

	loop(i, 0, arr.size()) {
		ll min_index = i+1;
		loop(j, i + 1, arr.size()) {
			if(arr[j] < arr[min_index])
				min_index = j;

			++comparisons;
		}

		swap(arr[i], arr[min_index]);
		++swaps;
	}

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Selection Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << comparisons << endl;
	cout << "No. of swaps: " << swaps << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}


vi min_max_in_arr(vi arr) {
	vi v(2, arr[0]);
	
	loop(i, 0, arr.size()) {
		if(v[0] > arr[i])
			v[0] = arr[i];

		if(v[1] < arr[i])
			v[1] = arr[i];
	}

	return v;
}

void count_sort(vi arr) {
	clock_t start = clock();

	auto min_max = min_max_in_arr(arr);
	int count[min_max[1] - min_max[0] + 1] = {0};

	loop(i, 0, arr.size()) {
		++count[arr[i]-min_max[0]];
	}

	ll j = 0;
	loop(i, 0, min_max[1] - min_max[0] + 1) {
		while(count[i] != 0) {
			arr[j++] = i;
			--count[i];
		}
	}

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Count Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

vi quick_sort_partition(vi &arr, ll low, ll high) {
	ll swaps = 0, comparisons = 0;
	ll pivot = arr[high];

	ll j = -1;
	loop(i, 0, high) {
		if(pivot >= arr[i]) {
			swap(arr[++j], arr[i]);
			++swaps;
		}
		++comparisons;
	}

	swap(arr[j+1], arr[high]);

	vi v;
	v.pb(j+1);
	v.pb(swaps);
	v.pb(comparisons);

	return v;
}

vi quick_sort(vi arr, ll low, ll high) {
    vi res;
	res.pb(0);
	res.pb(0);

	if(low >= high)
		return vi{0, 0};

	auto par = quick_sort_partition(arr, low, high);
	res[0] += par[1];
	res[1] += par[2];

	quick_sort(arr, low, par[0] - 1);
	quick_sort(arr, par[0] + 1, high);

	return res;
}

void quick_sort_analysis(vi arr, ll low, ll high) {
	clock_t start = clock();

	auto res = quick_sort(arr, low, high);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Quick Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << res[1] << endl;
	cout << "No. of swaps: " << res[0] << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}