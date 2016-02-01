#include <bits/stdc++.h>
using namespace std;

// we can anticipate elements numbered up to 100000
int roots[100001];
vector<int> sets[100001];

// starting a test case, make each set contain only
// one element which is also its root
void initialize(int n) {
  for (int i = 1; i <= n; i++) {
    roots[i] = i;
    sets[i].clear();
    sets[i].push_back(i);
  }
}

// union the sets containing p and q
void set_union(int p, int q) {
  int p_root = roots[p];
  int q_root = roots[q];
  // finish early if they're in the same set
  if (p_root == q_root) {
    return;
  }

  if (sets[p_root].size() >= sets[q_root].size()) {
    // minimize the height of the set trees,
    // so make p the root of all elements in q
    for (int i : sets[q_root]) {
      sets[p_root].push_back(i);
      roots[i] = p_root;
    }
    sets[q_root].clear();
  }
  else {
    // otherwise,
    // make q the roots of all elements in p
    for (int i : sets[p_root]) {
      sets[q_root].push_back(i);
      roots[i] = q_root;
    }
    sets[p_root].clear();
  }
}

// move p into the set containing q
void move(int p, int q) {
  int p_root = roots[p];
  int q_root = roots[q];
  // finish early if they're in the same set
  if (p_root == q_root) {
    return;
  }

  // remove p from the set that contains it...
  auto it = sets[p_root].begin();
  while (*it != p) {
    it++;
  }
  sets[p_root].erase(it);

  // and add it into the set containing q
  sets[q_root].push_back(p);
  roots[p] = q_root;
}

// calculate how many elements are the set containing
// p and also their sum
void query(int p) {
  int p_root = roots[p];
  int sum = 0;
  for (int i : sets[p_root]) {
    sum += i;
  }
  printf("%d %d\n", sets[p_root].size(), sum);
}

int main() {
  int N, M;
  int command, p, q;
  while (scanf("%d %d", &N, &M) == 2) {
    initialize(N);
    for (int m = 0; m < M; m++) {
      cin >> command;
      switch (command) {
        case 1:
          scanf("%d %d", &p, &q);
          set_union(p, q);
          break;
        case 2:
          scanf("%d %d", &p, &q);
          move(p, q);
          break;
        case 3:
          scanf("%d", &p);
          query(p);
          break;
        default:
          break;
      }
    }
  }
}

