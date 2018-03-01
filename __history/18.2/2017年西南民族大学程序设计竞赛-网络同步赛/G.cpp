using namespace std;
#include<string>
#include<iostream>
#include<map>

const string win = "Alice";
const string lose = "Bob";
const string draw = "Draw";
map<string, string> ke_zhi;
int score[2];
string tmp1, tmp2;
int main() {
    int n;
    ke_zhi["Jin"] = "Mu";
    ke_zhi["Mu"] = "Tu";
    ke_zhi["Tu"] = "Shui";
    ke_zhi["Shui"] = "Huo";
    ke_zhi["Huo"] = "Jin";
    cin >> n;
    
    while (n--) {
        cin>>tmp1>>tmp2;
        if (ke_zhi[tmp1] == tmp2) {
            score[0] += 3;
        } else if(ke_zhi[tmp2] == tmp1) {
            score[1] += 3;
        }
    }
    
    if (score[0] > score[1]) {
        cout<<win;
    } else if (score[0] < score[1]) {
        cout<<lose;
    } else {
        cout<<draw;
    }
    return 0;
    
}

//win的时候cout了draw
//交之前检查一下 
