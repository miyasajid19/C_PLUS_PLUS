#include <iostream>
#include <string>

int main() {
    std::string line;
    std::string paragraph;
    
    std::cout << "Enter a paragraph (end input with an empty line):" << std::endl;
    
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;  // End input on empty line
        }
        paragraph += line + "\n";
    }
    
    std::cout << "\nYou entered:\n" << paragraph << std::endl;
    
    return 0;
}
