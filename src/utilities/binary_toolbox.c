int get_bit(int nbr)
{
    int bit = 0;

    if (nbr <= 32) {
        bit = 1 << (nbr - 1);
    }
    return (bit);
}