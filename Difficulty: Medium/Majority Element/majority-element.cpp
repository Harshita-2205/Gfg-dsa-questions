// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        //moore's algo
        
        int cnt =0;
        int ele;
        for(int i=0;i<arr.size();i++){
            if(cnt ==0){
                cnt = 1;
                ele = arr[i];
            }
            else if(arr[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        } 
        
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==ele){
                count++;
            }
        }
        if(count>(arr.size()/2)){
             return ele;
        }
        return -1;
        }
        
        
    
};