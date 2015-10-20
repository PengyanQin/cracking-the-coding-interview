//
//  11_0.cpp
//  
//
//  Created by Pengyan Qin on 7/13/15.
//
//

#include <iostream>
#include <utility>  // for swap()
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
// comparison sorting algorithm cannot perform better than O(nlogn)
//
///////////////////////////////////////////////////////////////////////////////////
// Bubble sort: compare adjacent pairs, the largest is pop
// time complexity: O(n^2)
void bubble_sort(int A[], int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n-1-i; ++j)
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
}
///////////////////////////////////////////////////////////////////////////////////
// Selection sort: Find the smallest and swap with first position
// take advantage of index
// time complexity: O(n^2)
void selection_sort(int A[], int n){
    for(int i = 0; i < n; ++i){
        int min = i;
        for(int j = i + 1; j < n ; ++j){
            if(A[j] < A[min])
                min = j;
        }
        swap(A[i], A[min]);
    }
    return;
}
///////////////////////////////////////////////////////////////////////////////////
// Insertion sort: consider one element at a time, insert into proper position
// time complexity; O(n^2)
// notice that the left part is sorted, A[0] through A[i-1] is sorted, insert A[i] in left proper position
// then A[0] through is A[i] is sorted
void insertion_sort(int A[], int n){
    for(int i = 1; i < n; ++i){
        for(int j = i; j > 0; --j){
            if(A[j] < A[j-1])
                swap(A[j], A[j-1]);
            else
                break;
        }
    }
}

// improvement on insertion
// use move instead of swap
void insertion_sort1(int A[], int n){
    for(int i = 1; i < n; ++i){
        int v = A[i];
        int j = i;
        for(; j > 0; --j){
            if(v < A[j-1])
                A[j] = A[j-1];
            else
                break;
        }
        A[j] = v;
    }
}

// use while loop instead of for loop
void insertion_sort2(int A[], int n){
    for(int i = 1; i < n; ++i){
        int v = A[i];
        int j = i;
        while(v < A[j-1] && j > 0){
            A[j] = A[j-1];
            --j;
        }
        A[j] = v;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// bucket sort: partitioning an array into a number of buckets (for small universe)
// store the sets of items within each bucket
// distrubution sorting algorithm
// time complexity:  O(n + k) when the number int the range of 1 to k
void bucket_sort(int A[], int n, int max_elts){ // max_elts = 10
    vector<vector<int> > vec(max_elts+1); // 0,1...10. there are 11 buckets
    for(int i = 0; i < n; ++i)
        vec[A[i]].push_back(A[i]); // copy each elts into a bucket
    
    int current = 0;
    for(int i = 0; i < max_elts + 1; ++i)
        for(int j = 0; j < vec[i].size(); ++j)
            A[current++] = vec[i][j];  // copy back each elts to the output container
}

// counting sort: the optimization of bucket sort
// store the count of items per bucket, then transform to the items' (index + 1) per bucket
// integer sorting algorithm
vector<int> counting_sort(int A[], int n, int max_elts){
    vector<int> C(max_elts + 1);
    vector<int> B(n);
    for(int i = 0; i < n; ++i)
        C[A[i]]++;       // C[A[i]] store the number of elt A[i]

    for(int i = 1; i < max_elts + 1; ++i){
        C[i] += C[i - 1];   // C[A[i] - 1] store buckets address for elt A[i]
    }
    
    for(int i = 0; i < n; ++i){ // copy elts into buckets
        B[C[A[i]] - 1]= A[i];
        --C[A[i]];
    }
    return B;
}
/////////////////////////////////////////////////////////////////////////////////////////
// radix sort: a sorting algorithm for integer that grouping keys by the individual digits
// Do bucket sort/counting sort for each digit
// non-comparative sorting algorithm
// time complexity: O(kn)
int get_max(int A[], int n){
    int max_elts = A[0];
    for(int i = 1; i < n; ++i)
        if(A[i] > max_elts)
            max_elts = A[i];
    return max_elts;
}

void radix_sort(int A[], int n, int exp){
    vector<vector<int> > B(10); // 0,1,2...,9
    for(int i = 0; i < n; ++i){
        int tmp = A[i]/exp;
        int digit = tmp%10;
        B[digit].push_back(A[i]);
    }
    int current = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < B[i].size(); ++j){
            A[current++] = B[i][j];
        }
    }
    
    int max_elts = get_max(A, n);
    exp = exp*10;
    if(max_elts/exp > 0)
        radix_sort(A, n, exp);
}

/////////////////////////////////////////////////////////////////////////////////////////
// merge sort: first divide list into smallest unit, then merge adjacent sorted sublist
// divied and conquer algorithm
// time complexity: O(nlogn)
void merge(int A[], int left, int mid, int right){
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int *B = new int[right - left + 1];
    for(int i = left, j = mid + 1, k = 0; (i < left + left_size) || (j < mid + 1 + right_size) ; ){
        if((i < left + left_size) && (j < mid + 1 + right_size)){
            B[k++] = A[i] < A[j] ? A[i++]: A[j++];
        }
        else if(i < left + left_size){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    
    for(int i = 0; i < right - left + 1; ++i)
        A[left + i] = B[i];
    delete[] B;
    return;
}

void mergesort(int A[], int left, int right){
    if(left >= right)
        return;
    int mid = left + (right - left)/2;
    mergesort(A, left, mid);
    mergesort(A, mid + 1, right);
    merge(A, left, mid, right);
}


//////////////////////////////////////////////////////////////////////////////////
// quick sort: partition the array based on the pivot
// divide and conquer algorithm
// time complexity:O(nlogn)
// space complexity: O(1) additinal memory
int partition(int A[], int left, int right){
    int pivot = A[right]; // pivot is the right most elts
    int i = left;
    int j = right - 1;
    while(i < j){
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot)
            j--;
        if(i < j)
            swap(A[i], A[j]);
    }
    swap(A[i], A[right]); // move pivot to middle. must use A[right], pivot is not right
    return i; // the index of pivot
}

void quick_sort(int A[], int left, int right){
    if(left >= right)
        return;
    int pivot = partition(A, left, right);
    quick_sort(A, left, pivot - 1);
    quick_sort(A, pivot + 1, right);
}

//////////////////////////////////////////////////////////////////////////////////
// binary search for sorting array

int binary_search(int A[], int left, int right, int val){
    if(left > right)
        return -1;
    int mid = left + (right - left)/2;
    if(A[mid] == val)
        return mid;
    if(val < A[mid])
        return binary_search(A, left, mid - 1, val);
    else{
        return binary_search(A, mid + 1, right, val);
    }
}

//////////////////////////////////////////////////////////////////////////////////
int main(){
    /*
    int A[] = {2, 5, 1, 9, 3, 5}; // the range of the elts is 0 ~ 10
    int n = 6;
     */
    int B[] = {170, 45, 75, 90, 802, 2, 24, 96};
    int m = 8;
    //int max_elts = 10;
    //bubble_sort(A, n);
    //selection_sort(A, n);
    //insertion_sort(A, n);
    //insertion_sort1(A, n);
    //insertion_sort2(A, n);
    //bucket_sort(A, n, max_elts);
    //vector<int> AA = counting_sort(A, n, max_elts);
    //mergesort(A, 0, n-1);
    //quick_sort(A, 0, n-1);
    /*
    for(int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
    */
    radix_sort(B, m, 1);
    for(int i = 0; i < m; ++i)
        cout << B[i] << " ";
    cout << endl;
    //cout << binary_search(B, 0, m-1, 45) << endl;
}

