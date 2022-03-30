bool cmpFunc (char* a, char* b, int* order_map) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    for(int i = 0; i < len_a && i < len_b; i++){
        if(order_map[a[i]-'a'] < order_map[b[i]-'a']) 
            return true;
        else if(order_map[a[i]-'a'] > order_map[b[i]-'a']) 
            return false;
    }
    
    return (len_a <= len_b);
}

bool isAlienSorted(char** words, int wordsSize, char* order) {
    int order_map[26] = {0};
    for(int i = 0; i < 26; i++){
        order_map[order[i]-'a'] = i;
    } 
    
    for(int i = 0; i < wordsSize-1; i++){
        if(!cmpFunc(words[i], words[i+1], order_map)) 
            return false;
    }
    
    return true;
}