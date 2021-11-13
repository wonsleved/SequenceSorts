template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
LinkedListSequence()
    : m_list( new LinkedList<T>() ) {}

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
LinkedListSequence(int size)
        : m_list( new LinkedList<T>(size) ) {}

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
LinkedListSequence(T* items, int size)
        : m_list( new LinkedList<T>(items, size) ) {};

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
LinkedListSequence(const LinkedListSequence<T, AllocatorT>& another)
        : m_list( new LinkedList<T>(*another.m_list) ) {};

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
LinkedListSequence(const LinkedList<T>& list)
        : m_list( new LinkedList<T>(list) ) {}

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>&
LinkedListSequence<T, AllocatorT>::
operator= (const LinkedListSequence<T, AllocatorT>& another) {
    m_list = new LinkedList<T>(*another.m_list);
}

template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>&
LinkedListSequence<T, AllocatorT>::
operator= (LinkedListSequence<T, AllocatorT>* another) {
    m_list = new LinkedList<T>(*another->m_list);
}



template <typename T, typename AllocatorT>
LinkedListSequence<T, AllocatorT>::
~LinkedListSequence() {
    delete m_list;
}

template <typename T, typename AllocatorT>
T LinkedListSequence<T, AllocatorT>::
getItem(int index) const {
    return m_list->getItem(index);
}

template <typename T, typename AllocatorT>
int LinkedListSequence<T, AllocatorT>::
getSize() const {
    return m_list->getSize();
}

template <typename T, typename AllocatorT>
T LinkedListSequence<T, AllocatorT>::
getFirst() const {
    return m_list->getFirst();
}

template <typename T, typename AllocatorT>
T LinkedListSequence<T, AllocatorT>::
getLast() const {
    return m_list->getLast();
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT&
LinkedListSequence<T, AllocatorT>::
insert(int index, const T& item) {
    m_list->insert(index, item);
    return *this;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT&
LinkedListSequence<T, AllocatorT>::
remove(int index) {
    m_list->remove(index);
    return *this;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT&
LinkedListSequence<T, AllocatorT>::
append(const T& item) {
    m_list->append(item);
    return *this;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT&
LinkedListSequence<T, AllocatorT>::
prepend(const T& item) {
    m_list->prepend(item);
    return *this;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT&
LinkedListSequence<T, AllocatorT>::
clear() {
    m_list->clear();
    return *this;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT*
LinkedListSequence<T, AllocatorT>::
map(T (*function)(const T& item)) {
    LinkedList<T>* tmp = m_list->map(function);
    LinkedListSequence<T, AllocatorT>* result =
            new LinkedListSequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT*
LinkedListSequence<T, AllocatorT>::
filter(bool (*function)(const T& item)) {
    LinkedList<T>* tmp = m_list->filter(function);
    LinkedListSequence<T, AllocatorT>* result =
            new LinkedListSequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT*
LinkedListSequence<T, AllocatorT>::
getSubSequence(int startIndex, int endIndex) const {
    LinkedList<T>* tmp = m_list->getSubList(startIndex, endIndex);
    LinkedListSequence<T, AllocatorT>* result =
            new LinkedListSequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename LinkedListSequence<T, AllocatorT>::
SequenceT*
LinkedListSequence<T, AllocatorT>::
concat(SequenceT& sequence) const {
    LinkedListSequence<T, AllocatorT>* result =
            new LinkedListSequence<T, AllocatorT>(*this);
    for (int i = 0; i < sequence.getSize(); i++) {
        result->append(sequence.getItem(i));
    }
    return result;
}

template <typename T, typename AllocatorT>
T
LinkedListSequence<T, AllocatorT>::
reduce(T (*function)(const T& previousValue, const T& currentValue)) {
    return m_list->reduce(function);
}



template <typename T, typename AllocatorT>
std::ostream& operator<< (std::ostream &out, const LinkedListSequence<T, AllocatorT>& list) {
    out << "<";
    for (int i = 0; i < list.getSize() - 1; i++) {
        out << list.getItem(i) << ", ";
    }
    if (list.getSize() > 0)
        out << list.getItem(list.getSize() - 1);
    out << ">";
    return out;
}



