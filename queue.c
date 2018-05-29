/*
 * queue.c
 *
 *  Created on: May 22, 2018
 *      Author: rsc
 */

#include "queue.h"

void queueInit(queue_t *queue)
{
	queue->flag = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->data[queue->tail] = '\0';
}

void enqueue(queue_t *queue, uint8_t c)
{
	queue->data[queue->tail] = c;
	queue->tail++;
	if(queue->tail >= QUEUE_SIZE)
		queue->tail = 0;
	queue->data[queue->tail] = '\0';
	if(queue->tail == queue->head)
	{
		queue->head++;
		if(queue->head >= QUEUE_SIZE)
			queue->head = 0;
	}
}

uint8_t dequeue(queue_t *queue)
{
	static uint8_t c;
	c = queue->data[queue->head];
	queue->head++;
	if(queue->head >= QUEUE_SIZE)
		queue->head = 0;
	return c;
}

void queueFlush(queue_t *queue, uint8_t *destination, uint8_t n)
{
	static uint8_t i;
	for(i = 0; (queue->head != (queue->tail)) && (i < QUEUE_SIZE) && (i <= n); i++)
	{
		destination[i] = dequeue(queue);
	}
	queueInit(queue);
}
