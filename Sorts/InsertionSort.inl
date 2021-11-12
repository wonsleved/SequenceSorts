template<typename Iterator, typename Comparator>
void InsertionSort(Iterator begin, Iterator end, Comparator comparator) {
    _InsertionSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void InsertionSort(Iterator begin, Iterator end) {
    _InsertionSort(begin, end, __secrecy::Iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _InsertionSort(Iterator begin, Iterator end, Comparator comparator)
{
    for (Iterator i = begin + 1; i != end; ++i) {
        Iterator j = i;
        while (j != begin && comparator(j, j - 1)) {
            __secrecy::swap(*(j - 1), *j);
            --j;
        }
    }
}
