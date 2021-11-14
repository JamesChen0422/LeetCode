
#define SWAP(x,y) {char temp=x; x=y; y=temp;}
char* reverse(char *s, int len){    
    int head=0, tail=len-1;
    
    while(head<tail){
        SWAP(s[head], s[tail]);
        head++, tail--;
    }
    
    return s;
}

bool isPalindrome(char * s){
    int tmp=0;
    char *new = malloc(strlen(s) * sizeof(char));
    char *inv = malloc(strlen(s) * sizeof(char));
    
    for(int i=0; i<strlen(s); i++){
        if(s[i]>='a' && s[i]<='z'){
            new[tmp] = s[i];
            tmp++;
        } else if(s[i]>='A' && s[i]<='Z'){
            new[tmp] = s[i]+32;
            tmp++;
        } else if(s[i]>='0' && s[i]<='9'){
            new[tmp] = s[i];
            tmp++;
        }
    }
    
    memcpy(inv, new, strlen(s));
    
    inv = reverse(inv, tmp);
    
    for(int i=0; i<strlen(s); i++){
        if(new[i]!=inv[i])
            return false;
    }
    return true;
}