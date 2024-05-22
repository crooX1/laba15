#include "matrix.h"

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
void test_getMemMatrix1() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0 && m.nCols == 0 && m.values != NULL);
    freeMemMatrix(m);
}
void test_getMemMatrix2() {
    matrix m = getMemMatrix(1, 4);
    assert(m.nRows == 1 && m.nCols == 4 && m.values != NULL);
    freeMemMatrix(m);
}
void test_getMemMatrix() {
    test_getMemMatrix1();
    test_getMemMatrix2();
}
void test_getMemArrayOfMatrices1() {
    matrix *ms = getMemArrayOfMatrices(5, 0, 0);
    for (size_t i = 0; i < 5; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 5);
}
void test_getMemArrayOfMatrices2() {
    matrix *ms = getMemArrayOfMatrices(3, 2, 2);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 2 && ms[i].nCols == 2 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}
void test_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices1();
    test_getMemArrayOfMatrices2();
}
void test_swapRows1() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3
    },1, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 2, 3
    },1, 3);
    swapRows(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_swapRows2() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3,
            4, 5, 6
    },2, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            4, 5, 6,
            1, 2, 3
    },2, 3);
    swapRows(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
}
void test_swapColumns_oneColumn() {
    matrix m1 = createMatrixFromArray((int[]) {
            1,
            2,
            3
    },3, 1);
    matrix m2 = createMatrixFromArray((int[]) {
            1,
            2,
            3
    },3, 1);
    swapColumns(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_swapColumns_twoColumns() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 4,
            2, 5,
            3, 6
    },3, 2);
    matrix m2 = createMatrixFromArray((int[]) {
            4, 1,
            5, 2,
            6, 3
    },3, 2);
    swapColumns(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_swapColumns() {
    test_swapColumns_oneColumn();
    test_swapColumns_twoColumns();
}
void test_insertionSortRowsMatrixByRowCriteria1() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3,
    },1, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 2, 3
    },1, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_insertionSortRowsMatrixByRowCriteria2() {
    matrix m1 = createMatrixFromArray((int[]) {
            3, 3, 3,
            1, 1, 1,
            2, 2, 2
    },3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 1, 1,
            2, 2, 2,
            3, 3, 3
    },3, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria1();
    test_insertionSortRowsMatrixByRowCriteria2();
}
void test_insertionSortColsMatrixByColCriteria1() {
    matrix m1 = createMatrixFromArray((int[]) {
            1,
            2,
            3
    },3, 1);
    matrix m2 = createMatrixFromArray((int[]) {
            1,
            2,
            3
    },3, 1);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_insertionSortColsMatrixByColCriteria2() {
    matrix m1 = createMatrixFromArray((int[]) {
            3, 1, 2,
            3, 1, 2,
            3, 1, 2
    },3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 2, 3,
            1, 2, 3,
            1, 2, 3
    },3, 3);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
}
void test_isSquareMatrix1() {
    matrix m = createMatrixFromArray((int[]) {
            1, 1, 1,
            2, 2, 2,
            3, 3, 3
    },3, 3);
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}
void test_isSquareMatrix2() {
    matrix m = createMatrixFromArray((int[]) {
            1, 1, 1,
            2, 2, 2,
    },2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}
void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
}
void test_areTwoMatricesEqual1() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    },3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    },3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_areTwoMatricesEqual2() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 8
    },3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    },3, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual1();
    test_areTwoMatricesEqual2();
}
void test_isEMatrix1() {
    matrix m = createMatrixFromArray((int[]) {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
    },3, 3);
    assert(isEMatrix(m));
    freeMemMatrix(m);
}
void test_isEMatrix2() {
    matrix m = createMatrixFromArray((int[]) {
            1, 0, 3,
            4, 1, 0,
            0, 0, 1
    },3, 3);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}
void test_isEMatrix() {
    test_isEMatrix1();
    test_isEMatrix2();
}
void test_isSymmetricMatrix1() {
    matrix m = createMatrixFromArray((int[]) {
            1, 2, 3,
            2, 3, 7,
            3, 7, 1
    },3, 3);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}
void test_isSymmetricMatrix2() {
    matrix m = createMatrixFromArray((int[]) {
            5, 4, 3,
            7, 2, 0,
            3, 4, 1
    },3, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}
void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
}
void test_transposeSquareMatrix1() {
    matrix m1 = createMatrixFromArray((int[]) {
            1
    },1, 1);
    matrix m2 = createMatrixFromArray((int[]) {
            1
    },1, 1);
    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_transposeSquareMatrix2() {
    matrix m1 = createMatrixFromArray((int[]) {
            1, 2, 3,
            1, 2, 3,
            1, 2, 3
    },3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
            1, 1, 1,
            2, 2, 2,
            3, 3, 3
    },3, 3);
    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_transposeSquareMatrix() {
    test_transposeSquareMatrix1();
    test_transposeSquareMatrix2();
}
void test_getMinValuePos1() {
    matrix m = createMatrixFromArray((int[]) {
            2
    },1, 1);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(m);
}
void test_getMinValuePos2() {
    matrix m = createMatrixFromArray((int[]) {
            8, 2, 3,
            5, 7, 1,
            4, 2, 3
    },3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 1 && p.colIndex == 2);
    freeMemMatrix(m);
}
void test_getMinValuePos() {
    test_getMinValuePos1();
    test_getMinValuePos2();
}
void test_getMaxValuePos1() {
    matrix m = createMatrixFromArray((int[]) {
            41
    },1, 1);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(m);
}
void test_getMaxValuePos2() {
    matrix m = createMatrixFromArray((int[]) {
            7, 4, 1,
            5, 21, 3,
            1, 21, 23
    },3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 2 && p.colIndex == 2);
    freeMemMatrix(m);
}
void test_getMaxValuePos() {
    test_getMaxValuePos1();
    test_getMaxValuePos2();
}
void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_isSquareMatrix();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}