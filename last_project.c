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

     printf("Enter your player name: ");
     scanf(" %[^\n]", team[count].name);

    printf("Enter your player age : ");
    scanf("%d", &team[count].age);
    if(team[count].age < 0){
        printf("the player can't have this age ! ");
        return count;
    } 

    printf("Enter your player shirt number : ");
    scanf("%d", &team[count].shirtNumber);
    if(team[count].shirtNumber < 0){
        printf("the player can't have this shirt number ! ");
        return count;
    }

    int position;
    printf("1. Goal keeper \n2. Defender \n3. Midfield\n4.Forward\n");
    printf("Enter your player position : ");
    scanf("%d", &position);
    if(position < 0 && position > 4){
        printf("invalid choise !");
        return count;
    }
    switch(position){
        case 1: strcpy(team[count].position, "Goal keeper"); break;
        case 2: strcpy(team[count].position, "Defender"); break;
        case 3: strcpy(team[count].position, "Midfield"); break;    
        case 4: strcpy(team[count].position, "Forward"); break;
    }

    printf("Enter your player goals : ");
    scanf("%d", &team[count].goals);
    if(team[count].goals < 0){
        printf("invalid goals ! ");
        return count;
    }

    printf("Player added successfully!\n");
    return count + 1;
}

int add_multiple_players(int count) {
    int how_many;
    printf("How many players do you want to add? ");
    scanf("%d", &how_many);
    if(how_many < 0){
        printf("wrong input !");
    }

    for (int i = 0; i < how_many; i++) {
        count = Add_player(count);
    }
    return count;
}

void Display_players(int count){
    player temp;
    int Dis_choise;
    
    for(int i = 0; i < count; i++){
        printf("---------------- id : %d ------------------\n", team[i].id);
            printf("name : %s\n", team[i].name);
            printf("shirt number : %d\n", team[i].shirtNumber);
            printf("position : %s\n", team[i].position);
            printf("age : %d\n", team[i].age);
            printf("goals : %d\n", team[i].goals);
            printf("--------------------------------------------\n");
    }
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
                if(team[i].age < team[j].age){
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
        int position;
        printf("1. Goal keeper \n2. Defender \n3. Midfield\n4.Forward\n");
        printf("Enter your player position : ");
        scanf("%d", &position);

        if(position < 0 && position > 4){
            printf("invalid choise !");
            return ;
        }
        
        for(int i = 0; i < count; i++){
            if(team[i].id == Edit_ID){
                switch(position){
                    case 1: strcpy(team[i].position, "Goal keeper"); break;
                    case 2: strcpy(team[i].position, "Defender"); break;
                    case 3: strcpy(team[i].position, "Midfield"); break;    
                    case 4: strcpy(team[i].position, "Forward"); break;
                }
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

int Delete_player(int count) {
    int deleted_id;
    printf("Enter the ID you want to delete: ");
    scanf("%d", &deleted_id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (team[i].id == deleted_id) {
            for (int j = i; j < count - 1; j++) {
                team[j] = team[j + 1];
            }

            count--;
            found = 1;

            printf("Player with ID %d deleted successfully!\n", deleted_id);
            break;
        }
    }

    if (!found) {
        printf("No player found with ID %d\n", deleted_id);
    }

    return count;
}

int Search_player(int count, int found) {
    char Search[20];
    int s_id;
    int c;

    printf("--------------- Search Player ---------------\n");
    printf("1. Search with name\n");
    printf("2. Search with ID\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    if (c == 1) {
        printf("Enter player name: ");
        scanf(" %[^\n]", Search);

        for (int i = 0; i < count; i++) {
            if (strcmp(team[i].name, Search) == 0) {
                found = i;
            }
        }
    } 
    else if (c == 2) {
        printf("Enter player ID: ");
        scanf("%d", &Search);

        for (int i = 0; i < count; i++) {
            if (team[i].id == s_id) {
                found = i;
            }
        }
    }

    return found;
}


void Statistics(int count){
    printf("\n------------------- the total number of players --------------------\n");
    printf("the total number of players in the squad is : %d\n", count);
    printf("--------------------------------------------------------------------\n");
    
    int s = 0;
    for(int i = 0; i < count; i++){
        s += team[i].age;
    }
    printf("--------------------- Average age of players -----------------------\n");    
    if (count > 0) {
        int average = s / count;
        printf("Average age of players: %d\n", average);
    } else {
        printf("No players available to calculate average age.\n");
    }
    printf("--------------------------------------------------------------------\n");
    
    printf("--------------- players who have scored more than X ----------------\n");
    int x = 0;
    printf("players who have scored more than X goals (X entered by the user) : \n");
    scanf("%d", &x);

    for(int i = 0; i < count; i++){
        if(team[i].goals > x){
            printf("%s\n", team[i].name);
        }
    }
    printf("--------------------------------------------------------------------\n");

    printf("--------------------------- top scorer -----------------------------\n");
    printf("top scorer (player with the most goals)\n");
    int m_size;
    char most[30];
    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(team[i].goals < team[j].goals){
                m_size = j;
                strcpy(most, team[j].name);
            }
        }
    }
    printf("i found : %s\n", most);
    printf("--------------------------------------------------------------------\n");

    printf("------------------- youngest and oldest players --------------------\n");

    if (count > 0) {
        int minAge = team[0].age;
        int maxAge = team[0].age;
        char youngest[30];
        char oldest[30];

        strcpy(youngest, team[0].name);
        strcpy(oldest, team[0].name);

        for (int i = 1; i < count; i++) {
            if (team[i].age < minAge) {
                minAge = team[i].age;
                strcpy(youngest, team[i].name);
            }
            if (team[i].age > maxAge) {
                maxAge = team[i].age;
                strcpy(oldest, team[i].name);
            }
        }

        printf("The oldest player is : %s (%d years)\n", oldest, maxAge);
        printf("The youngest player is : %s (%d years)\n", youngest, minAge);
    } else {
        printf("No players available.\n");
    }

    printf("--------------------------------------------------------------------\n");

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
        printf("5. Delete a player\n");
        printf("6. Statistics\n");
        printf("7. Exit\n");
        printf("\n///////////////////////////////////////////\n");
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
            case 5:
                count = Delete_player(count);
                break;
            case 6:
                Statistics(count);
                break;
            case 7:
                running = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}
