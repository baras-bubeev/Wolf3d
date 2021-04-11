# Libc
## About
This project gave me the opportunity to rewrite some of the functions of the standard C library.<br/>
___
**My functions represent the same prototype and behavior as the originals. The library contains the following standard library functions:**
```
• memset          • bzero
• memcpy          • memccpy
• memmove         • memchr
• memcmp          • strlen
• strlcpy         • strlcat
• strchr          • strrchr
• strnstr         • strncmp
• atoi            • isalpha
• isdigit         • isalnum
• isascii         • isprint
• toupper         • tolower
• calloc          • strdup
```
___
**The library also contains the following additional functions:**<br/>
___
### substr
***Prototype***
```C
char *ft_substr(char const *s, unsigned int start, size_t len);
```
***Parameters***<br/>
#1. The string from which to create the substring.<br/>
#2. The start index of the substring in the string `s`.<br/>
#3. The maximum length of the substring.<br/>

***Return value***<br/>
The substring. `NULL` if the allocation fails.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`.
______
### strjoin
***Prototype***
```C
char *ft_strjoin(char const *s1, char const *s2);
```
***Parameters***<br/>
#1. The prefix string.<br/>
#2. The suffix string.<br/>

***Return value***<br/>
The new string. `NULL` if the allocation fails.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of `s1` and `s2`.
___
### strtrim
***Prototype***
```C
char *ft_strtrim(char const *s1, char const *set);
```
***Parameters***<br/>
#1. The string to be trimmed.<br/>
#2. The reference set of characters to trim.<br/>

***Return value***<br/>
The trimmed string. `NULL` if the allocation fails.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string.
___
### split
***Prototype***
```C
char **ft_split(char const *s, char c);
```
***Parameters***<br/>
#1. The string to be split.<br/>
#2. The delimiter character.<br/>

***Return value***<br/>
The array of new strings resulting from the split. `NULL` if the allocation fails.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must be ended by a `NULL` pointer.
___
### itoa
***Prototype***
```C
char *ft_itoa(int n);
```
***Parameters***<br/>
#1. the integer to convert.<br/>

***Return value***<br/>
The string representing the integer. `NULL` if the allocation fails.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
___
### strmapi
***Prototype***
```C
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
***Parameters***<br/>
#1. The string on which to iterate.<br/>
#2. The function to apply to each character.<br/>

***Return value***<br/>
The string created from the successive applications of ’f’. Returns `NULL` if the allocation fails.<br/>

***Description***<br/>
Applies the function `f` to each character of the string `s` to create a new string (with malloc(3)) resulting from successive applications of `f`.
___
### putchar_fd
***Prototype***
```C
void ft_putchar_fd(char c, int fd);
```
***Parameters***<br/>
#1. The character to output.<br/>
#2. The file descriptor on which to write.<br/>

***Description***<br/>
Outputs the character `c` to the given file descriptor.
___
### putstr_fd
***Prototype***
```C
void ft_putstr_fd(char *s, int fd);
```
***Parameters***<br/>
#1. The string to output.<br/>
#2. The file descriptor on which to write.<br/>

***Description***<br/>
Outputs the string `s` to the given file descriptor.
___
### putendl_fd
***Prototype***
```C
void ft_putendl_fd(char *s, int fd);
```
***Parameters***<br/>
#1. The string to output.<br/>
#2. The file descriptor on which to write.<br/>

***Description***<br/>
Outputs the string `s` to the given file descriptor, followed by a newline.
___
### putnbr_fd
***Prototype***
```C
void ft_putnbr_fd(int n, int fd);
```
***Parameters***<br/>
#1. The integer to output.<br/>
#2. The file descriptor on which to write.<br/>

***Description***<br/>
Outputs the integer `n` to the given file descriptor.
___
### The following structure was used for functions with lists:
```C
typedef struct  s_list
{
void            *content;
struct s_list   *next;
}               t_list;
```
___
### lstnew
***Prototype***
```C
t_list *ft_lstnew(void *content);
```
***Parameters***<br/>
#1. The content to create the new element with.<br/>

***Return value***<br/>
The new element.<br/>

***Description***<br/>
Allocates (with malloc(3)) and returns a new element. The variable `content` is initialized with the value of the parameter `content`. The variable `next` is initialized to `NULL`.
___
### lstadd_front
***Prototype***
```C
void ft_lstadd_front(t_list **lst, t_list *new);
```
***Parameters***<br/>
#1. The address of a pointer to the first link of a list.<br/>
#2. The address of a pointer to the element to be added to the list.<br/>

***Description***<br/>
Adds the element `new` at the beginning of the list.
___
### lstsize
***Prototype***
```C
int ft_lstsize(t_list *lst);
```
***Parameters***<br/>
#1. The beginning of the list.<br/>

***Return value***<br/>
Length of the list.<br/>

***Description***<br/>
Counts the number of elements in a list.<br/>
___
### lstlast
***Prototype***
```C
t_list *ft_lstlast(t_list *lst);
```
***Parameters***<br/>
#1. The beginning of the list.<br/>

***Return value***<br/>
Last element of the list.<br/>

***Description***<br/>
Returns the last element of the list.<br/>
___
### lstadd_back
***Prototype***
```C
void ft_lstadd_back(t_list **lst, t_list *new);
```
***Parameters***<br/>
#1. The address of a pointer to the first link of a list.<br/>
#2. The address of a pointer to the element to be added to the list.<br/>

***Description***<br/>
Adds the element `new` at the end of the list.<br/>
___
### lstdelone
***Prototype***
```C
void ft_lstdelone(t_list *lst, void (*del)(void *));
```
***Parameters***<br/>
#1. The element to free.<br/>
#2. The address of the function used to delete the content.<br/>

***Description***<br/>
Takes as a parameter an element and frees the memory of the element’s content using the function `del` given as a parameter and free the element. The memory of `next` must not be freed.<br/>
___
### lstclear
***Prototype***
```C
void ft_lstclear(t_list **lst, void (*del)(void *));
```
***Parameters***<br/>
#1. The adress of a pointer to an element.<br/>
#2. The adress of the function used to delete the content of the element.<br/>

***Description***<br/>
Deletes and frees the given element and every successor of that element, using the function `del` and free(3). Finally, the pointer to the list must be set to `NULL`.<br/>
___
### lstiter
***Prototype***
```C
void ft_lstiter(t_list *lst, void (*f)(void *));
```
***Parameters***<br/>
#1. The adress of a pointer to an element.<br/>
#2. The adress of the function used to iterate on the list.<br/>

***Description***<br/>
Iterates the list `lst` and applies the function `f` to the content of each element.<br/>
___
### lstmap
***Prototype***
```C
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
***Parameters***<br/>
#1. The adress of a pointer to an element.<br/>
#2. The adress of the function used to iterate on the list.<br/>
#3. The adress of the function used to delete the content of an element if needed.<br/>

***Return value***<br/>
The new list. `NULL` if the allocation fails.<br/>

***Description***<br/>
Iterates the list `lst` and applies the function `f` to the content of each element. Creates a new list resulting of the successive applications of the function `f`. The `del` function is used to delete the content of an element if needed.<br/>
___
