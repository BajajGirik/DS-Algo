#include "../myheader.h"


vector<ll> input_data();
void print_data(vector<ll> arr);
void bubble_sort(vector<ll> arr);
void insertion_sort(vector<ll> arr);
void selection_sort(vector<ll> arr);
void count_sort(vector<ll> arr);
void min_max_in_array(vector<ll> arr);


vector<ll> input_data() {
	vector<ll> v;
	
	ll temp;
	while(cin >> temp) {
		v.pb(temp);
	}

	return v;
}

void print_data(vector<ll> arr) {
	cout << "Array contents: " << endl;
	for(auto x: arr) {
		cout << x << " ";
	}
	cout << endl;
}

void bubble_sort(vector<ll> arr) {
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

void insertion_sort(vector<ll> arr) {
	clock_t start = clock();
	ll comparisons = 0, swaps = 0;

	loop(i, 0, arr.size()) {
		ll value = arr[i];
		ll j = i-1;
		while(j >= 0 && arr[j] < value) {
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

void selection_sort(vector<ll> arr) {
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


vector<ll> min_max_in_arr(vector<ll> arr) {
	vector<ll> v(2, arr[0]);
	
	loop(i, 0, arr.size()) {
		if(v[0] > arr[i])
			v[0] = arr[i];

		if(v[1] < arr[i])
			v[1] = arr[i];
	}

	return v;
}

void count_sort(vector<ll> arr) {
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