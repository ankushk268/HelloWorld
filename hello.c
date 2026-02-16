#include <stdio.h>

/*
 * Overall spend = bank subvention amount + aggregator cost.
 * bank subvention amount = loan_amount * (subvention_rate / 100)
 */
double calculate_overall_spend(double loan_amount,
                               double subvention_rate,
                               double aggregator_cost)
{
    double bank_subvention_amount = loan_amount * (subvention_rate / 100.0);
    return bank_subvention_amount + aggregator_cost;
}

int main(void)
{
    double loan_amount;
    double subvention_rate;
    double aggregator_cost;

    printf("Enter loan amount: ");
    if (scanf("%lf", &loan_amount) != 1) {
        printf("Invalid input for loan amount.\n");
        return 1;
    }

    printf("Enter bank subvention rate (in %%): ");
    if (scanf("%lf", &subvention_rate) != 1) {
        printf("Invalid input for subvention rate.\n");
        return 1;
    }

    printf("Enter cost paid to aggregator: ");
    if (scanf("%lf", &aggregator_cost) != 1) {
        printf("Invalid input for aggregator cost.\n");
        return 1;
    }

    if (loan_amount < 0 || subvention_rate < 0 || aggregator_cost < 0) {
        printf("Values cannot be negative.\n");
        return 1;
    }

    double overall_spend = calculate_overall_spend(loan_amount, subvention_rate, aggregator_cost);

    printf("\nBank subvention amount: %.2f\n", loan_amount * (subvention_rate / 100.0));
    printf("Aggregator cost: %.2f\n", aggregator_cost);
    printf("Overall spend: %.2f\n", overall_spend);

    return 0;
}
