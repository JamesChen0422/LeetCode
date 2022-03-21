

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int* ans = malloc(500 * sizeof(int));
    int* pos = calloc(26, sizeof(int));
    int j=0, prev=0;
    *returnSize = 0;
    
    for(int i=0; i<strlen(s); i++){
        pos[s[i]-'a'] = i;
    }
    
    for(int i=0; i<strlen(s); i++){
        j = j>pos[s[i]-'a'] ? j:pos[s[i]-'a'];
        if(i==j){
            ans[(*returnSize)++] = j-prev+1;
            prev = j+1;
        }
    }
    
    return ans;
}