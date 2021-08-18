#include <iostream>

using namespace std;

int main() {
    string name;
    name = "Ислам";
    cout<<"Привет, " + name  << endl;
    
    int score = 0, bot_score = 0;
    bool game = true;
    while (game == true) {
        cout << "1 - камень, 2 - ножницы, 3 - бумага, 4 - выход" << endl;
        int command, bot_command;
        cin >> command;
        bot_command = random() % 3 + 1;
        
        if (command == 4) {
            cout << "Игра закончена" << endl;
            if (score > bot_score) {
                cout << "Вы победили";
            }
            break;
        }
        
        if (command % 3 - bot_command == -1) {
            score += 1;
        } else 
        if (command == bot_command) {
            score += 1;
            bot_score += 1;
        } else {
            bot_score += 1;
        }
        cout << "Бот выбрал: " << bot_command << endl; 
        cout << name + ": " << score << " | Противник: " << bot_score << endl;
        
    }

    return 0;
}
