

char * interpret(char * command){
    char* ans = malloc((strlen(command)+1) * sizeof(char));
    int idx = 0;
    
    for(int i=0; i<strlen(command); i++){
        if(command[i] == 'G'){
            ans[idx++] = 'G';
        } else if(command[i] == '('){
            if(command[i+1] == ')'){
                ans[idx++] = 'o';
                i++;
            } else {
                ans[idx++] = 'a';
                ans[idx++] = 'l';
                i+=3;
            }
        }
    }

    ans[idx] = '\0';
    
    return ans;
}