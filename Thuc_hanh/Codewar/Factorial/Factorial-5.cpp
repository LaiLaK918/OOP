#include <sstream>
#include <iomanip>
#include <vector>

struct decimal_bignum
{
    // biggest decimal divisor that is able to divide a 64 bit
    // number before multiplication overflow
    // 1000000000 < 4294967296
    static const uint32_t divisor = 1000000000;

    decimal_bignum(uint64_t v)
        : _chunks(1, v)
    {
    }

    decimal_bignum & operator*=(uint32_t f)
    {
        // multiply every chunk with the factor
        for (auto & c : _chunks)
        {
            c *= f;
        }

        // check for 32 bit multiplication overflow of most significant chunk
        int i = _chunks.size() - 1;
        uint64_t o = _chunks[i] / divisor;
        if (o != 0)
        {
            _chunks.push_back(o);
            _chunks[i] = _chunks[i] % divisor;
        }
        i--;
        for (;i >= 0; i--)
        {
            // addition won't overflow as we're using a 32 bit number
            _chunks[i + 1] += _chunks[i] / divisor;
            _chunks[i] = _chunks[i] % divisor;
        }
        return *this;
    }

    std::string str() const
    {
        std::stringstream ss;
        auto rit = _chunks.rbegin();
        // invariant: at least one chunk
        ss << *rit;
        rit++;
        for (; rit != _chunks.rend(); rit++)
        {
            ss << std::setfill('0') << std::setw(9);
            ss << *rit;
        }
        return ss.str();
    }

    private:

    // chunks are stored in reverse order for efficiency
    std::vector<uint64_t> _chunks;
};

std::string factorial(int n)
{
    if (n < 0) return "";
    else
    {
        decimal_bignum num = 1;
        while (n > 1) {
            num *= n;
            n--;
        }
        return num.str();
    }
}
