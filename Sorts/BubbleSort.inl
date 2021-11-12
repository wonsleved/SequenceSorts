template<typename Iterator, typename Comparator>
void BubbleSort(Iterator begin, Iterator end, Comparator comparator) {
    _BubbleSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void BubbleSort(Iterator begin, Iterator end) {
    _BubbleSort(begin, end, __secrecy::Iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _BubbleSort(Iterator begin, Iterator end, Comparator comparator)
{
    for (Iterator i = begin; i != end - 1; ++i)
        for (Iterator j = begin; j != end - 1 - (i - begin); ++j)
            if (comparator(j + 1, j))
                __secrecy::swap(*(j+1), *j);
}



