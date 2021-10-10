class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int minr = 0;
        int maxr = m-1;
        int minc=0;
        int maxc=n-1;
        int num=n*m;
        int count=0;
        while(count < num) {
            for(int j = minc; j <= maxc && count < num; j++) {
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;
            
            for(int i = minr; i <= maxr && count < num; i++) {
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            
            
            
             for(int j = maxc; j >= minc && count < num; j--) {
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;
            
            for(int i = maxr; i >= minr && count < num; i--) {
                    v.push_back(matrix[i][minc]);
                    count++;
            }
           
            minc++;
        }
        
        
        return v;
    }
};