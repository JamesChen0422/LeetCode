#define MAX 10000

char* removeDuplicateLetters(char* s) {
    int stack[26][MAX], size=0, i, j, h;
    int *top = calloc(26, sizeof(int));
    char *ans = malloc(27 * sizeof(char));
    int cnt = 0;
    
    for(i=strlen(s)-1; i>=0; i--)
        stack[s[i]-'a'][top[s[i]-'a']++] = i;
    
    for(i=0;i<26;i++){
        if(top[i]>0)
            cnt++;
    }
    
    h = 0;
    while(h<cnt){
        for(i=0;i<26;i++){
            if(top[i]>0){
                for(j=0;j<26;j++){
                    if(j == i)
                        continue;
                    if(top[j]>0&&stack[i][top[i]-1]>stack[j][0])
                        break;                    
                }
                if(j==26){
                    ans[size++] = i+'a';
                    for(j=0;j<26;j++){
                        if(j == i)
                            continue;
                        if(top[j]>0){
                            while(top[j]>0&&stack[j][top[j]-1]<stack[i][top[i]-1])
                                top[j]--;
                        }
                    }
                    top[i] = 0;
                    h++;
                    break;
                }
            }
        }
    }
    ans[size] = 0;
    return ans;
}