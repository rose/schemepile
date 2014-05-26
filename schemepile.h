#include <iostream>
#include <typeinfo>

using namespace std;

// Errors

struct Error {};

ostream& operator<<(ostream& out, Error e) {
  out << "Oh noes a error!" << endl;
  return out;
}


// Numbers

struct Zero {};

template<class P>
struct Succ { };

template<class P1, class P2>
struct Add { typedef Error val; };

template<class Any1, class Any2>
struct Add<Succ<Any1>, Succ<Any2> > { typedef typename Add<Succ<Succ<Any1> >, Any2>::val val; };

template<class Any>
struct Add<Succ<Any>, Zero> { typedef Succ<Any> val; };

template<class Any>
struct Add<Zero, Succ<Any> > { typedef Succ<Any> val; };

template<>
struct Add<Zero, Zero> { typedef Zero val; };


template<class Any>
ostream& operator<<(ostream& out, Succ<Any> peano) {
  Any foo;
  out << "s" << foo;
  return out;
}

ostream& operator<<(ostream& out, Zero peano) {
  out << "." << endl;
  return out;
}


// Booleans

struct True {};
struct False {};

ostream& operator<< (ostream& out, True) {
  out << "true" << endl; 
  return out;
}

ostream& operator<< (ostream& out, False) {
  out << "false" << endl;
  return out;
}

template<class Predicate, class Then, class Else>
struct If { typedef Error val; };

template<class Then, class Else>
struct If<True, Then, Else> { typedef Then val; };

template<class Then, class Else>
struct If<False, Then, Else> { typedef Else val; };

template<class C1, class C2>
struct Equal { typedef False val; };

template<>
struct Equal<Zero, Zero> { typedef True val; };

template<>
struct Equal<True, True> { typedef True val; };

template<>
struct Equal<False, False> { typedef True val; };

// template<>
// struct Equal<Nil, Nil> { typedef True val; };

template<class P1, class P2>
struct Equal<Succ<P1>, Succ<P2> > { typedef typename Equal<P1, P2>::val val; };


// Lists

struct Nil {};

template<class Car, class Cdr>
struct Cons { };

template<class List>
struct MapAddOne { typedef Error val; };

template<class Car, class Cdr>
struct MapAddOne<Cons<Car, Cdr> > { 
  typedef Cons< typename Add< Succ<Zero>, Car >::val, typename MapAddOne<Cdr>::val > val; 
};

template<>
struct MapAddOne<Nil> { typedef Nil val; };

ostream& operator<< (ostream& out, Nil) {
  out << "nil" << endl;
  return out;
}

template<class Car, class Cdr>
ostream& operator<< (ostream& out, Cons<Car,Cdr>) {
  Car car;
  Cdr cdr;
  out << car << " : " << cdr;
  return out;
}


