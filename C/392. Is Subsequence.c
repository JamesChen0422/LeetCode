

bool isSubsequence(char* s, char* t) {
    while(*t){
        if(*s == *t) s += 1;
        *t++;
    }
    
    if(*s)
        return false;
    else 
        return true;    
}


========================================================================


bool isSubsequence(char* s, char* t) {
    while (*t)
        s += *s == *t++;
    return !*s;
}
