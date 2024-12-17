#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

std::pair<std::set<int>, std::set<int>> parser(const std::string &filepath) {
    std::ifstream inputFile(filepath);
    if (!inputFile) {
        std::cerr << "Unable to open file\n";
    }

    // auto comp = [](const int a, const int b) { return a < b; };
    std::set<int> leftList;
    std::set<int> rightList;

    std::string line;
    while (std::getline(inputFile, line)) {
        int num_1 = stoi(line.substr(0, 5)); // First 5 chars as integer
        leftList.insert(num_1);

        int num_2 = stoi(line.substr(8, 5)); // Starting at 8th position, 5 chars
        rightList.insert(num_2);
    }
    cout << "Left List : " << leftList.size() << '\n';
    cout << "Right List: " << rightList.size() << '\n';
    
    return std::make_pair(leftList, rightList); // Corrected return statement
}

template<typename T>
std::vector<T> to_vector(std::set<T>& s) {
    vector<T> v(s.begin(), s.end());
    return v;
}


int getDistance(std::vector<int>& left, std::vector<int>& right) {
    int result = 0;

    int len = (left.size() < right.size())? left.size() : right.size();

    for(int i=0; i<len; i++){
        result += abs(left[i] - right[i]);
    }

    return result;
}

int main() {
    auto [left, right] = parser("input.txt");

    // cout << "Parsed Left List: ";
    // for (int num : left) cout << num << " ";
    // cout << "\nParsed Right List: ";
    // for (int num : right) cout << num << " ";
    // cout << endl;

    auto leftList = to_vector(left);
    auto rightList = to_vector(right);

    int result = getDistance(leftList, rightList);
    cout<<result<<'\n';

    return 0;
}
