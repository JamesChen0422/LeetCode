

int scoreOfParentheses(char * s){
   int score=0, weight = 1;
    
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            weight *= 2;
        } else{
            weight /= 2;
            if(s[i-1]=='(')
                score += weight;
        }
    }
    
    return score;
}