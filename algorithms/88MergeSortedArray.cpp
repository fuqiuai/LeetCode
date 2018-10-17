class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //用双指针
        int a=0,b=0;
        while(a<m && b<n){
            if (nums1[a]<nums2[b]){
                a++;
            }
            else{
                nums1.insert(nums1.begin()+a,nums2[b]);
                a++;m++;
                b++;
            }
        }
        if (a==m){
            for (int i=b;i<n;i++){
                nums1.insert(nums1.begin()+a,nums2[i]);
                a++;m++;
            }            
        }
        nums1.resize(m);
    }
};
