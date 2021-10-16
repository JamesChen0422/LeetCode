

bool canConstruct(char * ransomNote, char * magazine){
    int cnt=0;
    for(int i=0; i<strlen(ransomNote); i++){
        for(int j=0; j<strlen(magazine); j++){
            if(ransomNote[i]==magazine[j]){
                magazine[j]=' ';
                cnt++;
                break;
            }
        }
    }
    return cnt==strlen(ransomNote);
}


======================================================



bool canConstruct(char * ransomNote, char * magazine){
    int* character = calloc(26, sizeof(int));
    int i;
    
    for(int i=0; i<strlen(magazine); i++)
        character[magazine[i]-'a']++;
    
    for(int i=0; i<strlen(ransomNote); i++){
        character[ransomNote[i]-'a']--;
        if(character[ransomNote[i]-'a']<0)
            return false;
    }
    
    return true;
}