#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_EXPENSES 10

typedef struct expenses {
    int value;
    char name[MAX_NAME_LENGTH];
} expenses;

int client_list_size = 0;
expenses client_expenses[MAX_EXPENSES];
int *list_size_handler = &client_list_size;

void show_expenses();
void add_expense();

void display_menu() {
    int client_choice;

    printf("Choose an option from the menu:\n1 - Show expenses\n2 - Add Expense\n");
    scanf("%d", &client_choice);

    switch (client_choice) {
        case 1:
            show_expenses();
            break;
        case 2:
            add_expense();
            break;
        default:
            printf("Not a valid number!\n");
            display_menu();
            break;
    }
}

void add_expense() {
    if (*list_size_handler == MAX_EXPENSES) {
        printf("No more expenses can be added!\n");
        display_menu();
        return;
    }

    char expense_name[MAX_NAME_LENGTH];
    int expense_value;

    printf("Write the name of the expense:\n");
    scanf("%s", expense_name);

    printf("How much money will you spend on this expense?\n");
    scanf("%d", &expense_value);

    strcpy(client_expenses[*list_size_handler].name, expense_name);
    client_expenses[*list_size_handler].name[MAX_NAME_LENGTH - 1] = '\0';
    client_expenses[*list_size_handler].value = expense_value;
    (*list_size_handler)++;

    int client_choice;

    printf("Expense added. Would you like to add more expenses?\n1 - Yes\n2 - No\n");
    scanf("%d", &client_choice);

    switch (client_choice) {
        case 1:
            add_expense();
            break;
        case 2:
            display_menu();
            break;
        default:
            printf("Enter a valid number!\n");
            printf("Would you like to add more expenses?\n1 - Yes\n2 - No\n");
            scanf("%d", &client_choice);
            if (client_choice == 1) {
                add_expense();
            } else {
                display_menu();
            }
            break;
    }
}

void show_expenses() {
    int i = 0;

    if (*list_size_handler == 0) {
        printf("No current expenses\n");
        display_menu();
    }

    while (i < *list_size_handler) {
        printf("%d - %s: %d\n", i + 1, client_expenses[i].name, client_expenses[i].value);
        i++;
    }

    display_menu();
}

int main() {
    display_menu();
    return 0;
}
