#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

// Function declarations
int chooseTheme();
void selectWord(int themeChoice, std::string &chosenWord);
void showHangman(int attempts);
void playGame(const std::string &chosenWord);

// ------------------------------------------------------------
int main() {
    std::srand(std::time(nullptr));
    std::cout << "*************** HANGMAN GAME ***************\n";

    int themeChoice = chooseTheme();
    std::string chosenWord;

    selectWord(themeChoice, chosenWord);
    playGame(chosenWord);

    std::cout << "********************************************\n";
    return 0;
}

// ------------------------------------------------------------

int chooseTheme() {
    std::string themes[] = {"fruits", "countries", "sports", "places"};
    int choice;

    std::cout << "Choose a theme (0-fruits, 1-countries, 2-sports, 3-places): ";
    std::cin >> choice;

    if (choice < 0 || choice > 3) {
        std::cout << "Invalid theme!\n";
        return chooseTheme();
    }

    std::cout << "Chosen theme: " << themes[choice] << '\n';
    return choice;
}

// ------------------------------------------------------------

void selectWord(int themeChoice, std::string &chosenWord) {
    switch (themeChoice) {
        case 0: { // Fruits
            std::string fruits[] = {"banana", "apple", "grape", "orange", "pineapple"};
            chosenWord = fruits[std::rand() % 5];
            break;
        }
        case 1: { // Countries
            std::string countries[] = {"brazil", "canada", "japan", "mexico", "egypt"};
            chosenWord = countries[std::rand() % 5];
            break;
        }
        case 2: { // Sports
            std::string sports[] = {"soccer", "basketball", "volleyball", "tennis", "swimming"};
            chosenWord = sports[std::rand() % 5];
            break;
        }
        case 3: { // Places
            std::string places[] = {"beach", "mountain", "forest", "desert", "city"};
            chosenWord = places[std::rand() % 5];
            break;
        }
        default:
            std::cout << "Invalid option.\n";
            break;
    }
}

// ------------------------------------------------------------

void showHangman(int attempts) {
    std::cout << "\n";

    switch (attempts) {
        case 0:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |        \n"
                         " |        \n"
                         " |        \n"
                         " |        \n"
                         "_|___\n";
            break;
        case 1:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |        \n"
                         " |        \n"
                         " |        \n"
                         "_|___\n";
            break;
        case 2:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |       |\n"
                         " |       |\n"
                         " |        \n"
                         "_|___\n";
            break;
        case 3:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |      \\|\n"
                         " |       |\n"
                         " |        \n"
                         "_|___\n";
            break;
        case 4:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |      \\|/\n"
                         " |       |\n"
                         " |        \n"
                         "_|___\n";
            break;
        case 5:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |      \\|/\n"
                         " |       |\n"
                         " |      / \n"
                         "_|___\n";
            break;
        case 6:
            std::cout << "  _______\n"
                         " |/      |\n"
                         " |      (_)\n"
                         " |      \\|/\n"
                         " |       |\n"
                         " |      / \\\n"
                         "_|___\n";
            break;
    }

    std::cout << "\n";
}

// ------------------------------------------------------------

void playGame(const std::string &chosenWord) {
    std::string display(chosenWord.size(), '_');
    int attempts = 0;
    const int maxAttempts = 6;
    bool correctGuess = false;

    std::cout << "The word has " << chosenWord.size() << " letters.\n";

    while (attempts < maxAttempts && display != chosenWord) {
        std::cout << "\nWord: " << display << '\n';
        std::cout << "Remaining attempts: " << (maxAttempts - attempts) << '\n';
        std::cout << "Enter a letter: ";

        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        correctGuess = false;

        for (size_t i = 0; i < chosenWord.size(); ++i) {
            if (chosenWord[i] == guess && display[i] == '_') {
                display[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            std::cout << "✅ Correct letter!\n";
        } else {
            attempts++;
            std::cout << "❌ Wrong letter!\n";
            showHangman(attempts);
        }
    }

    if (display == chosenWord) {
        std::cout << "\n🎉 Congratulations! You won! The word was: " << chosenWord << '\n';
    } else {
        std::cout << "\n💀 You lost! The word was: " << chosenWord << '\n';
    }
}
