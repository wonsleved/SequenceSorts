template<typename Iterator, typename Comparator>
void BinaryInsertionSort(Iterator begin, Iterator end, Comparator comparator) {
    _BinaryInsertionSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void BinaryInsertionSort(Iterator begin, Iterator end) {
    _BinaryInsertionSort(begin, end, __secrecy::iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _BinaryInsertionSort(Iterator begin, Iterator end, Comparator comparator)
{
    if (begin + 1 == end)
        return;

    if (comparator(begin + 1, begin)) {
        __secrecy::swap(*(begin + 1), *begin);
    }

    for (Iterator i = begin + 2; i != end; ++i) {

        Iterator left = begin;
        Iterator right = i;
        Iterator last = begin - 1;

        while (left != right) {
            Iterator middle = left + (right - left) / 2;
            if (comparator(i, middle))
                right = middle;
            else
                left = middle;

            if (last == middle)
                break;

            last = middle;
        }

        for (Iterator j = right; j != i; ++j) {
            __secrecy::swap(*j, *i);
        }
    }
}