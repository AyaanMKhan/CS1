// In this code we will use stack to check the balance of parentheses.

#include <ctype.h> // needed for isdigit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The array will store the items in the stack, first in
// index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is
// empty top will be -1.

#define SIZE 100
#define EMPTY -1

struct stack {

  char items[SIZE];
  int top;
};

void initialize(struct stack *stackPtr);
int full(struct stack *stackPtr);
int push(struct stack *stackPtr, char value);
int empty(struct stack *stackPtr);
char pop(struct stack *stackPtr);
int peek(struct stack *stackPtr);
void print_stack(struct stack *stackPtr);

// functions you have to complete:
int checkBalance(char exp[]);

int priority(char ch);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
int isParentheses(char ch1);

int main(void) {
  int ch;
  char exp[SIZE], c;

  int valid;

  printf("\nEnter Expression: ");
  scanf("%[^\n]s", exp);

  printf("Your input expression: %s\n", exp);

  valid = checkBalance(exp);

  if (valid) {
    char *postfix = infixToPostfix(exp);
    printf("The postfix is: %s\n", postfix);

    free(postfix);
  }

  return 0;
}

int checkBalance(char exp[]) {
  int valid = 1;
  struct stack mine;

  // Set up the stack and push a couple items, then pop one.
  initialize(&mine);

  printf("\nChecking balance...\n");
  for (int i = 0; exp[i] != '\0'; i++) {
    // if it is an open parentheses, push to stack
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      push(&mine, exp[i]);

    // if it is any kind of closing parentheses, check for a match
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      // pop from stack
      // it is invalid of pop is empty or an unmathcing open parentheses
      char a = pop(&mine);
      if (a == EMPTY || (exp[i] == ')' && a != '(') ||
          (exp[i] == '}' && a != '{') || (exp[i] == ']' && a != '[')) {
        // update valid value
        valid = 0;
        printf("INVALID!!!\n");
        return valid;
        // print message
        // return valid
      }
    }
  }

  // if stack isn't empty, still have extra parentheses in the stack
  if (pop(&mine) != EMPTY) // it means we still have a parenthesis in the stack
  {
    valid = 0;
    printf("INVALID, You have extra!!\n");
    // set valid to 0
    // print message
  }
  // if we passed last check, then stack is empty
  if (valid == 1)
    // print message
    printf("VALID\n");

  return valid;
}

void print_stack(struct stack *stackPtr) {
  for (int i = 0; i <= stackPtr->top; i++)
    printf("%c-->", stackPtr->items[i]);

  printf("\n");
}

void initialize(struct stack *stackPtr) { stackPtr->top = -1; }

// If the push occurs, 1 is returned. If the
// stack is full and the push can't be done, 0 is
// returned.
int push(struct stack *stackPtr, char value) {

  // Check if the stack is full.
  if (full(stackPtr))
    return 0;

  // Add value to the top of the stack and adjust the value of the top.
  stackPtr->items[stackPtr->top + 1] = value;
  (stackPtr->top)++;
  return 1;
}

// Returns true iff the stack pointed to by stackPtr is full.
int full(struct stack *stackPtr) { return (stackPtr->top == SIZE - 1); }

// Returns true iff the stack pointed to by stackPtr is empty.
int empty(struct stack *stackPtr) { return (stackPtr->top == -1); }

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char pop(struct stack *stackPtr) {

  char retval;

  // Check the case that the stack is empty.
  if (empty(stackPtr))
    return EMPTY;

  // Retrieve the item from the top of the stack, adjust the top and return
  // the item.
  retval = stackPtr->items[stackPtr->top];
  (stackPtr->top)--;
  return retval;
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
int peek(struct stack *stackPtr) {

  // Take care of the empty case.
  if (empty(stackPtr))
    return EMPTY;

  // Return the desired item.
  return stackPtr->items[stackPtr->top];
}

char *infixToPostfix(char infix[]) {
  // create a stack to store operators
  // initialize the stack
  struct stack operator;
  initialize(&operator);
  // keep track of postfix index using some counter variable
  int count = 0;
  // allocating memory for the postfix expression
  char *postfix = malloc(sizeof(char) * 2 * strlen(infix) + 1);
  // store the length of the expression in some variable

  // iterating through the infix and processing each char
  // loop goes up to length of infix expression
  for (int i = 0; i < strlen(infix); i++) {
    // if the char is a digit puts it into the postfix
    if (isdigit(infix[i]))
        ;
    {
      // to deal with multiple digits
      // keep adding as long as it is a digit
      while (isdigit(infix[i])) {
        postfix[count] = infix[i];
        i++;
        count++;
      }
      // fix the i position
      i--;
      // add white space between numbers
      postfix[count] = ' ';
      count++;
    }

    // if the char is an operator, and the stack is empty, pushing it. if the
    // stack isn't empty, checking for priority.
    else if (isOperator(infix[i])) {
      // push if stack is empty
      if (empty(&operator))
        push(&operator, infix[i]);

      // if the priority is higher than the top of the stack, pushing it to
      // operators stack
      else if (priority(infix[i]) > priority(peek(&operator))) {
        push(&operator, infix[i]);
      }

      // if priority is lower or equal, popping the stack into the postfix until
      // it is empty or the priority of the char is higher than the one from the
      // top of stack
      else {
        // loop keeps going as long as stack is not empty, and prioirty of
        // current operator is <= top of stack, and top of stack is not a
        // parentheses
        while (
            !empty(&operator) &&
            priority(infix[i]) <=
                priority(peek(&operator) && !isParentheses(peek(&operator)))) {
          // pop operator and add it to the postfix expression
          postfix[count] = pop(&operator);
          count++;
          // add space between characters
          postfix[count] = " ";
          count++;
        }

        // push the operator to stack
        push(&operator, infix[i]);
      }
    }
    // checks if the char is a parentheses
    else if (infix[i] == "(" || infix[i] == ")") {
      // if it is an open parentheses pushes it to operators
      if (infix[i] == "(")
        // push to stack
        push(&operator, infix[i]);
      // if not, pops the operators stack into the postfix until it gets to an
      // open parentheses.
      else {
        while (peek(&operator) != "(") {
          // pop operator and put it in postfix
          postfix[count] = pop(&operator);
          count++;
          postfix[count] = " ";
          count++;
          // add white space
        }
        // do one more pop to get rid of the (
        pop(&operator);
      }
    }

  } // end of iterating through the the infix

  // pops all the operators left in the stack and adds white spaces between
  // them. this is your job to finish on your own
  while (!empty(&operators)) {
    postfix[count] = '  ';
    count++;
    postfix[count] = pop(&operator);
    count++;
  }
  postfix[count] = '\0';
  // do not forget to put the null terminator to the end of postfix

  // return postfix expression
  return postfix;
}

// returns the priority of the passed character
// (  {  [  : 0
// + - : 1
// * / %: 2
// ^ : 3
int priority(char ch) {
  if (ch == "(" || ch == "{" || ch = "[")
    return 0;
  if (ch == "+" || ch == "-")
    return 1;
  if (ch == "*" || ch == "/" || ch "%")
    return 2;
  if (ch == "^")
    return 3;
}

// returns 1 of ch is an operator + - * / ^ %
// returns 0 otherwise
int isOperator(char ch) {
  if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "%" ||
      ch == "^")
    return 1;
  return 0;
}

// parentheses check
//  returns 1 of ch is a parentheses { [ ( ) ] }
//  returns 0 otherwise
int isParentheses(char ch1) {
  if (ch1 == "(" || ch1 == "{" || ch1 == "[" || ch1 == ")" || ch1 == "}" ||
      ch1 == "]")
    return 1;
  return 0;