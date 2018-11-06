#ifndef PALINDROME_H
#define PALINDROME_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef enum { false, true } bool;

bool is_palindrome_iter(char *str);
bool is_palindrome_rec(char *str);
char *talloc(size_t num_chars);
char *get_string(FILE *f);

#endif /* PALINDROME_H */
