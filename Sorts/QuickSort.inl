template<typename Iterator, typename Comparator>
void QuickSort(Iterator begin, Iterator end, Comparator comparator) {
    _QuickSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void QuickSort(Iterator begin, Iterator end) {
    _QuickSort(begin, end, __secrecy::Iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _QuickSort(Iterator begin, Iterator end, Comparator comparator)
{
    __quick_sort(begin, end, comparator);
}

template <typename Iterator, typename Comparator>
void __quick_sort(Iterator begin, Iterator end, Comparator comparator)
{
    if ( end - begin > 1 ) {
        Iterator bound = __partition(begin, end, comparator);
        __quick_sort(begin, bound, comparator);
        __quick_sort(bound + 1, end, comparator);
    }
}

template <typename Iterator, typename Comparator>
Iterator __partition(Iterator begin, Iterator end, Comparator comparator)
{
    Iterator pivot = end - 1;
    Iterator i = begin;
    for (Iterator j = begin; j != pivot; ++j) {
        if (comparator(j, pivot)){
            __secrecy::swap(*i++, *j);
        }
    }
    __secrecy::swap(*i, *pivot);
    return i;
}

