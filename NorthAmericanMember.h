#include <string>
#include <vector>

#ifndef NAM_HEADER
#define NAM_HEADER

class NorthAmericanMember {
    public:
        string name;
        vector<char> strategy;
        int strength;
        bool sorMember;
        bool ptMember;

        NorthAmericanMember(string _name, int _strength, vector<char> _strategy, bool _rockschool, bool _tiger) {
            name = _name;
            strategy = _strategy;
            strength = _strength;
            sorMember = _rockschool;
            ptMember = _tiger;
        }

        bool operator<(const NorthAmericanMember& defender) {
            if (defender.sorMember || defender.ptMember) {
                throw Punches(this->strength, defender.strength);
            }
            // s > r > p
            int defenderWins = 0;
            int thisWins = 0;
            for (int i = 0; i < defender.strategy.size(); i++) {
                if (defender.strategy.at(i) == 's') {
                    if (this->strategy.at(i) == 'p') {
                        defenderWins++;
                    } else if (this->strategy.at(i) == 'r') {
                        thisWins++;
                    }
                } else if (defender.strategy.at(i) == 'r') {
                    if (this->strategy.at(i) == 's') {
                        defenderWins++;
                    } else if (this->strategy.at(i) == 'p') {
                        thisWins++;
                    }
                } else { // paper
                    if (this->strategy.at(i) == 'p') {
                        defenderWins++;
                    } else if (this->strategy.at(i) == 's') {
                        thisWins++;
                    }
                }
                if (defenderWins >= 3) {
                    return true;
                } else if (attackerWins >= 3) {
                    return false;
                }
            }
            if (defenderWins > thisWins) {
                return true;
            } else if (defenderWins == thisWins) {
                return true;
            } else {
                return false;
            }
        }

        ostream& operator<<(ostream& out, const NorthAmericanMember& member) {
            cout << member.name;
            if (member.ptMember) {
                cout << " (Paper Tigers)";
            } else if (member.sorMember) {
                cout << " (School of Rock)";
            }
            cout << endl;
        }

}

#endif