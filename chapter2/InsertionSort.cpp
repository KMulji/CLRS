#include <iostream>
#include <vector>

using std::vector;


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
    vector<int> nums = {5,2,4,6,1,3};
    InsertionSort(nums);
    DisplayVector(nums);
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

 
 
*/