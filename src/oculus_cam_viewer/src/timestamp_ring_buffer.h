/**
 * @Author Lars Harmsen
 */

#pragma once

#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>

#define BUFFER_SIZE 2


template <typename T>
class TimestampRingBuffer {
	public:
		TimestampRingBuffer();
		~TimestampRingBuffer() { }
		
		void add(T element, long millis);
		
		/**
		  * Puts the element nearest to millis in dst.
		  * dst can be returned null, check isEmpty() first
		  * returns the abs difference of the found element to millis
		  */
		long getNearest(long millis, T* dst);
		
		/**
		  * Returns element added last, not the one with the latest timestamp 
		  * Can be null, check isEmpty() first
		  */
		T* getLastElement() {
			return &(data[pointer]);
		}
		
		/**
		  * Returns timestamp added last, not the one with the highest value 
		  * Can be null, check isEmpty() first
		  */
		long getLastTime() {
			return times[pointer];
		}
		
		bool isEmpty();
		
	private:
		int pointer;
		long times[BUFFER_SIZE];
		T data[BUFFER_SIZE];
};


template <typename T>
TimestampRingBuffer<T>::TimestampRingBuffer() {
	pointer = 0;
	memset(times, 0, sizeof(times));
}

template <typename T>
void TimestampRingBuffer<T>::add(T element, long millis) {
	pointer = (pointer + 1) % BUFFER_SIZE;
	times[pointer] = millis;
	data[pointer] = element;
}

template <typename T>
long TimestampRingBuffer<T>::getNearest(long millis, T* dst) {
	int current = pointer;
	int next = current - 1;
	if(next < 0) {
		next = BUFFER_SIZE - 1;
	}
	
	while(std::abs(millis - times[current]) > std::abs(millis - times[next])){
		current = next;
		--next;
		if(next < 0) {
			next = BUFFER_SIZE - 1;
		}
	}
	
	*dst = data[current];
	return std::abs(millis - times[current]);
}

template <typename T>
bool TimestampRingBuffer<T>::isEmpty() {
	for(int i=0; i < BUFFER_SIZE; ++i) {
		if(times[i] != 0){
			return false;
		}
	}
	return true;
}
