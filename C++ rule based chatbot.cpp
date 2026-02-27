#include <iostream>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Convert string to lowercase
string toLowerCase(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

string getJoke() {
    string jokes[] = {
            "Why do programmers prefer dark mode? Because light attracts bugs!",
            "Why don't skeletons fight each other? They don't have the guts.",
		    "Why did the coffee file a police report? It got mugged."
		};
        return jokes[rand() % 3];
}

string getQuote() {  
    string quotes[] = {
            "Code is like humor. When you have to explain it, it’s bad.",
            "First, solve the problem. Then, write the code.",
            "Experience is the name everyone gives to their mistakes."
        };
        return quotes[rand() % 3];
}

// Get chatbot response
string getResponse(string input) {
    input = toLowerCase(input);

    if (input.find("hello") != string::npos || input.find("hi") != string::npos)
        return "Hello! How can I help you today?";

    if (input.find("how are you") != string::npos)
        return "I'm doing well, thank you for asking! How about you?";

    if (input.find("joke") != string::npos) {
        return getJoke();
    }

    if (input.find("quote") != string::npos) {
        return getQuote();
    }

    if (input.find("math") != string::npos) {
        double num1, num2;
        char op;
        cout << "Enter expression (e.g., 5 + 3): ";
        cin >> num1 >> op >> num2;

        switch(op) {
            case '+': cout << "Result: " << num1 + num2 << endl; break;
            case '-': cout << "Result: " << num1 - num2 << endl; break;
            case '*': cout << "Result: " << num1 * num2 << endl; break;
            case '/': 
                if(num2 != 0){
				cout << "Result: " << num1 / num2 << endl;
				} 
                else{
				cout << "Error: Division by zero!" << endl;
                }
				break;
            default: cout << "Invalid operator!" << endl;
        }
        return "Anything else I can help you with?";
    }

    if (input == "exit")
        return "exit";

    return "Sorry, I don't understand that. Try asking something else!";
}

int main() {
    srand(time(0));
    string userInput;

    cout << "===== Welcome to C++ Chatbot =====" << endl;
    cout << "Type 'exit' to quit.\n" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        string response = getResponse(userInput);

        if (response == "exit") {
            cout << "Bot: Goodbye! Have a great day!" << endl;
            break;
        }

        cout << "Bot: " << response << endl;
    }

    return 0;
}
