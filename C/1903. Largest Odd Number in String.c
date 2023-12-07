char* largestOddNumber(char* num) {
    int len = strlen(num);

    while(len)
    {
        if((num[len-1] - '0') % 2)
        {
            break;
        }
        len--;
    }
    num[len] = '\0';    
    return num;
}

char* largestOddNumber(char* num) {
    for (int i = strlen(num) - 1; i >= 0 && !(num[i] & 1); i--)
    {
        num[i] = '\0';
    }
    return num;
}

