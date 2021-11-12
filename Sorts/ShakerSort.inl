template<typename Iterator, typename Comparator>
void ShakerSort(Iterator begin, Iterator end, Comparator comparator) {
    _ShakerSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void ShakerSort(Iterator begin, Iterator end) {
    _ShakerSort(begin, end, __secrecy::Iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _ShakerSort(Iterator begin, Iterator end, Comparator comparator)
{
    Iterator left = begin;
    Iterator right = end - 1;
    while (left != right) {
        for (Iterator i = right; i != left; --i) {
            if (comparator(i, i - 1))
                __secrecy::swap(*i, *(i - 1));
        }
        ++left;
        for (Iterator i = left; i != right; ++i) {
            if (comparator(i + 1, i))
                __secrecy::swap(*(i + 1), *i);
        }
        if (left != right)
            --right;
    }
}