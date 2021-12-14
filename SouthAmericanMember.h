// Aksel Torgerson
// atorgerson

#include <iostream>
#include "Punches.h"
#include <string>
#include <vector>

#ifndef SAM_HEADER
#define SAM_HEADER

using namespace std;

class SouthAmericanMember {
    private:
        string name;
        vector<char> strategy;
        int strength, speed;
        bool sorMember;
        bool ptMember;
    public:

        SouthAmericanMember(){}

        SouthAmericanMember(string _name, int _strength, int _speed, vector<char> _strategy, bool _rockschool, bool _tiger) {
            name = _name;
            strategy = _strategy;
            strength = _strength;
            speed = _speed;
            sorMember = _rockschool;
            ptMember = _tiger;
        }

        bool operator<(const SouthAmericanMember& defender) {
            if ((defender.sorMember && this->ptMember) || (defender.ptMember && this->sorMember)) {
                throw Punches(this->strength, defender.strength, this->speed, defender.speed);
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
                if (defenderWins >= 4) {
                    return true;
                } else if (thisWins >= 4) {
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

        friend ostream& operator<<(ostream& out, const SouthAmericanMember& member) {
            cout << member.name;
            if (member.ptMember) {
                cout << " (Paper Tigers)";
            } else if (member.sorMember) {
                cout << " (School of Rock)";
            }
            cout << endl;
        }

};

#endif