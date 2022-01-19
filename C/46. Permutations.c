/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define SWAP(x,y) {int tmp=*x; *x=*y; *y=tmp;}

void permute1(int* a, int l, int r, int *count,int **ret,int numsSize,int **returnColumnSizes){ 
	int i; 
	if (l == r){
        *(ret+*count)=malloc(sizeof(int)*numsSize);
        memcpy(*(ret+*count), a, numsSize * sizeof(int));
        *returnColumnSizes=realloc(*returnColumnSizes, sizeof(int)*(*(count)+1));
        *(*returnColumnSizes+(*count))=numsSize;
        (*count)++;        
    } else { 
		for (i = l; i <= r; i++) { 
			SWAP((a + l), (a + i)); 
			permute1(a, l + 1, r, count,ret,numsSize,returnColumnSizes); 
			SWAP((a + l), (a + i)); // backtrack 
		} 
	} 
} 

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int cnt=0;
    *returnColumnSizes=malloc(sizeof(int)*1);
    int **ret=malloc(sizeof(int *)*1000);
    permute1(nums,0,numsSize-1,&cnt,ret,numsSize,returnColumnSizes);
    *returnSize=cnt;
    return ret;
}   