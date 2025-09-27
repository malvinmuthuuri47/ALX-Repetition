#!/usr/bin/env python3
"""
Deletion-resilient hypermedia pagination
"""

import csv
import math
from typing import List, Dict, Any


class Server:
    """Server class to paginate a database of popular baby names.
    """
    DATA_FILE = "Popular_Baby_Names.csv"

    def __init__(self):
        self.__dataset = None
        self.__indexed_dataset = None

    def dataset(self) -> List[List]:
        """Cached dataset
        """
        if self.__dataset is None:
            with open(self.DATA_FILE) as f:
                reader = csv.reader(f)
                dataset = [row for row in reader]
            self.__dataset = dataset[1:]

        return self.__dataset

    def indexed_dataset(self) -> Dict[int, List]:
        """Dataset indexed by sorting position, starting at 0
        """
        if self.__indexed_dataset is None:
            dataset = self.dataset()
            truncated_dataset = dataset[:1000]
            self.__indexed_dataset = {
                    i: dataset[i] for i in range(len(dataset))
                    }
        return self.__indexed_dataset

    def get_hyper_index(self, index: int = None,
                        page_size: int = 10) -> Dict[int, Any]:
        """
        This function implements the algorithm for deletion-resilient
        hypermedia pagination.
        The pseudocode is as follows:
            1. Preprocess the dataset by creating an indexed dictionary where
               keys are the original position and values are the dataset rows.
            2. Receive a request with idx (where to start retrieving) and
               page_size (how many items to return)
            3. Validate index using assertion as required by the task
            4. Fetch items and append them to a list starting at idx, walking
               forward through the keys of the indexed_dataset, each time you
               find a valid record and stop when len(data) == page_size or you
               run out of dataset
            5. Compute the next_idx and if you hit the end of the dataset,
               next_idx may be none
            6. Return a hypermedia response as a dictionary
        """
        indexed_data = self.indexed_dataset()
        assert index is not None and 0 <= index < len(indexed_data)

        data = []
        curr_idx = index

        while len(data) < page_size and curr_idx < len(self.dataset()):
            if curr_idx in indexed_data:
                data.append(indexed_data[curr_idx])
            curr_idx += 1

        next_idx = curr_idx if curr_idx < len(self.dataset()) else None

        return {
                "index": index,
                "next_index": next_idx,
                "page_size": len(data),
                "data": data,
                }
