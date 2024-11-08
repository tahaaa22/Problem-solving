int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        vector<int> candyleft(n, 1); 
        vector<int> candyright(n, 1);
  
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candyleft[i] = candyleft[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candyright[i] = candyright[i + 1] + 1;
            }
        }

        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += max(candyleft[i], candyright[i]);
        }
        
        return total;
    }
