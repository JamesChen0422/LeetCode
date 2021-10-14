

bool isAnagram(char * s, char * t){
    if(strlen(s) != strlen(t))
        return false;
    int* character = calloc(26, sizeof(int));
    int i;
    
    for(i=0; i<strlen(s); i++){
        character[s[i]-'a']++;
        character[t[i]-'a']--;
    }
    
    for(i=0; i<26; i++){
        if(character[i])
            return false;
    }
    
    return true;
}