# 0x00. Pagination

## **Learning Objectives**
At the end of this project, you are expected to be able to explain to anyone, **without the help of Google**:
- How to paginate a dataset with simple page and page_size parameters
- How to paginate a dataset with hypermedia metadata
- How to paginate in a deletion-resilient manner

## **Requirements**
- All your files will be interpreted/compiled on Ubuntu 18.04 LTS using <span style="color:red">python3</span> (version 3.7)
- All your files should end with a new line
- The first line of all yout files should be exactly <span style="color:red">#!/usr/bin/python3</span>
- A <span style="color:red">README.md</span> file, at the root of the folder of the project, is mandatory.
- Your code should use the <span style="color:red">pycodestyle</span> (version 2.5.u+002A)
- The length of your files will be tested using <span style="color:red">wc</span>
- All your modules should have a documentation (<span style="color:red">python3 -c 'print(__import__("my_module").__doc__)'</span>)
- All your functions should have a documentation (<span style="color:red">python3 -c 'print(__import__("my_module").my_function.__doc__)'</span>)
- A documentation is not a simple word, it's a real sentence explaining what's the purpose of the module, class, or method (the length of it will be verified)
- All your functions and coroutines must be type-annotated.

> [!NOTE]
> Task One -> A helper function that takes two integer arguments *(page, page_size)* and returns a tuple of size two containing a start index and an end index corresponding to the range of indexes to return in a list for those particular pagination parameters.
> Task Two -> Implementing a method that takes two integer arguments (page=1, page_size=10) and uses assert to verify that both arguments are integers > 0. Then use the task one helper function to find the correct indexes to paginate the dataset correctly and return the appropriate page of the dataset.
> Task Three -> Implementing a method whose functionality is hypermedia pagination. It takes two integer arguments (page=1, page_size=10) and uses these to compute the pagination, returning a dictionary with the following key-value pairs:
> - page_size: the length of the returned dataset page
> - page: the current page number
> - data: the dataset page (equivalent to return from previous task)
> - next_page: number of the next page, None if no next page
> - prev_page: number of the previous page, None if no previous page
> - total_pages: the total number of pages in the dataset as an integer
> Task Four -> Implementing a deletion-resilient hypermedia pagination where if between two queries, certain rows are removed from the dataset, the user doesn't miss items from dataset when changing page. The method takes two arguments: index=None and page_size=10 and returns a dictionary with the following key-value pairs:
> - index: the current start index of the return page i.e. the index of the first item in the current page
> - next_index: the next index to query with. That should be the index of the frist item after the last item on the current page
> - page_size: the current page size
> - data: the actual page of the dataset
