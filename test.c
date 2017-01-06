/*
 * zlib License
 *
 * Regularized Incomplete Beta Function
 *
 * Copyright (c) 2016, 2017 Lewis Van Winkle
 * http://CodePlea.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgement in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */



/* This file just checks that the incomplete beta function produces
 * a few correct results.
 */


#include "incbeta.h"
#include <stdio.h>
#include <math.h>

int ltests = 0;
int lfails = 0;

#define lfequal(a, b) do {\
    ++ltests;\
    if (fabs((double)(a)-(double)(b)) > 0.00001) {\
        ++lfails;\
        printf("%s:%d (%f != %f)\n", __FILE__, __LINE__, (double)(a), (double)(b));\
    }} while (0)



int main(int argc, char *argv[])
{
    printf("INCBETA TEST SUITE\n");

    lfequal(incbeta(10, 10, .1), 0.00000);
    lfequal(incbeta(10, 10, .3), 0.03255);
    lfequal(incbeta(10, 10, .5), 0.50000);
    lfequal(incbeta(10, 10, .7), 0.96744);
    lfequal(incbeta(10, 10,  1), 1.00000);

    lfequal(incbeta(15, 10, .5), 0.15373);
    lfequal(incbeta(15, 10, .6), 0.48908);

    lfequal(incbeta(10, 15, .5), 0.84627);
    lfequal(incbeta(10, 15, .6), 0.97834);

    lfequal(incbeta(20, 20, .4), 0.10206);
    lfequal(incbeta(40, 40, .4), 0.03581);
    lfequal(incbeta(40, 40, .7), 0.99990);

    printf("%d of %d tests passed.\n", ltests - lfails, ltests);

    return lfails != 0;
}
