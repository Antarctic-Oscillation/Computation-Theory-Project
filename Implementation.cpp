#include <iostream>
#include <regex>

#define FAST                               \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

void MachineAccepting(std::string str);

unsigned short choice;
bool valid = true;

int main() {
    FAST;

    while(valid) {
        std::cout << "-----------------------------------------\n";
        std::cout << "Enter your preferred choice to match.\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "1) All strings such that the fourth to last symbol is always a 'b'\n";
        std::cout << "2) All strings in which every run of 'a' has length at least 3\n";
        std::cout << "3) end program" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                MachineAccepting("(a|b)*b(a|b)(a|b)(a|b)");
                break;
            case 2:
                MachineAccepting("(b|((aaa)(a)*))*");
                break;
            default:
                valid = false;
                break;
        }
    }
    std::cout << "======================================================";
    return 0;
}

void MachineAccepting(std::string str) {
    std::cout << "========================== ("<< choice <<") ===========================\n";
    std::cout << "Enter your patterns. type 'return' to return to menue." << std::endl;
    std::string input;
    
    while (true) {
        std::cin >> input;
        if (input == "return") break;

        std::regex pattern(str);

        if (std::regex_match(input, pattern)) {
            std::cout << "-> Accepted." << std::endl;
        } else {
            std::cout << "-> Rejected." << std::endl;
        }
    }
}
