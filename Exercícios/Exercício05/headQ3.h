typedef struct Number number;
struct Number {
    //^ se o digito for igual a 20 então é uma virgula;
    int digit;
    int position;
    number *next;
    number *before;
};

typedef struct Head head;
struct Head {
    int numbersAfterDot;
    number *start;
};

number *soma(number *n1, number *n2);
number *end(number *n);
int numberSize(number *n);