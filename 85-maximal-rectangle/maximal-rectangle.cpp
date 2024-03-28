 #include<stack>
 #include <vector>
 #include <limits.h>
 #include<iostream>
using namespace std;

class Solution {
public:

vector<int> nextSmall(vector<int> &heights, int n) {
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=n-1; i>=0; i--){
		int curr = heights[i];

		while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

vector<int> prevSmall(vector<int> &heights, int n){
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);

 for(int i=0; i<n; i++){
     int curr = heights[i];
     while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
     ans[i] = s.top();
     s.push(i);
   }
   return ans;
}

int largestRectangle(vector<int> &heights) {
     int n = heights.size();
vector<int> next(n);
next = nextSmall(heights,n);

vector<int> prev(n);
prev = prevSmall(heights,n);

int area = INT_MIN;
for(int i=0; i<n; i++){
	int l = heights[i];

	if(next[i] == -1) next[i] = n;

	int b = next[i] - prev[i] -1;

	int newArea = l*b;
	area = max(newArea,area);
}
return area;
}


int maximalRectangle(vector<vector<char>>& matrix) {
            int m=matrix.size();
              int n=matrix[0].size();

         if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }


        vector<int> histogram(n, 0);
        int area = 0;
   for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            area = max(area,largestRectangle(histogram));
   }
   return area;
}
};