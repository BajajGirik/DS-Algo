#include <iostream>

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *prev;

  static Node *head;
  static Node *last;
  static Node *curr;

  static void add(int);
  static void incrementByK(int, int);
  static void reset();
};

// initialise static property.
Node *Node::head = NULL;
Node *Node::last = NULL;
Node *Node::curr = NULL;

// add to a doubly-circular linked-list.
void Node::add(int val) {
  Node *ptr = new Node();
  ptr->val = val;
  ptr->prev = last;

  if (head == NULL || last == NULL) {
    head = ptr;
    ptr->prev = ptr;
  } else {
    last->next = ptr;
  }

  last = ptr;
  last->next = head;

  head->prev = last;
}

/**
 * This function will increment the curr pointer by k
 * by moving forward k times or moving backward (as it is circular linked-list)
 * some times to reach the same destination (whichever is efficient).
 */
void Node::incrementByK(int k, int n) {
  k = k % n;
  if (k <= 0) {
    // request to move backwards
    // no need to optimise as this won't happen much
    while (k++) {
      curr = curr->prev;
    }
    return;
  }

  int backMoves = n - k;
  // move back to reach the same position in less number of moves.
  if (k > backMoves) {
    cout << "BackMoves: " << backMoves << "\n";
    while (backMoves--) {
      curr = curr->prev;
    }
  }
  // move forward as requested if this is already optimised way.
  else {
    cout << "ForwardMoves: " << k << "\n";
    while (k--) {
      curr = curr->next;
    }
  }
}

void Node::reset() { head = last = curr = NULL; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    Node::add(i + 1);
  }

  Node::curr = Node::head;
  while (n != 1) {
    Node::incrementByK(k, n);

    cout << Node::curr->val << " ";

    if (Node::curr->val == Node::head->val) {
      Node::head = Node::curr->next;
    }

    if (Node::curr->val == Node::last->val) {
      Node::last = Node::curr->prev;
    }

    Node::curr->prev->next = Node::curr->next;
    Node::curr->next->prev = Node::curr->prev;

    Node *ptrToBeDeleted = Node::curr;
    Node::curr = Node::curr->next;

    ptrToBeDeleted->next = NULL;
    ptrToBeDeleted->prev = NULL;
    delete ptrToBeDeleted;

    --n;
  }

  cout << Node::head->val << "\n";
  delete Node::head;

  Node::reset();
  return 0;
}
