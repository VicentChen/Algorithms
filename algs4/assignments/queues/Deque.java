import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    private Node head;
    private Node tail;
    private int size;

    private class Node {
        Item item;
        Node prev;
        Node next;

        public Node() {
        }

        public Node(Node prev, Node next) {
            this.prev = prev;
            this.next = next;
        }

        public Node(Item item, Node prev, Node next) {
            this.item = item;
            this.prev = prev;
            this.next = next;
        }
    }

    // construct an empty deque
    public Deque() {
        head = new Node();
        tail = new Node();

        head.prev = null;
        head.next = tail;
        tail.prev = head;
        tail.next = null;

        size = 0;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return head.next == tail;
    }

    // return the number of items on the deque
    public int size() {
        return size;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) throw new IllegalArgumentException();

        Node node = new Node(item, head, head.next);
        head.next = node;
        node.next.prev = node;

        size++;
    }

    // add the item to the end
    public void addLast(Item item) {
        if (item == null) throw new IllegalArgumentException();

        Node node = new Node(item, tail.prev, tail);
        tail.prev = node;
        node.prev.next = node;

        size++;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        Node target = head.next;
        if (target == tail) throw new NoSuchElementException();

        Item item = target.item;

        head.next = target.next;
        head.next.prev = head;
        size--;

        return item;
    }

    // remove and return the item from the end
    public Item removeLast() {
        Node target = tail.prev;
        if (target == head) throw new NoSuchElementException();

        Item item = target.item;

        tail.prev = target.prev;
        tail.prev.next = tail;
        size--;

        return item;
    }

    private class DequeIterator implements Iterator<Item> {

        private Node curr;

        public DequeIterator() {
            curr = head;
        }

        public boolean hasNext() {
            return curr.next != tail;
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();

            curr = curr.next;
            Item item = curr.item;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    // return an iterator over items in order from front to end
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    // unit testing (optional)
    public static void main(String[] args) {
    }
}