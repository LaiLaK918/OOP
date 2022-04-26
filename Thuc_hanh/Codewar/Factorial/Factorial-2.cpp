using namespace std;

class BigInt {
private:
    vector<int> nums;
public:
    BigInt() {
        nums.clear();
    }
    
    BigInt(int x) {
        assert(x > 0);
        nums.clear();
        while(x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
    }
    
    BigInt & operator*=(const int & x) {
      for(int i = 0; i < nums.size(); ++i) {
          nums[i] *= x;
      }
      for(int i = 0; i < nums.size()-1; ++i) {
          nums[i+1] += nums[i] / 10;
          nums[i] %= 10;
      }
      while (nums[nums.size()-1] > 10) {
          int x = nums[nums.size()-1] / 10;
          nums[nums.size()-1] %= 10;
          nums.push_back(x);
      }
      return *this;
    }
    
    string toString() {
      string res = "";
      for(int i = nums.size()-1; i >= 0; --i)
          res = res + to_string(nums[i]);
      return res;
    }
    
};

string factorial(int factorial){
    if(factorial < 0) return "";
    if(factorial == 0) return 0;
    BigInt * num = new BigInt(factorial);
    for(int i = factorial-1; i > 1; --i)
        (*num) *= i;
    return num->toString();
}
