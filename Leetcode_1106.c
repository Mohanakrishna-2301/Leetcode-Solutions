#include <stdio.h>
#include <stdbool.h>

bool parseBoolExpr(char* expr) {
    char stack[2000];
    int top = -1;
    
    for (int i = 0; expr[i] != '\0'; ++i) {
        if (expr[i] == ',' || expr[i] == '(') {
            continue; // skip commas and opening parenthesis
        }
        if (expr[i] == ')') {
            int t = 0, f = 0;
            while (stack[top] == 't' || stack[top] == 'f') {
                if (stack[top] == 't') t++;
                else f++;
                top--;
            }
            char op = stack[top--]; // the operator before '('
            if (op == '!') {
                stack[++top] = f == 1 ? 't' : 'f';
            } else if (op == '&') {
                stack[++top] = f == 0 ? 't' : 'f';
            } else { // op == '|'
                stack[++top] = t > 0 ? 't' : 'f';
            }
        } else {
            stack[++top] = expr[i]; // push 't', 'f', or operator to stack
        }
    }
    
    return stack[0] == 't';
}

int main() {
    char expr[] = "|(&(t,f,t),!(t))";
    bool result = parseBoolExpr(expr);
    printf("Result: %s\n", result ? "true" : "false");
    return 0;
}
