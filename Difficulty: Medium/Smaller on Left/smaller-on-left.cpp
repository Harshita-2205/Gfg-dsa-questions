vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    vector<int> ans(n,-1);
    set<int>set;
    set.insert(arr[0]);
    for(int i=1;i<n;i++){
        auto a=set.lower_bound(arr[i]);
        if(a!=set.begin()) a--, ans[i]=*a;
        set.insert(arr[i]);
    }
    return ans;
    
    
}