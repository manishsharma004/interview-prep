#!/usr/bin/env python

from functools import reduce

print("Running in python")

def gcd(first, second):
  first, second = min(first, second), max(first, second)

  while second % first != 0:
    first, second = second % first, first

  return first

def gcd_multiple(*numbers):
  return reduce(lambda first, second: gcd(first, second), numbers)


for t in range(0, int(input())):
  numbers = list(map(int, input().split(' ')))
  print("gcd(%s) = %s" % (', '.join(map(str, numbers)), str(gcd_multiple(*numbers))))
