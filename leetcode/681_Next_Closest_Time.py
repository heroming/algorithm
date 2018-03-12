#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
 * Author:heroming
 * File:681_Next_Closest_Time.py
 * Time:2017/09/24 11:01:17
'''

class Solution(object) :
    def nextClosestTime(self, time) :

        def valid(s) :
            v = s.split(':')
            a, b = int(v[0]), int(v[1])
            if a < 24 and b < 60 :
                return a * 60 + b
            return -1

        def dfs(k, s) :
            if k == 4 :
                a = valid(s)
                if a != -1 :
                    diff = 0
                    if a <= self.T :
                        diff = a + 24 * 60 - self.T 
                    else :
                        diff = a - self.T
                    if diff < self.t :
                        self.t = diff
                        self.ans = s
                return
            for c in self.v :
                x = ':' if k == 2 else ''
                dfs(k + 1, s + x + c)

        dic = {}
        for c in time :
            if c != ':' : dic[c] = True
        self.v = dic.keys()
        self.T = valid(time)
        self.t = 0xF0F0F0
        self.ans = None
        dfs(0, "")
        return self.ans
