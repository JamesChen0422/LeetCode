

#define swap(x, y) int tmp = x; x = y; y = tmp;

void reverseString(char* s, int sSize){
    int head=0, tail = sSize-1;
    
    while(head<tail){
        swap(s[head], s[tail]);
        head++, tail--;   
    }
}