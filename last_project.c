#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int shirtNumber;
    char position[20];
    int age;
    int goals;
} player;

player team[100] = {
    {1, "Lionel Messi",   10, "Forward",   36, 800},
    {2, "Cristiano Ronaldo", 7, "Forward", 39, 850},
    {3, "Kylian Mbappe",  7, "Forward",   25, 250},
    {4, "Kevin De Bruyne", 17, "Midfield", 32, 150},
    {5, "Virgil van Dijk", 4, "Defender",  32, 50}
}; 

int next_id = 6;

int Add_player(int count) {
    if (count >= 100) {
        printf("No space to add more players!\n");
        return count;
    }

    team[count].id = next_id++;
    printf("------------ id = %d ----------------\n", team[count].id);

    printf("Enter your player name : ");
    scanf(" %[^\n]", team[count].name);

    printf("Enter your player age : ");
    scanf("%d", &team[count].age);

    printf("Enter your player shirt number : ");
    scanf("%d", &team[count].shirtNumber);

    printf("Enter your player position : ");
    scanf(" %[^\n]", team[count].position);

    printf("Enter your player goals : ");
    scanf("%d", &team[count].goals);

    printf("Player added successfully!\n");
    return count + 1;
}

int add_multiple_players(int count) {
    int how_many;
    printf("How many players do you want to add? ");
    scanf("%d", &how_many);

    for (int i = 0; i < how_many; i++) {
        count = Add_player(count);
    }
    return count;
}

void Display_players(int count){
    player temp;
    int Dis_choise;
    printf("1. Sort players alphabetically (Name).\n");
    printf("2. Sort players by age.\n");
    printf("3. Display players by position.\n");
    scanf("%d", &Dis_choise);

    if(Dis_choise == 1){
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(team[i].name, team[j].name) > 0) {
                    temp = team[i];
                   team[i] =team[j];
                   team[j] = temp;
                }
            }
            printf("---------------- id : %d ------------------\n", team[i].id);
            printf("name : %s\n", team[i].name);
            printf("shirt number : %d\n", team[i].shirtNumber);
            printf("position : %s\n", team[i].position);
            printf("age : %d\n", team[i].age);
            printf("goals : %d\n", team[i].goals);
            printf("--------------------------------------------\n");
        }
    }else if(Dis_choise == 2){
        for(int i = 0; i < count; i++){
            for(int j = i + 1; j < count; j++){
                if(team[i].age > team[j].age){
                    temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                }
            }
            printf("---------------- id : %d ------------------\n", team[i].id);
            printf("name : %s\n", team[i].name);
            printf("shirt number : %d\n", team[i].shirtNumber);
            printf("position : %s\n", team[i].position);
            printf("age : %d\n", team[i].age);
            printf("goals : %d\n", team[i].goals);
            printf("--------------------------------------------\n");
        }
    }else if(Dis_choise == 3){
        for(int i = 0; i < count; i++){
            for(int j = i + 1; j < count; j++){
                if(strcmp(team[i].position, team[j].position) > 0){
                    temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                }
            }
            printf("---------------- id : %d ------------------\n", team[i].id);
            printf("name : %s\n", team[i].name);
            printf("shirt number : %d\n", team[i].shirtNumber);
            printf("position : %s\n", team[i].position);
            printf("age : %d\n", team[i].age);
            printf("goals : %d\n", team[i].goals);
            printf("--------------------------------------------\n");
        }
    }
}

void Edit_player(int count){
    int Edit_chois = 0;

    printf("1. Change a player's position.\n");
    printf("2. Change a player's age.\n");
    printf("3. Change the number of goals scored by a player.\n");
    scanf("%d", &Edit_chois);

    int Edit_ID;
    printf("Enter player ID :");
    scanf("%d", &Edit_ID);

    if(Edit_chois == 1){
        char Edited_position[10];
        printf("Enter edited position : ");
        scanf("%s", Edited_position);

        for(int i = 0; i < count; i++){
            if(team[i].id == Edit_ID){
                strcpy(team[i].position, Edited_position);
            }
        }
        printf("position edited succesfully ! \n");
    }else if(Edit_chois == 2){
        int Edited_age;
        printf("Enter edited position : ");
        scanf("%s", Edited_age);

        for(int i = 0; i < count; i++){
            if(team[i].id == Edit_ID){
                team[i].age = Edited_age;
            }
        }
        printf("age edited succesfully ! \n");
    }else if(Edit_chois == 3){        
        int Edited_goals;
        printf("Enter edited position : ");
        scanf("%s", Edited_goals);

        for(int i = 0; i < count; i++){
            if(team[i].id == Edit_ID){
                team[i].goals = Edited_goals;
            }
        }
        printf("goals edited succesfully ! \n");
    }
}

int Search_player(int count, int found){
    char Search[20];
    int s_id;
    int c;
    printf("1. Search with name : \n");
    printf("2. Search with id : \n");
    printf("2. Change the number of goals scored by a player. : \n");
    scanf("%d", &c);
    if(c == 1){
        printf("Enter player name : ");
        scanf(" %[^\n]", Search);
        for(int i = 0; i < count; i++){
            if(strcmp(team[i].name, Search) == 0){
                found = i ;
            }
        }
    }else if(c == 2){
        printf("Enter player ID : ");
        scanf("%d", &Search);
        for(int i = 0; i < count; i++){
            if(team[i].id == s_id){
                found = i ;
            }
        }
    }
    return found;
}

int main() {
    int choice;
    int count = 5;
    int found = 0;
    int running = 1;

    while (running) {
        printf("\n/////////// Menu Team Management ///////////\n");
        printf("1. Add a player\n");
        printf("2. Display all players\n");
        printf("3. Edit a player\n");
        printf("4. Search for a player\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int add;
                printf("1. Add single player\n");
                printf("2. Add multiple players\n");
                scanf("%d", &add);

                if (add == 1)
                    count = Add_player(count);
                else if (add == 2)
                    count = add_multiple_players(count);
                break;
            }
            case 2:
                Display_players(count);
                break;
            case 3:
                Edit_player(count);
                break;
            case 4:
                found = Search_player(count, found);
                printf("%d", found);
                break;
            case 7:
                running = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}
