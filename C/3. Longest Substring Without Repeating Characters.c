
int lengthOfLongestSubstring(char * s){
   int max =0;

   for(int i=0; i<strlen(s); i++){
        bool visit[256]={false};
        for(int j = i; j<strlen(s) && !visit[s[j]]; j++){
            max = j-i+1>max ? j-i+1 : max;
            visit[s[j]] = true;            
        } 
        visit[s[i]] = false;
   }

   return max;
}


==============================================================


int lengthOfLongestSubstring(char * s){
    char *address[128] = {NULL};
    int len =0;
    char *tmp, *start=s; //Assign the first pointer
    while(*start)
    {
        tmp = address[*start]; //Extract value
        address[*start] = start; //Assign the value
        if(tmp >= s)
        {
            len = len > start - s ? len : start - s; //Difference between current pointer and starting pointer
            s = tmp +1; // next starting pointer
        }
        start++;
    }
    len = len > start - s ? len : start -s;
    return len;
}