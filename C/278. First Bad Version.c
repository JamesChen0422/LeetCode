// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int begin = 1;
    int end = n;
    int index = n;

    while((end-begin) > 1) {
        int middle = begin + (end - begin) / 2;
        if(isBadVersion(middle)) {
            end = middle - 1;
            index = middle;
        } else {
            begin = middle + 1;
        }
    }
    if (index > begin && isBadVersion(begin))
        index = begin;
    if (index > end && isBadVersion(end))
        index = begin;

    return index;
}