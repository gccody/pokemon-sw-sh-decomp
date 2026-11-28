// Unk_a7bb80_Views::Unk_a7bb80, the lookup of a view by name. Included after
// the declarations of Unk_a7bb80_Views and Unk_23f4660: contents/common/views.h
// has contents/common/framework.h's, and the files of src/unsorted/views
// (tools/viewgen.py) declare their own, with the type getters each instance
// inlines. Needs contents/common/cast.h.

// The first element in [first, last) that pred holds for, else last. Not
// std::find_if: the original returns last itself when nothing is found,
// which libc++'s (returning first) doesn't compile to.
template <class It, class Pred>
inline It Unk_FindIf(It first, It last, Pred pred) {
    for (It it = first; it != last; ++it)
        if (pred(*it))
            return it;
    return last;
}

template <class T>
T* Unk_a7bb80_Views::Unk_a7bb80(const Unk_5cfaf0_Name& name) {
    auto it = Unk_FindIf(field_78.begin(), field_78.end(), [name](Unk_23f4660* view) {
        return view->field_5c0.Unk_5cfaf0() == name;
    });
    if (it == field_78.end())
        return nullptr;
    return Unk_DynamicCast<T>(*it);
}
