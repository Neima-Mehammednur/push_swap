
#include "push_swap.h"
// calculating the costs of moving each element to its correct
// position, you can choose the operation that minimizes the 
// total number of moves. For example, if moving one element involves
// fewer operations than another, you can prioritize that move.
// Dynamic Strategy: If your algorithm can adapt based on the current
// state of the stack and the calculated costs, it will be more flexible and
// capable of efficiently addressing various configurations.


//the number of operations needed to move elements

// void calculate_push_cost(t_stack *stack_a, t_stack *stack_b) {
//     // Logic to calculate costs for pushing elements
//     // Iterate through stack_a and stack_b and compute costs
//     // Update the push_cost attribute for each node if necessary
// }



// Main function to calculate costs for pushing elements from stack_a to stack_b
void calculate_push_costs(t_stack *stack_a, t_stack *stack_b) {
    while (stack_a) {
        calculate_push_cost(stack_a, stack_b);
        stack_a = stack_a->next;
    }
}

// Calculates how many operations are needed to bring an element to the top
int get_cost_to_top(t_stack *stack, int index) {
    int cost = 0;
    // Logic to calculate cost based on index and stack length
    return cost;
}

// // Calculates the cost of pushing a specific node from stack_a to stack_b
// void calculate_push_cost(t_stack *node_a, t_stack *stack_b) {
//     // Logic to determine the push cost based on current positions
//     int cost = get_cost_to_top(stack_b, node_a->index);
//     node_a->push_cost = cost; // Update the push cost for node_a
// }

// // Determine the best move based on calculated costs
// void determine_best_move(t_stack *stack_a, t_stack *stack_b) {
//     // Logic to find the node in stack_a with the lowest push_cost
// }
