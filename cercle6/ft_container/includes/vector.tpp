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
#include <type_traits>
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
				T *_data;

			
		//┌───────────────────────────────────┐
		//│ CONSTRUCTOR					   │
		//└───────────────────────────────────┘

		public:
			explicit vector (const allocator_type& alloc = allocator_type()): _capacity(0), _dataCounter(0), _data(0), _myAlloc(alloc) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _myAlloc(alloc), _dataCounter(0) {
				_capacity = n * 2;
				_data = _myAlloc.allocate(n);
				for (; _dataCounter < n; _dataCounter++) {
					_myAlloc.construct(_data + _dataCounter, val);
				}
			}
			
			template <class InputIterator>
			explicit vector (InputIterator first,
							InputIterator last,
							const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) : _myAlloc(alloc)
			{
				int distance = std::distance(first, last); 
				this->_capacity = distance;
				_data = _myAlloc.allocate(distance);
				while (first != last) {
					this->_myAlloc.construct(this->_data + this->_dataCounter, *first);
					this->_dataCounter++;
					first++;
				}
			}

			explicit vector (const vector& x) : _capacity(x._capacity), _dataCounter(0) {
				this->_myAlloc = x._myAlloc;
				this->_data = _myAlloc.allocate(this->_capacity);
				for (int i = 0; i < this->_capacity; i++) {
					this->_myAlloc.construct(this->_data + this->_dataCounter, x._data + this->_dataCounter);
					this->_dataCounter++;
				}
			}
			
		//┌───────────────────────────────────┐
		//│ DESTRUCTOR						│
		//└───────────────────────────────────┘
		
			~vector() {
				if (this->_capacity > 0) {
					for (size_type i = 0; i < this->_dataCounter; i++) {
						this->_myAlloc.destroy(this->_data + i);
					}
					this->_myAlloc.deallocate((this->_data), this->_capacity);
				}
			}
		
		//┌───────────────────────────────────┐
		//│ ITERATORS						 │
		//└───────────────────────────────────┘

			typedef ft::Iterator<T> iterator;
			typedef ft::Iterator<T const> const_iterator;
			typedef ft::ReverseIterator<T> reverse_iterator;
			typedef ft::ReverseIterator<T const> const_reverse_iterator;

		private:
		
			template <typename ite_type>
			ite_type takeFirst(void) {
				if (this->_dataCounter > 0)
					return (ite_type(&(this->_data[0])));
				else
					return (NULL);
			}
			
			template <typename ite_type>
			ite_type takeLast(void) {
				if (this->_dataCounter > 0)
					return (ite_type(&(this->_data[this->_dataCounter - 1])));
				else
					return (NULL);
			}
		
		public:
		
			iterator begin() { return (takeFirst<iterator>()); };
			const_iterator begin() const { return (takeFirst<const_iterator>()); };

			iterator end() { return (takeLast<iterator>() + 1); };
			const_iterator end() const { return (takeLast<const_iterator>() + 1); };

			reverse_iterator rbegin() { return (takeLast<reverse_iterator>()); };
			const_reverse_iterator rbegin() const { return (takeLast<const_reverse_iterator>()); };

			reverse_iterator rend() { return (takeFirst<reverse_iterator>() + 1); };
			const_reverse_iterator rend() const { return (takeFirst<const_reverse_iterator>() + 1); };
		
		//┌───────────────────────────────────┐
		//│ CAPACITY						  │
		//└───────────────────────────────────┘

			size_type size() const { return (this->_dataCounter); };
			size_type max_size() const { return (this->_myAlloc.max_size()); }
			
			void resize (size_type n, value_type val = value_type()) {
				if (n < this->_dataCounter) {
					for (int i = 0; i + n < this->_dataCounter; i++) {
						this->_myAlloc.destroy(this->_data + n + i);
						this->_dataCounter--;
					}
				}
				else {
					if (n > this->_capacity)
						this->reverve(n);
					while (n > this->_dataCounter) {
						this->_myAlloc.construct(this->_data + this->_dataCounter, val);
						this->_dataCounter++;
					}
				}
			}
			
			size_type capacity() const { return (this->_capacity); }

			bool empty() const { return ((this->_dataCounter == 0) ? true : false); }

			void reserve (size_type n) {
				pointer array;
				size_type nb_element = this->_dataCounter;
				size_type new_capacity = this->_capacity;
				while (n > new_capacity)
					new_capacity *= 2;
				if (new_capacity > this->max_size())
					throw std::length_error("vector::reserve");
				if (new_capacity != this->_capacity) {
					array = this->_myAlloc.allocate(new_capacity);
					std::uninitialized_copy(this->begin(), this->end(), array);
					this->clear();
					this->_dataCounter = nb_element;
					this->_myAlloc.deallocate(this->_data, this->_capacity);
					this->_data = array;
					this->_capacity = new_capacity;
				}
			}

		//┌───────────────────────────────────┐
		//│ ELEMENT ACCESS					│
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

			reference back() { return (this->_data[this->_dataCounter]); }
			const_reference back() const { return (this->_data[this->_dataCounter]); }

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
				this->insert(this->_start, n, val);
			}

			void push_back (const value_type& val) {
				if (this->_dataCounter == this->_capacity)
					this->reserve(this->_dataCounter + 1);
				this->_myAlloc.construct(this->_data + this->_dataCounter, val);
				this->_dataCounter++;
			}

			void pop_back() {
				if (this->_dataCounter > 0) {
					this->erase(this->_data[this->_dataCounter - 1]);
				}
			}

		private:

			void fill_until(iterator it, iterator position, pointer tmp) {
				while (it != position && it != this->end()) {

				}
			}

		public:

			iterator insert (iterator position, const value_type& val) {
				pointer tmp;
				if (this->_dataCounter == this->_capacity)
					this->reserve(this->_dataCounter + 1);
				tmp = this->_myAlloc.allocate(this->capacity());
				iterator it = this->begin();
				fill_until(it, position, iterator(&tmp) + );
			}
			//void insert (iterator position, size_type n, const value_type& val);
			//template <class InputIterator>
			//void insert (iterator position, InputIterator first, InputIterator last);
		
			iterator erase(iterator position) {
				
				while (position != this->end() && position + 1 != this->end()) {
					this->_myAlloc.destroy(position);
					this->_myAlloc.constuct(position, *(position + 1));
					position++;
				}
				this->_dataCounter--;
			}

			iterator erase (iterator first, iterator last) {
				int distance = std::distance(first, last);
				for (iterator it = first; it != last; it++)
					this->myAlloc.destroy(it);
				while (first != this->end() && first + distance != this->end()) {
					this->_myAlloc.constuct(first, *(first + distance));
					first++;
				}
				this->_dataCounter -= distance;
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
				if (this->_capacity > 0) {
					for (size_type i = 0; i < this->_dataCounter; i++) {
						this->_myAlloc.destroy(this->_data + i);
					}
					this->_dataCounter = 0;
				}
			};

	};
}

#endif