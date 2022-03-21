

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	int i = 0, j = 0, k = 0;
    int * stack = (int*) malloc (pushedSize * sizeof(int));
	while (k >= 0 && k < pushedSize && j < poppedSize) {
		if (k>0 && stack[k-1] == popped[j]) {
			k--; j++;
		} else {
			if (i < pushedSize){
				if (pushed[i] == popped[j]){
					i++; j++;
				} else {
					stack[k++] = pushed[i++];
				}
			} else {
                free (stack);
				return false;
            }
		}
	}
    free (stack);
	return true;
}
