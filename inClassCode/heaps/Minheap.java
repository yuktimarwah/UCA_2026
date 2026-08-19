class Minheap {
	int[] heap;
	int size;
	Minheap (int capacity) {
		heap = new int[capacity];
		size = 0;
}

 void insert (int value) {
	heap[size] = value;
	int i = size;
	size++;

	while (i > 0) {
	int p = (i-1)/2;
	if (heap[p] > heap[i]) {
	       int temp = heap[i];
               heap[i] = heap[p];
               heap[p] = temp;
	       i = p;
	}
	else {
		break;
	     }
	}
}

int remove() {
	int og_root = heap[0];

	int temp = heap[size - 1];
	heap[size - 1] = heap[0];
	heap[0] = temp;
	size--;

	int i = 0;

	while ((2*i+1) < size) {
	int left = 2*i+1;
        int right = 2*i+2;

	int smaller = i;
	if (left < size && heap[left] < heap[smaller] ) {
		smaller  = left;
	}
	if (right < size && heap[right] < heap[smaller] ){
		smaller = right;
	}

	if (smaller != i) {
		int temp1 = heap[smaller];
		heap[smaller] = heap[i];
		heap[i] = temp1;

		i = smaller;
	}
	else {
		break;
	}
}
    return og_root;
  }

public static void main (String[] args) {
	 Minheap h = new Minheap(10);

        h.insert(5);
        h.insert(3);
        h.insert(8);
        h.insert(1);
        h.insert(2);

        System.out.println(h.remove()); // 1
        System.out.println(h.remove()); // 2
        System.out.println(h.remove()); // 3
}
}
