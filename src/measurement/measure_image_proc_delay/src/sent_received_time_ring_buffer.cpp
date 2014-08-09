/**
 * @Author Lars Harmsen
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <string.h>

#include "sent_received_time_ring_buffer.h"

SentReceivedTimeRingBuffer::SentReceivedTimeRingBuffer() {
	pointer = 0;
	memset(sentTimes, 0, sizeof(sentTimes));
	memset(receivedTimes, 0, sizeof(receivedTimes));
}

void SentReceivedTimeRingBuffer::add(long millisSent, long millisReceived) {
	pointer = (pointer + 1) % BUFFER_SIZE;
	sentTimes[pointer] = millisSent;
	receivedTimes[pointer] = millisReceived;
}

bool SentReceivedTimeRingBuffer::containsSentTime(long millisSent) {
	for(int i = 0; i < BUFFER_SIZE; ++i) {
		if(sentTimes[i] == millisSent) {
			return true;
		}
	}
	return false;
}

long SentReceivedTimeRingBuffer::getReceivedTime(long millisSent) {
	for(int i = 0; i < BUFFER_SIZE; ++i) {
		if(sentTimes[i] == millisSent) {
			return receivedTimes[i];
		}
	}
	return 0;
}
