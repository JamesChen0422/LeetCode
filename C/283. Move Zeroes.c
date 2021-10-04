#define SWAP(x,y) {int temp; temp=x; x=y; y=temp;}

void moveZeroes(int* nums, int numsSize){
	int zero=-1, i=0;

	while(i<numsSize){   
		if(zero==-1 && !nums[i]){
			zero=i;
        } else if(zero!=-1 && nums[i]){
			SWAP(nums[zero], nums[i]);
            i=zero;
            zero=-1;
        }        
        i++;
	}   
}


=============================================================


void moveZeroes(int* nums, int numsSize){
    int cnt=0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==0)
            cnt++;
        else if(cnt>0)
            nums[i-cnt]=nums[i];
    }
    for(int i=0;i<cnt;i++)
        nums[numsSize-1-i] = 0;
}