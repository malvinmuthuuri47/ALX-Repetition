"""
This module contains logic that implements hypermedia pagination
"""

import csv
from math import ceil
from typing import Tuple, List, Dict, Any


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
        # check that the func params are ints; Raise an assertion error if not
        assert isinstance(page, int)
        assert isinstance(page_size, int)

        # check that the func params are > 0. If not, raise an assertion error
        assert page > 0
        assert page_size > 0

        dataset = self.dataset()
        start_idx, end_idx = index_range(page, page_size)

        if start_idx >= len(dataset):
            return []

        return dataset[start_idx:end_idx]

    def get_hyper(self, page: int = 1, page_size: int = 10) -> Dict[str, Any]:
        """
        This function implements simple pagination functionality

        Args:
            page (int): The page number
            page_size (int): The no. of items per page

        Returns:
            Dict[str, Any] : Returns a dictionary whose keys are strings and
                             the values are a mixture of various data types
        """
        dataset = self.dataset()

        data = self.get_page(page, page_size)
        total_pages = ceil(len(dataset) / page_size)

        hyper = {
                "page_size": len(data),
                "page": page,
                "data": data,
                "next_page": page + 1 if page < total_pages else None,
                "prev_page": page - 1 if page > 1 else None,
                "total_pages": total_pages
                }
        return hyper
