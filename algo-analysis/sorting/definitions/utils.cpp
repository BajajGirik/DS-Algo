#include "../headers/sorting.h"
#include "../headers/utils.h"

ll get_largest_kth_element(vi arr, ll k, ll start, ll end) {
	auto par = quick_sort_partition(arr, start, end);

	if(k == par[0] + 1)
		return arr[k];

	if(k > par[0] + 1) 
		return get_largest_kth_element(arr, k - 1 - par[0], par[0] + 1, end);

	return get_largest_kth_element(arr, k, start, par[0] - 1);
}