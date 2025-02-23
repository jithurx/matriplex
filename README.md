# Matrix Multiplication in C

## 📌 Description
This C program performs **matrix multiplication** for two user-defined matrices. It prompts the user to input the dimensions and elements of the matrices, validates whether multiplication is possible, computes the product, and displays the result in a neatly formatted manner.

## 🚀 Features
- **User Input**: Accepts dimensions and elements for both matrices.
- **Validation**: Checks if multiplication is possible (columns of Matrix A must match rows of Matrix B).
- **Computation**: Performs matrix multiplication using nested loops.
- **Formatted Output**: Displays the resultant matrix in an easy-to-read format.

## 🛠️ Usage
1. **Compile the program:**  
   ```sh
   gcc matriplex.c -o matriplex
   ```
2. **Run the executable:**  
   ```sh
   ./matriplex
   ```
3. **Enter the matrix dimensions and elements as prompted.**

## 📝 Example
### **Input:**
```
Enter number of rows and columns for Matrix A (row col): 2 3  
Enter number of rows and columns for Matrix B (row col): 3 2  
Enter elements for Matrix A:  
1 2 3  
4 5 6  
Enter elements for Matrix B:  
7 8  
9 10  
11 12  
```

### **Output:**
```
Resultant Matrix:
|  58  64 |
| 139 154 |
```

## 📌 Notes
- Ensure the number of columns in Matrix A equals the number of rows in Matrix B.
- The program dynamically allocates matrices based on user input.

---
Feel free to modify and expand the functionality! 🚀
