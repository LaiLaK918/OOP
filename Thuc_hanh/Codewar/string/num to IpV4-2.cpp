#include<sstream>
#include<bitset>

std::string uint32_to_ip(uint32_t ip)
{
	std::bitset<32> n(2149583361);
	std::stringstream ss;
	ss << n;
	std::string bin;
	ss >> bin;
	std::string res;
	for (int i = 0; i < 32; i += 8) {
		std::string tmp = bin.substr(i, 8);
		res.append(std::to_string(std::stoi(tmp, nullptr, 2)));
		res.append(".");
	}
	res.pop_back();
	return res;
}
