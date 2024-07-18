## ft_containers - My C++ Containers Reimplementation

Welcome to **ft_containers**, my personal project where I embarked on a journey to recreate some of the core containers from the C++ Standard Template Library (STL). This project was driven by a desire to deepen my understanding of data structures, algorithms, and low-level C++ concepts. 

### Containers Implemented:

- **Vector:** A dynamic array capable of growing and shrinking efficiently.
- **Stack:** An adapter implementing the LIFO (Last-In, First-Out) principle.
- **Map:** An ordered associative container storing key-value pairs (implemented using a Red-Black Tree).
- **Set:** An ordered container storing unique elements (also implemented using a Red-Black Tree).

### Utilities:

- **Pair:** A template structure for holding two objects.
- **Iterators:** Custom iterators for traversing containers (including const, reverse, and const_reverse iterators).
- **Algorithm Functions:** Implementation of `equal` and `lexicographical_compare` for container comparisons.

### Implementation Highlights:

- **Templates:** All containers are template-based, allowing them to work with any data type.
- **Allocator Support:**  I incorporated custom allocator support, allowing for flexible memory management.
- **Red-Black Trees (RBT):**  `Map` and `Set` are built upon RBTs, guaranteeing logarithmic complexity for search, insertion, and deletion operations.
- **Iterator Design:** I implemented various iterator types (iterator, const_iterator, reverse_iterator, const_reverse_iterator) to provide a consistent interface for container traversal.
- **Exception Safety:**  I paid close attention to exception safety, ensuring that my containers gracefully handle potential errors and maintain a valid state. 

### Key Challenges and Learnings:

- **Red-Black Tree Implementation:** Implementing an RBT from scratch was a significant challenge, requiring meticulous attention to detail and extensive debugging to ensure correct balancing and functionality. This process greatly enhanced my understanding of RBTs and their complexities.
- **Iterator Design and Behavior:** Crafting robust iterators that work correctly in different scenarios (e.g., insertion, deletion, swapping) proved to be another major learning experience. I gained a deeper appreciation for the nuances of iterator categories and their implications for container functionality.
- **Memory Management and Allocators:** Working with custom allocators pushed me to understand how memory allocation works in C++ at a finer level.  I had to consider issues like alignment, deallocation, and managing different allocation strategies.

### Testing and Validation:

- **Thorough Unit Tests:** I created comprehensive unit tests (found in `_tests.cpp` files) to validate the functionality and efficiency of each container and its methods.  The tests encompass a wide range of scenarios, including:
    - Performance comparisons against the STL containers using time measurements.
    - Boundary condition testing (empty containers, maximum size, large data sets).
    - Iterator invalidation after container modifications.
    - Memory leak detection using tools like Valgrind.
    - Robust error handling and exception handling.

### What This Project Means to Me:

This project wasn't just about code; it was a personal quest to explore the intricacies of data structures and algorithms that power the C++ STL. By reimplementing these containers, I gained:

- **Foundational Knowledge:** A deep, hands-on understanding of how containers are designed, implemented, and optimized.
- **Problem-Solving Skills:**  The ability to break down complex problems into manageable steps and develop robust solutions.
- **C++ Mastery:** Enhanced proficiency in C++ templates, memory management, iterators, and exception safety. 
- **Code Quality:** A greater emphasis on writing clean, well-documented, and testable code.

### Future Improvements:

- I plan to expand this project by implementing additional STL containers, such as `list`, `deque`, and `queue`. 
- I am always looking for ways to improve the efficiency and performance of my containers. 
- I intend to explore different allocation strategies and implement custom allocators to further enhance the flexibility of the library.

### Feel free to explore the code, run the tests, and provide feedback! I welcome contributions and suggestions as I continue to enhance this project. 
