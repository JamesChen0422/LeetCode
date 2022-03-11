

bool areAlmostEqual(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    if(len1 != len2)
        return false;
    
    char* alph = calloc(26, sizeof(char));
    int cnt=0;
    
    for(int i=0; i<len1; i++){
        if(s1[i] != s2[i]){
            if(cnt>1)
                return false;
            else
                cnt++;
            
            alph[s1[i]-'a']++;
            alph[s2[i]-'a']--;
        }
    }
    
    for(int i=0; i<26; i++){
        if(alph[i]!=0)
            return false;
    }
    
    return true;
}