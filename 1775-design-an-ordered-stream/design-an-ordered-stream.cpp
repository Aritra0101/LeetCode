class OrderedStream {
public:
    int ptr = 1;
    string* hashMap;
    int len;


    OrderedStream(int n) {
        len = n+1;
        hashMap = new string[len];
    }
    
    vector<string> insert(int idKey, string value) {
        hashMap[idKey] = value;

        vector<string> output;

        if(ptr==idKey)
        {
            while( ptr<len && hashMap[ptr] != "" ) {
                output.push_back( hashMap[ptr] );
                ptr++;
            }
        }

        return output;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */