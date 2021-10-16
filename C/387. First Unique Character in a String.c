

int firstUniqChar(char * s){
    int* character = calloc(26, sizeof(int));
       
    for(int i=0; i<strlen(s); i++)
        character[s[i]-'a']++;
    
    for(int i=0; i<strlen(s); i++){
        if( character[s[i]-'a'] == 1)
            return i;
    }
    
    return -1;
}