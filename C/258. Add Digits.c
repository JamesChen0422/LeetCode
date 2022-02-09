

int addDigits(int num){
    int sum=0;
    while(num){
        sum += (num%10);
        num /= 10;
        if(!num && sum>=10){
            num = sum;
            sum = 0;
        }
    }
    
    return sum;
}


=========================================================


int addDigits(int num) {
    return (num % 9 == 0 && num / 9 >= 1) ? 9 : num % 9;
}