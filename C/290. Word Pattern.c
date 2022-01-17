/*
Memory beat 100%
*/
bool wordPattern(char * pattern, char * s){
    
    int index, patternLength = strlen(pattern), stringLength = strlen(s), count = 0, strIndex = 0, wordCount = 0;
    for(index = 0; index < stringLength; index++){
        if(s[index] == ' ')
        {
            s[index] = '\0';
            wordCount++;
        }
    }
    if(patternLength != (wordCount+1)) 
        return false;

    int charMap[26] = {0};
    char *pStringMap[26] = {NULL};
    
    for(index = 0; index < patternLength; index++){
        if(charMap[pattern[index] - 'a'] == 0){
            charMap[pattern[index] - 'a'] = 1;
            for(strIndex = 0; strIndex < 26; strIndex++){     
                if((pStringMap[strIndex] != NULL) && !strcmp(&s[count],pStringMap[strIndex]))  
                    return false;
            }
            pStringMap[pattern[index] - 'a'] = &s[count];
            count += strlen(&s[count]) + 1; 
        }
        else {
            if(!strcmp(&s[count], pStringMap[pattern[index] - 'a'])){
                count += strlen(&s[count]) + 1;
                continue;
            } else
                return false;
        }
    }
    return true;
}


===================================================================================


/*
Memory beat 100%
*/
bool wordPattern(char *pattern, char *s)
{
    int count = 0;
    char *token = NULL;
    char **dict = calloc(26, sizeof(char *));

    token = strtok(s, " ");

    for (int i = 0; i < strlen(pattern); i++) {
        if (!dict[pattern[i] - 'a']) {
            dict[pattern[i] - 'a'] = token;
        } else {
            if (strcmp(dict[pattern[i] - 'a'], token)) {
                return false;
            }
        }

        count++;
        
        if(!(token = strtok(NULL, " ")))
            break;
    }

    if(count != strlen(pattern) || token != NULL)
        return false;

    for (int i = 0; i < 26; i++) {
        if (!dict[i])
            continue;

        for (int j = i + 1; j < 26; j++) {
            if (!dict[j])
                continue;

            if (!strcmp(dict[i], dict[j]))
                return false;
        }
    }

    return true;
}
