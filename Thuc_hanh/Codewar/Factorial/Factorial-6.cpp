#include <sstream>
#include <string>
#include <utility>

std::string sub(const std::string &a,
                const std::string &b);

std::string add(const std::string &a,
                const std::string &b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  if (a[0] == '-') return sub(b, a.substr(1));
  if (b[0] == '-') return sub(a, b.substr(1));
  std::ostringstream oss;
  int carry = 0;
  for (unsigned int i = 0; i < a.size() || i < b.size(); ++i) {
    int x = i < a.size() ? a[a.size() - i - 1] - '0': 0;
    int y = i < b.size() ? b[b.size() - i - 1] - '0': 0;
    int sum = x + y + carry;
    oss << (sum % 10);
    carry = sum / 10;
  }
  if (carry > 0) oss << carry;
  std::string s(oss.str());
  return std::string(s.rbegin(), s.rend());
}

std::string neg(const std::string &x) {
  if (x.empty()) return x;
  return x[0] == '-' ? x.substr(1) : "-" + x;
}

std::string sub(const std::string &a,
                const std::string &b) {
  if (b.empty()) return a;
  if (a.empty()) return neg(b);
  if (a[0] == '-') return neg(add(a.substr(1), b));
  if (b[0] == '-') return add(a, b.substr(1));
  if (a.size() < b.size()) return neg(sub(b, a));
  if (a.size() == b.size () && a < b) return neg(sub(b, a));
  std::ostringstream oss;
  int borrow = 0;
  for (unsigned int i = 0; i < a.size() || i < b.size(); ++i) {
    int x = i < a.size() ? a[a.size() - i - 1] - '0': 0;
    int y = i < b.size() ? b[b.size() - i - 1] - '0': 0;
    int diff = x - y - borrow;
    if (diff < 0) {
      borrow = 1;
      diff += 10;
    } else {
      borrow = 0;
    }
    oss << diff;
  }
  std::string s(oss.str());
  return std::string(s.rbegin(), s.rend());
}

std::string pad(const std::string &s, unsigned int n) {
  if (s.size() >= n) return s;
  std::ostringstream oss;
  for (unsigned int i = 0; i < n - s.size(); ++i) {
    oss << '0';
  }
  oss << s;
  return oss.str();
}

// x * 10^n, n >= 0
std::string e(const std::string &x, int n) {
  std::ostringstream oss;
  oss << x;
  for (int i = 0; i < n; ++i) {
    oss << '0';
  }
  return oss.str();
}

std::pair<std::string, std::string>
split(const std::string &s) {
  int n = s.size() / 2;
  return std::make_pair(s.substr(0, n), s.substr(n));
}

std::string mul_small(const std::string &a,
                      const std::string &b) {
  return std::to_string(std::stoi(a) * std::stoi(b));
}

std::string strip(const std::string &x) {
  if (x.empty()) return x;
  int i = 0;
  while (x[i] == '0') ++i;
  return x.substr(i);
}

// karatsuba
std::string mul(const std::string &a,
                const std::string &b) {
  if (a.size() != b.size()) {
    return mul(pad(a, b.size()), pad(b, a.size()));
  }
  if (a.size() == 1) {
    return mul_small(a, b);
  }
  auto [a1, a2] = split(a);
  auto [b1, b2] = split(b);
  int n = a2.size();
  std::string a1b1 = mul(a1, b1);
  std::string a2b2 = mul(a2, b2);
  std::string a1b1_a1b2_a2b1_a2b2 = mul(add(a1, a2),
                                        add(b1, b2));
  return strip(add(add(a2b2, e(sub(a1b1_a1b2_a2b1_a2b2,
                                   add(a1b1, a2b2)), n)),
                   e(a1b1, n * 2)));
}

std::string prod(int start, int end) {
  if (start >= end) {
    return std::to_string(start);
  }
  int mid = start + (end - start) / 2;
  return mul(prod(start, mid), prod(mid + 1, end));
}

std::string factorial(int n) {
  return prod(1, n);
}
