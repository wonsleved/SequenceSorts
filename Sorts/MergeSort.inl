template<typename Iterator, typename Comparator>
void MergeSort(Iterator begin, Iterator end, Comparator comparator) {
    _MergeSort(begin, end, __secrecy::iter_comp_iter(comparator));
}

template<typename Iterator>
void MergeSort(Iterator begin, Iterator end) {
    _MergeSort(begin, end, __secrecy::iter_less_iter());
}

template<typename Iterator, typename Comparator>
void _MergeSort(Iterator begin, Iterator end, Comparator comparator)
{
    --end;
    size_t size = (end - begin) + 1;
    if (size < 2)
        return;

    Iterator middle = begin + (end - begin) / 2;

    __merge_sort(begin, middle, comparator);
    if (middle != end)
        __merge_sort(middle + 1, end, comparator);

    __merge(begin, middle, end, comparator);
}

template <typename Iterator, typename Comparator>
void __merge(Iterator left, Iterator middle, Iterator right, Comparator comparator) {
    if (left == right)
        return;

    Iterator start2 = middle + 1;

    if (comparator(middle, start2)) {
        return;
    }



    while (true) {

        if (comparator(left, start2)) {
            if (left == middle)
                break;
            ++left;
        }
        else {
            auto value = *start2;
            Iterator index = start2;

            while (index != left) {
                *index = *(index - 1);
                index--;
            }
            *left = value;

            if (start2 == right)
                break;

            left++;
            middle++;
            start2++;
        }
    }

}

template<typename Iterator, typename Comparator>
void __merge_sort(Iterator begin, Iterator end, Comparator comparator)
{
    size_t size = (end - begin) + 1;
    if (size < 2)
        return;

    Iterator middle = begin + (end - begin) / 2;

    __merge_sort(begin, middle, comparator);
    if (middle != end)
        __merge_sort(middle + 1, end, comparator);

    __merge(begin, middle, end, comparator);
}
