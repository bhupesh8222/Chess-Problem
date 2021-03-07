#include <bits/stdc++.h> 
using namespace std;

int mostFrequent(vector<int> arr) 
{ 
    // find the max frequency using linear traversal 
    int max_count = 1, index, curr_count = 1; 
    for (int i = 1; i < arr.size(); i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                index=i-1;
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        //res = arr[arr.size()- 1]; 
        index=arr.size()- 1;
    } 
  
    return index; 
} 

int getPowerCouple2021(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    
    vector<int> resultArray(friends_weight.size());
    int count =1,i;
    resultArray[0]=count;
    for(int i=1;i<friends_weight.size();i++)
    {
        if( friends_from[i]==friends_from[i-1] && friends_to[i]==friends_to[i-1])
            resultArray[i]=count;
        else
        {
            count++;
             resultArray[i]=count;
        }
    }
    int index;
    int result = mostFrequent(resultArray);
    return friends_from[index]*friends_to[index];
    
}

int main()
{
	int friends_nodes=4,friends_edges= 4;
	vector<int> friends_from{1, 1, 2, 2};
	vector<int> friends_to{3, 3, 4, 4};
	vector<int> friends_weight{1, 2, 1, 2};
	cout<<getPowerCouple2021(friends_nodes,friends_edges,friends_from,friends_to,friends_weight);
}





