#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
 * Author:heroming
 * File:data.py
 * Time:2017/09/05 12:31:48
'''

from random import randint

if __name__ == '__main__' :

    f = open("1003.in", "w")
    for t in xrange(1000) :
        n = 16
        f.writelines("%d\n" % (n));


        for k in xrange(n) :
            data = []
            for i in xrange(5) :
                data.append(str(randint(1, 100)))
            f.writelines(' '.join(data) + '\n')


