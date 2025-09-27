"""
This module contains code that performs simple pagination
"""

import csv
import math
from typing import Tuple, List


def index_range(page: int, page_size: int) -> Tuple[int, int]:
    """
    This function calculates the ranges of pagination that correspond
    to the page and page_size parameters passed to it

    Args:
        page (int): The page number (1-indexed)
        page_size (int): No. of items per page

    Returns:
        Tuple[int, int]: (start_idx, end_idx)
    """
    start_idx = (page - 1) * page_size
    end_idx = page * page_size
    return start_idx, end_idx


class Server:
    """Server class to paginate a database of popular baby names.
    """
    DATA_FILE = "Popular_Baby_Names.csv"

    def __init__(self):
        self.__dataset = None

    def dataset(self) -> List[List]:
        """Cached dataset
        """
        if self.__dataset is None:
            with open(self.DATA_FILE) as f:
                reader = csv.reader(f)
                dataset = [row for row in reader]
            self.__dataset = dataset[1:]

        return self.__dataset

    def get_page(self, page: int = 1, page_size: int = 10) -> List[List]:
        """
        This function implements simple pagination functionality

        Args:
            page (int): The page number
            page_size (int): The no. of items per page

        Returns:
            List[List] : A list of lists correctly paginated datasets
        """
        assert isinstance(page, int), "page must be an integer"
        assert isinstance(page_size, int), "page must be an integer"

        assert page > 0, "page must be greater than 0"
        assert page_size > 0, "page_size must be greater than 0"

        '''
        Use the index_range function to calculate the appropriate indexes
        based on the values entered in the get_page
        '''
        dataset = self.dataset()
        start_idx, end_idx = index_range(page, page_size)

        if start_idx >= len(dataset):
            return []

        return dataset[start_idx:end_idx]
