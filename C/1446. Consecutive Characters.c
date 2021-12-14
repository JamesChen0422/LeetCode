

int maxPower(char * s){
    int max=0, tmp=1;
    for(int i=1; i<strlen(s); i++){
        if(s[i]==s[i-1])
            tmp++;
        else{
            max = tmp>max ? tmp:max;
            tmp=1;
        }            
    }
    return tmp>max ? tmp:max; 
}