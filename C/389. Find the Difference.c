

char findTheDifference(char * s, char * t){
    char* alph = calloc(26, sizeof(char));
    char res;
    int len = strlen(s);
    for(int i=0; i<len; i++){
        alph[s[i]-'a']--, alph[t[i]-'a']++;
    }
    alph[t[len]-'a']++;
    for(int i=0; i<26; i++){
        if(alph[i]>0)
            res=i+'a';
    }
    return res;
}


========================================================


char findTheDifference(char * s, char * t){
    char res=0;
    int len = strlen(s);
    
    for(int i=0; i<len; i++){
        res ^= s[i]^t[i];
    }
    
    res ^= t[len];
    
    return res;
}


========================================================


char findTheDifference(char* s, char* t) {
    int sum=0;
    int i=0;
    while(s[i]!='\0') {
        sum+=t[i]-s[i];
        i++;
    }
    return sum + t[i];
}