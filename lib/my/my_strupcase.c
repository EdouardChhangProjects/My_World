/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** put everything in upercase
*/

int my_strlen(char const *str);

char replace_char(char *dic_src, char *dic_dest, char c);

char *my_strupcase(char *str)
{
    int length = my_strlen(str);
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char alphabet_up[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++) {
        str[i] = replace_char(alphabet, alphabet_up, str[i]);
    }
    return str;
}
