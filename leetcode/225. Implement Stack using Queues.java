import java.util.LinkedList;
import java.util.Queue;

class ImplementStackUsingQueues {
    public Queue<Integer> q1;
    public Queue<Integer> q2;

    public ImplementStackUsingQueues() {
        this.q1 = new LinkedList<>();
        this.q2 = new LinkedList<>();
    }

    public void push(int x) {
        Queue<Integer> holdingQueue;
        Queue<Integer> finalQueue;

        if (this.q1.isEmpty()) {
            finalQueue = this.q1;
            holdingQueue = this.q2;
        } else {
            finalQueue = this.q2;
            holdingQueue = this.q1;
        }

        finalQueue.add(x);

        while (!holdingQueue.isEmpty()) {
            finalQueue.add(holdingQueue.remove());
        }
    }

    public int pop() {
        if (this.empty()) {
            return -1;
        }

        if (!this.q1.isEmpty()) {
            return this.q1.remove();
        }

        return this.q2.remove();
    }

    public int top() {
        if (this.empty()) {
            return -1;
        }

        if (!this.q1.isEmpty()) {
            return this.q1.peek();
        }

        return this.q2.peek();
    }

    public boolean empty() {
        return this.q1.isEmpty() && this.q2.isEmpty();
    }
}
