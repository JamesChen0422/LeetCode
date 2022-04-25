/*
 *	struct Iterator {
 *		// Returns true if the iteration has more elements.
 *		bool (*hasNext)();
 *
 * 		// Returns the next element in the iteration.
 *		int (*next)();
 *	};
 */

struct PeekingIterator {
    struct Iterator *iterator;
    int cnt;
    int hasPeeked;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = calloc(1, sizeof(struct PeekingIterator));
    piter->iterator = iter;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    return obj->hasPeeked ? obj->cnt : (obj->hasPeeked = 1, obj->cnt = obj->iterator->next());
}

int next(struct PeekingIterator* obj) {
    return obj->hasPeeked ? obj->hasPeeked = 0, obj->cnt : (obj->cnt = obj->iterator->next());
}

bool hasNext(struct PeekingIterator* obj) {
    return obj->hasPeeked || obj->iterator->hasNext();
}

/**
 * Your PeekingIterator struct will be instantiated and called as such:
 * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
 * int param_1 = peek(obj);
 * int param_2 = next(obj);
 * bool param_3 = hasNext(obj);
 * peekingIteratorFree(obj);
*/