
int maxProduct(int* nums, int numsSize) 
{
	int maxp = INT_MIN;
	int headp = 1; //multiply elements from head to tail
	int tailp = 1; //multiply elements from tail to head
	int tmp;
	for (int i = 0; i < numsSize; ++i)
	{
		headp *= nums[i];
		tailp *= nums[numsSize - 1 - i];
		tmp = headp > tailp ? headp : tailp;
		maxp = tmp > maxp ? tmp : maxp;
		if (!headp) headp = 1; //if element == 0, array is divided, reset the product = 0.
		if (!tailp) tailp = 1;
	}
	return maxp;
}