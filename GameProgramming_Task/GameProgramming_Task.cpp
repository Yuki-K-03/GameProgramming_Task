#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Slime.h"
#include "Demon.h"
#include "Sword.h"
#include "Spear.h"
using namespace std;

enum e_Monster {
    e_Slime = 0,
    e_Demon = 1,
};

void ShowStatus(Character& character) {
    printf("-----------\n");
    printf("%s\n", character.getName());
    printf("HP  : %3d\n", character.getHp());
    printf("ATK : %3d\n", character.getAttack());
    printf("DEF : %3d\n", character.getDefense());
    printf("-----------\n");
}

int main()
{
    srand((unsigned int)time(NULL));


    Sword sword;
    Spear spear;
    // 武器選択
    int select = 0;
    while (1 > select || select > 2) {
        printf("どの武器を装備しますか？\n");
        printf("1 %s, 2 %s\n", sword.getName(), spear.getName());
        cin >> select;
    }

    Player player("Hero", &sword);
    Slime slime;
    Demon demon;
    Enemy* enemy;

    // 戦闘相手選択
    select = 0;
    while (1 > select || select > 2) {
        printf("どちらと戦いますか？\n");
        printf("1 %s, 2 %s\n", slime.getName(), demon.getName());
        cin >> select;
    }
    select--;

    switch (select)
    {
    case e_Slime:
        enemy = &slime;
        break;
    case e_Demon:
        enemy = &demon;
        break;
    default:
        printf("戦闘相手選択エラー\n");
        return 1;
        break;
    }

    // ゲーム開始
    int turn = 0;
    do {
        printf("=====%2dターン目=====\n", ++turn);
        ShowStatus(player);
        ShowStatus(*enemy);
    } while (!player.Play(*enemy) && !slime.Play(player));

    ShowStatus(player);
    ShowStatus(*enemy);

    return 0;
}