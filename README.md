# FindMajority
Performance comparison of 8 different algorithms solving the majority element problem in C.

This project was developed to compare the performance of different algorithms that solve the majority element problem in an array using the C programming language.

What is a Majority Element?
If there is an element that repeats more than ⌊n/2⌋ in an array, this element is called a majority element. Otherwise, the algorithm is expected to return -1.

🎯 Project Purpose
Algorithms with different time and space complexity:

To compare their performance on small and large arrays,
To observe which algorithms are more efficient in real-time studies,
To experimentally examine different ways of solving the same problem.

🔍 8 Algorithms Implemented in the Project:
Brute-force: Checks the number of repetitions of each element one by one. (O(n²))
Insertion Sort + Middle Element: Sorts the data and returns the middle element.
Merge Sort + Middle Element
Quick Sort (first element is pivot) + Middle Element
3-Way Quick Sort + Middle Element: Sorts groups of the same elements more efficiently.
Divide-and-Conquer: Finds the majority element by dividing the array.
Hash-Based Method: Counts the element frequencies with a hash table. (O(n))
Boyer-Moore Voting Algorithm: Runs in O(n) time without using memory. (Optimal)
