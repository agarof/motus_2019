#include "SFML/Graphics.h"

int get_nbr_len(int nbr)
{
    int len = 1;

    while (nbr > 9) {
        nbr /= 10;
        ++len;
    }
    return (len);
}

void nbr_to_sftext(sfText *text, int nbr)
{
    int nbr_len = get_nbr_len(nbr);
    char to_display[nbr_len + 1];

    to_display[nbr_len] = '\0';
    while (nbr_len > 0) {
        --nbr_len;
        to_display[nbr_len] = nbr % 10 + 48;
        nbr /= 10;
    }
    sfText_setString(text, to_display);
}

void letter_to_sftext(sfText *text, char letter)
{
    char str[2];

    if (letter >= 'a' && letter <= 'z') {
        letter -= 32;
    }
    str[0] = letter;
    str[1] = '\0';
    sfText_setString(text, str);
}