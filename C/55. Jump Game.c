

bool canJump(int* nums, int numsSize){
    int start=0, end;
    
    if(numsSize==1)
        return true;
    
    for(int i=0; i<numsSize; i++){
        if(i==numsSize-1)
            return true;
        
        if(!nums[i]){
            if(i==0)
                return false;
            
            end=i;
            int temp=0;
            if(i!=numsSize-1){
                while(end>=start){
                    if(nums[end]>temp)
                        break;
                    else if(end==start && nums[end]<=temp)
                        return false;
                    temp++;
                    end--;
                }
            } else {
                while(end>=start){
                    if(nums[end]>=temp)
                        return true;                    
                    temp++;
                    end--;
                }
            }
        } 
        
    }
    
    return false;
}


==================================================================


bool canJump(int* nums, int numsSize){
   int reach=numsSize-1;
    for(int i=numsSize-2;i>=0;i--)   
        if(i+nums[i]>=reach)    
            reach=i;
    
    return !reach;
}