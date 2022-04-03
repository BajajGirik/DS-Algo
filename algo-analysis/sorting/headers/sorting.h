#ifndef SORTING_H
#define SORTING_H
#define BUCKET_SIZE 100

#include "../../myheader.h"


vi bubble_sort(vi);
vi insertion_sort(vi);
vi selection_sort(vi);
ll count_sort(vi);
vi quick_sort_partition(vi &, ll, ll);
vi quick_sort(vi, ll, ll);
vi heapify(vi &, ll, ll);
vi heap_sort(vi);
ll bucket_sort(vi);
void make_buckets(vi &, ll);
void radix_sort(vi);

#endif