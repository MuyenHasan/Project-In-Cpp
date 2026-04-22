#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// User structure
struct User {
    std::string username;
    std::string password;
    std::string email;
};

// File to store user data
const std::string DATA_FILE = "users.txt";

// Load users from file
std::vector<User> loadUsers() {
    std::vector<User> users;
    std::ifstream file(DATA_FILE);
    User user;
    
    while (file >> user.username >> user.password >> user.email) {
        users.push_back(user);
    }
    file.close();
    return users;
}

// Save users to file
void saveUsers(const std::vector<User>& users) {
    std::ofstream file(DATA_FILE);
    for (const auto& user : users) {
        file << user.username << " " << user.password << " " << user.email << "\n";
    }
    file.close();
}

// Check if username exists
bool usernameExists(const std::vector<User>& users, const std::string& username) {
    return std::any_of(users.begin(), users.end(), 
        [&username](const User& u) { return u.username == username; });
}

// Register new user
bool registerUser(const std::vector<User>& users) {
    User newUser;
    
    std::cout << "\n=== Registration ===\n";
    std::cout << "Username: ";
    std::cin >> newUser.username;
    
    if (usernameExists(users, newUser.username)) {
        std::cout << "Error: Username already exists!\n";
        return false;
    }
    
    std::cout << "Password: ";
    std::cin >> newUser.password;
    
    std::cout << "Email: ";
    std::cin >> newUser.email;
    
    // Save to file
    std::ofstream file(DATA_FILE, std::ios::app);
    file << newUser.username << " " << newUser.password << " " << newUser.email << "\n";
    file.close();
    
    std::cout << "Registration successful!\n";
    return true;
}

// Login user
bool loginUser(const std::vector<User>& users) {
    std::string username, password;
    
    std::cout << "\n=== Login ===\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            std::cout << "Login successful! Welcome, " << username << "!\n";
            return true;
        }
    }
    
    std::cout << "Invalid username or password!\n";
    return false;
}

// Main menu
void showMenu() {
    std::cout << "\n========== Menu ==========\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose: ";
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Welcome to C++!" << std::endl;
    std::cout << "Happy coding!" << std::endl;
    return 0;
}