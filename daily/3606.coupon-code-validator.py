from typing import List
import string

ALL = string.ascii_letters + string.digits + '_'

KEY = {
    "electronics": 0,
    "grocery": 1,
    "pharmacy": 2, 
    "restaurant": 3,
}

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        val_code_idx = [i for i in range(len(code)) if all(c in ALL for c in code[i]) and isActive[i] and businessLine[i] in KEY and len(code[i]) > 0]
        sorted_code_idx = sorted(val_code_idx, key=lambda x: (KEY[businessLine[x]], code[x]))
        return [code[i] for i in sorted_code_idx]