typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* que = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    que->front = 0;
    que->rear = 0;
    que->size = k + 1;  // Increase size by 1 to distinguish between full and empty
    que->arr = (int*)malloc(que->size * sizeof(int));
    return que;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->rear + 1) % obj->size != obj->front % obj->size) {
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear + 1) % obj->size;
        return true;
    }
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->front % obj->size != obj->rear % obj->size) {
        obj->front = (obj->front + 1) % obj->size;
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->front % obj->size != obj->rear % obj->size) {
        return obj->arr[obj->front];
    }
    return -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->front % obj->size != obj->rear % obj->size) {
        int rearIndex = (obj->rear - 1 + obj->size) % obj->size;
        return obj->arr[rearIndex];
    }
    return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front % obj->size == obj->rear % obj->size;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->size == obj->front % obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
