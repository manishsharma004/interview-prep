#!/usr/bin/env python

num_keys = int(input())

phonebook = {}

for i in range(num_keys):
  name, phone_number = input().split()
  phonebook[name] = phone_number

num_queries = num_keys

for q in range(num_queries):
  name = input()
  if name in phonebook:
    print("%s=%s" % (name, phonebook[name]))
  else:
    print("Not Found")
