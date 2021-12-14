#ifndef IRPS_HEADER
#define IRPS_HEADER
using namespace std;
template <class T>
class IRPSSHierarchy {
    public:
        T member;
        IRPSSHierarchy *left;
        IRPSSHierarchy *right;

        IRPSSHierarchy(T _member) {
            member = T(_member);
            left = NULL;
            right = NULL;
        }

        void Insert(T new_member) {
            try {
                if (new_member >= this->member) {
                    if (left) {
                        left->Insert(new_member);
                    } else {
                        left = new IRPSSHierarchy(new_member);
                    }
                } else {
                    if (right) {
                        right->Insert(new_member);
                    } else {
                        right = new IRPSSHierarchy(new_member);
                    }
                }
            } catch(Punches& punch) {
                cout << punch.what() << endl;
                if (e.defender <= e.challenger) {
                    member = new_member;
                }
            }
        }

        friend ostream& operator<<(ostream& out, const IRPSSHierarchy& hierarchy) {
            if (hierarchy.left) {
                out << *(hierarchy.left)
            }
            out << hierarchy.member << endl;
            if (hierarchy.right) {
                out << *(hierarchy.right); 
            }
            return out;
        }
}

#endif