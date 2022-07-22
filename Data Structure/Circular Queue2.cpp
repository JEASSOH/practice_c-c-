#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element  data[MAX_QUEUE_SIZE];
	int  front, rear,size; //size = number of data
} QueueType;

// Error Handling
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Queue initialization
void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;
	q->size = 0;
	printf("Q is initialized!!\n");
}

// Check if queue is empty
int is_empty(QueueType* q)
{
	if (q->front == -1 && q->rear == -1)
		return 1;
	else
		return 0;
}

// Check if queue is full
int is_full(QueueType* q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}

// Print queue - need to consider two cases:
// Case 1: q->front <= q->rear
// Case 2: q->front > q->rear
// Print the items starting from data[q->front] through data[q->rear]
void queue_print(QueueType* q)
{
	if (is_empty(q)) {
		printf("Queue is empty!!\n");
		printf("The front value: %d\n", q->front);
		printf("The rear value: %d\n", q->rear);
		return;
	}
	int temp = q->front;
	for (int i = 0; i < q->size; i++)
	{
		printf(": %d :", q->data[temp]);
		temp = ++temp % MAX_QUEUE_SIZE;
	}

		printf("\n");
		printf("The front value: %d\n", q->front);
		printf("The rear value: %d\n", q->rear);
		printf("\n");


}

// Add an item into queue
void enqueue(QueueType* q, element item)
{
	
	if (is_full(q)) {
		error("Queue is full!!");
		return;
	}
	
	// if queue is empty (i.e. front == rear == -1)
	if (is_empty(q)) {
		q->front += 1;
		q->rear += 1;
	}

	// if there are more than or equal to one item in queue
	else
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	q->data[q->rear] = item;
	q->size++;
	// q->data[++(q->rear)] = item; 
}


// Remove and return an item from queue
element dequeue(QueueType* q)
{
	element item;
	
	if (is_empty(q)) {
		error("Queue is empty!!");
		return -1;
	}
	item = q->data[q->front];
	q->data[q->front] = NULL;
	q->size--;
	// int item = q->data[++(q->front)];

	// if there is only one item in queue (i.e., front == rear)
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}

	// if there are more than or equal to two items in queue 
	else
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 모듈로 연산을 통해 배열의 0번 인덱스로 돌아 감

	return item;
}

// Check the item in the front
element peek(QueueType* q)
{
	if (is_empty(q))
		error("Q is empty!!");

	return q->data[q->front];
}

int get_count(QueueType* q, int x)
{
	int temp = q->front;
	int count = 0;
	for (int i = 0; i < q->size; i++)
	{
		if (q->data[temp] == x) {
			count++;
			
		}
		temp = ++temp % MAX_QUEUE_SIZE;
	}
	return count;
}
int main(void)
{
	QueueType queue;
	int x;

	init_queue(&queue);

	enqueue(&queue,1);
	queue_print(&queue);
	enqueue(&queue,2);
	queue_print(&queue);
	enqueue(&queue, 3);
	queue_print(&queue);
	enqueue(&queue, 4);
	queue_print(&queue);
	dequeue(&queue);
	queue_print(&queue);
	enqueue(&queue, 3);
	queue_print(&queue);
	dequeue(&queue);
	queue_print(&queue);
	enqueue(&queue, 5);
	queue_print(&queue);
	enqueue(&queue, 6);
	queue_print(&queue);
	printf("%d\n",get_count(&queue, 3));
	printf("%d", get_count(&queue, 7));

	return 0;
}