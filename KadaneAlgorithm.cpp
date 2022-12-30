int kadaneAlgo(vector<int> vec){
    int maxSum = vec[0];
    int sum = 0;
    for(auto itr:vec){
        sum+=itr;
        maxSum = max(maxSum,sum);
        if(sum<0) sum = 0;
    }
    return maxSum;
}
