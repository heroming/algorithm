class TimeMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = {}


    def set(self, key, value, t):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if key in self.dic :
            self.dic[key].append((t, value))
        else :
            self.dic[key] = [(t, value)]


    def get(self, key, t):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        if key in self.dic :
            v = self.dic[key]
            l, r = 0, len(v) - 1
            while l <= r :
                m = (l + r) >> 1
                if v[m][0] <= t :
                    l = m + 1
                else :
                    r = m - 1
            return "" if r < 0 else v[r][1]
        else :
            return ""

