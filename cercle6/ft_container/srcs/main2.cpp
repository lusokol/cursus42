/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:23 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/31 18:34:38 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iterator>

#include "../includes/vector.hpp"
#include "../includes/stack.hpp"
#include "../includes/pair.hpp"
#include "../includes/map.hpp"


#include "../includes/rbt.hpp"


#include <vector>
#include <stack>
#include <map>





#ifndef STD
	#define TYPE ft
	#define ITER ReverseIterator
#else
	#define TYPE std
	#define ITER reverse_iterator
#endif



// A retirer
#include <sstream>
// #include <type_traits>
#include <list>

/* Invalid read of size x in valgrind are made by errors in the main
	this errors are here to compare with the real vector
*/


void	create_header(std::string const title) {
		std::cout << std::endl << std::endl << "|****" ;
		for (size_t i = 0; i < title.length(); i++) {
			std::cout << "*";
		}
		std::cout << "****|" << std::endl
			<< "|*   " << title << "   *|" << std::endl
			<< "|****" ;
		for (size_t i = 0; i < title.length(); i++) {
			std::cout << "*";
		}
		std::cout << "****|" << std::endl;
}

template <class T>
void	print_constructor(std::string title, TYPE::vector<T> &el) {
	std::cout << title << " : " << std::endl
				<< el.size() << " " << el.capacity()
				<< " | [";
	for (typename TYPE::vector<T>::iterator it = el.begin(); it < el.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}


void	vectorMegaTest() {
	/****************************/
	/*			Constructors	*/
	/****************************/
	create_header("Constructors");
	{
		TYPE::vector<float> defaultV;
		TYPE::vector<char>	fillV(3, 'd');
		TYPE::vector<char>	rangeV(fillV.begin()+1, fillV.end());
		TYPE::vector<char>	copyV(fillV);

		print_constructor("Default", defaultV);
		print_constructor("Fill", fillV);
		print_constructor("Range", rangeV);
		print_constructor("Copy", copyV);
	}


		/****************************/
		/*			Iterators		*/
		/****************************/
		create_header("Iterators");
	{
		/* Use .begin() and .end() */
		std::cout << std::endl << std::endl << "\tUse Iterator" << std::endl;
		TYPE::vector<int>	lol(4, 100);
		std::cout << lol.capacity() << ", is empty ?(no) "
			<< lol.empty() << std::endl;
		TYPE::vector<int>::iterator it = lol.begin();
		TYPE::vector<int>::iterator it_end = lol.end();
		while(it != it_end)
		{
			std::cout << " My iterator : "<< *it << std::endl;
			it++;
		}

		TYPE::vector<int> pouet(8, 5);
		TYPE::vector<int>::iterator pos = pouet.begin();
		while(pos != pouet.end())
			std::cout << *pos++ << std::endl;

		std::cout << "Range constructor !!!" << std::endl;
		pouet.push_back(122);
		TYPE::vector<int> ranger(pouet.begin() + 2, pouet.end() - 1);
		std::cout << "Ranger size : " << ranger.size()
			<< "\tlast value = "<< *(pouet.end() - 1) << std::endl;

		/* Use .rbegin() and .rend() */
		// std::vector<int>::reverse_iterator itB = lol.rbegin();
		// std::vector<int>::reverse_iterator itE = lol.rend();
	}
		/****************************/
		/*			Capacity		*/
		/****************************/
		create_header("Capacity");
	{
		/* Basics */
		std::cout << std::endl << std::endl << "\tUse .size(), .capacity(), .empty(), .max_size()" << std::endl;
		TYPE::vector<int> lel;
		TYPE::vector<std::string> empty_str;	
		std::cout << lel.size() << " | "
			<< lel.capacity() << " | "
			<< lel.empty() << " | " 
			<< lel.max_size() << std::endl;
		// std::cout << stdlel[0]; //segfault
		try
		{
			std::cout << "try to reserve over max_size" << std::endl;
			empty_str.reserve(empty_str.max_size() + 1);
		}
		catch(const std::length_error& e) {std::cerr << e.what() << '\n';}
	}
	{
		/* Use .reserve() */
		std::cout << std::endl << std::endl << "\tUse .reserve()" << std::endl;
		TYPE::vector<int>::size_type sz;

		TYPE::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		TYPE::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
		/* Use .resize() */
		std::cout << std::endl << std::endl << "\tUse .resize()" << std::endl;
		TYPE::vector<int> myvector;
		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';


		/****************************/
		/*			El access		*/
		/****************************/
		create_header("Element access");
		/* Use [] */
		std::cout << std::endl << std::endl << "\tUse []" << std::endl;
	{
		TYPE::vector<int> myvector (10);   // 10 zero-initialized elements
		TYPE::vector<int>::size_type sz = myvector.size();
		for (unsigned i=0; i<sz; i++) myvector[i]=i;	// assign some values
		for (unsigned i=0; i<sz/2; i++)	// reverse vector using operator[]
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}
		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		//std::cout << "out of range :" << myvector[15] << std::endl; // working but create invalid read (as expected)

		TYPE::vector<std::string> str(2, "Whaou !");
		for(int i = 0; i < 2; i++)
			std::cout << str[i] << std::endl;
		std::cout << "out of range : \"" << str[15] << "\"" << std::endl; // working but create invalid read (as expected)
		str.reserve(10);
		std::cout << "change reserve " << str.capacity() << " | " << str.size() << std::endl;
		for(size_t i = 0; i < str.size(); i++)
			std::cout << str[i] << std::endl;
	}	
		/* Use .at() */
		std::cout << std::endl << std::endl << "\tUse .at()" << std::endl;
	{
		TYPE::vector<int> myvector (10);   // 10 zero-initialized ints
		for (unsigned i=0; i<myvector.size(); i++) // assign some values
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	{
		TYPE::vector<int> myvector(10);
		try {
			myvector.at(20)=100;      // vector::at throws an out-of-range
		}
		catch (std::out_of_range& e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (const std::exception& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}

		/* Use .front() and .back() */
		std::cout << std::endl << std::endl << "\tUse .front() and .back()" << std::endl;
	{
		TYPE::vector<int> myvector;
		myvector.push_back(78);
		myvector.push_back(16); // now front equals 78, and back 16
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		TYPE::vector<float> empty_str;
		// std::cout << "|" << empty_str.front() << "| |"
		// 	<< empty_str.back() << "|" << std::endl; //! real segfault, man said undefined behavior sooooo
	}

		/****************************/
		/*			Modifiers		*/
		/****************************/
		create_header("Modifiers");
		/* Use assign() */
		std::cout << std::endl << std::endl << "\tUse .assign()" << std::endl;
	{
		TYPE::vector<int> first;
		TYPE::vector<int> second;
		TYPE::vector<int> third(10, 34);

		first.assign (7,100);             // 7 ints with a value of 100

		TYPE::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << " | " << int (second.capacity())  << '\n';
		std::cout << "Size of third: " << int (third.size()) << " | " << int (third.capacity()) << '\n';
	}

		/* Use push_back() and pop_back()*/
		std::cout << std::endl << std::endl << "\tUse .push_back() and .pop_back()" << std::endl;
	{
		TYPE::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		while (!myvector.empty()) {
			sum+=myvector.back();
			myvector.pop_back();
			std::cout << "current size : " << myvector.size() << std::endl;
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
		try {
			std::cout << "is empty : " << myvector.empty()
				<< std::endl << "myvector[1] : " << myvector[1] << std::endl;
				// << std::endl << "iterator.begin() : " << *myvector.begin() // real works but man said "If the container is empty, the returned iterator value shall not be dereferenced." soooooo
				// << std::endl << "iterator.end() : " << *myvector.end() << std::endl; // same
		}
		catch(const std::exception& e){std::cerr << e.what() << '\n';}
	}

		/* Use insert() */
		std::cout << std::endl << std::endl << "\tUse .insert()" << std::endl;
	{
		TYPE::vector<int> myvector (2,100);
		TYPE::vector<int>::iterator it;

		it = myvector.begin();
		std::cout << myvector.capacity() << std::endl;
		it = myvector.insert ( it+2, 200 );
		std::cout << myvector.capacity() << std::endl;

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (3,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<std::string> str(3, "base");
		std::vector<std::string>::iterator strIt;

		str.push_back("startEnd");
		strIt = str.begin();
		strIt = str.insert(strIt+1, "some news");

		for (strIt=str.begin(); strIt<str.end(); strIt++) {
			std::cout << *strIt << std::endl;
		}
	}

		/* Use erase() */
		std::cout << std::endl << std::endl << "\tUse .erase()" << std::endl;
	{
		TYPE::vector<int> myvector;
		TYPE::vector<int>::iterator retIt;
		for (int i=1; i<=10; i++) myvector.push_back(i);// set some values (from 1 to 10)
		retIt = myvector.erase (myvector.begin()+5); // erase the 6th element
		std::cout << "retIt val= " << *retIt << " " << std::endl;
		retIt = myvector.erase (myvector.begin(),myvector.begin()+3); // erase the first 3 elements:
		std::cout << "retIt val= " << *retIt << " " << std::endl;


		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n' << myvector[myvector.size() + 1];
	}

		/* Use swap() */
		// int adder = 4; // put to 0 to remove Invalid read size of x in valgrind
		std::cout << std::endl << std::endl << "\tUse .swap()" << std::endl;
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200
		std::vector<int>::iterator it = foo.begin();
		// std::vector<int>::iterator it4 = foo.begin() + adder;

		std::cout << "it addr before swap : " << *it << " | " << std::endl;
		// std::cout << "it4 addr before swap : " << *it4 << " | " << std::endl;
		std::cout << "foo " << &foo << " size | reserve : " << foo.size() << " | " << foo.capacity() << std::endl;
		std::cout << "bar " << &bar << " size | reserve : " << bar.size() << " | " << bar.capacity() << std::endl;
		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';

		std::cout << "it after swap : " << *it << " | " << std::endl;
		// std::cout << "it4 after swap must be garbage : " << *it4 << " | " << std::endl;
		std::cout << "foo " << &foo << " size | reserve : " << foo.size() << " | " << foo.capacity() << std::endl;
		std::cout << "bar " << &bar << " size | reserve : " << bar.size() << " | " << bar.capacity() << std::endl;
	}
	std::cout << std::endl;
	{
		TYPE::vector<int> foo (3,100);   // three ints with a value of 100
		TYPE::vector<int> bar (5,200);   // five ints with a value of 200
		TYPE::vector<int>::iterator it = foo.begin();
		// TYPE::vector<int>::iterator it4 = foo.begin() + adder;

		std::cout << "it addr before swap : " << *it << " | " << std::endl;
		// std::cout << "it4 addr before swap : " << *it4 << " | " << std::endl;
		std::cout << "foo " << &foo << " size | reserve : " << foo.size() << " | " << foo.capacity() << std::endl;
		std::cout << "bar " << &bar << " size | reserve : " << bar.size() << " | " << bar.capacity() << std::endl;
		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';

		std::cout << "it after swap : " << *it << " | " << std::endl;
		// std::cout << "it4 after swap must be garbage : " << *it4 << " | " << std::endl;
		std::cout << "foo " << &foo << " size | reserve : " << foo.size() << " | " << foo.capacity() << std::endl;
		std::cout << "bar " << &bar << " size | reserve : " << bar.size() << " | " << bar.capacity() << std::endl;
	}



		/* Use clear() */
		std::cout << std::endl << std::endl << "\tUse .clear()" << std::endl;
	{
		TYPE::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

		/****************************/
		/*			Allocator		*/
		/****************************/
		create_header("Allocator");
		/* Use get_allocator()*/
		std::cout << std::endl << std::endl << "\tUse .get_allocator()" << std::endl;
	{
		TYPE::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		std::cout << "The vector contains:";
		for (i=0; i<5; i++) {
			try{std::cout << ' ' << myvector.at(i);}
			catch(const std::exception& e) {std::cerr << e.what() << '\n';}
		}
		std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}

		/****************************/
		/*	Relational Operators	*/
		/****************************/
		create_header("Relational operators");
	{
		TYPE::vector<int> foo (3,100);   // three ints with a value of 100
		TYPE::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}

		/****************************/
		/*		Non-member swap		*/
		/****************************/	
		create_header("Non member swap");
	{
	TYPE::vector<int> foo (3,100);   // three ints with a value of 100
	TYPE::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (TYPE::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (TYPE::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	}

		//////////////////////////////////
		//			operator=			//
		//////////////////////////////////
		// vector<int> foo (3,0);
		// vector<int> bar (5,0);

		// bar = foo;
		// foo = vector<int>();

		// std::cout << "Size of foo: " << int(foo.size()) << '\n';
		// std::cout << "Size of bar: " << int(bar.size()) << '\n';


	// iterator tests
	create_header("Iterator tests");
	{
		std::vector<int> pouet(5, 8);
		pouet.push_back(2);
		pouet.push_back(3);
		pouet.push_back(4);
		//print all
		std::vector<int>::iterator start = pouet.begin();
		while (start != pouet.end()) {
			std::cout << "[" << *start << "] ";
			start++;
		}
		std::cout << std::endl;

		std::vector<int>::iterator defIt;
		// std::vector<int>::iterator assignIt = pouet.begin();
		defIt = pouet.begin(); // segfault without this (normal)
		std::vector<int>::iterator copyIt(defIt);
		defIt--;

		if (defIt < copyIt)
			{ std::cout << "defIt < copyIt" << std::endl;}
		if (++defIt == copyIt)
			{ std::cout << "defIt == copyIt" << std::endl;}

		int minusINT = pouet.begin() - pouet.end();
		std::vector<int>::iterator it = minusINT + pouet.end();
		std::cout << minusINT << " " << *it << std::endl;

		it = pouet.begin();
		it += 6;
		std::cout << "must be 3 : " << *it << std::endl;
		it -= 1;
		std::cout << "must be 2 : " << *it << std::endl;
	}
	std::cout << std::endl;

	{
		TYPE::vector<int> pouet(5, 8);
		pouet.push_back(2);
		pouet.push_back(3);
		pouet.push_back(4);
		//print all
		TYPE::vector<int>::iterator start = pouet.begin();
		while (start != pouet.end()) {
			std::cout << "[" << *start << "] ";
			start++;
		}
		std::cout << std::endl;
		TYPE::vector<int>::iterator defIt;
		// TYPE::vector<int>::iterator assignIt = pouet.begin();
		defIt = pouet.begin(); // segfault without this (normal)
		TYPE::vector<int>::iterator copyIt(defIt);
		defIt--;

		if (defIt < copyIt)
			{ std::cout << "defIt < copyIt" << std::endl;}
		if (++defIt == copyIt)
			{ std::cout << "defIt == copyIt" << std::endl;}

		int minusINT = pouet.begin() - pouet.end();
		// TYPE::vector<int>::iterator it = minusINT + pouet.end();
		TYPE::vector<int>::iterator it = pouet.end() + minusINT;
		std::cout << minusINT << " " << *it << std::endl;
		// TYPE::vector<int>::iterator minus = pouet.end() - minusINT;

		it = pouet.begin();
		it += 6;
		std::cout << "must be 3 : " << *it << std::endl;
		it -= 1;
		std::cout << "must be 2 : " << *it << std::endl;
	}

	create_header("Itearator");
	{
		std::vector<std::string> strs;
		std::vector<std::string>::iterator it = strs.begin();
		std::vector<std::string>::iterator itEnd = strs.end();
		std::cout << "lol " << std::endl;
		strs.push_back("pouet");
		std::cout << &*it << "\t\t" << &*itEnd << std::endl
			<< &*(strs.begin()) << "\t" << &*(strs.end());
	}
	std::cout << std::endl;
	{
		TYPE::vector<std::string> strs;
		TYPE::vector<std::string>::iterator it = strs.begin();
		TYPE::vector<std::string>::iterator itEnd = strs.end();
		std::cout << "lol " << std::endl;
		strs.push_back("pouet");
		std::cout << &*it << "\t\t" << &*itEnd << std::endl
			<< &*(strs.begin()) << "\t" << &*(strs.end());
	}

	std::cout << std::endl;

	{
		std::vector<int> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct.at(): " << vct.at(i) << " | ";
			std::cout << "vct[]: " << vct[i] << std::endl;
		}

		std::cout << "ic" << std::endl;
		std::vector<int> const vct_c(vct);
		std::cout << "ci" << std::endl;
		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		try {
			vct.at(10) = 42;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

}


void	iterator_tests() {

	create_header("random_access_iterator");
{
	TYPE::vector<int>	base;
	int	filler[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	base.insert(base.begin(), filler, filler+12);
	std::cout << std::endl << "Content of base : [";
	for (TYPE::vector<int>::iterator it = base.begin(); it < base.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << "]" << std::endl;

 	// Constructors
	TYPE::vector<int>::iterator defaultI;
	TYPE::vector<int>::iterator ptrI(filler+2);
	TYPE::vector<int>::iterator assignI = base.begin();
	TYPE::vector<int>::iterator copyI(assignI);

	// std::cout << *defaultI << std::endl; // segfault (but it's ok)
	defaultI = base.end();
	std::cout << *defaultI << std::endl;	// 0
	std::cout << *ptrI << ", post " << *(ptrI++) << ", pre " << *(++ptrI) << std::endl;				// 3 3 5
	std::cout << *assignI  << ", post " << *(assignI++) << ", pre " << *(++assignI) << std::endl;	// 1 1 3
	std::cout << *copyI << ", post " << *(copyI++) << ", pre " << *(++copyI) << std::endl;			// 1 1 3

	ptrI -= 2;
	assignI -= 2;
	copyI -= 2;
	std::cout << std::endl << *ptrI << " " << *assignI << " " << *copyI << std::endl;	// 3 1 1

	if (copyI == assignI) std::cout << "CopyI == assignI" << std::endl;		//
	if (copyI != assignI) std::cout << "CopyI != assignI" << std::endl;
	if (copyI > assignI) std::cout << "CopyI > assignI" << std::endl;
	if (copyI < assignI) std::cout << "CopyI < assignI" << std::endl;
	if (copyI >= assignI) std::cout << "CopyI >= assignI" << std::endl;		//
	if (copyI <= assignI) std::cout << "CopyI <= assignI" << std::endl;
	
	if (copyI == ptrI) std::cout << "CopyI == ptrI" << std::endl;
	if (copyI != ptrI) std::cout << "CopyI != ptrI" << std::endl;			//
	if (copyI < ptrI) std::cout << "CopyI < ptrI" << std::endl;				//
	if (copyI > ptrI) std::cout << "CopyI > ptrI" << std::endl;
	if (copyI <= ptrI) std::cout << "CopyI <= ptrI" << std::endl;			//
	if (copyI >= ptrI) std::cout << "CopyI >= ptrI" << std::endl;

	std::cout << std::endl;
	std::cout << *(ptrI + 5) << std::endl;			// 8
	std::cout << *(5 + ptrI) << std::endl;			// 8
	// std::cout << (ptrI + assignI) << std::endl;	// error
	std::cout << *(ptrI - 2) << std::endl;			// 1
	std::cout << (ptrI - assignI) << std::endl;		// ? garbage
	std::cout << (base.end() - base.begin() - 2) << std::endl;	// 10
	std::cout << *(ptrI + 5 - 2) << std::endl;		// 6
	// std::cout << *(2 - copyI) << std::endl;		// error

	std::cout << std::endl << ptrI[5] << copyI[8];	// 89

	std::cout << std::endl << ptrI.base() << std::endl;

}

	// With const_iterator you can move the iterator but you can't change the content
	create_header("const_iterator");
{
	TYPE::vector<int>					lel(5, 10);
	lel.push_back(453);

	TYPE::vector<int>::const_iterator	first = lel.begin();
	TYPE::vector<int>::const_iterator	last = lel.end() - 1;
	TYPE::vector<int>::iterator			notConstLast = lel.end() - 1;

	std::cout << *first << " " << *last << std::endl;	// 10 453
	last--;
	notConstLast--;
	// *last = 5;										// error
	*notConstLast = 5;
	std::cout << *last << std::endl;					// 5

	if (last == first) {std::cout << "last == first" << std::endl;}
	if (last == notConstLast) {std::cout << "last == notConstLast" << std::endl;}

	TYPE::vector<int>::difference_type	newSize = first - notConstLast;	// -4
	std::cout << newSize << std::endl;

}

	create_header("reverse_iterator");
{
	TYPE::vector<int>	lel;
	int	filler[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	lel.insert(lel.begin(), filler, filler+12);
	lel.push_back(987);

	TYPE::vector<int>::reverse_iterator start = lel.rbegin();
	TYPE::vector<int>::reverse_iterator end = lel.rend();

	std::cout << "Start : " << *start << " End : " << *end << std::endl; // 987 0
	end--;
	start++;
	std::cout << "Start : " << *start << " End : " << *end << std::endl; // 12 1
	start += 5;
	end -= 5;
	std::cout << "Start : " << *start << " End : " << *end << std::endl; // 7 6
	std::cout << "Start : " << start[5] << " End : " << end[5] << std::endl; // 2 1


}
{
	TYPE::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef TYPE::vector<int>::iterator iter_type;
															// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (myvector.begin());						//   ^
															//         ------>
	iter_type until (myvector.end());						//                       ^
															//
	TYPE::ITER<iter_type> rev_until (from);		// ^
															//         <------
	TYPE::ITER<iter_type> rev_from (until);		//                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
}

}


void	stack_tests() {
		/****************************/
		/*			Stack			*/
		/****************************/
create_header("Stack empty");
{
	TYPE::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';	// 55
}
create_header("Stack size");
{
	TYPE::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';	//0

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';	//5

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';	//4
}
create_header("Stack top");
{
	TYPE::stack<int> mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.top() -= 5;
	std::cout << "mystack.top() is now " << mystack.top() << '\n';	//15
}
create_header("Stack top and pop");
{
	TYPE::stack<int> mystack;
	for (int i=0; i<5; ++i) mystack.push(i);
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();	// 4 3 2 1 0
		mystack.pop();
	}
	std::cout << '\n';
}
create_header("Stack relational operators");
{
	TYPE::stack<int> foo;   // three ints with a value of 100
	TYPE::stack<int> bar;   // two ints with a value of 200

	foo.push(12);
	bar.push(11);

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
}

void	utils_tests() {
	create_header("is_integral");
{
	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << TYPE::is_integral<char>::value << std::endl;
	std::cout << "int: " << TYPE::is_integral<int>::value << std::endl;
	std::cout << "const int: " << TYPE::is_integral<const int>::value << std::endl; // must be true
	std::cout << "volatile int: " << TYPE::is_integral<volatile int>::value << std::endl; // must be true
	std::cout << "const volatile char: " << TYPE::is_integral<const volatile char>::value << std::endl; // must be true
	std::cout << "float: " << TYPE::is_integral<float>::value << std::endl;
}

	create_header("equal");
{
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	TYPE::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	if ( TYPE::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3] = 345;
	if ( TYPE::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
}
	create_header("lexicographical_compare");
{
	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;
	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
	std::cout << "Using default comparison (operator<): ";
	std::cout << TYPE::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';
}

	create_header("Pair");
{
	TYPE::pair<int,char> foo (10,'z');
	TYPE::pair<int,char> bar (90,'a');

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";	//
	if (foo< bar) std::cout << "foo is less than bar\n";		//
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";	//
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl << "foo = bar now" << std::endl;
	foo = bar;
	
	if (foo==bar) std::cout << "foo and bar are equal\n";		//
	if (foo!=bar) std::cout << "foo and bar are not equal\n";	
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";	//
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";	//
}

	create_header("Make pair");
{
	TYPE::pair <int,int> foo;
	TYPE::pair <int,int> bar;

	foo = TYPE::make_pair (10,20);
	bar = TYPE::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}
}

/*
void	rb_tree_tests() {
	{
		create_header("Easy rotate");	
		ft::red_black_tree<int> b;
		b.insert(12);
		b.insert(8);
		b.insert(2);
		
		b.print_tree(b.get_root());
	}
	{
		create_header("Another easy rotate");	
		ft::red_black_tree<int> b;
		b.insert(12);
		b.insert(8);
		b.insert(10);
		b.print_tree(b.get_root());
	}
	{
		create_header("More fun");
		ft::red_black_tree<int> b;
		b.insert(12);
		b.insert(234);
		b.insert(2);
		b.insert(1);
		b.insert(3);
		b.insert(23);
		b.insert(54);
		b.insert(13);
		std::cout << "Mini " << b.minimum(b.get_root())->data << std::endl;
		std::cout << "Maxi " << b.maximum(b.get_root())->data << std::endl;
		b.print_tree(b.get_root());
	}
	create_header("Suite");
	{
		ft::red_black_tree<int> b;
		for (int i=0; i < 100 ; i++) {
			b.insert(i);
		}
		std::cout << "Mini " << b.minimum(b.get_root())->data << std::endl;
		std::cout << "Maxi " << b.maximum(b.get_root())->data << std::endl;
		b.print_tree(b.get_root());
	}
	create_header("Let's go random !!!");
	{
		ft::red_black_tree<int> b;
		std::srand(std::time(NULL)); // use current time as seed for random generator
		// int random_variable = std::rand();
		int nb = 10 + (std::rand() % (50 - 10 + 1));
		std::cout << "Insert " << nb << " elements with random value on [0 500]: " << std::endl;
		// roll 6-sided dice 20 times
		for (int n=0; n != nb; ++n) {
			int x = 0 + (std::rand() % (500 - 0 + 1));
			// std::cout << "try to insert : " << x << std::endl;
			b.insert(x);
		}
		std::cout << "Mini " << b.minimum(b.get_root())->data << std::endl;
		std::cout << "Maxi " << b.maximum(b.get_root())->data << std::endl;
		b.print_tree(b.get_root());
	}
	{
	// remove with right && left == NULL
	{
		create_header("Remove with left && right == NULL");	
		ft::red_black_tree<int> b;
		b.insert(12);
		b.insert(8);
		b.insert(2);
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 2" << std::endl; 
		b.delete_el(b.search(2));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 12" << std::endl; 
		b.delete_el(b.search(12));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 8" << std::endl; 
		b.delete_el(b.search(8));
		b.print_tree(b.get_root());
	}
	// remove with right || left == NULL
	{
		create_header("Remove with left || right == NULL");	
		ft::red_black_tree<int> b;
		b.insert(34);
		b.insert(2);
		b.insert(12);
		b.insert(32);
		b.insert(5);
		
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 2" << std::endl; 
		b.delete_el(b.search(2));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 34" << std::endl; 
		b.delete_el(b.search(34));
		b.print_tree(b.get_root());
	}
	// remove with left && right != NULL
	{
		create_header("Remove with left && right != NULL and z != root");
		ft::red_black_tree<int> b;
		b.insert(34);
		b.insert(2);
		b.insert(12);
		b.insert(32);
		b.insert(93);
		b.insert(100);
		b.insert(43);
		b.insert(5);
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 34" << std::endl; 
		b.delete_el(b.search(34));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 43" << std::endl; 
		b.delete_el(b.search(43));
		b.print_tree(b.get_root());
	}
	// remove with left && right != NULL and z == root
	{
		create_header("Remove with left && right != NULL and z == root");
		ft::red_black_tree<int> b;
		b.insert(12);
		b.insert(8);
		b.insert(2);
		b.insert(22);
		b.insert(32);
		b.insert(42);
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 8" << std::endl; 
		b.delete_el(b.search(8));
		b.print_tree(b.get_root());
	}
	// remove with children but !grandChildren
	{
		create_header("Remove with children but !grandChildren");
		ft::red_black_tree<int> b;
		b.insert(34);
		b.insert(2);
		b.insert(12);
		b.insert(32);
		b.insert(93);
		b.insert(100);
		b.insert(43);
		b.insert(5);
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 93" << std::endl; 
		b.delete_el(b.search(93));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 100" << std::endl; 
		b.delete_el(b.search(100));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 34" << std::endl; 
		b.delete_el(b.search(34));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 12" << std::endl; 
		b.delete_el(b.search(12));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 43" << std::endl; 
		b.delete_el(b.search(43));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 2" << std::endl; 
		b.delete_el(b.search(2));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 32" << std::endl; 
		b.delete_el(b.search(32));
		b.print_tree(b.get_root());
		std::cout << std::endl << "Delete 5" << std::endl; 
		b.delete_el(b.search(5));
		b.print_tree(b.get_root());
	}
}
	{
		create_header("1 -> 14");
		ft::red_black_tree<int> b;
		for (int i = 1; i < 15; i++)
			b.insert(i);
		b.print_tree(b.get_root());
		
		b.delete_el(b.search(1));
		b.print_tree(b.get_root());
		for (int i = 0; i < 4; i++) {
			b.delete_el(b.get_root()->right);
			b.print_tree(b.get_root());
		}
		for (int i = 0; i < 8; i++) {
			b.delete_el(b.get_root());
			b.print_tree(b.get_root());
		}
		std::cout << std::endl << "Already empty" << std::endl;
		b.delete_el(b.get_root());
		b.print_tree(b.get_root());
		std::cout << std::endl << "Root must be nil " << b.get_root() << " " << b.get_root()->parent << std::endl;
		b.delete_el(b.get_root());
		b.print_tree(b.get_root());
	}
}
*/



template <typename T>
void	printSize(TYPE::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TYPE::vector<T>::const_iterator it = vct.begin();
		typename TYPE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


template <typename T, typename U>
void	printMap(ft::map<T, U> &x) {
	for (typename ft::map<T, U>::iterator it = x.begin();
		it != x.end(); it++) {
			std::cout << it->first << " ==> " << it->second << std::endl;
		}
}

template <typename T, typename U>
void	printMap(std::map<T, U> &x) {
	for (typename std::map<T, U>::iterator it = x.begin();
		it != x.end(); it++) {
			std::cout << it->first << " ==> " << it->second << std::endl;
		}
}


void	mapMegaTest() {
	{
		create_header("Insert");
		TYPE::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( TYPE::pair<char,int>('a',100) );
		mymap.insert ( TYPE::pair<char,int>('z',200) );

		TYPE::pair<TYPE::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( TYPE::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		TYPE::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, TYPE::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, TYPE::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		TYPE::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

	}
}


using namespace ft;

int main() {
	vectorMegaTest();
	// iterator_tests();
	// stack_tests();
	// utils_tests();

	// rb_tree_tests();

	mapMegaTest();


std::cout << std::endl;


	// {
	// 	TYPE::map<int, int> pouet;

	// 	std::cout << pouet.empty() << std::endl;
	// 	std::cout << pouet.size() << std::endl;
	// 	std::cout << pouet.max_size() << std::endl;

	// }


	{
		create_header("STD comp");
		std::map<char, int> b;

		b.insert( std::pair<char, int>('b', 2));
		b.insert( std::pair<char, int>('a', 1));
		b.insert( std::pair<char, int>('w', 20));
		b.insert( std::pair<char, int>('r', 15));

		std::map<char, int>::iterator debut = b.begin();
		std::map<char, int>::iterator end = b.end();

		std::cout << debut->first << " ==> " << debut->second << std::endl
			 << end->first << " ==> " << end->second << std::endl;
	
		std::pair<char, int> start = *end;
		std::cout << "|" << start.first << "|" << std::endl;
	}
std::cout << std::endl;


std::cout << std::endl;
create_header("Map with <char, int>");
	{
		map<char, int> b;

		b.insert(ft::pair<char, int>('c', 11));
		b.insert(ft::pair<char, int>('a', 21));
		b.insert(ft::pair<char, int>('z', 41));
		b.insert(ft::pair<char, int>('t', 331));

		map<char, int>::iterator debut = b.begin();
		map<char, int>::iterator end = b.end();

		std::cout << "Print begin() and end()" << std::endl
			<< debut->first << " ==> " << debut->second << std::endl
			<< end->first << " ==> " << end->second << std::endl;

		std::cout << std::endl << "remove first el : " << debut->first << std::endl;
		b.erase(debut);
		b.erase(b.begin());
		printMap(b);

		std::cout << "size of b " << b.size() << std::endl;
		b.clear();
		std::cout << "size of b " << b.size() << std::endl;
		printMap(b);



		// std::cout << "|" << b['a'] << "|" << std::endl;
	}

	// {
	// 	using namespace std;
	// 	std::cout << "lol";
	// 	vector<int> roger(2, 120);
	// 	for (vector<int>::iterator it = roger.begin(); it < roger.end(); it++) {
	// 		cout << *it << endl;
	// 	}
	// }
	// {
	// 	using namespace ft;
	// 	std::cout << "lol";
	// 	vector<int> roger(2, 120);
	// 	for (vector<int>::iterator it = roger.begin(); it < roger.end(); it++) {
	// 		std::cout << *it << std::endl;
	// 	}
	// }




std::cout << std::endl;







// 	create_header("value_comp()");
// {
// 	std::map<char,int> mymap;

// 	mymap['x']=1001;
// 	mymap['y']=2002;
// 	mymap['z']=3003;

// 	std::cout << "mymap contains:\n";

// 	std::pair<char,int> highest = *mymap.rbegin();          // last element

// 	std::map<char,int>::iterator it = mymap.begin();
// 	do {
// 		std::cout << it->first << " => " << it->second
// 		<< " " << mymap.value_comp()(*it, highest) << '\n';
// 	} while ( mymap.value_comp()(*it++, highest) );

// }

// 	create_header("Basic Map");
// {
// 	std::map<std::string, int> base;

// 	base["salut"] = 1;
// 	base["les"] = 8;
// 	base["poulets"] = -12;
// 	base["."] = 199;
// 	base["a"] = 199;
// 	base["a"] = 234;

// 	for (std::map<std::string, int>::iterator it = base.begin(); it != base.end(); it++) {
// 		std::cout << it->first << " => " << it->second << std::endl;
// 	}
// }



	return 0;
}