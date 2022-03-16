

char* simplifyPath(char* path) {
    char *ans = malloc(sizeof(char) * (strlen(path) + 1));
    int idx = -1;
    
    if(strlen(path) == 0)
        return path;
    else
        ans[++idx] = *path++;
    
    while(*path){
        while(*path && *path != '/'){
            ans[++idx] = *path++;
        }   

        if(ans[idx] == '.' && ans[idx - 1] == '/'){
            idx--;
            if(*path == '/')
                path++;
        } else if(ans[idx] == '.' && ans[idx - 1] == '.' && ans[idx - 2] == '/'){
            if(idx == 2)
                idx = 0;
            else{
                idx -= 3;
                while(ans[idx] != '/')
                    idx--;
            }
            if(*path == '/')
                path++;
        } else
            if(*path == '/')
                if(ans[idx] == '/')
                    path++;
                else
                    ans[++idx] = *path++;
    }    
    
    if(idx > 0 && ans[idx] == '/')
        idx--;
    ans[idx + 1] = 0;
    
    return ans;
}