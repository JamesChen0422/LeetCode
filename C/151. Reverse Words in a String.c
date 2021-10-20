#define swap(x,y) { char temp; temp=x, x=y, y=temp; }

void reverse(char* s, int start, int end){
    for(int i=0; i<=(end-start)/2; i++){
        swap(s[start+i], s[end-i]);
    }
    return;
}

char* reverseWords(char* s){
    int start = 0;
    int Word = 0;
    int len = 0;
    int index = 0;
    int wordCount = 0;
    char x;
    while(s[index]){
        if (s[index] != ' '){
            if (Word == 0){
                wordCount++;
            }
            if (start == 1 && Word == 0){
                s[len++] = ' ';
            }
            if (len != index){
                s[len++] = s[index];
            } else {
                len++;
            }
            start = 1;
            Word = 1;
        } else {
            Word = 0;
        }
        
        index++;
    }
    
    s[len] = 0;
    
    if (len <= 1 || wordCount <= 1) return s;
    
    reverse(s, 0, len - 1);
    
    index = 0;
    
    for (int i=1; i<len; i++){
        if (s[i] == ' '){
            reverse(s, index, i - 1);
            index = i + 1;
        }
    }
    
    reverse(s, index, len - 1);
    
    return s;
}