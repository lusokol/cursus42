/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:43:21 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/17 15:21:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
//#include <type_traits>
#include <iostream>

namespace ft {

    template <typename Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <typename Traits>
    struct iterator_traits<Traits *> {
        typedef std::ptrdiff_t difference_type;
        typedef Traits value_type;
        typedef Traits * pointer;
        typedef Traits & reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename Traits>
    struct iterator_traits<Traits * const> {
        typedef std::ptrdiff_t difference_type;
        typedef Traits value_type;
        typedef const Traits* pointer;
        typedef const Traits& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    class Iterator {
        
        private:
            T *_ptr;
            typedef iterator_traits<T *> _traits;
            
        public:
            typedef typename _traits::difference_type   difference_type;
            typedef typename _traits::value_type        value_type;
            typedef typename _traits::pointer           pointer;
            typedef typename _traits::reference         reference;
            typedef typename _traits::iterator_category iterator_category;

			pointer const &base(void) const { return (this->_ptr); }

            //================= constructor / copy / destructor =================//
            Iterator(void): _ptr(0) {}
            Iterator(pointer ptr): _ptr(ptr) {}
            template <typename U>
                Iterator(Iterator<U> const &ref) : _ptr(ref.base()) {}
            ~Iterator(void) {}

            //============================ operator =============================//
            friend bool operator==(const Iterator &a, const Iterator &b) { return a._ptr == b._ptr; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a._ptr != b._ptr; };
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            Iterator &operator=(Iterator<T> const &ref) {
                this->_ptr = ref._ptr;
                return (*this);
            }
            Iterator &operator=(pointer ptr) {
                this->_ptr = ptr;
                return (*this);
            }
            Iterator &operator++() {
                _ptr++;
                return *this;
            }
            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            Iterator &operator--() {
                this->_ptr--;
                return *this;
            }
            Iterator operator--(int) {
                Iterator tmp = *this;
                --(*this);
                return tmp;
            }

            
            Iterator operator+(difference_type n) const {
                return Iterator(this->_ptr + n);
            }
            Iterator operator-(difference_type n) const {
                return Iterator(this->_ptr - n);
            }
            difference_type operator+(Iterator<T> const &ref) const {
                return (this->_ptr + ref._ptr);
            }
            difference_type operator-(Iterator<T> const &ref) const {
                return (this->_ptr - ref._ptr);
            }
			Iterator operator+=(difference_type n) {
				this->_ptr += n;
                return *this;
            }
			Iterator operator-=(difference_type n) {
				this->_ptr -= n;
                return *this;
            }

			bool operator<(Iterator &ref) {
				return (this->_ptr < ref._ptr);
			}
			bool operator>(Iterator &ref) {
				return (this->_ptr > ref._ptr);
			}
			 
			friend bool operator<(const   Iterator& a, const   Iterator& b) { return (a._ptr < b._ptr); };
			friend bool operator>(const   Iterator& a, const   Iterator& b) { return (a._ptr > b._ptr); };
			
			bool operator<=(Iterator &ref) {
				return (this->_ptr <= ref._ptr);
			}
			bool operator>=(Iterator &ref) {
				return (this->_ptr >= ref._ptr);
			}
			reference operator[](difference_type n) const {
				return *(this->_ptr + n);
			}
    };

	// Forward iterator requirements

	template <typename T, typename U>
	bool	operator==(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T, typename U>
	bool	operator!=(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() != rhs.base());
	}

// Random access iterator requirements

	template <typename T, typename U>
	bool	operator<=(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <typename T, typename U>
	bool	operator>=(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T, typename U>
	bool	operator<(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename T, typename U>
	bool	operator>(Iterator<T> const &lhs,
	Iterator<U> const &rhs) {
		return (lhs.base() > rhs.base());
	}

// Operators '-' and '+' must also work with different types

	template <typename T>
	Iterator<T>	operator+(
	typename Iterator<T>::difference_type n,
	const Iterator<T>&iter) {
		return (Iterator<T>(iter.base() + n));
	}

	template <typename T>
	Iterator<T>	operator-(
	typename Iterator<T>::difference_type n,
	const Iterator<T>&iter) {
		return (Iterator<T>(iter.base() - n));
	}

	template <typename T>
    class ReverseIterator {        

		private:
            T _ptr;
            typedef iterator_traits<T> _traits;
            
        public:
            typedef typename _traits::difference_type   difference_type;
            typedef typename _traits::value_type        value_type;
            typedef typename _traits::pointer           pointer;
            typedef typename _traits::reference         reference;
            typedef typename _traits::iterator_category iterator_category;
			typedef T iterator_type;

			T base(void) const { return (this->_ptr); }

            //================= constructor / copy / destructor =================//
            ReverseIterator(void): _ptr(0) {}
            ReverseIterator(iterator_type ptr): _ptr(ptr) {}
            template <typename U>
                ReverseIterator(ReverseIterator<U> const &ref) : _ptr(ref.base()) {}
            //template <typename U>
            //    ReverseIterator(Iterator<U> const &ref) : _ptr(ref.base()) {}
            ~ReverseIterator(void) {}

            //============================ operator =============================//
            friend bool operator==(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr == b._ptr; };
            friend bool operator!=(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr != b._ptr; };
            reference operator*() const {
				iterator_type tmp = this->_ptr;
				--tmp;
				return *tmp;
			}
            pointer operator->() {
				iterator_type tmp = this->_ptr;
				--tmp;
				return &*tmp;
			}
			//ReverseIterator operator=(const ReverseIterator& a){_ptr = a._ptr; return (*this);}
            //ReverseIterator &operator=(ReverseIterator<T> const &ref) {
            //    this->_ptr = ref.base();
            //    return (*this);
            //}
            //ReverseIterator &operator=(pointer ptr) {
            //    this->_ptr = ptr;
            //    return (*this);
            //}
            ReverseIterator &operator++() {
                --(this->_ptr);
                return *this;
            }
            ReverseIterator operator++(int) {
                ReverseIterator tmp = *this;
                --(this->_ptr);
                return tmp;
            }
            ReverseIterator &operator--() {
                ++(this->_ptr);
                return *this;
            }
            ReverseIterator operator--(int) {
                ReverseIterator tmp = *this;
                ++(this->_ptr);
                return tmp;
            }

            
            ReverseIterator operator+(difference_type n) const {
                return (ReverseIterator(this->_ptr - n));
            }
            ReverseIterator operator-(difference_type n) const {
                return (ReverseIterator(this->_ptr + n));
            }
            difference_type operator+(ReverseIterator<T> const &ref) const {
                return (this->_ptr + ref._ptr);
            }
            difference_type operator-(ReverseIterator<T> const &ref) const {
                return (ref._ptr - this->_ptr);
            }
			ReverseIterator operator+=(difference_type n) {
				this->_ptr -= n;
                return *this;
            }
			ReverseIterator operator-=(difference_type n) {
				this->_ptr += n;
                return *this;
            }

			bool operator<(ReverseIterator &ref) {
				return (this->_ptr > ref._ptr);
			}
			bool operator>(ReverseIterator &ref) {
				return (this->_ptr < ref._ptr);
			}
			bool operator<=(ReverseIterator &ref) {
				return (this->_ptr >= ref._ptr);
			}
			bool operator>=(ReverseIterator &ref) {
				return (this->_ptr <= ref._ptr);
			}
			reference operator[](difference_type n) const {
				return *(this->_ptr - n - 1);
			}
			// operator	ReverseIterator<T const>(void) const {
			// 	return (ReverseIterator<T const>(this->_ptr));
			// }
    };;

	template <typename Iter1, typename Iter2>
	bool	operator==(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename Iter1, typename Iter2>
	bool	operator<(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename Iter1, typename Iter2>
	bool	operator!=(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename Iter1, typename Iter2>
	bool	operator>(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename Iter1, typename Iter2>
	bool	operator>=(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <typename Iter1, typename Iter2>
	bool	operator<=(
	ReverseIterator<Iter1> const &lhs,
	ReverseIterator<Iter2> const &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename Iterator>
	ReverseIterator<Iterator>	operator+(
	typename ReverseIterator<Iterator>::difference_type n,
	ReverseIterator<Iterator> const &iter) {
		return (iter + n);
	}

	template <typename Iterator>
	typename ReverseIterator<Iterator>::difference_type	operator+(
	ReverseIterator<Iterator> const &lhs,
	ReverseIterator<Iterator> const &rhs) {
		return (lhs.base() + rhs.base());
	}
	
}

#endif