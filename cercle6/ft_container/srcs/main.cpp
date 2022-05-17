/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:16:05 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/16 14:53:12 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#ifndef STD
# define __VECTOR ft
#else
# define __VECTOR std
#endif

bool mypredicate (int i, int j) {
  return (i==j);
}

int main(void) {

//std::cout << "namespace : " << __VECTOR << std::endl;
#ifndef STD
	std::cout << "namespace ft\n" << std::endl;
#else
	std::cout << "namespace std\n" << std::endl;
#endif
std::cout << "Test constructor : The contents of fifth are: 16 2 77 29" << std::endl;
{
    // constructors used in the same order as described above:
  __VECTOR::vector<int> first;                                // empty vector of ints
  __VECTOR::vector<int> second (4,100);                       // four ints with value 100
  __VECTOR::vector<int> third (second.begin(),second.end());  // iterating through second
  __VECTOR::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  __VECTOR::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (__VECTOR::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << std::endl;


std::cout << "Test operator = : Size of foo: 0, Size of bar: 3" << std::endl;
{
   __VECTOR::vector<int> foo (3,0);
  __VECTOR::vector<int> bar (5,0);

  bar = foo;
  foo = __VECTOR::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
  std::cout << std::endl;


std::cout << "Test begin : myvector contains: 1 2 3 4 5" << std::endl;
{
    __VECTOR::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (__VECTOR::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test end : myvector contains: 1 2 3 4 5" << std::endl;
{
   __VECTOR::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (__VECTOR::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test rbegin : myvector contains: 5 4 3 2 1" << std::endl;
{
    __VECTOR::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  __VECTOR::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (__VECTOR::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test rend : 5 4 3 2 1" << std::endl;
{
   __VECTOR::vector<int> myvector (5);  // 5 default-constructed ints

  __VECTOR::vector<int>::reverse_iterator rit = myvector.rbegin();

  int i=0;
  for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (__VECTOR::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test size : 0. size: 0, 1. size: 10, 2. size: 20, 3. size: 19" << std::endl;
{
   __VECTOR::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test max_size : size: 100, capacity: 128, max_size: 1073741823" << std::endl;
{
   __VECTOR::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test resize : myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0" << std::endl;
{
   __VECTOR::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test capacity : size: 100, capacity: 128, max_size: 1073741823" << std::endl;
{
   __VECTOR::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test empty : total: 55" << std::endl;
{
   __VECTOR::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test reserve : making foo grow:\ncapacity changed: 1\ncapacity changed: 2\ncapacity changed: 4\ncapacity changed: 8\ncapacity changed: 16\ncapacity changed: 32\ncapacity changed: 64\ncapacity changed: 128\nmaking bar grow:\ncapacity changed: 100" << std::endl;
{
   __VECTOR::vector<int>::size_type sz;

  __VECTOR::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  __VECTOR::vector<int> bar;
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
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test operator[] : myvector contains: 9 8 7 6 5 4 3 2 1 0" << std::endl;
{
   __VECTOR::vector<int> myvector (10);   // 10 zero-initialized elements

  __VECTOR::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
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
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test at : myvector contains: 0 1 2 3 4 5 6 7 8 9" << std::endl;
{
   __VECTOR::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test front : myvector.front() is now 62" << std::endl;
{
   __VECTOR::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test back : myvector contains: 10 9 8 7 6 5 4 3 2 1 0" << std::endl;
{
   __VECTOR::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test assign : Size of first: 7\nSize of second: 5\nSize of third: 3" << std::endl;
{
   __VECTOR::vector<int> first;
  __VECTOR::vector<int> second;
  __VECTOR::vector<int> third;

	// std::cout << "try 1" << std::endl; getwchar();
  first.assign (7,100);             // 7 ints with a value of 100
	// std::cout << "try 1.2" << std::endl; getwchar();
	// for (ft::Iterator<int> it = first.begin(); it != first.end(); it++)
		// std::cout << "it didtance : " << std::distance(first.begin(), first.end()) << std::endl;
	// std::cout << "try 2" << std::endl; getwchar();
  __VECTOR::vector<int>::iterator it;
  it=first.begin()+1;

	// std::cout << "try 3 distance : " << std::distance(it, first.end()-1) << std::endl; getwchar();
  second.assign (it,first.end()-1); // the 5 central values of first

	// std::cout << "try 4" << std::endl; getwchar();
  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

	// std::cout << "try 5" << std::endl; getwchar();
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test push back : myvector stores 6 numbers." << std::endl;
{
   __VECTOR::vector<int> myvector;

  std::cout << "Please enter some integers (enter 0 to end):\n";

    myvector.push_back (5);
    myvector.push_back (789);
    myvector.push_back (65);
    myvector.push_back (50);
    myvector.push_back (0);
    myvector.push_back (98);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test pop back : The elements of myvector add up to 600" << std::endl;
{
   __VECTOR::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "The elements of myvector add up to " << sum << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test insert : myvector contains: 501 502 503 300 300 400 400 200 100 100 100" << std::endl;
{
  __VECTOR::vector<int> myvector (3,100);
  __VECTOR::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );



for (__VECTOR::vector<int>::iterator it2=myvector.begin(); it2<myvector.end(); it2++)
    std::cout << ' ' << *it2;
  std::cout << " size : " << myvector.size() << '\n';



  myvector.insert (it,2,300);



for (__VECTOR::vector<int>::iterator it2=myvector.begin(); it2<myvector.end(); it2++)
    std::cout << ' ' << *it2;
  std::cout << " size : " << myvector.size() << '\n';



  // "it" no longer valid, get a new one:
  it = myvector.begin();

  __VECTOR::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test erase : myvector contains: 4 5 7 8 9 10" << std::endl;
{
   __VECTOR::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test swap : foo contains: 200 200 200 200 200\nbar contains: 100 100 100 " << std::endl;
{
   __VECTOR::vector<int> foo (3,100);   // three ints with a value of 100
  __VECTOR::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test clear : myvector contains: 100 200 300\nmyvector contains: 1101 2202" << std::endl;
{
   __VECTOR::vector<int> myvector;
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
  std::cout << std::endl;

//////////////////////////////////////////////
std::cout << "Test operator (comparaison) : The contents of both sequences are equal.\nThe contents of both sequence differ." << std::endl;
{
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  // using default comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  myvector[3]=81;                                 // myvector: 20 40 60 81 100

  // using predicate comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";
}

{
	__VECTOR::vector<int> test;
	for (int i = 0; i < 10000000; i++)
		test.push_back(1);
	for (int i = 0; i < 10000000; i++)
		test.pop_back();
}
}
