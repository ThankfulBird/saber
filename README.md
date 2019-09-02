# Saber
![Build Status](https://travis-ci.com/ThankfulBird/saber.svg?branch=master)  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) [![Generic badge](https://img.shields.io/badge/version-v0.2.3-brightgreen.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/size-4.49kB-blueviolet.svg)](https://shields.io/) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)
<br><br><br><img width="128" src="./img/project-icon.png" align="right">
Saber is a C library to help you testing your apps using assertions.
* __Easy To Learn:__ Saber is designed to make learning curve in its most smoothest form.
* __Concise:__ Saber is focused on pure development. Abstraction is the fundamental of this library.
* __Open Source:__ Found a glitch? No worries. You can implement a better algorithm for any part you want.

## Documentation
Saber is well-documented. You can start learning Saber using [Saber Wiki](https://github.com/ThankfulBird/saber/wiki).

## A Tiny Glimpse
I put an example below just to give you a concrete example. For further information please visit wiki page.
```c
#include "saber.h"

int main(int argc, char const *argv[])
{
    int generated_value = 3, expected_value = 4;
    void_ptr generated_value_ptr = (void *) &generated_value;
    void_ptr expected_value_ptr = (void *) &expected_value;
    AssertionNode my_assertion = create_assertion(IS_EQUAL, INTEGER,
        generated_value_ptr, expected_value_ptr);
    printf("Does function work well? %s\n",
        test_assertion(my_assertion)) ? "YES!" : "NO!";
    return EXIT_SUCCESS;
}
```
One can easily say we will see `Does function work well? NO!` as output. It may seem a little bit complicated but actually it is not. For easy functions this library may seem redundant but for gigantic libraries Saber is an awesome library.

## Licence 
Saber is [GNU Licensed.](https://github.com/ThankfulBird/ctring/blob/master/LICENSE)
