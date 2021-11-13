#ifndef SEQUENCESORTS_SECRECY_H
#define SEQUENCESORTS_SECRECY_H

namespace __secrecy {

    struct Iter_less_iter
    {
        template<typename Iterator1, typename Iterator2>
        bool
        operator()(Iterator1 it1, Iterator2 it2) const
        { return *it1 < *it2; }
    };


    inline Iter_less_iter iter_less_iter()
    { return Iter_less_iter(); }

    template<typename Comparator>
    struct Iter_comp_iter {
        Comparator comparator;

        explicit Iter_comp_iter(Comparator comp)
                : comparator(comp) {};

        template <typename Iterator1, typename Iterator2>
        bool operator()(Iterator1 it1, Iterator2 it2)
        { return bool(comparator(*it1, *it2));};
    };



    template<typename Comparator>
    inline Iter_comp_iter<Comparator> iter_comp_iter(Comparator comparator)
    { return Iter_comp_iter<Comparator>(comparator); }



    template <typename Type>
    void swap(Type& first, Type& second)
    {
        auto tmp = second;
        second = first;
        first = tmp;
    }
}

#endif
