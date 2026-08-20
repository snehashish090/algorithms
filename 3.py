# 3. Longest Substring Without Repeating Characters
# Given a string s, find the length of the longest substring without duplicate characters.

# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution:
    def checkHasRepitions(self, list1, list2):
        l_bound = list1[0]
        u_bound = list1[1]

        count = 0
        for k in list2:
            if k >= l_bound and k <= u_bound:
                count += 1
        return True if count > 1 else False

    def lengthOfLongestSubstring(self, s: str) -> int:
        _map = {}

        if len(s) <= 1:
            return len(s)

        for i in range(len(s)):
            _char = s[i]
            if _char not in _map:
                _map[_char] = [i]
            else:
                _map[_char].append(i) 
        
        _max_map ={}
        _max_map_windows = {}
        for _char in _map:
            _map[_char].append(len(s))
            _max_map[_char] = 0
            _max_map_windows[_char] = []
            diff = 0
            for k in range(len(_map[_char])):
                diff = _map[_char][k] if k == 0 else _map[_char][k] - \
                    _map[_char][k-1]
                if diff > _max_map[_char]:
                    dont = False
                    for _temp in _map:
                        dont = self.checkHasRepitions([_map[_char][k-1], _map[_char][k]], _map[_temp])
                    if not dont:
                        _max_map[_char] = diff
                        _max_map_windows[_char] = [_map[_char][k-1], _map[_char][k]]
                    else:
                        print(_char, _map[_char][k-1], _map[_char][k], _map[_char])

        print(_map, _max_map, _max_map_windows)
        
        return 0
            




            