template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
DynamicArraySequence()
        : m_array( new DynamicArray<T>() ) {}

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
DynamicArraySequence(int size)
        : m_array( new DynamicArray<T>(size) ) {}

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
DynamicArraySequence(T* items, int size)
        : m_array( new DynamicArray<T>(items, size) ) {};

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
DynamicArraySequence(const DynamicArraySequence<T, AllocatorT>& another)
        : m_array( new DynamicArray<T>(*another.m_array) ) {};

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
DynamicArraySequence(const DynamicArray<T>& array)
        : m_array( new DynamicArray<T>(array) ) {}

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>&
DynamicArraySequence<T, AllocatorT>::
operator= (const DynamicArraySequence<T, AllocatorT>& another) {
    if (&another != this)
        m_array = new DynamicArray<T>(*another.m_array);
    return *this;
}

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>&
DynamicArraySequence<T, AllocatorT>::
operator= (DynamicArraySequence<T, AllocatorT>* another) {
    if (&another != this)
        m_array = new DynamicArray<T>(*another->m_array);
    return *this;
}

template <typename T, typename AllocatorT>
DynamicArraySequence<T, AllocatorT>::
~DynamicArraySequence() {
    delete m_array;
}

template <typename T, typename AllocatorT>
T DynamicArraySequence<T, AllocatorT>::
getItem(int index) const {
    return m_array->getItem(index);
}

template <typename T, typename AllocatorT>
int DynamicArraySequence<T, AllocatorT>::
getSize() const {
    return m_array->getSize();
}

template <typename T, typename AllocatorT>
T DynamicArraySequence<T, AllocatorT>::
getFirst() const {
    return m_array->getFirst();
}

template <typename T, typename AllocatorT>
T DynamicArraySequence<T, AllocatorT>::
getLast() const {
    return m_array->getLast();
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::
insert(int index, const T& item) {
    m_array->insert(index, item);
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::
remove(int index) {
    m_array->remove(index);
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::
append(const T& item) {
    m_array->push(item);
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::
prepend(const T& item) {
    m_array->unshift(item);
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::clear() {
    m_array->clear();
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::pop() {
    m_array->pop();
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT&
DynamicArraySequence<T, AllocatorT>::
shift() {
    m_array->shift();
    return *this;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT*
DynamicArraySequence<T, AllocatorT>::
map(T (*function)(const T& item)) {
    DynamicArray<T>* tmp = m_array->map(function);
    DynamicArraySequence<T, AllocatorT>* result =
            new DynamicArraySequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::SequenceT*
DynamicArraySequence<T, AllocatorT>::
filter(bool (*function)(const T& item)) {
    DynamicArray<T>* tmp = m_array->filter(function);
    DynamicArraySequence<T, AllocatorT>* result =
            new DynamicArraySequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT*
DynamicArraySequence<T, AllocatorT>::
getSubSequence(int startIndex, int endIndex) const {
    DynamicArray<T>* tmp = m_array->getSubList(startIndex, endIndex);
    DynamicArraySequence<T, AllocatorT>* result =
            new DynamicArraySequence<T, AllocatorT>(*tmp);
    delete tmp;
    return result;
}

template <typename T, typename AllocatorT>
typename DynamicArraySequence<T, AllocatorT>::
SequenceT*
DynamicArraySequence<T, AllocatorT>::
concat(SequenceT& sequence) const {
    DynamicArraySequence<T, AllocatorT>* result =
            new DynamicArraySequence<T, AllocatorT>(*this);
    for (int i = 0; i < sequence.getSize(); i++) {
        result->append(sequence.getItem(i));
    }
    return result;
}

template <typename T, typename AllocatorT>
T DynamicArraySequence<T, AllocatorT>::
reduce(T (*function)(const T& previousValue, const T& currentValue)) {
    return m_array->reduce(function);
}


template <typename T, typename AllocatorT>
std::ostream& operator<< (std::ostream &out, const DynamicArraySequence<T, AllocatorT>& array) {
    out << "[";
    for (int i = 0; i < array.getSize() - 1; i++) {
        out << array.getItem(i) << ", ";
    }
    if (array.getSize() > 0)
        out << array.getItem(array.getSize() - 1);
    out << "]";
    return out;
}

template <typename T, typename AllocatorT>
T& DynamicArraySequence<T, AllocatorT>::operator[]
(int index) {
    return (*m_array)[index];
}


