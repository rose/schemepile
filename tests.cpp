#include "schemepile.h"

// Sanity tests

template<int n>
struct MakePeano { typedef Succ<typename MakePeano<n-1>::value> value; };

template<>
struct MakePeano<0> { typedef Zero value; };

main() {
  Add<Zero, Succ<Succ<Zero> > >::val two;
  Add<Succ<Zero>, False>::val error;
  Add<Succ<Zero>, Zero>::val one;
  Add<Succ<Succ<Zero> >, Succ<Succ<Zero> > >::val four;
  cout << "Testing numbers and bools.  Expected results: 2, error, 1, 4" << endl;
  cout << two << error << one << four;

  If<True, Succ<Zero>, Zero>::val one_again;
  If<False, Succ<Zero>, Zero>::val zero;
  Equal<Succ<Zero>, Succ<Zero> >::val one_is_one;
  If<Zero, Succ<Zero>, Zero>::val zero_isnt_bool;
  Equal<Succ<Nil>, Succ<Zero> >::val nil_isnt_zero;
  If<Equal<False, False>::val, Succ<Succ<Zero> >, Cons<True, Nil> >::val equal_gives_bool;
  cout << "Testing bools.  Expected results: 1, 0, true, error, false, 2" << endl;
  cout << one_again << zero << one_is_one << zero_isnt_bool << nil_isnt_zero << equal_gives_bool;

  Cons<Succ<Succ<Zero> >, Cons< Zero, Cons< Succ<Succ<Succ<Zero> > >, Nil> > > list;
  MapAddOne<Cons<Succ<Succ<Zero> >, Cons< Zero, Cons< Succ<Succ<Succ<Zero> > >, Nil> > > >::val list2;
  cout << "Testing lists.  Expected results: 2:0:3:Nil, 3:1:4:Nil" << endl;
  cout << list << list2;
}

