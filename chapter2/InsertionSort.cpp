#include <iostream>
#include <vector>

using std::vector;
void InsertionSortBack(vector<int> &nums);
vector<int> BinaryAdd(vector<int> &nums1,vector<int> &nums2);
void SelectionSort(vector<int> &nums);
int BinarySearch(vector<int> &nums,int key);

void MergeSort(int *A,int n);
void MergeSortPrivate(int A[],int lo,int hi);
void Merge(int A[],int lo,int mid,int hi);

void QuickSort(vector<int> &nums);
void QuickSortHelp(vector<int> &nums,int lo,int hi);
int Partition(vector<int> &nums,int lo,int hi);

bool TwoSum(vector<int> &nums,int goal);




/****************************************************************************
    Input: A sequence of n numbers [a1,a2,...,an].


    Output: A permutation [a1',a2',...,an'] of the input sequence such that 
            a1'<=a2'<=...<=an'.


****************************************************************************/
void InsertionSort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        int key = nums[i];
        int j=i-1;

        while(j>=0 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1] =key;
    }
        
}
/**************************************************************************
     Helper: Print Vector to Console.
***************************************************************************/
void DisplayVector(vector<int> &nums)
{
    for(auto x:nums)
        std::cout<<x<<std::endl;

}

int main()
{
    // vector<int> nums1 = {1,1,1,1};//15
    // vector<int> nums2 = {1,1,1,1};//15
    // vector<int> c = BinaryAdd(nums1,nums2);

    vector<int> a = {9,4,2,6,7,3,1};
    std::cout<<TwoSum(a,11)<<std::endl;
    DisplayVector(a);
    
    return 0;
}
/********************************************************************************************
 *              Insertion Sort Loop Invariant Proof.                       *
 
 Proof that Insertion Sort algorithm is correct using loop invariants(informal proof)
 1.Initialization -> Algorithm is correct prior to first iteration of loop
 2.Maintenance -> If Algorithm is true before iteration of a loop, it remains
   true before the next iteration
 3. Termination -> The loop terminates and when it terminates the invariant gives
    us a useful property that helps show that the algoritm is correct.


    Example using Insertion Sort ->
    1.state Loop Invariant -> At the start of each iteration of the for loop of 
      lines 18-28, the subarray A[0,i-1] consists of the elements originally
      in A[0,i-1] but in sorted order.

    2. Proof for Initialization -> Prior to the first iteration of the loop, when
       i=2 the subarray A[0,i-1] consists of one element. A subarray with 1 element
       is sorted 

    3. Proof for maintenance -> The for loop works by moving values A[i-1],A[i-2],A[i-3]
       and so on by one position to the right until we find the correct position for A[i],
       and insert it. The subarray still meets the loop invariant as we increase i.

    4. Proof for termination -> Once i reaches n(size of array), the loop terminates and we
       get a subarray A[0,n-1], that consists of the original arrays elements but in sorted
       sorted order. 
***********************************************************************************************/

/*Exercise section***************************************************************************************************/

/*******************************************************************************************************************
 *                                      Exercise 2.1-1                                                  *
 Using Insertion sort algorithm, illustrate the operation of sorting an
 array initially containing the sequence [31,41,59,26,41,58].
    31, 41, 59, 26, 41 ,58.

    i=1,j=0;
    since its in order we move i forward.

    31, 41, 59, 26, 41 ,58.
    i=2,j=1,key=null
    since its in order we move i forward.

    31, 41, 59, 26, 41 ,58.
    i=3,j=2,key=null
    since j>=0 and 59>26 we set nums[j+1]=j and do j--.

     31, 41, 59, 59, 41 ,58.
     i=3,j=1 key=26;
     since 41>26 we set nums[j+1]=j and do j--;

     31,41,41,59,41,58
     i=3,j=0,key=26
     since 31>26 we set nums[j+1]=j and do j--;

     31,31,41,59,41,58
     i=3,j=-1,key=26.

     since j<0 we set nums[j+1]=key and increase i by 1

     26,31,41,59,41,58

     i=4,j=3,key=41,
     since 59>41 we set nums[j+1]=j and do j--

     26,31,41,59,59,58 

     i=4,j=2,key=41
     since the rest is not greate than key we set nums[j+1]=key and increase i by 1.

     26,31,41,41,59,58
     i=5,j=4,key=58

     since 59>58 we set nums[j+1]=j and do j--;
     26,31,41,41,59,59
     since the rest of the array is sorted we set nums[j+1]=key and terminate. returning sorted array.

     26,31,41,41,58,59
*/

/******************************************************************************************************** *
 *    Exercise 2.1-2                                                                                      *
 *     1. State loop invariant -> At each iteration of the for loop the sum = A[0],A[1],...,A[i] holds.
 *     2. Initialization proof -> At initialization the sum =0.
 *     3. Maintenance proof -> At each iteration of the loop we add A[i] to sum. Therefore at the start
 *         of each iteration the sum is always true.
 *     4. Termination -> The algorithm terminates at once all elements in the array have been summed.
 * 
*/

/************************************************************************************************************
 *            Exercise 2.1-3                                                                                *
 * 
          5,2,4,6,1,3
          key=2, i=1,j=0

          5,2,2,6,1,3
          5,4,2,6,1,3
 
 */

void InsertionSortBack(vector<int> &nums)
{
      for(int i=1;i<nums.size();i++)
    {
        int key = nums[i];
        int j=i-1;

        while(j>=0 && nums[j]<key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1] =key;
    }
}

/************************************************************************************************************* *
 * Exercise 2.1-4                                                                                            *
  
1. Loop Invariant -> At each iteration of the loop the value at nums[i] may be equal to key or not equal to key.
2. Initialization -> before we start we have not found any key.
3. Maintenance -> Before each iteration 
*/
int LinearSearch(vector<int> &nums,int key)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==key)
        {
            return i;
        }
        
    }
    return -1;
}

/******************************************************************************************************************** *
 * Exercise 2.1-5
**********************************************************************************************************************/
vector<int> BinaryAdd(vector<int> &nums1,vector<int> &nums2)
{
    vector<int> ans;
    int carry=0;
    for(int i=nums1.size()-1;i>=0;i--)
    {
        int c = (nums1[i]+nums2[i]+carry)%2;
        ans.push_back(c);

        if(nums1[i]+nums2[i]+carry>=2)
        {
            carry=1;
        }else
        {
            carry=0;
        }
    }
    ans.push_back(carry);
    return ans;
}

void SelectionSort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]<nums[i])
            {
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }
}

void MergeSort(int *A,int n)
{
    MergeSortPrivate(A,0,n-1);
}

void MergeSortPrivate(int A[],int lo,int hi)
{
    int mid;
    if(lo<hi)
    {
        mid = lo +(hi-lo)/2;
        MergeSortPrivate(A,lo,mid);
        MergeSortPrivate(A,mid+1,hi);
        Merge(A,lo,mid,hi);
        
    }

}
void Merge(int A[],int lo,int mid,int hi)
{
    int i=lo;
    int j=mid+1;
    int k=0;

    int B[hi-lo+1];

    while(i<=mid && j<=hi)
    {
        if(A[i]<=A[j])
        {
            B[k++]=A[i++];
        }else
        {
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
    {
        B[k++] = A[i];
    }
    for(;j<=hi;j++)
    {
        B[k++]=A[j];
    }

    for(int k=0;k<hi-lo+1;k++)
    {
        A[lo+k]=B[k];
    }
}

int BinarySearch(vector<int> &nums,int key)
{
    int lo=0;
    int hi=nums.size()-1;

    while(lo<=hi)
    {
        int mid = lo +(hi-lo)/2;

        if(nums[mid]==key)
        {
            return mid;
        }else if(key>nums[mid])
        {
            lo=mid+1;
        }else if(key<nums[mid])
        {
            hi=mid-1;
        }
    }
    return -1;
}

void QuickSort(vector<int> &nums)
{
    QuickSortHelp(nums,0,nums.size()-1);
}
void QuickSortHelp(vector<int> &nums,int lo,int hi)
{
    if(lo<hi)
    {
        int pivot = Partition(nums,lo,hi);
        QuickSortHelp(nums,lo,pivot-1);
        QuickSortHelp(nums,pivot+1,hi);
    }
}
int Partition(vector<int> &nums,int lo,int hi)
{
    int pivot = hi;

    int i=lo;
    int j=pivot-1;

    while(i<=j)
    {
        while(i<=j && nums[i]<nums[pivot])
        {   
            i++;
        }
        while(i<=j && nums[j]>nums[pivot])
        {
            j--;
        }
        if(i<=j)
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }

    int temp = nums[i];
    nums[i]=nums[pivot];
    nums[pivot]=temp;


    return i;
}

bool TwoSum(vector<int> &nums,int goal)
{
    QuickSort(nums);

    int i=0;
    int j=nums.size()-1;

    while(i<j)
    {
        int sum = nums[i]+nums[j];

        if(sum==goal)
        {
            return true;
        }else if(sum<goal)
        {
            i++;
        }else if(sum>goal)
        {
            j--;
        }
    }
    return false;
}