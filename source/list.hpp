#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
#include <iostream>

template <typename T>
struct List;
template <typename T>
struct ListNode{
	ListNode(): m_value(),m_prev(nullptr),m_next(nullptr) {}
	ListNode(T const& v, ListNode* prev, ListNode* next): m_value(v), m_prev(prev),m_next(next) {}
	T m_value;
	ListNode* m_prev;
	ListNode* m_next;
};
template <typename T>
struct ListIterator
{
	typedef ListIterator<T> Self;

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;
	friend class List <T>;

	ListIterator(): m_node(nullptr) {
	}
	ListIterator(ListNode <T>* n): m_node(n) {
	}
	reference operator* () const{
		return m_node->m_value;
	}

	pointer operator->() const{
		return *(m_node->m_value);
	}

	Self& operator++(){
		*this = next();
		return *this;
	}

	Self operator++(int x){
		while(x>0){
				*this=next();
				x--;
		return *this;
		}
	}

	bool operator==(const Self& x) const{
		return m_node==x.m_node;
	}

	bool operator!=(const Self& x) const{
		return m_node!=x.m_node;
	}

	Self next() const{
		if (m_node){
				return ListIterator(m_node -> m_next);
			}
		else{
			return ListIterator(nullptr);
		}
	}

	ListNode<T>* getNode() const{
		return m_node;
	};
	
private :
	ListNode <T>* m_node = nullptr ;
};
template <typename T>
struct ListConstIterator
{
	friend class List <T>;
	public :
	private :
	ListNode <T>* m_node = nullptr ;
};
template <typename T>
class List
{
public :
	typedef T value_type;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef T & reference;
	typedef const T & const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;

	friend class ListIterator <T>;
	friend class ListConstIterator <T>;
	/*Default*/
	List(): m_size{0}, m_first{nullptr}, m_last{nullptr} {}

	bool empty() const{
		if(m_first==nullptr && m_last== nullptr) return true;
		return false;
	}
	
	std::size_t size() const{
		return m_size;
	}
	/*Copy*/
	List(List const& copy) : m_size{0}, m_first{nullptr}, m_last{nullptr}{
		ListIterator<T> ListIt = copy.begin();
		while(ListIt != copy.end()){
			push_back(*ListIt);
			ListIt++;
		}
		push_back(*ListIt);
	}

	/*Move*/
	List(List&& list): m_size{list.m_size}, m_first{list.m_first}, m_last{list.m_last}{
		list.m_size=0;
		list.m_first=nullptr;
		list,m_last=nullptr;
	}

	void push_front (T const& x){
		if(!empty()){
			m_first -> m_prev = new ListNode<T>{x, nullptr , m_first};
			m_first = m_first -> m_prev;
		}
		else{
			m_first = new ListNode<T>{x, m_last, nullptr};
			m_last= m_first;
		}
		m_size++;
	}

	void push_back (T const& x){
		if(!empty()){
			m_last -> m_next = new ListNode<T>{x, nullptr , m_first};
			m_last = m_last -> m_next;
		}
		else{
			m_last = new ListNode<T>{x, nullptr, nullptr};
			m_first= m_last;
		}
		m_size++;
	}

	void pop_front (){
		if(size()==1){
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
		}
		else if(!empty()){
			m_first= m_first ->m_next;
			delete m_first -> m_prev;
			m_first -> m_prev = nullptr;
		}
		m_size--;
	}

	void pop_back (){
		if(size()==1){
			delete m_last;
			m_first = nullptr;
			m_last = nullptr;
		}
		else if(!empty()){
			m_last= m_last ->m_prev;
			delete m_last -> m_next;
			m_last -> m_next = nullptr;
		}
		m_size--;
	}

	T& front(){
		return m_first -> m_value;
	}

	T& back(){
		return m_last -> m_value;
	}

	void clear(){
		while (!empty()){
			pop_back();
			}
	}

	~List(){
		clear();
	}

	iterator begin() const{
		return iterator(m_first);
	}

	iterator end() const{
		return iterator(m_last);
	}

	void insert(iterator const& iter, T const& x){
		ListNode<T>* input = new ListNode<T>(x, nullptr, nullptr);
		ListNode<T>* prev = iter.getNode() -> m_prev;
		ListNode<T>* next = iter.getNode() -> m_next;
		input-> m_prev = prev;
		input-> m_next = next;
		m_size++;
	}

	void reverse(){
		List<T> tmp{*this};
		clear();
		for (iterator iter = tmp.begin(); iter!=tmp.end(); iter++){
			push_front(*iter);
		}
		push_front(tmp.back());
	}	
private :
	std :: size_t m_size = 0;
	ListNode <T>* m_first = nullptr;
	ListNode <T>* m_last = nullptr;
};

template<typename T>
bool operator==(List<T> const& xs, List<T> const& ys)
{
	if (xs.size()!=ys.size()) return false;
	ListIterator<T> yIt = ys.begin();
	for(ListIterator<T> xIt = xs.begin(); xIt != xs.end(); ++xIt)
	{
		if(*xIt != *yIt) return false;
		++yIt;
	}
	return true;
}

template<typename T>
bool operator!=(List<T> const& xs, List<T> const& ys)
{
	if (xs.size()!=ys.size()) return true;
	ListIterator<T> yIt = ys.begin();
	for(ListIterator<T> xIt = xs.begin(); xIt != xs.end(); ++xIt)
	{
		if(*xIt == *yIt) return false;
		++yIt;
	}
	return true;
}

template<typename T>
List<T> reverse (List<T>& l) {
  l.reverse();
  return l;
}
# endif // # define BUW_LIST_HPP
