#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdint>

int main()
{
    std::ifstream f_names("files/22.txt");

    std::string str_names; 
    std::getline(f_names, str_names);

    std::vector<std::string> names;

    std::stringstream stream(str_names);
    std::string intermediate;

    while (std::getline(stream, intermediate, ',')) names.push_back(intermediate);

    std::sort(names.begin(), names.end());

    std::vector<std::string>::iterator it;

    for (it = names.begin(); it != names.end(); ++it)
        *it = it->substr(1, it->size() - 2);



    uint64_t result = 0;
    for (int i = 0; i < names.size(); i++) {
        uint32_t name_size = 0;
        for (int j = 0; j < names[i].size(); j++) name_size += names[i][j] & 31;
        result += name_size * (i + 1);
    }

    std::cout << result << std::endl;
}
