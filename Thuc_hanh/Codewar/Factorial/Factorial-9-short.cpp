#include <string>

std::string sum(std::string a, std::string b) {
  std::string res = "";
  a.length() > b.length() ? b.insert(0, a.length() - b.length(), '0') : a.insert(0, b.length() - a.length(), '0');
  for (int i = a.length() - 1; i >= 0; i--){
      if (i != 0) {
          int temp = (a[i] + b[i]) - 2 * '0';
          if (temp >= 10) {
              temp -= 10;
                a[i - 1]++;
          }
        res.insert(0, std::to_string(temp));
        }
        else res.insert(0, std::to_string((a[0] + b[0]) - 2 * '0'));
    }
    return res; 
}

std::string factorial(int n) {
    if (n < 0) return "";
    if (n >= 0 and n < 2) return "1";
    std::string res = "1", temp = "1";
    int i = 2, j;
    while (i <= n) {
        j = i;
        while (j > 1) {
            res = sum(res, temp);
            j--;
        }
        temp = res;
        i++;
    }
    return res;
}
