#include "Node.h"

template <class _Ty> Node<_Ty>::Node() {

}

template <class _Ty> Node<_Ty>::Node(_Ty _data) {
	data = _data;
	next = NULL;
}

template <class _Ty> Node<_Ty>::~Node() {

}