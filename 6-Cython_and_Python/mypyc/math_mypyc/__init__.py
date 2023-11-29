from typing import List

def clip_vector(
        a: List[float], min_value: float, max_value: float
) -> List[float]:
    len_ = len(a)
    for i in range(len_):
        if a[i] < min_value:
            a[i] = min_value
        elif a[i] > max_value:
            a[i] = max_value
    return a