#include <bits/stdc++.h>
using namespace std;
void swap(int arr1[], int arr2[], int min_a, int max_b)
{
    int temp = arr1[min_a];
    arr1[min_a] = arr2[max_b];
    arr2[max_b] = temp;
}
int main() {
	    int n,m,count = 0;
	    cin>>n>>m;
	    int arr1[n],arr2[m], sum_a = 0, sum_b = 0;
	    for(int i = 0; i<n; i++)
	    {
	        cin>>arr1[i];
	        sum_a+= arr1[i];
	    }
	    for(int i = 0; i<m; i++)
	    {
	        cin>>arr2[i];
	        sum_b+= arr2[i];
	    }
	    while(sum_a<=sum_b)
	    {
	        int min = INT_MAX, max = INT_MIN, min_a = -1, max_b = -1;
	        for(int i = 0; i<n; i++)
	        {
	            if(arr1[i] < min)
	            {
	                min = arr1[i];
	                min_a = i;
	            }
	        }
	        for(int i = 0; i<m; i++)
	        {
	            if(arr2[i] > max)
	            {
	                max = arr2[i];
	                max_b = i;
	            }
	        }
	        if(min>=max)
	        {
	            count = -1;
	            break;
	        }
	        swap(arr1, arr2, min_a,max_b);
	        count++;
	        sum_a-=min;
	        sum_a+=max;
	        sum_b-=max;
	        sum_b+=min;
	        
	    }
	return 0;
}
