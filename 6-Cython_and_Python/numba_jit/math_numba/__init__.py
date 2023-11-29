from typing import List
import numpy as np
from numba.pycc import CC

cc = CC("math_numba")
cc.verbose = True

@cc.export("clip_vector", "f4[:](f4[:], f4, f4)")
def clip_vector(a: List[float], min_value: float, max_value: float) -> List[float]:
    len_ = len(a)
    for i in range(len_):
        if a[i] < min_value:
            a[i] = min_value
        elif a[i] > max_value:
            a[i] = max_value
    return a