//Time limit Exceeded
 
int strStr(char * haystack, char * needle){
    if(!(strlen(needle)))
        return 0;
    if(!haystack || strlen(needle) > strlen(haystack)) 
        return -1;
    
    for(int i=0; i<strlen(haystack); i++){
        int index=i;
        int j=0;
        while(haystack[index]== needle[j]){          
           if(j == strlen(needle)-1){
                return i;   
           }
           index++; j++;
       }
    }
              
    return -1;
}


===============================================================


int strStr(char* haystack, char* needle) {
    int needleLength = strlen(needle) + 1;
    int hayStackLength = strlen(haystack) + 1;
    int hayStackOriginalLength = hayStackLength;
    if (needleLength == 1) {
        return 0;
    }
    for (int i = 0; i < hayStackOriginalLength; i++, hayStackLength--) {
       if (needleLength > hayStackLength) {
            return -1;
        }
        for (int j = i, needleIndex = 0; j < i + needleLength; j++, needleIndex++) {
            if (needleIndex == needleLength - 1) {
                return i;
            }
            if (needle[needleIndex] != haystack[j]) {
                break;
            }
        }
    }
    
    return -1;
}
