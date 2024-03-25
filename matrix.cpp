#include <iostream> 
#include <fstream> 
#include <iomanip> 

const int N = 10; // Maximum size of the square matrix

// Function definition to read matrices from a file
void read_matrix(int matrixA[N][N], int matrixB[N][N], int& size, const std::string& file_name) { 
    std::ifstream file(file_name); // Creating an input file stream object and open the file with the given file name
    if (!file.is_open()) { // Checking if the file is opened successfully
        std::cerr << "Error: Unable to open file " << file_name << std::endl; 
        exit(EXIT_FAILURE); 
    }

    file >> size; // Reading matrix size from the first line of the file
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            if (!(file >> matrixA[i][j])) { 
                std::cerr << "Error: Invalid data in file " << file_name << std::endl; 
                exit(EXIT_FAILURE); 
            }
        }
    }

    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrixB[i][j])) { 
                std::cerr << "Error: Invalid data in file " << file_name << std::endl; 
                exit(EXIT_FAILURE); 
            }
        }
    }
    file.close(); // Closing the input file stream
}

// Function definition to print a matrix
void print_matrix(const int matrix[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            std::cout << std::setw(5) << matrix[i][j]; // Print matrix element with width of 5 spaces
        }
        std::cout << std::endl; 
    }
}

// Function definition to add two matrices
void add_matrix(const int matrixA[N][N], const int matrixB[N][N], int sum[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            sum[i][j] = matrixA[i][j] + matrixB[i][j]; // Adding corresponding elements of matrixA and matrixB and store the result in sum
        }
    }
}

// Function definition to multiply two matrices
void mult_matrix(const int matrixA[N][N], const int matrixB[N][N], int product[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            product[i][j] = 0; 
            for (int k = 0; k < size; ++k) { 
                product[i][j] += matrixA[i][k] * matrixB[k][j]; // Performing dot product and store the result in product
            }
        }
    }
}

// Function definition to subtract one matrix from another
void subt_matrix(const int matrixA[N][N], const int matrixB[N][N], int diff[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            diff[i][j] = matrixA[i][j] - matrixB[i][j]; // Subtracting corresponding elements of matrixB from matrixA and storing the result in diff
        }
    }
}

// Function definition to update a specific element in the matrix
void update_element(int matrix[N][N], int row, int col, int value, int size) { 
    if (row >= 0 && row < size && col >= 0 && col < size) { 
        matrix[row][col] = value; // Updating the element at the specified row and column with the given value
    } else { 
        std::cerr << "Error: Invalid row or column index." << std::endl; 
    }
}

// Function definition to find the maximum value in the matrix
void max_value(const int matrix[N][N], int size) { 
    int max_val = matrix[0][0]; 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            if (matrix[i][j] > max_val) { 
                max_val = matrix[i][j]; 
            }
        }
    }
    std::cout << "Max value of the matrix: " << max_val << std::endl; 
}

// Function definition to transpose the matrix
void transpose_matrix(const int matrix[N][N], int size) { 
    int transpose[N][N]; 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            transpose[j][i] = matrix[i][j]; // Swapping row and column indices to transpose the matrix
        }
    }
    std::cout << "Transposed Matrix A:" << std::endl; 
    print_matrix(transpose, size); 
}

int main() { 
    int size; 
    int matrixA[N][N], matrixB[N][N], result[N][N]; 

    read_matrix(matrixA, matrixB, size, "matrix_input.txt"); // Reading matrices from input file

    std::cout << "Matrix A:" << std::endl; 
    print_matrix(matrixA, size);
    std::cout << std::endl; 

    std::cout << "Matrix B:" << std::endl; 
    print_matrix(matrixB, size);
    std::cout << std::endl; 

    add_matrix(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum:" << std::endl; 
    print_matrix(result, size); 
    std::cout << std::endl; 

    mult_matrix(matrixA, matrixB, result, size); 
    std::cout << "Matrix Product:" << std::endl;
    print_matrix(result, size); 
    std::cout << std::endl;

    subt_matrix(matrixA, matrixB, result, size); 
    std::cout << "Matrix Difference:" << std::endl; 
    print_matrix(result, size); 
    std::cout << std::endl; 

    update_element(matrixA, 1, 1, 100, size); 
    std::cout << "Updated Matrix A:" << std::endl; 
    print_matrix(matrixA, size); 
    std::cout << std::endl; 

    max_value(matrixA, size); 
    std::cout << std::endl; 
    
    transpose_matrix(matrixA, size); 

    return 0; 
}





