

bool detectCapitalUse(char * word){
    int cap=0;
    for(int i=0;i<strlen(word);i++){
        if(word[i]-'a'<0)
            cap++;
    }

    return !cap || cap == strlen(word) ||  cap==1 && isupper(word[0]);
}