#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ANSI escape codes for text colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";

// Function to display a decorative line
void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

// Function for user login
bool login() {
    string username, password;
    const string correctUsername = "ibad";  // Predefined username
    const string correctPassword = "12345";  // Predefined password
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        cout << CYAN;
        printLine('=', 37);
        cout << "           USER LOGIN               " << endl;
        printLine('=', 37);
        cout << RESET;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == correctUsername && password == correctPassword) {
            cout << GREEN << "\nLogin successful! ?\n" << RESET;
            return true;
        } else {
            cout << RED << "\nInvalid username or password. ?\n" << RESET;
            ++attempts;
            if (attempts < maxAttempts) {
                cout << "Please try again. Attempts left: " << (maxAttempts - attempts) << "\n\n";
            }
        }
    }

    cout << RED << "\nMaximum login attempts reached. Exiting program.\n" << RESET;
    return false;
}

// Function to ask a question and check the answer
int askQuestion(const string& question, const string& option1, const string& option2,
                const string& option3, const string& option4, char correctAnswer) {
    char userAnswer;
    cout << "\n" << question << endl;
    cout << "A. " << option1 << endl;
    cout << "B. " << option2 << endl;
    cout << "C. " << option3 << endl;
    cout << "D. " << option4 << endl;

    cout << "Enter your answer (A, B, C, or D): ";
    cin >> userAnswer;

    // Convert to uppercase in case user enters lowercase
    userAnswer = toupper(userAnswer);

    if (userAnswer == correctAnswer) {
        cout << GREEN << "Correct! ?\n" << RESET;
        return 1;  // Return 1 for a correct answer
    } else {
        cout << RED << "Wrong! ? The correct answer was " << correctAnswer << ".\n" << RESET;
        return 0;  // Return 0 for a wrong answer
    }
}

int main() {
    // User login
    if (!login()) {
        return 1; // Exit program if login fails
    }

    int score = 0;

    cout << CYAN;
    printLine('=', 37);
    cout << "      WELCOME TO THE QUIZ GAME      " << endl;
    printLine('=', 37);
    cout << RESET;

    // Asking 5 questions
    score += askQuestion("What is the capital of Pakistan?",
                         "Karachi", "Lahore", "Islamabad", "Quetta", 'C');
    score += askQuestion("Which one is a programming language?",
                         "HTML", "C++", "MS Word", "Excel", 'B');
    score += askQuestion("What does CPU stand for?",
                         "Central Processing Unit", "Computer Personal Unit",
                         "Central Program Unit", "Control Processing Unit", 'A');
    score += askQuestion("Which of the following is an output device?",
                         "Keyboard", "Mouse", "Monitor", "Microphone", 'C');
    score += askQuestion("Which symbol is used to denote a comment in C++?",
                         "//", "/* */", "#", "$", 'A');

    // Display final score
    cout << CYAN;
    cout << "\n";
    printLine('=', 30);
    cout << "       QUIZ GAME OVER!         " << endl;
    cout << "       Your Score: " << score << "/5\n";
    printLine('=', 30);
    cout << RESET;

    return 0;
}

