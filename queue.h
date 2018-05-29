/*
 * queue.h
 *
 * This software is licensed under the GNU General Public License v3.0.
 *
 *  Created on: May 22, 2018
 *      Author: Ricardo Cirio
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>

#define	QUEUE_SIZE	8

typedef struct {
	uint8_t flag, head, tail, data[QUEUE_SIZE];
}queue_t;

void queueInit(queue_t *queue);

void enqueue(queue_t *queue, uint8_t c);

uint8_t dequeue(queue_t *queue);

void queueFlush(queue_t *queue, uint8_t *destination, uint8_t n);

#endif /* QUEUE_H_ */
