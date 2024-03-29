typedef struct {
    char** Browser;
    int top;
    int size;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory* ret = malloc(sizeof(BrowserHistory));
    ret->Browser = malloc(101 * sizeof(char*));
    ret->Browser[0] = malloc(21 * sizeof(char));
    ret->Browser[0][strlen(homepage)] = '\0';
    memcpy(ret->Browser[0], homepage, strlen(homepage));
    ret->top = 0;
    ret->size = 1;
    return ret;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {

    obj->top++;
    if(obj->Browser[obj->top] != NULL){
        obj->Browser[obj->top] = malloc(21 * sizeof(char));
   }
    obj->Browser[obj->top][strlen(url)] = '\0';
    memcpy(obj->Browser[obj->top], url, strlen(url));
    obj->size = obj->top + 1;

}

char * browserHistoryBack(BrowserHistory* obj, int steps) {

      obj->top = fmax(0, obj->top - steps);  
      return obj->Browser[obj->top];
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
      obj->top = fmin(obj->size-1, obj->top + steps); 
      return obj->Browser[obj->top];
}

void browserHistoryFree(BrowserHistory* obj) {
    int idx = 0;
    while(1){
        if(obj->Browser[idx] != NULL)
            break;
        free(obj->Browser[idx]);
        idx++;
    }
    free(obj);
}
