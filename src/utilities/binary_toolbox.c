int get_bit(int nbr)
{
    int bit = 0;

    if (nbr <= 32) {
        bit = 1 << (nbr - 1);
    }
    return (bit);
}

int get_bit_count(int count)
{
    int size = sizeof(int) * 8;
    int result = 0;
    int pos = 0;

    while (pos < size) {
        if (count | (1 << pos)) {
            ++result;
        }
        ++pos;
    }
    return (result);
}