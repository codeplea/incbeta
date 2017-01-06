[![Build Status](https://travis-ci.org/codeplea/incbeta.svg?branch=master)](https://travis-ci.org/codeplea/incbeta)

#Incomplete Beta Function

`incbeta.c` contains only one function. It is the incomplete beta function. It
is released under the zlib license.


##Example?

```C
    /* Call it with a, b, x. */
    double r = incbeta(10, 10, 0.3); /*0.03255*/
```


##How does it work?

This solves the continued fraction using Lentz's algorithm.


##Why would I use this?

Maybe you're trying to do a statistics test, and you don't want to pull in a
huge dependency like the [GNU Scientific
Library](https://www.gnu.org/software/gsl/manual/html_node/Incomplete-Beta-Function.html)
just to get one function you need.

By the way, you can use this to calculate Student's *t* cumulative distribution
function like this:

```C
double student_t_cdf(double t, double v) {
    /*The cumulative distribution function (CDF) for Student's t distribution*/
    double x = (t + sqrt(t * t + v)) / (2.0 * sqrt(t * t + v));
    double prob = incbeta(v/2.0, v/2.0, x);
    return prob;
}
```

