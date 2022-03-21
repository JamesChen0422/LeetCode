

char * mergeAlternately(char * word1, char * word2){
    int len = strlen(word1) + strlen(word2);
    char* new = malloc(201 * sizeof(char));
    
    char* _short = strlen(word1)<strlen(word2) ? word1:word2;
    char* _long = strlen(word1)>strlen(word2) ? word1:word2;
    int idx = 0;
    
    for(int i=0; i<strlen(_long); i++){
        if(i<strlen(_short)){
            new[idx++] = word1[i];
            new[idx++] = word2[i];
        } else {
            new[idx++] = _long[i];
        }
    }
    
    new[idx] = '\0';
    
    return new;
}

========================================================================


char * mergeAlternately(char * word1, char * word2){
    int len1=strlen(word1);
    int len2=strlen(word2);    
    char* ans = malloc(sizeof(char)*(len1+len2+1));
    int idx=0;

    for(int i=0,j=0;i<len1||j<len2;i++,j++){
        if(i<len1){
            ans[idx] = word1[i];
            idx++;
        }
        if(j<len2){
            ans[idx] = word2[j];
            idx++;
        }
    }
    
    ans[idx]='\0';

    return ans;
}

