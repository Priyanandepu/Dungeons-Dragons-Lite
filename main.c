#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int roll_dice(int sides) {
    return (rand() % sides) + 1;
}

// Function to create the character
void create_character(int *strength, int *health) {
    printf("Rolling for your character's stats...\n");
    *strength = roll_dice(6) + roll_dice(6) + roll_dice(6);
    *health = roll_dice(6) + roll_dice(6) + roll_dice(6);
    printf("Your character's Strength: %d, Health: %d\n", *strength, *health);
}

// Function to create the monster
void create_monster(int *strength, int *health) {
    printf("A wild monster appears!\n");
    *strength = roll_dice(6) + 6;
    *health = roll_dice(6) + 10;
    printf("Monster's Strength: %d, Health: %d\n", *strength, *health);
}

// Combat function
void combat(int player_strength, int *player_health, int monster_strength, int *monster_health) {
    while (*player_health > 0 && *monster_health > 0) {
        printf("\nPress Enter to roll for your attack...");
        getchar();

        int player_attack = roll_dice(6) + player_strength;
        int monster_defense = roll_dice(6) + monster_strength;

        printf("You attack with a roll of %d.\n", player_attack);
        printf("The monster defends with a roll of %d.\n", monster_defense);

        if (player_attack > monster_defense) {
            int damage = player_attack - monster_defense;
            *monster_health -= damage;
            if (*monster_health < 0) *monster_health = 0;
            printf("You deal %d damage! Monster's health: %d\n", damage, *monster_health);
        } else {
            printf("Your attack misses!\n");
        }

        if (*monster_health <= 0) {
            printf("\nYou have defeated the monster!\n");
            break;
        }

        printf("\nThe monster attacks!\n");
        int monster_attack = roll_dice(6) + monster_strength;
        int player_defense = roll_dice(6) + player_strength;

        printf("The monster attacks with a roll of %d.\n", monster_attack);
        printf("You defend with a roll of %d.\n", player_defense);

        if (monster_attack > player_defense) {
            int damage = monster_attack - player_defense;
            *player_health -= damage;
            if (*player_health < 0) *player_health = 0;
            printf("The monster deals %d damage! Your health: %d\n", damage, *player_health);
        } else {
            printf("You dodge the attack!\n");
        }

        if (*player_health <= 0) {
            printf("\nYou have been defeated by the monster...\n");
            break;
        }
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generator

    printf("Welcome to Dungeons & Dragons Lite!\n");

    int player_strength, player_health;
    int monster_strength, monster_health;

    create_character(&player_strength, &player_health);
    create_monster(&monster_strength, &monster_health);

    combat(player_strength, &player_health, monster_strength, &monster_health);

    printf("\nGame over. Thanks for playing!\n");

    return 0;
}
