

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==1)
        return strs[0];
        
    int len = 0, min = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i) {
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }

    for (int c = 0; c < min; c++) {
        for (int s = 1; s < strsSize; s++) {
            if(strs[0][c] == strs[s][c]){
                if (s == (strsSize - 1)){
                    len++;             
                }
            } else {
               goto end;
            }
        }
    }
end:
    
    if (len > 0) {
        char* ret = malloc(len * sizeof(int));
        strs[0][len] = '\0';
        strcpy(ret, strs[0]);
        return ret;
    }

    return "";
}