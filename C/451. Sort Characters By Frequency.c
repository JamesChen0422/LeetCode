

char * frequencySort(char * s){
    int characters[128]={0};
    int i, out, max, temp, index=0;
    
    for(i=0; i<strlen(s); i++){
        characters[s[i]]++;
    }
again:
    out = 0, max = 0, temp = 0;
    for(i=48; i<123; i++){
        if(characters[i] > max){
            max = characters[i];
            temp = i;
            out = 1;
        }
    }
    while(characters[temp]){
        s[index++]=temp;        
        characters[temp]--;
    }
    if(out)
        goto again;
    
    return s;
}