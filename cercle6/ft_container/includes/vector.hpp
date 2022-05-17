/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vector.tpp										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lusokol <lusokol@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/13 14:07:52 by lusokol		   #+#	#+#			 */
/*   Updated: 2022/05/04 16:46:12 by lusokol		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "iterator.hpp"
#include "enable_if.tpp"
#include "is_integral.tpp"
#include "lexicographical_compare.tpp"

namespace ft {
		
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		
		public:

			// typedef //
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			
			typedef std::ptrdiff_t				difference_type;
			typedef size_t						size_type;
			typedef std::forward_iterator_tag	iterator_category;
			
		protected:

				allocator_type _myAlloc;
				size_type _capacity;
				size_type _dataCounter;
				pointer _data;

			
		//┌───────────────────────────────────┐
		//│ CONSTRUCTOR					      │
		//└───────────────────────────────────┘

		public:
			explicit vector (const allocator_type& alloc = allocator_type()): _myAlloc(alloc) , _capacity(0), _dataCounter(0), _data(NULL) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _myAlloc(alloc), _capacity(0), _dataCounter(0), _data(NULL) {
				this->assign(n, val);
			}
			
			template <class InputIterator>
			explicit vector (InputIterator first,
							InputIterator last,
							const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) : _myAlloc(alloc), _capacity(0), _dataCounter(0), _data(NULL)
			{
				int distance = std::distance(first, last); 
				this->_capacity = distance;
				this->_data = this->_myAlloc.allocate(distance);
				while (first != last) {
					this->_myAlloc.construct(this->_data + this->_dataCounter, *first);
					this->_dataCounter++;
					first++;
				}
			}

			vector (vector<T, Alloc> const &x) : _myAlloc(x._myAlloc), _capacity(x._dataCounter), _dataCounter(0), _data(NULL) {
				this->_data = this->_myAlloc.allocate(x._dataCounter);
				for (size_type i = 0; i < x._dataCounter; i++) {
					this->push_back(*(x._data + this->_dataCounter));
				}
			}
			


		//┌───────────────────────────────────┐
		//│ OPERATOR=                         │
		//└───────────────────────────────────┘

			vector& operator= (const vector& x) {
				if (this != &x)
					this->assign(x.begin(), x.end());
				return (*this);
			}


		//┌───────────────────────────────────┐
		//│ DESTRUCTOR						  │
		//└───────────────────────────────────┘
		
			~vector() {
				if (this->_capacity > 0) {
					if (this->_dataCounter > 0)
						this->clear();
					if (this->_data != NULL) {
						this->_myAlloc.deallocate((this->_data), this->_capacity);
						this->_data = NULL;
					}
				}
			}
		
		//┌───────────────────────────────────┐
		//│ ITERATORS						 │
		//└───────────────────────────────────┘

			typedef ft::Iterator<T> iterator;
			typedef ft::Iterator<T const> const_iterator;
			typedef ft::ReverseIterator<iterator> reverse_iterator;
			typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

		private:
		
			template <typename ite_type>
			ite_type takeFirst(void) {
					return (ite_type(_data));
			}
			
			template <typename ite_type>
			ite_type takeLast(void) {
					return (this->begin() + _dataCounter);
			}
			
			template <typename ite_type>
			ite_type takeFirst(void) const {
					return (ite_type(_data));
			}
			
			template <typename ite_type>
			ite_type takeLast(void) const {
					return (this->begin() + _dataCounter);
			}
		
		public:
		
			iterator begin() { return (takeFirst<iterator>()); };
			const_iterator begin() const { return (takeFirst<const_iterator>()); };

			iterator end() { return (takeLast<iterator>()); };
			const_iterator end() const { return (takeLast<const_iterator>()); };

			reverse_iterator rbegin() { return (takeLast<reverse_iterator>()); };
			const_reverse_iterator rbegin() const { return (takeLast<const_reverse_iterator>()); };

			reverse_iterator rend() { return (takeFirst<reverse_iterator>()); };
			const_reverse_iterator rend() const { return (takeFirst<const_reverse_iterator>()); };
		
		//┌───────────────────────────────────┐
		//│ CAPACITY						  │
		//└───────────────────────────────────┘

			size_type size() const { return (this->_dataCounter); };
			size_type max_size() const { return (this->_myAlloc.max_size()); }
			
			void resize (size_type n, value_type const &val = value_type()) {
				if (n < this->_dataCounter) {
					iterator tmp(this->begin() + n);
					while (tmp != this->end()) {
						this->pop_back();
					}
				}
				else {
					if (n > this->_capacity * 2)
						this->reserve(n);
					while (n > this->_dataCounter) {
						this->push_back(val);
					}
				}
			}
			
			size_type capacity() const { return (this->_capacity); }

			bool empty() const { return (this->_dataCounter == 0); }

			void reserve (size_type n) {
				if (n > this->_capacity) {
					pointer array;
					size_type nb_element = this->_dataCounter;
					size_type new_capacity = n;
					if (new_capacity > this->max_size())
						throw std::length_error("vector::reserve");
					if (new_capacity > this->_capacity) {
						array = this->_myAlloc.allocate(new_capacity);
						if (this->_dataCounter > 0)
							std::uninitialized_copy(this->begin(), this->end(), array);
						this->clear();
						this->_dataCounter = nb_element;
					this->_myAlloc.deallocate(this->_data, this->_capacity);
						this->_data = array;
						this->_capacity = new_capacity;
					}
				}
			}

		//┌───────────────────────────────────┐
		//│ ELEMENT ACCESS					  │
		//└───────────────────────────────────┘

			reference operator[] (size_type n) { return (this->_data[n]); }
			const_reference operator[] (size_type n) const { return (this->_data[n]); }
			
			reference at(size_type n) {
				if (n >= this->size())
					throw std::out_of_range("vector::at");
				return (this->_data[n]);
			}
			const_reference at(size_type n) const {
				if (n >= this->size())
					throw std::out_of_range("vector::at");
				return (this->_data[n]);
			}

			reference front() { return (this->_data[0]); }
			const_reference front() const { return (this->_data[0]); }

			reference back() { return (this->_data[this->_dataCounter - 1]); }
			const_reference back() const { return (this->_data[this->_dataCounter - 1]); }

		//┌───────────────────────────────────┐
		//│ MODIFIERS						 │
		//└───────────────────────────────────┘

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				this->clear();
				this->insert(this->begin(), first, last);
			}
			
			void	assign(size_type n, T const &val) {
				this->clear();
				this->insert(this->begin(), n, val);
			}

			void push_back (const value_type& val) {
				if (this->_dataCounter >= this->_capacity) {
					this->reserve((this->_capacity == 0) ? 1 : this->_capacity * 2);
				}
				this->_myAlloc.construct(this->_data + this->_dataCounter, val);
				this->_dataCounter++;
			}

			void pop_back() {
				if (this->_dataCounter > 0) {
					this->_myAlloc.destroy(this->_data + this->_dataCounter - 1);
					this->_dataCounter--;
				}
			}

		private:

			void insert_base(iterator position, int n, const value_type& val) {
				ft::vector<T> cpy;
				size_type diff = std::distance(this->begin(), position);
				if (this->_dataCounter + n >= this->_capacity * 2)
					cpy.reserve(this->_dataCounter + n);
				else if (this->_dataCounter + n >= this->_capacity)
					cpy.reserve(this->_dataCounter * 2);
				else
					cpy.reserve(this->_capacity);
				size_type index = 0;
				for (; index < diff; index++)
					cpy.push_back(this->_data[index]);
				for (int i = 0; i < n; i++)
					cpy.push_back(val);
				for (; index < this->size(); index++) {
					cpy.push_back(this->_data[index]);
				}
				this->swap(cpy);
			}

		public:

			iterator insert (iterator position, const value_type& val) {
				difference_type tmp = std::distance(this->begin(), position);
				insert_base(position, 1, val);
				return (this->begin() + tmp);
			}
			
			void insert (iterator position, size_type n, const value_type& val) {
				insert_base(position, n, val);
			}

			template <class InputIterator>
			void insert (iterator position, 
						InputIterator first,
						InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) {
				ft::vector<T> cpy;
				size_type diff = std::distance(this->begin(), position);
				size_type n = std::distance(first, last);
				if (this->_dataCounter + n >= this->_capacity * 2)
					cpy.reserve(this->_dataCounter + n);
				else if (this->_dataCounter + n >= this->_capacity)
					cpy.reserve((this->_dataCounter + n )* 2);
				else
					cpy.reserve(this->_capacity);
				size_type index = 0;
				for (; index < diff; index++)
					cpy.push_back(this->_data[index]);
				for (; first != last; first++)
					cpy.push_back(*first);
				for (; index < this->size(); index++) {
					cpy.push_back(this->_data[index]);
				}
				this->swap(cpy);
			}
		
			iterator erase(iterator position) {
				int ret = std::distance(this->begin(), position);
				if (position + 1 == this->end())
					this->pop_back();
				else {
					while (position != this->end() && position + 1 != this->end()) {
						this->_myAlloc.destroy(&*position);
						this->_myAlloc.construct(&*position, *(position + 1));
						position++;
					}
					this->_myAlloc.destroy(&*position);
					this->_dataCounter--;
				}
				return (iterator(this->begin()) + ret);
			}

			iterator erase(iterator first, iterator last) {
				int ret = std::distance(this->begin(), first);
				int distance = std::distance(first, last);
				for (iterator it = first; it != last; it++) {
					this->_myAlloc.destroy(&*it);
				}
				while (first != this->end() && first + distance != this->end()) {
					this->_myAlloc.construct(&*first, *(first + distance));
					this->_myAlloc.destroy(&*(first + distance));
					first++;
				}
				this->_dataCounter -= distance;
				return (iterator(this->begin()) + ret);
			}

		private:

			template <class Swap>
			void ft_swap(Swap &a, Swap &b) {
				Swap tmp = a;
				a = b;
				b = tmp;
			}
					
		public:
		
			void swap(vector& x) {
				ft_swap(this->_data, x._data);
				ft_swap(this->_myAlloc, x._myAlloc);
				ft_swap(this->_dataCounter, x._dataCounter);
				ft_swap(this->_capacity, x._capacity);
			}


			void clear() {
				if (this->_data)
					this->erase(this->begin(), this->end());
			};

			allocator_type get_allocator() const { return (this->_myAlloc); }


	};

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		  x.swap(y);
	  }

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs || lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs > rhs || lhs == rhs);
	}
}

#endif