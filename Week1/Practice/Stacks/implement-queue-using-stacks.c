#define MAX_SIZE 100000

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->arr[++obj->rear] = x;
}

int myQueuePop(MyQueue* obj) {
    return obj->arr[obj->front++];
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front > obj->rear;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
