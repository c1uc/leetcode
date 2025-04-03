# export daily ac to json format and can be used in https://huxulm.github.io/lc-rating/zen
import os
import re
import json

res_dict = {}
pattern = re.compile(r'(\d+)[._].*')

def extract(s: str):
    for f in os.listdir(s):
        res = pattern.match(f)
        if res:
            res_dict[str(res.group(1))] = "AC"

    with open('res.txt', 'w') as f:
        json.dump(res_dict, f)

extract('./daily')
