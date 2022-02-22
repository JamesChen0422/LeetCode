

int titleToNumber(char * columnTitle){
    int res = columnTitle[0]-'@';
    for(int i=1; i<strlen(columnTitle); i++){
        res *= 26;
        res += columnTitle[i]-'@';
    }
    
    return res;
}