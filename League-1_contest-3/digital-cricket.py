n = int(input())
lis = list(map(int,input().split()))
max_score = 0;
index = -1;
(striker, non_striker,dict) = (1,2,{})
for i in range(1,12):
    dict[i] = 0;
for i in lis:
    index+=1;
    if(i == 0 or i == -1):
            max_score = max(max_score,dict[striker]);
            striker = max(striker,non_striker)+1;
    elif(i == 1 or i == 3):
         dict[striker]+=i;
         (striker,non_striker) = (non_striker,striker)
    else:
         dict[striker]+=i;
    if((index+1)%6 == 0):
         (striker,non_striker) = (non_striker,striker)
max_score = max(max_score, max(dict[striker], dict[non_striker]));
print(max_score)
min_index = 1000000
top_scorer = 0;
for key, value in dict.items():
    if(value == max_score):
        if(key < min_index):
            top_scorer = key;
            min_index = key;
print(top_scorer,striker)

       
    
    
        
