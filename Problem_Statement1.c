#include <stdio.h>
#include <stdlib.h>

// Function to read data from a file and return it as an array of doubles
double* input_file_read(const char *file) {
    FILE *input_file = fopen(file, "r");
    if (input_file == NULL) {
        printf("File not found: %s\n", file);
        return NULL;
    }

    double *data_input_file = (double*)malloc(12 * sizeof(double));
    for (int i = 0; i < 12; i++) {
        fscanf(input_file, "%lf", &data_input_file[i]);
    }
    fclose(input_file);

    return data_input_file;
}

// Function to print monthly sales data
void monthly_sales(double *data_input) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Monthly sales report for 2022:\n");
    printf("Month    Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2f\n", months[i], data_input[i]);
    }
}

// Function to print sales summary
void sales_summary(double *data) {
    double minimum_sale_monthly = data[0];
    double maximum_sale_monthly = data[0];
    double average_sale_monthly = 0;

    for (int i = 0; i < 12; i++) {
        if (data[i] < minimum_sale_monthly) {
            minimum_sale_monthly = data[i];
        }
        if (data[i] > maximum_sale_monthly) {
            maximum_sale_monthly = data[i];
        }
        average_sale_monthly += data[i];
    }

    average_sale_monthly /= 12;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (January)\n", minimum_sale_monthly);
    printf("Maximum sales: $%.2f (December)\n", maximum_sale_monthly);
    printf("Average sales: $%.2f\n", average_sale_monthly);
}

// Function to print a six-month moving average report
void six_month_moving_average_report(double *data) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 6; i < 12; i++) {
        double average_money = 0;
        for (int j = i - 6; j < i; j++) {
            average_money += data[j];
        }
        average_money /= 6;
        printf("%s - %s $%.2f\n", months[i - 6], months[i], average_money);
    }
}

// Function to print sales report from highest to lowest
void highest_to_lowest_sales(double *data) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month    Sales\n");

    // Create an array of month-sales pairs
    struct MonthSale {
        const char *month;
        double sale;
    };

    struct MonthSale month_sales[12];
    for (int i = 0; i < 12; i++) {
        month_sales[i].month = months[i];
        month_sales[i].sale = data[i];
    }

    // Sort the month-sales array by sales in descending order
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (month_sales[i].sale < month_sales[j].sale) {
                struct MonthSale temp = month_sales[i];
                month_sales[i] = month_sales[j];
                month_sales[j] = temp;
            }
        }
    }

    // Print the sorted sales report
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2f\n", month_sales[i].month, month_sales[i].sale);
    }
}

int main() {
    const char *input_file = "sales_data.txt";  // Replace with your input file path
    double *sales_data = input_file_read(input_file);

    if (sales_data) {
        monthly_sales(sales_data);
        sales_summary(sales_data);
        six_month_moving_average_report(sales_data);
        highest_to_lowest_sales(sales_data);
        free(sales_data);  // Free the allocated memory
    }

    return 0;
}

