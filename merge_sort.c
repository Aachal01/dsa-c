#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int  merge(int nums1[], int  nums2[], int result[], int An, int Bn){

  int p1 = 0; //pointing towards array 1
  int p2 = 0; //pointing towards array 2
    
    while(p1 < nums1.size() && p2 < nums2.size()){
        if(nums1[p1] < nums2[p2]){
            result(counter++) = nums1[p1];
            p1++;
        }
        else if(nums1[p1] > nums2[p2]){
            result(counter++) = nums2[p2];
            p2++;
        }
    }
    
    
    while(p1 < nums1.size()){
        result(counter++) = nums1[p1];
        p1++;
    }
    while(p2 < nums2.size()){
        result(counter++) = nums2[p2];
        p2++;
    }
    
}

int  merge_sort(int arr[]){
  
  int N = arr.size();
  int mid = N/2;
  //divide the array in two halfs - left half and right half
  int  left_half(arr.begin(), arr.begin()+mid);
  int  right_half(arr.begin()+mid, arr.end());

  //base condition
  if(N == 1) return arr;
  //sort left half
  int  sorted_left = merge_sort(left_half);
  //sort right half
  int  sorted_right = merge_sort(right_half);
  //merge left and right half
  int  sorted_arr = merge(sorted_left, sorted_right);
  return sorted_arr;  
}

int main() {
  int  A = {100, 20, 50, 1, 15, 69};
  int  sorted_A = merge_sort(A);
  for(int num: sorted_A){
    cout << num << " ";
  }
  return 0;
}