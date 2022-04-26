#include "SelectionSort.h"

SelectionSort::SelectionSort() {

}

SelectionSort::SelectionSort(int nn) {
    n = nn;
    arr = new int[n];
}

SelectionSort::~SelectionSort() {

}

void SelectionSort::Sorted() {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}