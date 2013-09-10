/*
  The sum of the squares of the first ten natural numbers is,

  12 + 22 + ... + 102 = 385

  The square of the sum of the first ten natural numbers is,

  (1 + 2 + ... + 10)2 = 552 = 3025

  Hence the difference between the sum of the squares of the first
  ten natural numbers and the square of the sum is 3025  385 = 2640.

  Find the difference between the sum of the squares of the
  one hundred natural numbers and the square of the sum.
  */

var helper = require('./helper.js'),

    ar = Array.apply(null, Array(101)),
    result;

result = Math.pow(ar.reduce(function (a, _, i) {
    return ~~a + i;
  }), 2) -
  ar.reduce(function (a, _, i) {
    return ~~a + i * i;
  });

helper(25164150, result);
