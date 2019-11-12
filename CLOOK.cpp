// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
int size = 8; 
int disk_size = 200; 

// Function to perform C-LOOK on the request 
// array starting from the given head 
void CLOOK(int arr[], int head) 
{ 
	int seek_count = 0; 
	int distance, cur_track; 
	vector<int> left, right; 
	vector<int> seek_sequence; 

	// Tracks on the left of the 
	// head will be serviced when 
	// once the head comes back 
	// to the beggining (left end) 
	for (int i = 0; i < size; i++) { 
		if (arr[i] < head) 
			left.push_back(arr[i]); 
		if (arr[i] > head) 
			right.push_back(arr[i]); 
	} 

	// Sorting left and right vectors 
	std::sort(left.begin(), left.end()); 
	std::sort(right.begin(), right.end()); 

	// First service the requests 
	// on the right side of the 
	// head 
	for (int i = 0; i < right.size(); i++) { 
		cur_track = right[i]; 

		// Appending current track to seek sequence 
		seek_sequence.push_back(cur_track); 

		// Calculate absolute distance 
		distance = abs(cur_track - head); 

		// Increase the total count 
		seek_count += distance; 

		// Accessed track is now new head 
		head = cur_track; 
	} 

	// Once reached the right end 
	// jump to the last track that 
	// is needed to be serviced in 
	// left direction 
	seek_count += abs(head - left[0]); 
	head = left[0]; 

	// Now service the requests again 
	// which are left 
	for (int i = 0; i < left.size(); i++) { 
		cur_track = left[i]; 

		// Appending current track to seek sequence 
		seek_sequence.push_back(cur_track); 

		// Calculate absolute distance 
		distance = abs(cur_track - head); 

		// Increase the total count 
		seek_count += distance; 

		// Accessed track is now the new head 
		head = cur_track; 
	} 

	cout << "Total number of seek operations = "
		<< seek_count << endl; 

	cout << "Seek Sequence is" << endl; 

	for (int i = 0; i < seek_sequence.size(); i++) { 
		cout << seek_sequence[i] << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	// Request array 
	int arr[size] = { 176, 79, 34, 60, 
					92, 11, 41, 114 }; 
	int head = 50; 

	cout << "Initial position of head: " << head << endl; 

	CLOOK(arr, head); 

	return 0; 
} 