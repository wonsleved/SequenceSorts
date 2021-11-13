template<typename Iterator, typename Comparator>
void SelectionSort(Iterator begin, Iterator end, Comparator comparator) {
    _SelectionSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void SelectionSort(Iterator begin, Iterator end) {
    _SelectionSort(begin, end, __secrecy::iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _SelectionSort(Iterator begin, Iterator end, Comparator comparator)
{
    for (Iterator i = begin + 1; i != end; ++i) {
        Iterator iter = i - 1;
        for (Iterator j = i; j != end; ++j) {
            if (comparator(j, iter)) {
                iter = j;
            }
        }
        if (i - 1 != iter)
            __secrecy::swap(*(i-1), *iter);
    }
}