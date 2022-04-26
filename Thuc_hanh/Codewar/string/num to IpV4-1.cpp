#include <sstream>

std::string uint32_to_ip(uint32_t ip)
{
  std::stringstream result{};
  result << (ip >> 24) << '.' << (ip >> 16 & 0xFF) << '.' 
      << (ip >> 8 & 0xFF ) << '.' << (ip & 0xFF);
  return result.str();
}
