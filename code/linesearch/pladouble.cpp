#include <cstdlib>
#include <cmath>
#include "pladouble.h"

using std::copy;


/*
//copysign Felix					//falsch: siehe sign 14.05.11
pladouble copysign(double v, pladouble &a){
  pladouble tmp;
  tmp.val = copysign(v,a.val);
  for (int i=0; i < a.ndim; ++i)
    tmp.grad[i]=copysign(v,a.val)*a.grad[i];			
  return tmp;
}

//copysign2 Felix
pladouble copysign(pladouble &a){
  pladouble tmp;
  tmp.val = copysign(1.0,a.val);
  for (int i=0; i < a.ndim; ++i) 
    tmp.grad[i]=copysign(1.0,a.val)*a.grad[i];
  return tmp;
}

*/