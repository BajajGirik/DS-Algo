#include "../headers/sorting.h"
#include "../headers/utils.h"

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

ll get_largest_kth_element(vi arr, ll k, ll start, ll end) {
	auto par = quick_sort_partition(arr, start, end);

	if(k == par[0] + 1)
		return arr[k];

	if(k > par[0] + 1) 
		return get_largest_kth_element(arr, k - 1 - par[0], par[0] + 1, end);

	return get_largest_kth_element(arr, k, start, par[0] - 1);
}

void bubble_sort_analysis(vi arr) {
	clock_t start = clock();

	auto details = bubble_sort(arr);

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Bubble Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << details[0] << endl;
	cout << "No. of swaps: " << details[1] << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void insertion_sort_analysis(vi arr) {
	clock_t start = clock();

	auto details = insertion_sort(arr);

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Insertion Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << details[0] << endl;
	cout << "No. of swaps: " << details[1] << endl;
	cout << "Execution Time: " << (double)(end-start)/ (double)CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void selection_sort_analysis(vi arr) {
	clock_t start = clock();

	auto details = selection_sort(arr);

	clock_t end = clock();

	cout << endl << "------------------------------" << endl;
	cout << "Selection Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << details[0] << endl;
	cout << "No. of swaps: " << details[1] << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void count_sort_analysis(vi arr) {
	clock_t start = clock();

	ll size = count_sort(arr);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Count Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "Size of array(hash) used: " << size << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void quick_sort_analysis(vi arr) {
	clock_t start = clock();

	auto res = quick_sort(arr, 0, arr.size() - 1);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Quick Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << res[1] << endl;
	cout << "No. of swaps: " << res[0] << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void heap_sort_analysis(vi arr) {
	clock_t start = clock();

	auto res = heap_sort(arr);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Heap Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "No. of comparisons: " << res[1] << endl;
	cout << "No. of swaps: " << res[0] << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void bucket_sort_analysis(vi arr) {
	clock_t start = clock();

	ll bucket_count = bucket_sort(arr);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Bucket Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "Number of buckets used: " << bucket_count << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}

void radix_sort_analysis(vi arr) {
	clock_t start = clock();

	radix_sort(arr);

	clock_t end = clock();
	cout << endl << "------------------------------" << endl;
	cout << "Radix Sort Analysis (For array of size " << arr.size() << "):" << endl;
	cout << "Execution Time: " << (double)(end-start)/ CLOCKS_PER_SEC << "sec" << endl << endl;
	cout << "------------------------------" << endl;
}