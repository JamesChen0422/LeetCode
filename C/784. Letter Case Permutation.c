

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize){
    int len = strlen(S);
    int permutation;
    int count = 0;
    for(int i = 0;i<len;i++)
    {
        if(isalpha(S[i]))
        {
            count++;
        }
    }
    permutation = pow(2,count);
    char** a = malloc(permutation*sizeof(char*));
    char* s = (char*)malloc((len+1)*sizeof(char));
    for(int k = 0;k<permutation;k++)
    {
        a[k]=malloc((len+1)*sizeof(char));
    }
    int i,j;
    int index = 0;
    strcpy(a[0],S);
    index++;
    int index_1;
    for(i = 0;i<len;i++)
    {
        index_1 = index;
        if(isalpha(S[i]))
        {
           if(isupper(S[i]))
           {
               for(j = 0;j<index_1;j++)
               {
                   strcpy(s,a[j]);
                   s[i] = tolower(s[i]);
                   strcpy(a[index],s);  
                   index++;
               }
           }
            else
            {
               for(j = 0;j<index_1;j++)
               {
                   strcpy(s,a[j]);
                   s[i] = toupper(s[i]);
                   strcpy(a[index],s);  
                   index++;
               }
            }
        }
    }
    *returnSize = index;
    return a;
}