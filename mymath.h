// mymath.h
/**/
/*#ifdef MYMATH_H*/
/*#define MYMATH_H*/
/**/

namespace N {
  class Mymath {
    public:
      void do_something();
      int factorial(int num);
      double power(double num, double exponent);
      double natlog(double num);
      double logx(double num, double exponent);
      double gradient_est(double guess, int exponent);
      double nroot(double num, double exponent);

  };

}


/*#endif */
