
//Time Limit Exceed 

typedef struct {
    int cnt;
    char** words;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary* obj = malloc(sizeof(WordDictionary));
    obj->cnt = 0;
    obj->words = malloc(50001 * sizeof(char*));
    
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    obj->words[obj->cnt] = malloc((strlen(word)+1) * sizeof(char));
    strcpy(obj->words[obj->cnt], word);
    obj->cnt++;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    for(int i=0; i<obj->cnt; i++){
        if(strlen(obj->words[i]) != strlen(word))
            continue;
        if(!(strcmp(word, obj->words[i])))
            return true;
        for(int j=0; j<strlen(word); j++){
            if(word[j]=='.' || obj->words[i][j]==word[j]){
                if(j == (strlen(word)-1))    
                    return true;
                else
                    continue;
            }
            else 
                break;
        }
    }
    
    return false;
}

void wordDictionaryFree(WordDictionary* obj) {
    for(int i=0; i<obj->cnt; i++)
        free(obj->words[i]);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/