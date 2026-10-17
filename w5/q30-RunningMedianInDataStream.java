class MedianFinder {

    PriorityQueue<Integer> minheap = new PriorityQueue<>();
    PriorityQueue<Integer> maxheap = new PriorityQueue<>(Collections.reverseOrder());

    public void insert(int num) {
	    maxheap.offer(num);
	    minheap.offer(maxheap.poll());

	    if (minheap.size() > maxheap.size()) {
		    
		    maxheap.offer(minheap.poll());

	    }
    
    }

    public float getMedian() {

	    if (maxheap.isEmpty()) {
		    
		    throw new IllegalStateException("No numbers inserted");

	    }

	    if (maxheap.size() > minheap.size()) {
		    
		    return maxheap.peek();

	    }

	    return (maxheap.peek() + minheap.peek()) / 2.0f;
    }
}
