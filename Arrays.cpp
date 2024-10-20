#include <iostream>

/* 
    Write a function to reverse an array in place. 
    That is, modify the input array to obtain the
    answer.

    Use the following function signature: 
    void reverseArray(int arr[], int size)
*/
void reverseArray(int arr[], int size);


/*
    Modify a fixed-sized array (in place) so that 
    every i-th item, where i%2 == 0, is deleted.
    
*/
int main() {
    int arr[] = {10, 20, 30, 40, 50, 15};
    int len = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, len);
    for(int i = 0; i < len; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}

void reverseArray(int arr[], int size) {
    int temp;
    int right_index = size-1;
    for(int left_index = 0; left_index < right_index; left_index++){
        temp = arr[left_index];
        arr[left_index] = arr[right_index];
        arr[right_index] = temp;
        right_index--;
    }
}
