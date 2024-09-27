class MyCalendarTwo {
public:
vector<pair<int,int>> dates;
vector<pair<int,int>> overlaps;
    MyCalendarTwo() {
        this->dates = {};
        this->overlaps={};
    }
    
    bool book(int start, int end) {
        // returns false if it lies b/w any overlappings : 
        for(auto date : overlaps){
            if(doesOverlap(date.first,date.second,start,end)){return false;}
        }     

        // now, it means no three booking is there : 
        // now, add for double booking : 
        for(auto date : dates){
            if(doesOverlap(date.first,date.second,start,end)){
                overlaps.push_back(getOverlap(date.first,date.second,start,end));
            }
        }

        // now add the dates to our dates : 
        dates.push_back({start,end});
        return true;
    }

    private : 
    bool doesOverlap(int s1, int e1, int s2, int e2){
        return max(s1,s2)<min(e1,e2);
    }

    pair<int,int> getOverlap(int s1, int e1, int s2, int e2){
        return {max(s1,s2),min(e1,e2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */