

bool isIsomorphic(char * s, char * t){
    char *transs = calloc(128, sizeof(char));
    char *transt = calloc(128, sizeof(char));
    
    for(int i=0; i<strlen(s); i++){        
        if(!transs[s[i]] && !transt[t[i]]){
            transs[s[i]] = t[i];
            transt[t[i]] = s[i];
        } else{
            if(transs[s[i]] != t[i] || transt[t[i]] != s[i])
                return false;
        }        
    }
    
    return true;
}