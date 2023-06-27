#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char city[20];
    char sub[10]; 
    scanf("%s", city);
	
    printf("Welcome to NAMMA %s\n", city);


    printf("Enter number of suburbs your city have\n");
    int number_of_suburbs; scanf("%d\n", &number_of_suburbs);
    char** array_suburbs = (char**)malloc(number_of_suburbs * sizeof(char*));
    for(int suburbs = 0; suburbs < number_of_suburbs; suburbs++){
        scanf("%s\n", sub);
        array_suburbs[suburbs] = sub;
        printf("%d %s\n", suburbs, array_suburbs[suburbs]);
    }

    
    char*** town_sub = (char***)malloc(100 * sizeof(char**));
    char** array_town = (char**)malloc(100 * sizeof(char*));
    for(int i = 0, k = 0; i < number_of_suburbs; i++){
        printf("Enter number of town suburbs have in your city\n");
        int number_of_towns; scanf("%d", &number_of_towns);
        for (int town = 0; town < number_of_towns; town++, k++){
            town_sub[k] = (char**)malloc(2 * sizeof(char*));
            town_sub[k][0] = (char*)malloc(10 * sizeof(char));
            town_sub[k][1] = (char*)malloc(10 * sizeof(char));
            char tow[10]; scanf("%s", tow);
            array_town[k] = tow;
            town_sub[k][0] = tow;
            town_sub[k][1] = array_suburbs[i];
            printf("%s %s\n", town_sub[k][0], town_sub[k][1]);
        }
    }

    char*** corpo_town = (char***)malloc(200 * sizeof(char**));
    char** array_corpo = (char**)malloc(100 * sizeof(char*));
    int t = 0;
    for(int i = 0, t = 0; i < sizeof(array_town); i++){
        printf("Enter number of corporation your town have in your city\n");
        int number_of_corpo; scanf("%d", &number_of_corpo);
        for (int c = 0; c < number_of_corpo; c++, t++){
            corpo_town[t] = (char**)malloc(2 * sizeof(char*));
            corpo_town[t][0] = (char*)malloc(20 * sizeof(char));
            corpo_town[t][1] = (char*)malloc(20 * sizeof(char));
            char cor[10]; scanf("%s", cor);
            array_corpo[t] = cor;
            corpo_town[t][0] = cor;
            corpo_town[t][1] = array_corpo[i];
            printf("%s %s\n", corpo_town[t][0], corpo_town[t][1]);
        }
    }

    char corp1[20], corp2[20];
    scanf("%s %s", corp1, corp2);
    if(corp1 == corp2){
        printf("Enter different corporation");
        return 0;
    }
    char town1[20], town2[20];
    for(int i = 0; i<sizeof(corpo_town); i++){
        if(corpo_town[i][0] == corp1){
            // town1 = corpo_town[i][1];
            printf("Corporation is in town", corpo_town[i][1]);
        }
        if(corpo_town[i][0] == corp2){
            //  town2 = corpo_town[i][1];
             printf("Corporation is in town", corpo_town[i][1]);
        }
    }
    if(town1 == town2){
        printf("Corporation have common towm %s", town1);

    }
    else{
        printf("Corporation don't have common towm %s", town1);
    }    
}