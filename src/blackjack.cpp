#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const unordered_map<string, int> CARD_VALUES = {
    {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
    {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
    {"J", 10}, {"Q", 10}, {"K", 10}
};

int main() {
    int num_players;
    cout << "Enter number of players (including dealer): ";
    cin >> num_players;

    vector<int> player_scores(num_players, 0);
    vector<bool> can_hit(num_players, true);

    // Initial two cards for all players
    for (int round = 0; round < 2; ++round) {
        for (int player = 0; player < num_players; ++player) {
            string card;
            cin >> card;
            player_scores[player] += CARD_VALUES.at(card);
        }
    }

    // Player turns (excluding dealer at index 0)
    for (int player = 1; player < num_players; ++player) {
        while (can_hit[player]) {
            if (player_scores[player] > 21) {
                can_hit[player] = false;
                break;
            }

            cout << "Player " << player << ": Hit or Stand? ";
            string action;
            cin >> action;

            if (action == "Hit") {
                string card;
                cin >> card;
                player_scores[player] += CARD_VALUES.at(card);
            } else {
                can_hit[player] = false;
            }
        }
    }

    // Dealer's turn (special rules)
    while (can_hit[0]) {
        if (player_scores[0] > 16) {
            can_hit[0] = false;
        } else {
            string card;
            cin >> card;
            player_scores[0] += CARD_VALUES.at(card);
        }
    }

    // Determine results
    vector<string> results(num_players);
    for (int player = 1; player < num_players; ++player) {
        if (player_scores[player] > 21) {
            results[player] = "busted";
        } else if (player_scores[player] > player_scores[0] || player_scores[0] > 21) {
            results[player] = "winner";
        } else {
            results[player] = "loser";
        }
    }

    // Output results
    for (int player = 1; player < num_players; ++player) {
        cout << "Player " << player << ": " << results[player] << endl;
    }

    return 0;
}