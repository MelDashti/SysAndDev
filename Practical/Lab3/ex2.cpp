#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;

    bool operator<(const Player &other) const {
        if (score != other.score)
            return score > other.score;
        else
            return name < other.name;
    }
};

class LeaderBoard {
    set<Player> players;
public:
    void addPlayer(const string &name, int score) {
        players.insert(Player{name, score});
    }

    void removePlayer(const string &name) {
        for (auto it = players.begin(); it != players.end(); ) {
            if (it->name == name) {
                it = players.erase(it);
            } else {
                ++it;
            }
        }
    }

    void updateScore(const string &name, int newScore) {
        for (auto it = players.begin(); it != players.end(); ++it) {
            if (it->name == name) {
                players.erase(it);
                players.insert(Player{name, newScore});
                break;
            }
        }
    }

    void printTopPlayers(int n) {
        auto it = players.begin();
        for (int i = 0; i < n && it != players.end(); i++, ++it) {
            cout << it->name << " " << it->score << endl;
        }
    }
};

int main() {
    // Create a leaderboard
    LeaderBoard leaderBoard;
    leaderBoard.addPlayer("Alice", 100);
    leaderBoard.addPlayer("Bob", 200);
    leaderBoard.addPlayer("Charlie", 150);
    leaderBoard.addPlayer("David", 250);
    leaderBoard.addPlayer("Eve", 300);
    leaderBoard.addPlayer("Frank", 250);
    leaderBoard.addPlayer("Grace", 200);
    leaderBoard.addPlayer("Helen", 150);
    // Now we remove a player
    leaderBoard.removePlayer("Charlie");
    // Now we update a player's score
    leaderBoard.updateScore("David", 300);
    // Now we print the top 3 players
    leaderBoard.printTopPlayers(3);

}