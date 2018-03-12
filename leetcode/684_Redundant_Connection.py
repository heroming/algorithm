#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
 * Author:heroming
 * File:684_Redundant_Connection.py
 * Time:2017/09/24 11:00:34
'''

class Solution(object) :
    def findRedundantConnection(self, edges) :

        def find(x) :
            if p[x] != x : p[x] = find(p[x])
            return p[x]

        p = [i for i in xrange(2010)]
        for e in edges :
            u, v = find(e[0]), find(e[1])
            if u == v : return e
            p[v] = u
