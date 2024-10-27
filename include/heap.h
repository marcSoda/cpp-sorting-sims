#pragma once
#include "common.h"

Color getDistinctHeapColor(int index, int totalSize);
void heapify(std::vector<int>& arr, int n, int i);
void heapSort(std::vector<int>& arr);
