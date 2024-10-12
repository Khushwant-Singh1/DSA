#include <iostream>
#include <vector>
using namespace std;


bool isPossible(vector<int> arr, int n, int m,int mid){

    int studentCount = 1;
    int pageSum =0;
    for (int i = 0; i<n; i++){
        if(pageSum +arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount >m || arr[i]>mid){
                return false;
            }pageSum = arr[i];
        }
    }return true;
}

int allocateBooks(vector<int> arr, int n ,int m){
    int s = 0;
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    while (s<=e){
        int mid = s +(e-s)/2;
        if (isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid -1;
        }else {
            s = mid +1;

        }
    }return ans;
}

int main(){
 int n, m;
    

    cout << "Enter the number of books: ";
    cin >> n;
    cout << "Enter the number of students: ";
    cin >> m;

    vector<int> arr(n);
    cout << "Enter the pages of each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    int result = allocateBooks(arr, n, m);
    if (result == -1) {
        cout << "Allocation not possible." << endl;
    } else {
        cout << "Minimum number of pages that can be allocated: " << result << endl;
    }

    return 0;
}