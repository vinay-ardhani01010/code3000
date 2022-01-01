#include<bits/stdc++.h>
using namespace std;
bool isPossible(int mid, int A[], int N, int M)
    {
        int allocated = 1, pages = 0;
        for(int i = 0; i<N; i++)
        {
            if(A[i] > mid) return false;
            if(pages+A[i] > mid)
            {
                allocated+=1;
                pages = A[i];
            }
            else
            {
                pages+=A[i];
            }
        }
        if(allocated > M)return false;
        return true;
     }
int distributeGifts(int A[], int N, int M)
{
	    if(M > N) return -1;
        int sum = 0;
        for(int i = 0; i<N; i++)
        {
            sum+=A[i];
        }
        int i = A[0], j = sum, res = 0;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(isPossible(mid,A,N,M))
            {
                j = mid-1;
                res = mid;
            }
            else
            {
                i = mid+1;
            }
        }
        return res;
}
int main()
{
	int N,X;
	cin>>N>>X;
	int packs[N];
	for(int i = 0; i<N; i++)
	{
		cin>>packs[i];
	}
	cout<<distributeGifts(packs,N,X);
}