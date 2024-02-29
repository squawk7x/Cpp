#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>


using namespace std;

vector<string> ranks = {"6", "7", "8", "9", "10", "J", "Q", "K", "A"};
vector<string> suits = {"♦", "♥", "♠", "♣"};
vector<string> ranknames = {"6",    "7",     "8",    "9",  "10",
                            "jack", "queen", "king", "ace"};
vector<string> suitnames = {"diamonds", "hearts", "spades", "clubs"};

class Card{
// private:
public:
    string suit;
    string rank;
    string suitname;
    string rankname;
    int value;

// public:
    Card(string suit, string rank) : suit(suit), rank(rank) {
        suitname = suitnames[distance(suits.begin(),
                                      find(suits.begin(), suits.end(), suit))];
        rankname = ranknames[distance(ranks.begin(),
                                      find(ranks.begin(), ranks.end(), rank))];
        value = set_value(rank);
    }

    int set_value(string rank) {
        if (rank == "10" || rank == "Q" || rank == "K") {
            return 10;
        }
        if (rank == "A") {
            return 15;
        }
        if (rank == "J") {
            return 20;
        }
        return 0;
    }

    string toString() const {
        return suit + rank;
    }

    void set_suitname(string suit) {
        suitname = suitnames[distance(suits.begin(),
                                      find(suits.begin(), suits.end(), suit))];
    }

    void set_rankname(string rank) {
        rankname = ranknames[distance(ranks.begin(),
                                      find(ranks.begin(), ranks.end(), rank))];
    }

    string get_suitname() const {
        return suitname;
    }

    string get_rankname() const {
        return rankname;
    }
};

class JsuitChooser {
private:
    vector<string> suits;
    string suit;

public:
    JsuitChooser() {
        suits = {"♦", "♥", "♠", "♣"};
        suit = "";
    }

    void toggle() {
        rotate(suits.begin(), suits.begin() + 1, suits.end());
        suit = suits[0];
    }

    void toggle_to(string target_suit) {
        while (suit != target_suit) {
            toggle();
        }
        suit = suits[0];
    }

    void clear_suit() {
        suit = "";
    }

    string get_suit() const {
        return suit;
    }
};

JsuitChooser jsuitChooser;

class EightChooser {
private:
    vector<string> eights;

public:
    string decision;

    EightChooser() {
        eights = {"a", "n"};
        decision = "\0";
    }

    void toggle() {
        rotate(eights.begin(), eights.begin() + 1, eights.end());
        decision = eights[0];
    }

    void toggle_to(string dec) {
        while (decision != dec) {
            toggle();
        }
        decision = eights[0];
    }

    void clear_decision() {
        decision = "\0";
    }

    string get_decision() const {
        return decision;
    }
};

EightChooser eightChooser;

class BridgeChooser {
private:
    vector<string> bridge;

public:
    string decision;

    BridgeChooser() {
        bridge = {"y", "n"};
        decision = "\0";
    }

    void toggle() {
        rotate(bridge.begin(), bridge.begin() + 1, bridge.end());
        decision = bridge[0];
    }

    void toggle_to(string dec) {
        while (decision != dec) {
            toggle();
        }
        decision = bridge[0];
    }

    void clear_decision() {
        decision = "\0";
    }

    string get_decision() const {
        return decision;
    }
};

BridgeChooser bridgeChooser;

class JpointsChooser {
private:
    vector<string> jpoints;

public:
    string decision;

    JpointsChooser() {
        jpoints = {"m", "p"};
        decision = "\0";
    }

    void toggle() {
        rotate(jpoints.begin(), jpoints.begin() + 1, jpoints.end());
        decision = jpoints[0];
    }

    void toggle_to(string dec) {
        while (decision != dec) {
            toggle();
        }
        decision = jpoints[0];
    }

    void clear_decision() {
        decision = "\0";
    }

    string get_decision() const {
        return decision;
    }
};

JpointsChooser jpointsChooser;
class RoundChooser {
private:
    vector<string> round;

public:
    string decision;

    RoundChooser() {
        round = {"n", "c"};
        decision = "\0";
    }

    void toggle() {
        rotate(round.begin(), round.begin() + 1, round.end());
        decision = round[0];
    }

    void toggle_to(string dec) {
        while (decision != dec) {
            toggle();
        }
        decision = round[0];
    }

    void clear_decision() {
        decision = "\0";
    }

    string get_decision() const {
        return decision;
    }
};

RoundChooser roundChooser;

class Deck {
private:
    vector<Card> blind;
    vector<Card> stack;
    vector<Card> cards_played;
    vector<Card> bridge_monitor;
    int shuffles;
    bool is_visible;

public:
    Deck(vector<Card> blind = vector<Card>(), vector<Card> stack = vector<Card>()) {
        if (blind.empty()) {
            for (const string& suit : suits) {
                for (const string& rank : ranks) {
                    Card card(suit, rank);
                    blind.push_back(card);
                }
            }
            shuffle_blind();
        } else {
            this->blind = blind;
        }

        if (stack.empty()) {
            // No need to initialize stack
        } else {
            this->stack = stack;
        }

        cards_played.clear();
        bridge_monitor.clear();
        shuffles = 1;
        is_visible = false;
    }

    void toggle_is_visible() {
        is_visible = !is_visible;
    }

    void shuffle_blind() {
        random_device rd;
        mt19937 g(rd());
        shuffle(blind.begin(), blind.end(), g);
    }

    string stack_as_str() {
        string stack_str;
        for (const Card& card : stack) {
            stack_str += card.toString() + " ";
        }
        return stack_str;
    }
    
    string blind_as_str() {
        string blind_str;
        for (const Card& card : blind) {
            blind_str += card.toString() + " ";
        }
        return blind_str;
    }

    Card card_from_blind() {
        if (blind.empty()) {
            blind = stack;
            stack.clear();
            stack.push_back(blind.back());
            blind.pop_back();
            shuffle_blind();
            shuffles += 1;
        }
        if (!blind.empty()) {
            Card card = blind.back();
            blind.pop_back();
            return card;
        }
        cout << "not enough cards available\n";
        exit(EXIT_FAILURE);
    }

    void put_card_on_stack(const Card& card) {
        jpointsChooser.clear_decision();
        bridgeChooser.clear_decision();
        eightChooser.clear_decision();
        jsuitChooser.clear_suit();

        // Play audio
        // if (is_sound_on()) {
            // Play audio

        stack.push_back(card);
        cards_played.push_back(card);
        update_bridge_monitor(card);

        cout << bridge.player.name << " has played " << card.toString() << endl;
        cout << "stack: " << stack_as_str() << endl;
        cout << "blind: " << blind_as_str() << endl;

        if (bridge_monitor.size() == 4) {
            bridge.ask_for_bridge();
        }

        if (get_top_card_from_stack().rank == "J" && cards_played.size() > 0 && bridge.player.hand.cards.size() > 0) {
            bridge.ask_for_jsuit();
        }

        if (cards_played.size() >= 2 && bridge_monitor.size() >= 2 && get_top_card_from_stack().rank == "8") {
            eightChooser.toggle();
        }

        if (get_top_card_from_stack().rank == "J" && (bridge.player.hand.cards.size() == 0 || bridge_monitor.size() == 4)) {
            jpointsChooser.toggle();
        }

        if (bridge.player.hand.cards.size() == 0 && get_top_card_from_stack().rank != "6" && !bridgeChooser.decision) {
            roundChooser.decision = "delay";
        }
    }
    Card get_top_card_from_stack() {
        if (!stack.empty()) {
            return stack.back();
        }
    }

    void update_bridge_monitor(const Card& card) {
        if (!card || bridge_monitor.empty() || card.rank != bridge_monitor[0].rank) {
            bridge_monitor.clear();
        }
        bridge_monitor.push_back(card);
    }
};

Deck deck;


int main() {
    Card card("♥", "7");
    cout << card.toString() << endl;

    return 0;
}

