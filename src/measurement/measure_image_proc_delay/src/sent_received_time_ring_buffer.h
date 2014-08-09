/**
 * @Author Lars Harmsen
 */


#define BUFFER_SIZE 5

class SentReceivedTimeRingBuffer {
	public:
		SentReceivedTimeRingBuffer();
		~SentReceivedTimeRingBuffer() { }
		
		void add(long millisSent, long millisReceived);
		
		bool containsSentTime(long millisSent);
		long getReceivedTime(long millisSent);
		
	private:
		int pointer;
		long sentTimes[BUFFER_SIZE];
		long receivedTimes[BUFFER_SIZE];
};
