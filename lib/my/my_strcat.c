/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** put a str at the end of another str
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int src_length = my_strlen(src);

    for (int i = 0; i < src_length; i++) {
        dest[i + dest_length] = src[i];
    }
    return dest;
}
