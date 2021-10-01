class Solution {
public:
    string getPermutation(int n, int k) {
        // int ar[n];
        // string result="";
        // for(int i=0;i<n;i++)
        //     ar[i]=i+1;
        // for(int i=0;i<k-1;i++)
        //     next_permutation(ar,ar+n);
        // for(int i=0;i<n;i++)
        //     result+=to_string(ar[i]);
        // return result;
        int fac=1;
        vector<int> values;
        string result="";
        for(int i=1;i<=n;i++)
        {
            fac=fac*i;
            values.push_back(i);
        }
        k--;
        fac=fac/n;
        while(true)
        {
            n--;
            result+=to_string(values[k/fac]);
            values.erase(values.begin()+k/fac);
            if(values.size()==0)
                break;
            k=k%fac;
            fac=fac/n;
        }
        return result;
    }
};