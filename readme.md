# Implementation of a library.
The library already has a list of books included in it initially. This list is saved into a text file. Each book has an id (identification number), a name and a quantity.
The implement of this application by loading the list into an array of structure before dealing with it.
The user menu displays the following operations:

- Insert a book (id, name, quantity). (This function gets to read an array of characters including spaces) (saved changes into file at the end)
- Delete a book by id (saved changes into file at the end)
- Search a book by id and display its name and quantity using linear search recursively. If not exist, display “Not found”.
- Search a book by name and display its id and quantity using binary search. If not exist, display “Not found”. (Hint: your data should be sorted before you start search, you can use strcmp function).
- Display all books sorted by name, and their corresponding ids and quantity.
- Display all books unsorted, their ids, names and quantity (as entered)

After each operation,
Ask the user if he wants to perform any additional operation
* If yes, let him choose another operation.
* If no, exit from the program
