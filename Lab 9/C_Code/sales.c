#include <stdio.h>
#include <stdlib.h>

void monthlySalesReport(double sales[], char *months[]){
  printf("Monthly Sales Report for 2022\n");
  printf("Month\t\tSales\n");
  for (int i=0; i<12; i++){
    printf("%s\t\t", months[i]);
    printf("$%.2f\n", sales[i]);
  }
  printf("\n");
  return;
}

void salesSummary(double sales[], char *months[]){
    printf("Sales Report 2022\n");
    double minimum = sales[0];
    double maximum = sales[0];
    int minMonth=0;
    int maxMonth=0;
    double averageSales = sales[0];
    for (int i=1; i<12; i++){
        if (sales[i] < minimum){
            minimum = sales[i];
            minMonth=i;
        }
        if (sales[i] > maximum){
            maximum = sales[i];
            maxMonth=i;
        }
        averageSales += sales[i];
    }
    averageSales = averageSales/12;
    printf("Minimum:\t$%.2f (%s)\n", minimum,months[minMonth]);
    printf("Maxiumum:\t$%.2f (%s)\n", maximum,months[maxMonth]);
    printf("Average Sales:\t$%.2f\n\n", averageSales);
}

void movingAverage(double sales[], char *months[]){
    double averageSales;
    printf("Six-Month Moving Average Report:\n");
    for (int i=0; i<=6; i++){
        averageSales = 0;
        for (int n=0; n<6;n++){
            averageSales += sales[i+n];
        }
        averageSales = averageSales/6;
        printf("%s  -  %s\t$%.2f\n",months[i],months[i+5],averageSales);
    }
    printf("\n");
}

void highLowReport(double sales[], char *months[]){
    char *tempMonth;
    double tempSale;
    for (int i = 0; i < 11; i++) {
        int min_index = i;
        for (int j = i + 1; j < 12; j++) {
            if (sales[j] > sales[min_index]) {
                min_index = j;
            }
        }
        tempSale = sales[i];
        sales[i] = sales[min_index];
        sales[min_index] = tempSale;

        tempMonth = months[i];
        months[i] = months[min_index];
        months[min_index] = tempMonth;
    }
    printf("High to Low Sales Report:\n");
    for (int n = 0; n < 12; n++) {
        printf("%s\t$%.2f\n", months[n], sales[n]);
    }

}

int main() {
    double sales[12];
    printf("Checking for sales_data.txt\n");
    FILE *file;
    file = fopen("sales_data.txt", "r");\
    if (file == NULL){
        perror("Error opening file.\n");
        exit(1);
    }
    
    for (int i = 0; i < 12; i++) {
            if (fscanf(file, "%lf", &sales[i]) != 1) {
                printf("Error reading data from file.\n");
                exit(1);
            }
        }
    fclose(file);

    char *months[] = {"January","February","March","April", "May", "June","July",
                        "August","September","October","November","December"};

    monthlySalesReport(sales,months);
    salesSummary(sales,months);
    movingAverage(sales, months);
    highLowReport(sales, months);
    
    return 0;
}
