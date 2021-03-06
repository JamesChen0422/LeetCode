

bool checkInclusion(char * s1, char * s2){
    int len1=strlen(s1),len2=strlen(s2);
    if(len1>len2)
        return false;
    int arr1[128]={0};
    int arr2[128]={0};
    
    for(int i=0;i<len1;i++)
    {
        arr1[s1[i]]++;
        arr2[s2[i]]++;
        
    }
    if(memcmp(arr1,arr2,sizeof(arr1))==0)
            return true;
    for(int i=len1;i<len2;i++)
    {
        --arr2[s2[i-len1]];
        ++arr2[s2[i]];
        if(memcmp(arr1,arr2,sizeof(arr1))==0)
            return true;
    }
    return false;
}