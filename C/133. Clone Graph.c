/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct Node* newNode(struct Node* original) {
    struct Node* new = malloc(sizeof(*new));
    new->val = original->val;
    new->numNeighbors = original->numNeighbors;
    new->neighbors = calloc(new->numNeighbors, sizeof(struct Node*));
    return new;
}

struct Node* dfsCopy(struct Node* s, struct Node** newNodes) {
    int curr = s->val;
    newNodes[curr] = newNode(s);
    for (int i = 0; i < s->numNeighbors; i++) {
        if (newNodes[s->neighbors[i]->val] == NULL) {
            newNodes[curr]->neighbors[i] = dfsCopy(s->neighbors[i], newNodes);
        } else {
            newNodes[curr]->neighbors[i] = newNodes[s->neighbors[i]->val];
        }
    }
    return newNodes[curr];
}

struct Node *cloneGraph(struct Node *s) {
    struct Node* newGraph = NULL;
    if (s != NULL) {
        struct Node** newNodes = calloc(101, sizeof(struct Node*));
        newGraph = dfsCopy(s, newNodes);
        free(newNodes);
    }
    return newGraph;
}

