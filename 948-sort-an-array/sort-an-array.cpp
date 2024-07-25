class Solution {
public:
void merge(vector<int> &nums, int s, int mid, int e){
    int n1 = mid-s+1;
    int n2 = e-mid;
    vector<int> left(n1), right(n2);

    for(int i =0; i<n1; i++){
        left[i] = nums[s+i];
    }

    for(int i =0; i<n2; i++){
        right[i] = nums[mid+1+i];
    }

    int p1=0, p2=0, k = s;
    while(p1<n1 && p2<n2){
        if(left[p1] <= right[p2]){
            nums[k] = left[p1++];
        }
        else{
            nums[k] = right[p2++];
        }
        k++ ;
    }

    while(p1<n1) nums[k++] = left[p1++];
    while(p2<n2) nums[k++] = right[p2++];
}

void merge_sort(vector<int> &nums, int s, int e){
    if(s>=e) return;
    int mid = s + (e-s)/2;
    merge_sort(nums,s,mid);
    merge_sort(nums,mid+1,e);
    merge(nums,s,mid,e);
}


    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};