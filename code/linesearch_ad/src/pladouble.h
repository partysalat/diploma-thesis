#ifndef PLADOUBLE_H
#define PLADOUBLE_H
#include <limits>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>

using std::cerr;
using std::cin;
using std::cout;
using std::copy;
using std::istream;
using std::list;
using std::ostream;
using std::numeric_limits;
#define CXX_INF numeric_limits<double>::infinity()


inline double fmin( const double &x, const double &y ) {
    if (x<y) return x;
    else return y;
}

inline double fmax( const double &x, const double &y ) {
    if (x>y) return x;
    else return y;
}

inline double makeNaN() {
// #if defined(non_num)
//     double a,b;
//     a=non_num;
//     b=non_den;
//     return a/b;
// #else
// #  error Error: non_num undefined!
// #endif
    return 0;
   
}

class pladouble {
public:

    static double tau;
    static int switchnum;
    static list <int> active;
    static list <int> activen;
    static list <double> taulist;		//Taulist

    double val;
    double grad;

    inline pladouble();
    inline pladouble(const double v);
    inline pladouble(const double v, const double d);
    inline pladouble(const double v, double*);
    inline pladouble(const double v, const double d, double*);
    inline pladouble(const pladouble& a);
    inline ~pladouble();
    inline pladouble operator - () const;
    inline pladouble operator + () const;
    inline pladouble operator + (const double v) const;
    inline pladouble operator + (const pladouble& a) const;
    inline friend
    pladouble operator + (const double v, const pladouble& a);
    inline pladouble operator - (const double v) const;
    inline pladouble operator - (const pladouble& a) const;
    inline friend
    pladouble operator - (const double v, const pladouble& a);
    inline pladouble operator * (const double v) const;
    inline pladouble operator * (const pladouble& a) const;
    inline friend
    pladouble operator * (const double v, const pladouble& a);
    inline pladouble operator / (const double v) const;
    inline pladouble operator / (const pladouble& a) const;
    inline friend
    pladouble operator / (const double v, const pladouble& a);

    inline pladouble operator ++ ();
    inline pladouble operator ++ (int);
    inline pladouble operator -- ();
    inline pladouble operator -- (int);

    inline friend int sign(int v);
    inline friend int sign(double v);
    inline friend pladouble fabs(const pladouble &a);

    inline friend pladouble tan(const pladouble &a);
    inline friend pladouble exp(const pladouble &a);
    inline friend pladouble log(const pladouble &a);
    inline friend pladouble sqrt(const pladouble &a);
    inline friend pladouble sin(const pladouble &a);
    inline friend pladouble cos(const pladouble &a);
    inline friend pladouble asin(const pladouble &a);
    inline friend pladouble acos(const pladouble &a);
    inline friend pladouble atan(const pladouble &a);
    inline friend pladouble atan2(const pladouble &a, const pladouble &b);
    inline friend pladouble pow(const pladouble &a, double v);
    inline friend pladouble pow(const pladouble &a, const pladouble &b);
    inline friend pladouble pow(double v, const pladouble &a);
    inline friend pladouble log10(const pladouble &a);
    inline friend pladouble sinh (const pladouble &a);
    inline friend pladouble cosh (const pladouble &a);
    inline friend pladouble tanh (const pladouble &a);
    inline friend pladouble ceil (const pladouble &a);
    inline friend pladouble floor (const pladouble &a);
    inline friend pladouble fmax (const pladouble &a, const pladouble &b);
    inline friend pladouble fmax (double v, const pladouble &a);
    inline friend pladouble fmax (const pladouble &a, double v);
    inline friend pladouble fmin (const pladouble &a, const pladouble &b);
    inline friend pladouble fmin (double v, const pladouble &a);
    inline friend pladouble fmin (const pladouble &a, double v);
    inline friend pladouble ldexp (const pladouble &a, const pladouble &b);
    inline friend pladouble ldexp (const pladouble &a, const double v);
    inline friend pladouble ldexp (const double v, const pladouble &a);
    inline friend double frexp (const pladouble &a, int* v);
    inline void operator = (const double v);
    inline void operator = (const pladouble& a);
    inline void operator += (const double v);
    inline void operator += (const pladouble& a);
    inline void operator -= (const double v);
    inline void operator -= (const pladouble& a);
    inline void operator *= (const double v);
    inline void operator *= (const pladouble& a);
    inline void operator /= (const double v);
    inline void operator /= (const pladouble& a);

    inline int operator ! () const;

    inline friend ostream& operator << ( ostream&, const pladouble& );
    inline friend istream& operator >> ( istream&, pladouble& );

    inline friend void runforward(list <int> activelist);
    inline friend double getTau();
    inline friend list <int> getactiveswitches();
    inline friend void printactiveswitches();
    inline friend list <double> gettaulist();	//Taulist getter
};

pladouble::pladouble() {
}

pladouble::pladouble(const double v) {
    val = v;
    grad = 0.0;
}

pladouble::pladouble(const double v, const double d) {
    val = v;
    grad = d;
}

pladouble::pladouble(const pladouble& a) {
    val = a.val;
    grad=a.grad;
}

pladouble::~pladouble() {
}

pladouble pladouble::operator - () const {
    pladouble tmp;
    tmp.val=-val;
    tmp.grad=-grad;
    return tmp;
}

pladouble pladouble::operator + () const {
    return *this;
}

pladouble pladouble::operator + (const double v) const {;
    return pladouble(val+v,grad);
}

pladouble pladouble::operator + (const pladouble& a) const {
    pladouble tmp;
    tmp.val = val + a.val;
    tmp.grad=grad+a.grad;
    return tmp;
}

pladouble operator + (const double v, const pladouble& a) {
    return pladouble(v+a.val, a.grad);
}


pladouble pladouble::operator - (const double v) const {
    return pladouble(val-v,grad);
}

pladouble pladouble::operator - (const pladouble& a) const {
    pladouble tmp;
    tmp.val=val-a.val; 
    tmp.grad=grad-a.grad;
    return tmp;
}

pladouble operator - (const double v, const pladouble& a) {
    pladouble tmp;
    tmp.val=v-a.val;
    tmp.grad=-a.grad;
    return tmp;
}

pladouble pladouble::operator * (const double v) const {
    pladouble tmp;
    tmp.val=val*v;
    tmp.grad=grad*v;
    return tmp;
}

pladouble pladouble::operator * (const pladouble& a) const {
    pladouble tmp;
    tmp.val=val*a.val;
    tmp.grad=grad*a.val+val*a.grad;
    return tmp;
}

pladouble operator * (const double v, const pladouble& a) {
    pladouble tmp;
    tmp.val=v*a.val;

    tmp.grad=v*a.grad;
    return tmp;
}

pladouble pladouble::operator / (const double v) const {
    pladouble tmp;
    tmp.val=val/v;
    tmp.grad=grad/v;
    return tmp;
}

pladouble pladouble::operator / (const pladouble& a) const {
    pladouble tmp;
    tmp.val=val/a.val;
    tmp.grad=(grad*a.val-val*a.grad)/(a.val*a.val);
    return tmp;
}

pladouble operator / (const double v, const pladouble& a) {
    pladouble tmp;
    tmp.val=v/a.val;
    tmp.grad=(-v*a.grad)/(a.val*a.val);
    return tmp;
}

pladouble pladouble::operator ++ () {
    ++val;
    return *this;
}

pladouble pladouble::operator ++ (int) {
    pladouble tmp;
    tmp.val=val++;
    tmp.grad=grad;
    return tmp;
}

pladouble pladouble::operator -- () {
    --val;
    return *this;
}

pladouble pladouble::operator -- (int) {
    pladouble tmp;
    tmp.val=val--;
    tmp.grad=grad;
    return tmp;
}

int sign(int v){
    return (v >0) - (v < 0);
}

int sign(double v){
    return (v >0) - (v < 0);
}

pladouble fabs(const pladouble &a) {
	int sigma;
	pladouble tmp;
	++(a.switchnum);
	if((!a.active.empty())&&(a.switchnum == abs(a.active.front()))){
	  sigma = sign(a.active.front());
	  a.active.push_back(a.active.front());
	  a.active.pop_front();
	}
	else{
	  sigma = sign(a.val+a.grad);
	  double taun=CXX_INF;
	  if(fabs(a.grad)>=10e-15)
	    taun = -a.val/a.grad;
	  if((taun < CXX_INF) && (taun >= 0.0))		//Liste der Tau erstellen (NEU)
	    a.taulist.push_back(taun);
	  
	  if(a.tau == taun){
	    a.activen.push_back(sigma*a.switchnum);
	  }
	  else if(taun < pladouble::tau ){
	    a.tau = taun;
	    if(!a.activen.empty())
		a.activen.clear();
	    a.activen.push_back(sigma*a.switchnum);
	  }
	}
	tmp.val=fabs(a.val);
	tmp.grad=sigma*(a.val+a.grad)-tmp.val;
	return tmp;
}

pladouble tan(const pladouble& a) {
    pladouble tmp;
    double tmp2;
    tmp.val=std::tan(a.val);
    tmp2=cos(a.val);
    tmp2 *= tmp2;
    tmp.grad=a.grad/tmp2;
    return tmp;
}

pladouble exp(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::exp(a.val);
    tmp.grad=tmp.val*a.grad;
    return tmp;
}

pladouble log(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::log(a.val);
    if ((a.val>0 || a.val==0) && a.grad>=0)
      tmp.grad=a.grad/a.val;
    else tmp.grad=makeNaN();
    return tmp;
}

pladouble sqrt(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::sqrt(a.val);
    if ((a.val>0 || a.val==0) && a.grad>=0)
      tmp.grad=a.grad/tmp.val/2;
    else tmp.grad=makeNaN();
    return tmp;
}

pladouble sin(const pladouble &a) {
    pladouble tmp;
    double tmp2;
    tmp.val=std::sin(a.val);
    tmp2=std::cos(a.val);
    tmp.grad=tmp2*a.grad;
    return tmp;
}

pladouble cos(const pladouble &a) {
    pladouble tmp;
    double tmp2;
    tmp.val=std::cos(a.val);
    tmp2=-std::sin(a.val);
    tmp.grad=tmp2*a.grad;
    return tmp;
}

pladouble asin(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::asin(a.val);
    double tmp2=std::sqrt(1-a.val*a.val);
    tmp.grad=a.grad/tmp2;
    return tmp;
}

pladouble acos(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::acos(a.val);
    double tmp2=-std::sqrt(1-a.val*a.val);
    tmp.grad=a.grad/tmp2;
    return tmp;
}

pladouble atan(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::atan(a.val);
    double tmp2=1+a.val*a.val;
    tmp2=1/tmp2;
    if (tmp2!=0)
        tmp.grad=a.grad*tmp2;
    else
        tmp.grad=0.0;
    return tmp;
}

pladouble atan2(const pladouble &a, const pladouble &b) {
    pladouble tmp;
    tmp.val=std::atan2(a.val, b.val);
    double tmp2=a.val*a.val;
    double tmp3=b.val*b.val;
    double tmp4=tmp3/(tmp2+tmp3);
    if (tmp4!=0)
        tmp.grad=(a.grad*b.val-a.val*b.grad)/tmp3*tmp4;
    else
        tmp.grad=0.0;
    return tmp;
}

pladouble pow(const pladouble &a, double v) {
    pladouble tmp;
    tmp.val=std::pow(a.val, v);
    double tmp2=v*std::pow(a.val, v-1);
    tmp.grad=tmp2*a.grad;
    return tmp;
}

pladouble pow(const pladouble &a, const pladouble &b) {
    pladouble tmp;
    tmp.val=std::pow(a.val, b.val);
    double tmp2=b.val*std::pow(a.val, b.val-1);
    double tmp3=std::log(a.val)*tmp.val;
    tmp.grad=tmp2*a.grad+tmp3*b.grad;
    return tmp;
}

pladouble pow(double v, const pladouble &a) {
    pladouble tmp;
    tmp.val=std::pow(v, a.val);
    double tmp2=tmp.val*std::log(v);
    tmp.grad=tmp2*a.grad;
    return tmp;
}

pladouble log10(const pladouble &a) {
    pladouble tmp;
    tmp.val=std::log10(a.val);
    double tmp2=std::log((double)10)*a.val;
    tmp.grad=a.grad/tmp2;
    return tmp;
}

pladouble sinh (const pladouble &a) {
    pladouble tmp;
    tmp.val=std::sinh(a.val);
    double tmp2=std::cosh(a.val);
    tmp.grad=a.grad*tmp2;
    return tmp;
}

pladouble cosh (const pladouble &a) {
    pladouble tmp;
    tmp.val=std::cosh(a.val);
    double tmp2=std::sinh(a.val);
    tmp.grad=a.grad*tmp2;
    return tmp;
}

pladouble tanh (const pladouble &a) {
    pladouble tmp;
    tmp.val=std::tanh(a.val);
    double tmp2=std::cosh(a.val);
    tmp2*=tmp2;
    tmp.grad=a.grad/tmp2;
    return tmp;
}


pladouble ceil (const pladouble &a) {
    pladouble tmp;
    tmp.val=std::ceil(a.val);

    tmp.grad=0.0;
    return tmp;
}

pladouble floor (const pladouble &a) {
    pladouble tmp;
    tmp.val=std::floor(a.val);

    tmp.grad=0.0;
    return tmp;
}

pladouble fmax (const pladouble &a, const pladouble &b) {
return ((a+b) + fabs(a-b))/2.; 
}

pladouble fmax (double v, const pladouble &a) {
return ((v+a) + fabs(a-v))/2.;
}

pladouble fmax (const pladouble &a, double v) {
return ((v+a) + fabs(a-v))/2.;
}

pladouble fmin (const pladouble &a, const pladouble &b) {
return ((a+b) - fabs(a-b))/2.; 
}

pladouble fmin (double v, const pladouble &a) {
return ((a+v) - fabs(a-v))/2.; 
}

pladouble fmin (const pladouble &a, double v) {
return ((a+v) - fabs(a-v))/2.;
}

pladouble ldexp (const pladouble &a, const pladouble &b) {
    return a*pow(2.,b);
}

pladouble ldexp (const pladouble &a, const double v) {
    return a*std::pow(2.,v);
}

pladouble ldexp (const double v, const pladouble &a) {
    return v*pow(2.,a);
}

double frexp (const pladouble &a, int* v) {
    return std::frexp(a.val, v);
}




/*******************  nontemporary results  *********************************/
void pladouble::operator = (const double v) {
    val=v;
    grad=0.0;
}

void pladouble::operator = (const pladouble& a) {
    val=a.val;
    grad=a.grad;
}

void pladouble::operator += (const double v) {
    val+=v;
}

void pladouble::operator += (const pladouble& a) {
    val += a.val;
    grad+=a.grad;
}

void pladouble::operator -= (const double v) {
    val-=v;
}

void pladouble::operator -= (const pladouble& a) {
    val -= a.val;
    grad-=a.grad;
}

void pladouble::operator *= (const double v) {
    val=val*v;
    grad*=v;
}

void pladouble::operator *= (const pladouble& a) {
    grad=grad*a.val+val*a.grad;
    val*=a.val;
}

void pladouble::operator /= (const double v) {
    val/=v;
    grad/=v;
}

void pladouble::operator /= (const pladouble& a) {
    grad=(grad*a.val-val*a.grad)/(a.val*a.val);
    val=val/a.val;
}

int pladouble::operator ! () const {
    return val == 0.0;
}


/*******************  i/o operations  ***************************************/
ostream& operator << ( ostream& out, const pladouble& a) {
    out << "Value: " << a.val << "\n";
    out << " Gradient value: " << a.grad << "\n ";
    return out;
}



void runforward(list <int> activelist){
  pladouble::tau = CXX_INF;
  pladouble::switchnum=0;
  if(!pladouble::taulist.empty())
    pladouble::taulist.clear();			//NEU  Tauliste leeren falls nicht leer
  if(!pladouble::active.empty())
    pladouble::active.clear();
  if(!pladouble::activen.empty())
    pladouble::activen.clear();
  if(!activelist.empty())
    pladouble::active.assign(activelist.begin(),activelist.end());
}

list <double> gettaulist(){				//NEU   Tauliste zurückgeben
  return pladouble::taulist;
}

double getTau(){
  return pladouble::tau;
}

list <int> getactiveswitches(){
  return pladouble::activen;
}

void printactiveswitches() {
	list<int>::const_iterator i;
	cout << "\nActive Switches:";
	for( i = pladouble::activen.begin(); i != pladouble::activen.end(); ++i)
		cout << *i << " ";
	cout << "\n";
}

#endif /* ADOLC_pladouble_H */
