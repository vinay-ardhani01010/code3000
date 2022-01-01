#include<bits/stdc++.h>
using namespace std;
void swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int N; 
	cin>>N;
	int balls[N];
	for(int i = 0; i<N; i++)
	{
		cin>>balls[i];
	}
	int striker = 1, non_striker  = 2,max_score = INT_MIN;
	unordered_map<int,int> map;
	for(int i = 0; i<N; i++)
	{
         if((i+1)%6 == 0)
         {
         	swap(&striker,&non_striker);
         }
         if(balls[i] == 0 || balls[i] == -1)
         {
         	map[striker]+=balls[i];
         	max_score = max(max_score, map[striker]);
         	striker = max(striker, non_striker)+1;
         }
         else if(balls[i] == 4 || balls[i] == 6 || balls[i] == 2)
         {
         	map[striker]+=balls[i];
         }
         else if(balls[i] == 1 || balls[i] == 3)
         {
         	map[striker]+=1;
         	swap(&striker, &non_striker);
         }
	}
	max_score = max(max_score,max(map[striker], map[non_striker]));
	int player_pos = INT_MAX, top_scorer;
	for(auto it : map)
	{
		if(it.second == max_score)
		{
              if(it.first < player_pos)
              {
              	top_scorer = it.first;
              	player_pos = it.first;
              }
		}
	}
	cout<<top_scorer<<" "<<striker;
}