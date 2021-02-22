// K’th Smallest/Largest Element in Unsorted Array

#include <bits/stdc++.h>
using namespace std;
 
int findKthSmallest(vector<int> const &v, int k)
{
    
    priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);
 
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
 
    return pq.top();
}

int FindKthLargest(vector<int> const &A, int k)
{
    priority_queue<int, vector<int>, greater<>> pq(A.begin(), A.begin() + k);
 
    for (int i = k; i < A.size(); i++)
    {
        if (A[i] > pq.top())
        {
            pq.pop();
            pq.push(A[i]);
        }
    }
 
    return pq.top();
}

 
int main()
{
    vector<int> arr[] = { 12, 3, 5, 7, 19 };
    int k = 2;
    cout << "K'th smallest element is " << findKthSmallest(arr, k);
    cout << "K'th largest element is " << FindKthLargest(arr,k);
    return 0;
}
