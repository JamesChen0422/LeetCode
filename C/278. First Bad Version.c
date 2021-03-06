// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    while (start < end) {
        int mid = start + (end - start) / 2;  //prevent overflow
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}
