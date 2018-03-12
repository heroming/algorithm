#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
 * Author:heroming
 * File:682_Baseball_Game.py
 * Time:2017/09/24 10:58:38
'''

class Solution(object) :
    def calPoints(self, ops) :
        ans = 0
        valid = []
        for x in ops :
            if x == '+' :
                valid.append(valid[-1] + valid[-2])
                ans += valid[-1]
            elif x == 'D' :
                valid.append(valid[-1] * 2)
                ans += valid[-1]
            elif x == 'C' :
                ans -= valid.pop()
            else :
                valid.append(int(x))
                ans += valid[-1]
        return ans

