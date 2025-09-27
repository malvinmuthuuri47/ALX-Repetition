"""
This module defines a function that calculates the appropriate ranges
to be used for pagination
"""
from typing import Tuple


def index_range(page: int, page_size: int) -> Tuple[int, int]:
    """
    This function calculates the ranges of pagination that correspond
    to the page and page_size parameters passed to it

    Args:
        page (int): The page number (1-indexed)
        page_size (int): No. of items per page

    Returns:
        Tuple[int, int] : (start_idx, end_idx)
    """
    start_idx = (page - 1) * page_size
    end_idx = page * page_size
    return (start_idx, end_idx)
