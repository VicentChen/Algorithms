import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item[] a;
    private int head;
    private int tail;

    // construct an empty randomized queue
    public RandomizedQueue() {
        a = (Item[]) new Object[4];
        head = 0;
        tail = 1;

    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return size() == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        int size = tail + a.length - head - 1;
        if (size >= a.length) size -= a.length;
        return size;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) throw new IllegalArgumentException();
        a[tail] = item;
        int tempTail = tail;

        tail++;
        if (tail == a.length) tail = 0;

        // swap randomly
        int random = StdRandom.uniform(1, size() + 1) + head;
        if (random >= a.length) random -= a.length;
        Item temp = a[tempTail];
        a[tempTail] = a[random];
        a[random] = temp;

        if (tail == head) resize(a.length * 2);
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        head++;
        if (head == a.length) head = 0;
        Item item = a[head];
        a[head] = null;

        if (size() < a.length / 4) resize(a.length / 2);

        return item;
    }

    private void resize(int newSize) {
        int currSize = size();
        Item[] newA = (Item[]) new Object[newSize];
        for (int i = 1; i <= currSize; i++) {
            int index = head + i;
            if (index >= a.length) index -= a.length;
            newA[i] = a[index];
        }
        head = 0;
        tail = currSize + 1;
        a = newA;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException();
        int index = head + StdRandom.uniform(1, size() + 1);
        if (index >= a.length) index -= a.length;
        return a[index];
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int[] indices;
        private int curr;

        public RandomizedQueueIterator() {
            curr = 0;
            indices = new int[size()];
            for (int i = 0; i < indices.length; i++) {
                indices[i] = i + 1;
            }
            StdRandom.shuffle(indices);
        }

        public boolean hasNext() {
            return curr < indices.length;
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();

            int index = indices[curr++] + head;
            if (index >= a.length) index -= a.length;
            return a[index];
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    // unit testing (optional)
    public static void main(String[] args) {
        RandomizedQueue<Integer> queue = new RandomizedQueue<Integer>();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        for (Integer i : queue) {
            StdOut.println(i);
        }
        StdOut.println(queue.dequeue());
        StdOut.println(queue.dequeue());
        StdOut.println(queue.dequeue());
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        for (Integer i : queue) {
            StdOut.println(i);
        }
    }
}