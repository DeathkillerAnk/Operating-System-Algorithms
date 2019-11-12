#include <bits/stdc++.h> 
using namespace std; 


// C++ program to demonstrate 
// SCAN Disk Scheduling algorithm 

int size = 8; 
int disk_size = 200; 

void LOOK(int arr[], int head, string direction) 
{ 
	int seek_count = 0; 
	int distance, cur_track; 
	vector<int> left, right; 
	vector<int> seek_sequence; 

	// appending values which are 
	// currently at left and right 
	// direction from the head. 
	for (int i = 0; i < size; i++) { 
		if (arr[i] < head) 
			left.push_back(arr[i]); 
		if (arr[i] > head) 
			right.push_back(arr[i]); 
	} 

	// sorting left and right vectors 
	// for servicing tracks in the 
	// correct sequence. 
	std::sort(left.begin(), left.end()); 
	std::sort(right.begin(), right.end()); 

	// run the while loop two times. 
	// one by one scanning right 
	// and left side of the head 
	int run = 2; 
	while (run--) { 
		if (direction == "left") { 
			for (int i = left.size() - 1; i >= 0; i--) { 
				cur_track = left[i]; 

				// appending current track to seek sequence 
				seek_sequence.push_back(cur_track); 

				// calculate absolute distance 
				distance = abs(cur_track - head); 

				// increase the total count 
				seek_count += distance; 

				// accessed track is now the new head 
				head = cur_track; 
			} 
			// reversing the direction 
			direction = "right"; 
		} 
		else if (direction == "right") { 
			for (int i = 0; i < right.size(); i++) { 
				cur_track = right[i]; 
				// appending current track to seek sequence 
				seek_sequence.push_back(cur_track); 

				// calculate absolute distance 
				distance = abs(cur_track - head); 

				// increase the total count 
				seek_count += distance; 

				// accessed track is now new head 
				head = cur_track; 
			} 
			// reversing the direction 
			direction = "left"; 
		} 
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

	// request array 
	int arr[size] = { 176, 79, 34, 60, 
					92, 11, 41, 114 }; 
	int head = 50; 
	string direction = "right"; 

	cout << "Initial position of head: " 
		<< head << endl; 

	LOOK(arr, head, direction); 

	return 0; 
} 
