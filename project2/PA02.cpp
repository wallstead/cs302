//  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <fstream>

int kSmall(int k, int anArray[], int first, int last);

int main(){

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val=0;		//Populate using your algorithm implementation
	int pivot;		        //Pivot position in array

	//User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value:";
	std::cin>>kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
    std::ifstream infile("data3.txt");
    
    int numbers[1000];
    int pos = 0; // counter for array
    while (infile >> numbers[pos]) {
        std::cout << pos << ": " << numbers[pos] << '\n'; // For DEBUG use only
        pos++;
    }

	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
    
    pivot = 0;
    kSmall_val = kSmall(kSmall_pos, numbers, 0, pos-1);



	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val<<std::endl;
}

int kSmall(int k, int anArray[], int first, int last) {
    int pivot = anArray[first];
    int *head = &anArray[first+1];
    int *tail = &anArray[last];
    
    int temp;
    
    while(head < tail) { // continue recursion
        
        if (*head >= pivot && *tail < pivot) { // swap immediately
            temp = *head;
            *head = *tail;
            *tail = temp;
        } else if (*head >= pivot && *tail > pivot) { //decrement tail only
            tail--;
        } else if (*head < pivot && *tail < pivot) { // increment head only
            head++;
        } else { // increment head and decrement tail
            head++;
            tail--;
        }
    }
    
    if (*tail > pivot) {
        tail--;
    }
    temp = pivot;
    anArray[first] = *tail;
    *tail = temp;
    
    int awayFromBase = tail-anArray+1;

    if (k == awayFromBase) {
        return *tail;
    } else if (k < awayFromBase) { // search left half
        return kSmall(k, anArray, first, tail-anArray-1);
    } else { // search right half
        return kSmall(k, anArray, head-anArray, last);
    }
}
