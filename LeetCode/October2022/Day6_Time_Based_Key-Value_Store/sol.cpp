class TimeMap {
public:
    TimeMap() {
    }
    map<pair<string,int>,string> a ;
    void set(string key, string value, int timestamp) {
        a[{key,timestamp}] =  value ;
    }
    
    string get(string key, int timestamp) {
        string b = "" ;
        for(int i=timestamp;i>=1;i--)
        {
            string c = a[{key,i}] ;
            if(c.length() > 0)
                return c;
        }
        return b;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// https://leetcode.com/problems/time-based-key-value-store/
