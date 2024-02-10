#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> ranks = {"6", "7", "8", "9", "10", "J", "Q", "K", "A"};
vector<string> suits = {"♦", "♥", "♠", "♣"};
vector<string> ranknames = {"6", "7", "8", "9", "10",
                            "jack", "queen", "king", "ace"};
vector<string> suitnames = {"diamonds", "hearts", "spades", "clubs"};

class Card
{
private:
  string suit;
  string rank;
  string suitname;
  string rankname;
  int value;

public:
  Card(string suit, string rank) : suit(suit), rank(rank)
  {
    suitname = suitnames[std::distance(
        suits.begin(), std::find(suits.begin(), suits.end(), suit))];
    rankname = ranknames[std::distance(
        ranks.begin(), std::find(ranks.begin(), ranks.end(), rank))];
    value = set_value(rank);
  }

  int set_value(string rank)
  {
    if (rank == "10" || rank == "Q" || rank == "K")
    {
      return 10;
    }
    if (rank == "A")
    {
      return 15;
    }
    if (rank == "J")
    {
      return 20;
    }
    return 0;
  }

  string toString() { return suit + rank; }

  void set_suitname(string suit)
  {
    suitname = suitnames[std::distance(
        suits.begin(), std::find(suits.begin(), suits.end(), suit))];
  }

  void set_rankname(string rank)
  {
    rankname = ranknames[std::distance(
        ranks.begin(), std::find(ranks.begin(), ranks.end(), rank))];
  }

  string get_suitname() const { return suitname; }

  string get_rankname() const { return rankname; }
};

class JsuitChooser
{
private:
  vector<string> suits;
  string suit;

public:
  JsuitChooser()
  {
    suits = {"♦", "♥", "♠", "♣"};
    suit = "";
  }

  void toggle()
  {
    std::rotate(suits.begin(), suits.begin() + 1, suits.end());
    suit = suits[0];
  }

  void toggle_to(string target_suit)
  {
    while (suit != target_suit)
    {
      toggle();
    }
    suit = suits[0];
  }

  void clear_suit() { suit = ""; }

  string get_suit() const { return suit; }
};

class EightChooser
{
private:
  vector<char> eights;
  char decision;

public:
  EightChooser()
  {
    eights = {'a', 'n'};
    decision = '\0';
  }

  void toggle()
  {
    std::rotate(eights.begin(), eights.begin() + 1, eights.end());
    decision = eights[0];
  }

  void toggle_to(char dec)
  {
    while (decision != dec)
    {
      toggle();
    }
    decision = eights[0];
  }

  void clear_decision() { decision = '\0'; }

  char get_decision() const { return decision; }
};

class BridgeChooser
{
private:
  vector<char> bridge;
  char decision;

public:
  BridgeChooser()
  {
    bridge = {'y', 'n'};
    decision = '\0';
  }

  void toggle()
  {
    std::rotate(bridge.begin(), bridge.begin() + 1, bridge.end());
    decision = bridge[0];
  }

  void toggle_to(char dec)
  {
    while (decision != dec)
    {
      toggle();
    }
    decision = bridge[0];
  }

  void clear_decision() { decision = '\0'; }

  char get_decision() const { return decision; }
};

class JpointsChooser
{
private:
  vector<char> jpoints;
  char decision;

public:
  JpointsChooser()
  {
    jpoints = {'m', 'p'};
    decision = '\0';
  }

  void toggle()
  {
    std::rotate(jpoints.begin(), jpoints.begin() + 1, jpoints.end());
    decision = jpoints[0];
  }

  void toggle_to(char dec)
  {
    while (decision != dec)
    {
      toggle();
    }
    decision = jpoints[0];
  }

  void clear_decision() { decision = '\0'; }

  char get_decision() const { return decision; }
};

class RoundChooser
{
private:
  vector<char> round;
  char decision;

public:
  RoundChooser()
  {
    round = {'n', 'c'};
    decision = '\0';
  }

  void toggle()
  {
    std::rotate(round.begin(), round.begin() + 1, round.end());
    decision = round[0];
  }

  void toggle_to(char dec)
  {
    while (decision != dec)
    {
      toggle();
    }
    decision = round[0];
  }

  void clear_decision() { decision = '\0'; }

  char get_decision() const { return decision; }
};

int main()
{
  RoundChooser chooser;
  std::cout << "Initial decision: " << chooser.get_decision() << std::endl;
  chooser.toggle();
  std::cout << "After toggle: " << chooser.get_decision() << std::endl;
  chooser.toggle_to('c');
  std::cout << "After toggling to 'c': " << chooser.get_decision() << std::endl;
  chooser.clear_decision();
  std::cout << "After clearing decision: " << chooser.get_decision()
            << std::endl;

  return 0;
}
