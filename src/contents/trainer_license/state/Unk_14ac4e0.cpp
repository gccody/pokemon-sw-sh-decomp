// Scope: common
//
// The League Card views' tables (Unk_14aae90.h) moving to a new buffer: the
// shape of boost::container::vector's priv_forward_range_insert_new_allocation
// with a range proxy, the copy of each table's reserve (0 elements to insert).
#include "contents/trainer_license/state/Unk_14aae90.h"

// Moves [first, last) to `to`, returning the end of what it made.
template <class T>
static T* Unk_14ac4e0_MoveRange(Unk_2771620_Allocator<T>& allocator, T* first, T* last, T* to) {
    while (first != last) {
        allocator.construct(to, static_cast<T&&>(*first));
        ++first;
        ++to;
    }
    return to;
}

// Moves `count` entries from `first` to `to`.
template <class T>
static T* Unk_14ac4e0_MoveCount(Unk_2771620_Allocator<T>& allocator, T* first, u64 count, T* to) {
    while (count--) {
        allocator.construct(to, static_cast<T&&>(*first));
        ++first;
        ++to;
    }
    return first;
}

template <class T>
static void Unk_14ac4e0_Destroy(T* p, u64 count) {
    while (count--) {
        p->~T();
        ++p;
    }
}

// Moves the table's entries to `start` (`capacity` entries), with `count`
// entries moved from `first` at `pos`, and frees the old buffer.
template <class T>
static void Unk_14ac4e0_Move(Unk_14aaec0_Table<T>* table,
                             T* start,
                             u64 capacity,
                             T* pos,
                             u64 count,
                             T* first) {
    T* finish = start;
    T* old = table->data;
    if (old != nullptr)
        finish = Unk_14ac4e0_MoveRange(table->field_0, table->data, pos, finish);
    first = Unk_14ac4e0_MoveCount(table->field_0, first, count, finish);
    finish += count;
    if (old != nullptr) {
        finish = Unk_14ac4e0_MoveRange(table->field_0, pos, old + table->size, finish);
        Unk_14ac4e0_Destroy(old, table->size);
        table->field_0.deallocate(table->data, table->capacity);
    }
    table->data = start;
    table->size = finish - start;
    table->capacity = capacity;
}

// 0x71014ac4e0
// NON_MATCHING: register allocation (the new buffer, the count and the allocator
// take other registers), and the free's alignment is set before its slot is
// loaded.
void Unk_14ac4e0(Unk_14aaec0_Table<Unk_14abaf0_Entry>* table,
                 Unk_14abaf0_Entry* start,
                 u64 capacity,
                 Unk_14abaf0_Entry* pos,
                 u64 count,
                 Unk_14abaf0_Entry* first) {
    Unk_14ac4e0_Move(table, start, capacity, pos, count, first);
}

// 0x71014ac740
// NON_MATCHING: register allocation (the new buffer, the count and the allocator
// take other registers), and the free's alignment is set before its slot is
// loaded.
void Unk_14ac740(Unk_14aaec0_Table<Unk_14abaa0_Entry>* table,
                 Unk_14abaa0_Entry* start,
                 u64 capacity,
                 Unk_14abaa0_Entry* pos,
                 u64 count,
                 Unk_14abaa0_Entry* first) {
    Unk_14ac4e0_Move(table, start, capacity, pos, count, first);
}

// 0x71014ac970
// NON_MATCHING: register allocation (the new buffer, the count and the allocator
// take other registers), and the free's alignment is set before its slot is
// loaded.
void Unk_14ac970(Unk_14aaec0_Table<Unk_14ab180_Entry>* table,
                 Unk_14ab180_Entry* start,
                 u64 capacity,
                 Unk_14ab180_Entry* pos,
                 u64 count,
                 Unk_14ab180_Entry* first) {
    Unk_14ac4e0_Move(table, start, capacity, pos, count, first);
}
