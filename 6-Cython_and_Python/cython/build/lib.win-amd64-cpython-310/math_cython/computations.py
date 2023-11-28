# pylint: disable=import-error 
from typing import List
import array

from .cython_computations import _cython_clip_vector
from .cython_computations import _naive_cython_clip_vector

def python_clip_vector(
    vector_in: List[float],
    min_value: float,
    max_value: float,
    vector_out: List[float]
) -> None:
    for idx in range(len(vector_in)):
        vector_out[idx] = min(max(vector_in[idx], min_value), max_value)

def naiva_cython_clip_vector(
    vector_in: array.array,
    min_value: float,
    max_value: float,
    vector_out: array.array
) -> None:
    _naive_cython_clip_vector(
        vector_in, min_value, max_value, vector_out
    )

def cython_clip_vector(
        vector_in: array.array,
        min_value: float,
        max_value: float,
        vector_out: array.array
) -> None:
    _cython_clip_vector(
        vector_in, min_value, max_value, vector_out
    )