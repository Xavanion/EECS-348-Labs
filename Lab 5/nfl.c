#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *possibleCombos[10000];
int comboTotal = 0;


void addCombo(char *combo){
    possibleCombos[comboTotal] = combo;
    comboTotal++;
    return;
}

void possibleScores(int score, int upperLimit, int lowerLimit, int touchdown_2pt, int touchdown_FG, int touchdown, int fg_3pt, int safety){
    int currentScore = ((touchdown_2pt*8) + (touchdown_FG*7) + (touchdown*6) + (fg_3pt*3) + (safety*2));
    if (score == currentScore){
        char *combo = malloc(100 * sizeof(char));;
        sprintf(combo, "%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdown_2pt, touchdown_FG, touchdown, fg_3pt, safety);
        addCombo(combo);
        return;
    }
    if (score < currentScore){
        return;
    }
    if (touchdown_2pt > lowerLimit || touchdown_FG > lowerLimit || touchdown > lowerLimit || fg_3pt > lowerLimit || safety > lowerLimit){
        return;
    }
    possibleScores(score, upperLimit, lowerLimit, touchdown_2pt, touchdown_FG, touchdown, fg_3pt, safety + 1);
    possibleScores(score, upperLimit, lowerLimit, touchdown_2pt, touchdown_FG, touchdown, fg_3pt + 1, safety);
    possibleScores(score, upperLimit, lowerLimit, touchdown_2pt, touchdown_FG, touchdown + 1, fg_3pt, safety);
    possibleScores(score, upperLimit, lowerLimit, touchdown_2pt, touchdown_FG + 1, touchdown, fg_3pt, safety);
    possibleScores(score, upperLimit, lowerLimit, touchdown_2pt + 1, touchdown_FG, touchdown, fg_3pt, safety);
}

void printPossibleScores(char *possibleCombos[]){
    char *tempCombos[10000];
    int tempComboTotal = 0;

    for (int i = 0; i < comboTotal; i++) {
        int isUnique = 1;
        for (int n = 0; n < tempComboTotal; n++) {
            if (strcmp(possibleCombos[i], tempCombos[n]) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique == 1) {
            tempCombos[tempComboTotal] = possibleCombos[i];
            printf("%s\n", tempCombos[tempComboTotal]);
            tempComboTotal++;
        }
    }
}


int main(){
    int score;
    printf("Enter the NFL Score: ");
    scanf("%d",&score);
    int upperLimit = ((score/8)-1);
    int lowerLimit = ((score/2)-1);
    if (score < 2){
        printf("No combinations\n");
    }
    else {
        printf("Possible combinations of scoring plays:\n");
        possibleScores(score, upperLimit, lowerLimit, 0, 0, 0, 0, 0);
        printPossibleScores(possibleCombos);
    }
    return 0;
}
