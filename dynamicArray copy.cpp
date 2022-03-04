/*
* Aaron Lieberman
* CS 121-7
* November 18 2019
* Assignment 1
*/

#include <iostream>
using namespace std;

void sort(int*, int);
double getAverage(int*, int);

int main() {
	// Dynamically Allocate Array Size
	int size;
	cout << "Enter # of tests: ";
	cin >> size;
	int *scores = new int[size];
	// Fill Array with Scores
	cout << "ENTER SCORES:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
	// Sort Array
	sort(scores, size);
	cout << "Sorted List: ";
	for (int i = 0; i < size; i++) {
		cout << scores[i] << ",";
	}
	cout << endl;
	// Get Average SCore
	cout << "Average: " << getAverage(scores, size) << endl;
	// Cleanup
	delete [] scores;
	return 0;
};

void sort(int* arr, int size) {
	bool sorted = true;
	for (int i = 0; i < size-1; i++) {
		if (arr[i] > arr[i+1]) {
			sorted = false;
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	if (!sorted) sort(arr, size);
}

double getAverage(int* arr, int size) {
	double sum;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum/(double)(size);
}
