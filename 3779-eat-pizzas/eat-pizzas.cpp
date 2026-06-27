class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
    
    sort(pizzas.begin(),pizzas.end());

     int n = pizzas.size();
      //kitne day 
     int num_of_day = n/4;

     int i = 0;
     int last = n-1;
     long long gain = 0;

    //odd day
    for(int itr = 1; itr <= num_of_day ; itr += 2 )
    {
      gain += pizzas[last];
      i += 3;//3 start ke
      last--;//1 last wala
    } 

    //even day
    for(int itr = 2 ; itr <= num_of_day ; itr += 2)
    {
      gain += pizzas[last-1];
      last -= 2;//end ke 2
      i += 2; //start ke 2
    }
     return gain;
    }
};