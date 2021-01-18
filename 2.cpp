#include <iostream>
#include <cstdio>

#define MAX_STR 1024

struct Password {
  int a, b;
  char letter;
  char str[MAX_STR + 1];
};

int read_password(Password& p) {
  int a, b;
  char letter, str[MAX_STR + 1];

  return scanf("%d-%d %c: %s", &p.a, &p.b, &p.letter, p.str);
}

bool is_valid_policy1(const Password& p) {
  int count = 0;

  for (int i = 0; p.str[i] != '\0'; ++i)
    if (p.str[i] == p.letter) count++;

  return count >= p.a && count <= p.b;
}

bool is_valid_policy2(const Password& p) {
  bool first_matches_char = p.str[p.a - 1] == p.letter;
  bool second_matches_char = p.str[p.b - 1] == p.letter;

  return first_matches_char != second_matches_char;
}

void solve(void) {
  Password p;
  int valid_p1 = 0;
  int valid_p2 = 0;

  while (read_password(p) != EOF) {
    if (is_valid_policy1(p)) valid_p1++;
    if (is_valid_policy2(p)) valid_p2++;
  }

  std::cout << valid_p1 << " valid passwords according to policy 1\n"
            << valid_p2 << " valid passwords according to policy 2\n";
}

int main(void) {
  solve();
  return 0;
}
