#include <iostream>
#include <string>

using namespace std;

struct Hero {
    string name;
    int level;
    int health;
    int attack;

    Hero(string n, int lvl, int hp, int atk)
        : name(n), level(lvl), health(hp), attack(atk) {}
};

void fight(Hero& attacker, Hero& defender) {
    cout << attacker.name << " атакует " << defender.name << endl;
    defender.health -= attacker.attack;

    if (defender.health <= 0) {
        defender.health = 0;
        cout << defender.name << " убит" << endl;
    }
    else {
        cout << "Теперь у " << defender.name << ": " << defender.health << " здоровья" << endl;
    }
}

void printHero(const Hero& hero) {
    cout << "Герой: " << hero.name
        << ", Уровень: " << hero.level
        << ", Здоровье: " << hero.health
        << ", Атака: " << hero.attack << endl;
}

int main()
{
    Hero heroes[3] = {
        Hero("Такса", 3, 50, 15),
        Hero("Пушистая такса", 8, 70, 20),
        Hero("Очень пушистая такса", 19, 100, 28)
    };

    cout << "Все герои:" << endl;
    for (int i = 0; i < 3; ++i) {
        printHero(heroes[i]);
    }

    int attackerIndex, defenderIndex;
    cout << "\nВыберите атакующего героя (число от 0 до 2): ";
    cin >> attackerIndex;
    cout << "Выберите защищающегося героя (число от 0 до 2): ";
    cin >> defenderIndex;

    if (attackerIndex >= 0 && attackerIndex < 3 &&
        defenderIndex >= 0 && defenderIndex < 3 &&
        attackerIndex != defenderIndex) {
        fight(heroes[attackerIndex], heroes[defenderIndex]);
    }
    else {
        cout << "Неверное значение" << endl;
    }

    cout << "Состояние героев:" << endl;
    for (int i = 0; i < 3; ++i) {
        printHero(heroes[i]);
    }

    return 0;
}
