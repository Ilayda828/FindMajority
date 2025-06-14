#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_COUNT 4

// Merge function used in Merge Sort to merge two sorted arrays into one
void Merge(int B[], int p, int C[], int q, int A[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) A[k++] = B[i++];
        else A[k++] = C[j++];
    }
    while (i < p) A[k++] = B[i++]; // Copy remaining elements from B
    while (j < q) A[k++] = C[j++];  // Copy remaining elements from C
}

// Recursive Merge Sort function
void MergeSort(int A[], int n) {
    if (n > 1) {
        int mid = n / 2;
        // Create two temporary arrays
        int* B = malloc(mid * sizeof(int));
        int* C = malloc((n - mid) * sizeof(int));

        // Copy data to subarrays B and C
        for (int i = 0; i < mid; i++) B[i] = A[i];
        for (int i = mid; i < n; i++) C[i - mid] = A[i];

        // Recursive sort of subarrays
        MergeSort(B, mid);
        MergeSort(C, n - mid);

        // Merge sorted subarrays into A
        Merge(B, mid, C, n - mid, A);

        // Free dynamically allocated memory
        free(B);
        free(C);
    }
}

// Finds the majority element in a sorted array (if exists)
int findMajority(int arr[], int n) {
    int current = arr[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == current) count++;
        else {
            current = arr[i];
            count = 1;
        }
        if (count > n / 2) return current;  // Majority found
    }
    return -1; // No majority element
}


// Sorted array with majority element
void generate_sorted_majority(int arr[], int n) {
    int i;
    for (i = 0; i < n / 2 + 1; i++) arr[i] = 1;
    for (; i < n; i++) arr[i] = i;
}

// Sorted array with median majority element
void generate_sorted_centered_majority(int* arr, int n) {
    int i=0, k=0;
    for(; i<n/4; i++)
        arr[i] = ++k;

    k++;

    for(; i< 3*n/4 + 1; i++)
        arr[i] = k;

    for(; i<n; i++)
        arr[i] = ++k;
}

// Sorted array with no majority element
void generate_sorted_no_majority(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i+1;
}

// Reverse sorted array with majority element
void generate_reverse_sorted_majority(int arr[], int n) {
    int i;
    for (i = 0; i < n / 2 + 1; i++) arr[i] = 1;
    for (; i < n; i++) arr[i] = i;
    // Reverse the array
    for (int j = 0; j < n / 2; j++) {
        int tmp = arr[j];
        arr[j] = arr[n - j - 1];
        arr[n - j - 1] = tmp;
    }
}

// Reverse sorted array with median majority element
void generate_reverse_sorted_centered_majority(int* arr, int n) {
    int i=0, k=0;
    for(; i<n/4; i++)
        arr[i] = ++k;

    k++;

    for(; i< 3*n/4 + 1; i++)
        arr[i] = k;

    for(; i<n; i++)
        arr[i] = ++k;

    for (int j = 0; j < n / 2; j++) {
        int tmp = arr[j];
        arr[j] = arr[n - j - 1];
        arr[n - j - 1] = tmp;
    }

}

// Reverse sorted array with no majority element
void generate_reverse_sorted_no_majority(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i+1;
    // Reverse the array
    for (int j = 0; j < n / 2; j++) {
        int tmp = arr[j];
        arr[j] = arr[n - j - 1];
        arr[n - j - 1] = tmp;
    }
}

// Random array with majority element
void generate_random_majority(int arr[], int n) {
    int majority = 1;
    int majority_count = n / 2 + 1;
    for (int i = 0; i < majority_count; i++) arr[i] = majority;
    for (int i = majority_count; i < n; i++) arr[i] = rand() % 100 + 100;
    // Shuffle the array
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void generate_random_centered_majority(int* arr, int n) {
    int i=0, k=0;
    for(; i<n/4; i++)
        arr[i] = ++k;

    k++;

    for(; i< 3*n/4 + 1; i++)
        arr[i] = k;

    for(; i<n; i++)
        arr[i] = ++k;

    //Shuffle
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// Random array with no majority element
void generate_random_no_majority(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000 + i;
    // Shuffle the array
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// Repeating elements with equal frequency, no majority
void generate_equal_repeats(int arr[], int n) {
    int values = 10;
    for (int i = 0; i < n; i++) {
        arr[i] = (i % values) + 1;
    }
    // Shuffle the array
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// All elements in the array are the same
void generate_all_same(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = 10;
}

// Helper function to print the array
void printArray(int* arr, int n) {
    printf("Input: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Run a series of tests for a specific input generator
void run_tests(void (*generator)(int*, int), const char* label) {
    double total_time = 0.0;
    int sizes[TEST_COUNT] = {1250, 2500, 3750, 5000}; // Array sizes to test

    printf("\n==== %s ====\n", label);

    for (int t = 0; t < TEST_COUNT; t++) {
        int n = sizes[t];
        int* arr = malloc(n * sizeof(int));
        generator(arr, n);

        printf("Test %d (size = %d):\n", t + 1, n);
        printArray(arr, n);

        // Measure execution time
        clock_t start = clock();
        MergeSort(arr, n);
        int majority = findMajority(arr, n);
        clock_t end = clock();

        double time_taken = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        total_time += time_taken;

        printf("Majority: %d\n", majority);
        printf("Execution time: %.20f ms\n\n", time_taken);

        free(arr);
    }

    printf("Average time for %s: %.20f ms\n", label, total_time / TEST_COUNT);
}

// Main function to run all test cases
int main() {
    srand(time(NULL)); // Seed random number generator

    run_tests(generate_sorted_majority, "Sorted - Majority Exists And The Smallest Value(Best Case)");
    run_tests(generate_sorted_centered_majority, "Sorted - Majority Exists And The Median element");
    run_tests(generate_sorted_no_majority, "Sorted - No Majority");
    run_tests(generate_reverse_sorted_majority, "Reversed - Majority Exists And The Smallest Value");
    run_tests(generate_reverse_sorted_centered_majority, "Reversed - Majority Exists And The Median element");
    run_tests(generate_reverse_sorted_no_majority, "Reversed - No Majority (Worst Case)");
    run_tests(generate_random_majority, "Random - Majority Exists And The Smallest Value");
    run_tests(generate_random_centered_majority, "Random - Majority Exists and The Middle Element (Median)");
    run_tests(generate_random_no_majority, "Random - No Majority");
    run_tests(generate_equal_repeats, "Random - Equal Repeats - No Majority");
    run_tests(generate_all_same, "All Elements Same");


    return 0;
}