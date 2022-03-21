

char * freqAlphabets(char * s){
    char* new = malloc((strlen(s)+1) * sizeof(char));
    int idx=0;
    
    for(int i=0; i<strlen(s); i++){
        if(s[i]>'2')
            new[idx++] = (s[i]+'a'-'1');
        else{
            if(i<strlen(s)-2){
                if(s[i+2]!='#')
                    new[idx++] = s[i]+'a'-'1';
                else{
                    new[idx++] = (((s[i]-'0')*10) + s[i+1]-'1' + 'a');
                    i+=2;
                }
            } else
                new[idx++] = s[i]+'a'-'1';
        }
    }
    
    new[idx] = '\0';
    
    return new;
}


=============================================================================


char * freqAlphabets(char * s){
    char* new = malloc((strlen(s)+1) * sizeof(char));
    int idx=0;
    
    for(int i=0; i<strlen(s); i++){
        if(i+2<strlen(s) && s[i+2]=='#'){
            new[idx++] = (((s[i]-'0')*10) + s[i+1]-'1' + 'a');
            i+=2; 
        } else                       
            new[idx++] = (s[i]+'a'-'1'); 
    }
    
    new[idx] = '\0';
    
    return new;
}