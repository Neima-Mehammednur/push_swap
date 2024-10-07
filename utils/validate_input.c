#include "../push_swap.h"


// Function to validate the entire input array of strings
void validate_input(char **input, t_stack **stack) {
    for (int i = 0; input[i] != NULL; i++) {
        // Check syntax
        if (!check_syntax(input[i])) {
            free_error(stack); // Handle error if syntax is invalid
        }
    }

    // Now you can parse and create stack
    for (int i = 0; input[i] != NULL; i++) {
        long num = ft_atoi(input[i]); // Assuming you have a ft_atoi function

        // Check for duplicates during parsing
        if (check_duplicate(*stack)) {
            free_error(stack); // Handle error if a duplicate is found
        }

        // Add the number to your stack (assuming you have a push function)
        push(stack, num); // Define push function to add number to stack
    }
}

