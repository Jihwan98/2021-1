#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
template <typename T>
class StackTemplate {
private:
	int topIdx;
	T* stackPtr;
public:
	StackTemplate(int size);
	~StackTemplate();
	void Push(const T& pushVal);
	T Pop();
	int getTopIdx();
};
template <typename T>
StackTemplate<T>::StackTemplate(int size) {
	stackPtr = new T[size];
	topIdx = -1;
}
template <typename T>
StackTemplate<T>::~StackTemplate() {
	delete[] stackPtr; stackPtr = NULL;
}
template <typename T>
void StackTemplate<T>::Push(const T& pushVal) {
	topIdx++;
	stackPtr[topIdx] = pushVal;
}
template <typename T>
T StackTemplate<T>::Pop() {
	return stackPtr[topIdx--];
}
template <typename T>
int StackTemplate<T>::getTopIdx() {
	return topIdx;
}
#endif