#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start  + (end - start)/2;

    while (start<=end){
        if (arr[mid] == key){
            return mid;
        }
            // go to right part
        if (key > arr[mid]){
                start = mid + 1;


        }else{
            end = mid-1;
        }

        mid = start  + (end - start)/2;
    }

    return -1;
}


int main(){
    int even[6] = {2,3,4,5,6,7};
    int odd[5] = {54,65,654,73,648};


    int index = binarySearch(even, 6,6);

    cout<<"the index of 6 is "<< index<<endl;
return 0;
}
