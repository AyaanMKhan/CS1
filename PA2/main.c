#include <stdio.h>
#include <stdlib.h>
#define GARAGE 10

typedef struct Student {
    int sequenceNumber;
    struct Student* next;
} Student;

typedef struct Queue {
    Student* front;
    Student* back;
    int nodeCount, k, th, garageCount;
} Queue;

void init(Queue* q){

    q->front = NULL;
    q->back = NULL;
    q->nodeCount = 0;
    q->k = 0;
    q->th = 0;
    q->garageCount = 0;

}

Student* peek(Queue* q) {

    return q->front;

}

int isEmpty(Queue* q) {

    return q->front == NULL;

}

Student* createStudent(int sequenceNumber) {

    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->sequenceNumber = sequenceNumber;
    newStudent->next = NULL;
    return newStudent;

}

void enqueue(Queue* q, Student* newStudent) {

    if (q->back == NULL) {
        q->front = newStudent;
        q->back = newStudent;
        newStudent->next = newStudent;
    } else {
        q->back->next = newStudent;
        q->back = newStudent;
        q->back->next = q->front;
    }
    q->nodeCount += 1;
}

Student* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }

    Student* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (isEmpty(q)) {
        q->back = NULL;
    }

    q->nodeCount -= 1;

    return temp;
}



void createReverseCircle(Queue* q) {

    int n = q->nodeCount;

    for (int i = n; i >= 1; i--) {

        Student* newStudent = createStudent(i);
        enqueue(q, newStudent);

    }

}

void rearrangeCircle(Queue* q) {
    // If the queue is empty or has only one element, do nothing
    if (isEmpty(q) || q->front == q->back) {
        return;
    }

    // Four variables for reversing
    Student *prev = q->back;    // Initially set to the last element in the circle
    Student *curr = q->front;   // Start with the front element
    Student *next = NULL;       // Will store the next node during traversal
    Student *last = q->back;    // Store the original back

    // First iteration handled outside the loop
    next = curr->next;          // Save next node
    curr->next = prev;          // Reverse the link for the first node
    prev = curr;                // Update prev to current node
    curr = next;                // Move to the next node

    // Loop through the circle and reverse the links until we reach the original back
    while (curr != q->front) {
        next = curr->next;      // Save the next node
        curr->next = prev;      // Reverse the link
        prev = curr;            // Move `prev` to the current node
        curr = next;            // Move to the next node
    }

    // After reversing, adjust the front and back pointers
    q->front->next = q->back;   // The old front becomes the new back and points to the new back
    q->back = q->front;         // The old front becomes the new back
    q->front = last;            // The old back becomes the new front
}

void display(Queue* q) {

    for(int i = 0; i < GARAGE; i++){
        if(!(isEmpty(&q[i]))){
            printf("%d ", q[i].garageCount);

            Student *front = q[i].front;
            int count = q[i].nodeCount;

            for(int j = 0; j < count; j++){
                printf("%d ", front->sequenceNumber);
                front = front->next;

                if(front == q[i].front){
                    break;
                }
            }

            printf("\n");
        }
    }
        

}

int main() {
    // Read input data
    int n, k, th, garageCount, studentInterested;
    scanf("%d", &n);
    Queue garages[GARAGE];

    for(int i = 0; i < GARAGE; i++){
        init(&garages[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &garageCount, &studentInterested, &k, &th);
        int index = garageCount -1;
        garages[index].garageCount = garageCount;
        garages[index].k = k;
        garages[index].th= th;
        garages[index].nodeCount = studentInterested;

        createReverseCircle(&garages[index]);
    }
    
    printf("Initial status of nonempty queues: \n");
    display(garages);

    for(int i = 0; i < GARAGE; i++){
        rearrangeCircle(&garages[i]);
    }

    printf("After ordering status of nonempty queues: \n");
    display(garages);


    return 0;
}