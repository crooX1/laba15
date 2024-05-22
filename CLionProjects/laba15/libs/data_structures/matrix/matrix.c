#include "matrix.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}
void freeMemMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }
    free(m.values);
}
void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(ms[i]);
    }
    free(ms);
}
void inputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j< m.nCols; j++){
            scanf(("%d",&m.values[i][j]));
        }
    }
}
void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}
void outputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d",m.values[i][j]);
        }
        printf("\n");
    }
}
void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i<nMatrices; i++){
        outputMatrix(ms[i]);
    }
}
void swapRows(matrix m, int i1, int i2){
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}
void swapColumns (matrix m, int j1, int j2){
    for (int i = 0; i< m.nRows; i++){
        int t = m.values[i][j1];
        m.values[i][j1]=m.values[i][j2];
        m.values[i][j2]=t;
    }
}
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria) (int *, int)){
    int criteriaArray[m.nRows];
    for (int i = 0; i<m.nRows; i++){
        criteriaArray[i] = criteria(m.values[i],m.nCols);
    }
    for (int i = 0; i < m.nRows; i++) {
        int t = criteriaArray[i];
        int j = i;
        while (j>0 && criteriaArray[j-1]>t){
            criteriaArray[j] = criteriaArray[j-1];
            swapRows(m,j,j-1);
            j--;
        }
        criteriaArray[j] = t;
    }
}
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)){
    int criteriaArray[m.nCols];
    int copyColumn[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j<m.nRows; j++){
            copyColumn[j] = m.values[j][i];
        }
        criteriaArray[i]=criteria(copyColumn, m.nRows);
    }
    for (int i = 1; i <m.nCols ; i++) {
        int t = criteriaArray[i];
        int j = i;
        while(j>0 && criteriaArray[j-1>t]){
            criteriaArray[j] = criteriaArray[j-1];
            swapColumns(m,j,j-1);
            j--;
        }
        criteriaArray[j] == t;
    }
}
bool isSquareMatrix(matrix m){
    return m.nRows == m.nCols;
}
bool areTwoMaticesEqual(matrix m1, matrix m2){
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    }
    return true;
}
bool isEMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i==j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0){
                return false;
            }
        }
    }return true;
}
bool isSymmetricMatrix(matrix m){
    if (!isSquareMatrix(m))
        return false;
    for(int i =0; i < m.nRows; i++)
        for (int j = 0; j< m.nCols; j++)
            if (i != j && m.values[i][j] != m.values[j][i])
                return false;
    return true;
}
void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void transposeSquareMatrix(matrix m){
    assert(isSquareMatrix(m));
    int pos = 0;
    for (int i = pos; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            if (i != j)
                swap(&m.values[i][j], &m.values[j][i]);
            pos++;
        }
}
position getMinValuePos(matrix m){
    int minRaw = 0;
    int minCol = 0;
    int min = m.values[minRaw][minCol];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min){
                min = m.values[i][j];
                minRaw = i;
                minCol = j;
            }
        }
    }
    return (position) {minRaw, minCol};
}
position getMaxValuePos(matrix m){
    int maxRaw = 0;
    int maxCol = 0;
    int max = m.values[maxRaw][maxCol];
    for (int i = 0; i< m.nCols; i++){
        for (int j = 0; j < m.nCols; j++){
            if (m.values[i][j]>max){
                max = m.values[i][j];
                maxRaw = i;
                maxCol = j;
            }
        }
    }
    return (position){maxRaw, maxCol};
}
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols){
    matrix m = getMemMatrix(nRows,nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++) {
            m.values[i][j] =a[k++];
        }
    }
    return m;
}
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols){
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++) {
        for (int i = 0; i<nRows; i++){
            for (int j = 0; j < nCols; j++) {
                ms[k].values[i][j] = values[l++];
            }
        }

    }
    return ms;
}
