#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Game {
public:
    Game(const std::string& title, const std::string& genre, double rating, int hours)
        : title(title), genre(genre), rating(rating), hours(hours) {}

    const std::string& getTitle() const {
        return title;
    }

    double getRating() const {
        return rating;
    }

    int getHours() const {
        return hours;
    }

    void print() const {
        std::cout << std::left
                  << std::setw(20) << title
                  << " | "
                  << std::setw(12) << genre
                  << " | Rating: "
                  << std::fixed << std::setprecision(1)
                  << rating
                  << " | "
                  << hours << " hours\n";
    }

private:
    std::string title;
    std::string genre;
    double rating;
    int hours;
};

class GameLibrary {
public:
    void addGame(const std::string& title, const std::string& genre, double rating, int hours) {
        games.emplace_back(title, genre, rating, hours);
    }

    void sortByRating() {
        std::sort(games.begin(), games.end(),
            [](const Game& a, const Game& b) {
                return a.getRating() > b.getRating();
            });
    }

    int totalHours() const {
        int total = 0;

        for (const auto& game : games) {
            total += game.getHours();
        }

        return total;
    }

    double averageRating() const {
        if (games.empty()) {
            return 0.0;
        }

        double total = 0.0;

        for (const auto& game : games) {
            total += game.getRating();
        }

        return total / games.size();
    }

    void printReport() const {
        std::cout << "Game Library\n";
        std::cout << "============\n";

        for (const auto& game : games) {
            game.print();
        }

        std::cout << "============\n";
        std::cout << "Games: " << games.size() << '\n';
        std::cout << "Total Hours: " << totalHours() << '\n';
        std::cout << "Average Rating: "
                  << std::fixed << std::setprecision(2)
                  << averageRating() << '\n';
    }

private:
    std::vector<Game> games;
};

int main() {
    GameLibrary library;

    library.addGame("Cyber World", "Action", 9.1, 42);
    library.addGame("Lost Kingdom", "RPG", 8.7, 68);
    library.addGame("Speed Legends", "Racing", 8.4, 25);
    library.addGame("Space Mission", "Adventure", 9.3, 35);

    library.sortByRating();
    library.printReport();

    return 0;
}