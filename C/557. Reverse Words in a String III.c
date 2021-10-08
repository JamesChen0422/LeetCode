

#define swap(x, y) int tmp = x; x = y; y = tmp;

void reverse(char* s, int head, int tail){
    
    while(head<tail){
        swap(s[head], s[tail]);
        head++, tail--;   
    }
}

char * reverseWords(char * s){
    int head=0, i=0;      
    
    while(*(s+i)){
        if(*(s+i)==' ' || *(s+i)=='\n'){
            reverse(s, head, i-1);
            head=i+1;
        }
        i++;
    }
        
    reverse(s, head, i-1);
    
    return s;
}