

char * toLowerCase(char * s){
    for(int i=0; i<strlen(s); i++){
        if(s[i] >= 'A' && s[i]<= 'Z')
            s[i] += 32;
    }
    
    return s;
}