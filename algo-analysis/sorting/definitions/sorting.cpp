#include "../headers/sorting.h"
#include "../headers/utils.h"

vi bubble_sort(vi arr) {
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

	return vi {comparisons, swaps};
}

vi insertion_sort(vi arr) {
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

	return vi {comparisons, swaps};
}

vi selection_sort(vi arr) {
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

	return vi {comparisons, swaps};
}

ll count_sort(vi arr) {
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

	return min_max[1] - min_max[0] + 1;
}

vi quick_sort_partition(vi &arr, ll low, ll high) {
	ll swaps = 0, comparisons = 0;
	ll pivot = arr[high];

	ll j = low-1;
	loop(i, low, high) {
		if(pivot >= arr[i]) {
			swap(arr[++j], arr[i]);
			++swaps;
		}
		++comparisons;
	}

	swap(arr[j+1], arr[high]);
	vi v(3);
	v[0] = j+1;
	v[1] = swaps;
	v[2] = comparisons;

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

vi heapify(vi &arr, ll index, ll stop) {
	ll left_index = 2*index + 1;
	ll right_index = 2*index + 2;

	if(left_index > stop) {
		return {0, 0};
	}

	ll max_index;
	
	if(right_index <= stop and arr[left_index] > arr[right_index]) {
		max_index = left_index;
	} else {
		max_index = right_index;
	}

	if(arr[index] < arr[max_index]) {
		swap(arr[index], arr[max_index]);
		auto last_details = heapify(arr, max_index, stop);
		return {1 + last_details[0] , 1 + last_details[1]};
	}

	return {0, 1};
}

vi heap_sort(vi arr) {

	// Heapify array elements to make max heap
	ll start = arr.size() / 2 - 1;

	ll comparisons = 0, swaps = 0;
	while(start >= 0) {
		auto details = heapify(arr, start, arr.size() - 1);
		swaps += details[0];
		comparisons += details[1];
		--start;
	}

	// delete max element to make output array in sorted format
	looprev(i, arr.size() - 1, 1) {
		swap(arr[0], arr[i]);
		++swaps;

		auto details = heapify(arr, 0, i - 1);
		swaps += details[0];
		comparisons += details[1];
	}

	return {swaps, comparisons};
}

ll bucket_sort(vi arr) {
	auto min_max = min_max_in_arr(arr);

	vvi buckets(min_max[1] / BUCKET_SIZE + 1);

	for(auto i : arr) {
		buckets[i/BUCKET_SIZE].pb(i);
	}

	ll j = 1;
	for(auto & i : buckets) {
		sort(all(i));
		cout << "Bucket " << j << " ";
	  	print_data(i);
		++j;
	}

	cout << endl << "Array after sorting: " << endl;
	for(auto i : buckets) {
		for(auto j: i) {
			cout << j << " ";
		}
	}

	cout << endl;
	return min_max[1] / BUCKET_SIZE + 1;
}

void make_buckets(vi & arr, ll exp) {
	vvi buckets(10);

	for(auto i: arr) {
		ll temp = i;
		temp /= exp;
		buckets[temp % 10].pb(i);
	}

	ll k = 0;
	for(auto i: buckets) {
		for(auto j: i) {
			arr[k++] = j;
		}
	}
}

void radix_sort(vi arr) {
	auto min_max = min_max_in_arr(arr);

	ll j = 1;
	for(ll i = 1; min_max[1] / i > 0; i *= 10) {
		cout << "Pass " << j << " ";
		make_buckets(arr, i);
		print_data(arr);
		cout << endl;
		++j;
	}
}