class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int i=0;
        int j=0;
        
        vector<int> unin;
        while(i<a.size() && j<b.size()){
            if (a[i] <= b[j]){
                if(unin.size()==0 || unin.back()!=a[i]){
                    unin.push_back(a[i]);
                }
                i++;
            }
            else{
                if(unin.size()==0 || unin.back()!=b[j]){
                    unin.push_back(b[j]);
                }
                j++;
            }
            
        }
        
        while(j<b.size()){
            if(unin.size()==0 || unin.back()!=b[j]){
                    unin.push_back(b[j]);
                }
                j++;
        }
        
        while(i<a.size()){
            if(unin.size()==0 || unin.back()!=a[i]){
                    unin.push_back(a[i]);
                }
                i++;
            
        }
        return unin;
        // return vector with correct order of elements
    }
};