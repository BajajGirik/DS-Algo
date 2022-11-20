#include <iostream>
#include <vector>

using namespace std;

// TLE on last case...
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   int n;
//   cin >> n;
//
//   vector<int> v(n);
//   for (int i = 0; i < n; ++i) {
//     v[i] = i + 1;
//   }
//
//   for (int i = 1; v.size() > 1; i = (i + 1) % v.size()) {
//     auto it = v.begin() + i;
//     cout << *it << " ";
//     v.erase(it);
//   }
//
//   cout << v[0];
//
//   cout << "\n";
//   return 0;
// }

struct Node {
  int val;
  Node *next;
};

Node *head = NULL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  head = new Node();
  Node *prev;
  head->val = 1;
  head->next = NULL;
  prev = head;

  for (int i = 1; i < n; ++i) {
    Node *ptr = new Node();
    ptr->val = i + 1;
    ptr->next = NULL;
    prev->next = ptr;
    prev = ptr;
  }

  // pointing last node to the head node
  // circular linked list
  prev->next = head;

  Node *curr = head;
  while (head->next != head) {
    Node *ptrToBeDeleted = curr->next;
    cout << ptrToBeDeleted->val << " ";

    curr->next = ptrToBeDeleted->next;

    if (ptrToBeDeleted->val == head->val) {
      head = ptrToBeDeleted->next;
    }

    free(ptrToBeDeleted);
    curr = curr->next;
  }

  cout << head->val << "\n";
  free(head);

  return 0;
}
