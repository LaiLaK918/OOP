#include<string>
using namespace std;
string factorial(int factorial){
  int n = factorial;
  if (n < 0) return "";
  if (n <= 1)  return "1";
  std::vector<int> v = { 2 };
  for (int i = 3; i <= n; i++) {
    int r = 0; //remainder
    for (int j = 0; j < (int) v.size(); j++) {
      v[j] *= i;
      v[j] += r;
      r = v[j] / 10;
      v[j] %= 10;
    }
    while (r > 0) {
      v.push_back(r % 10);
      r /= 10;
    }
  }
  string result;
  for (auto i = v.rbegin(); i != v.rend(); i++) {
    result += '0' + (*i);
  }
  return result;
}
