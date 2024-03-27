/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "IEcoCalculatorY.h"
#include "IEcoCalculatorX.h"

/* функция для сравнения int */
int __cdecl compareInts(const void *aPtr, const void *bPtr) {
    int a = *(int *)aPtr, b = *(int *)bPtr;
    return (a > b) - (b > a);
}

/* функция для сравнения double */
int __cdecl compareDoubles(const void *aPtr, const void *bPtr) {
    double a = *(double *)aPtr, b = *(double *)bPtr;
    return (a > b) - (b > a);
}

/* функция для сравнения float */
int __cdecl compareFloats(const void *aPtr, const void *bPtr) {
    float a = *(float *)aPtr, b = *(float *)bPtr;
    return (a > b) - (b > a);
}

/* функция для сравнения string */
int __cdecl compareStrings(const void *aPtr, const void *bPtr) {
    char *a = *(char **)aPtr, *b = *(char **)bPtr;
    return strcmp(a, b);
}

void fillArrayWithRandomInts(int *arr, int arrSize) {
    for (size_t i = 0; i < arrSize; i ++) {
        arr[i] = rand();
    }
}

void testIntSort(IEcoLab1 *pIEcoLab1, FILE *file, int arrSize, IEcoMemoryAllocator1 *pIMem) {
    clock_t start, end;
    int* arr;

    //test
    int arrSizeForTest = 10;
    arr = (int *) pIMem->pVTbl->Alloc(pIMem, arrSizeForTest * sizeof(int));
    fillArrayWithRandomInts(arr, arrSizeForTest);
    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSizeForTest, sizeof(int), compareInts);
    for (size_t i = 0; i < arrSizeForTest - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("insertionSort doesn't work for int.\n");
            return;
        }
    }
    pIMem->pVTbl->Free(pIMem, arr);

    //insertionSort
    arr = (int *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(int));
    fillArrayWithRandomInts(arr, arrSize);
    start = clock();

    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSize, sizeof(int), compareInts);

    end = clock();
    double insertionSortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    //qsort
    arr = (int *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(int));
    fillArrayWithRandomInts(arr, arrSize);
    start = clock();

    qsort(arr, arrSize, sizeof(int), compareInts);

    end = clock();
    double qsortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    fprintf(file, "%s,%s,%d,%lf\n", "insertSort", "int", arrSize, insertionSortDuration);
    fprintf(file, "%s,%s,%d,%lf\n", "qsort", "int", arrSize, qsortDuration);
}


void fillDoubleArray(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (double)rand() + ((double)rand() / RAND_MAX);
    }
}

void testDoubleSort(IEcoLab1 *pIEcoLab1, FILE *file, int arrSize, IEcoMemoryAllocator1 *pIMem) {
    clock_t start, end;
    double* arr;

    //test
    int arrSizeForTest = 10;
    arr = (double *) pIMem->pVTbl->Alloc(pIMem, arrSizeForTest * sizeof(double));
    fillDoubleArray(arr, arrSizeForTest);
    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSizeForTest, sizeof(double), compareDoubles);
    for (size_t i = 0; i < arrSizeForTest - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("insertionSort doesn't work for double.\n");
            return;
        }
    }
    pIMem->pVTbl->Free(pIMem, arr);

    //insertionSort
    arr = (double *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(double));
    fillDoubleArray(arr, arrSize);
    start = clock();

    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSize, sizeof(double), compareDoubles);

    end = clock();
    double insertionSortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    //qsort
    arr = (double *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(double ));
    fillDoubleArray(arr, arrSize);
    start = clock();

    qsort(arr, arrSize, sizeof(double), compareDoubles);

    end = clock();
    double qsortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    fprintf(file, "%s,%s,%d,%lf\n", "insertSort", "double", arrSize, insertionSortDuration);
    fprintf(file, "%s,%s,%d,%lf\n", "qsort", "double", arrSize, qsortDuration);
}

void fillFloatArray(float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (float)rand() + ((float)rand() / RAND_MAX);
    }
}

void testFloatSort(IEcoLab1 *pIEcoLab1, FILE *file, int arrSize, IEcoMemoryAllocator1 *pIMem) {
    clock_t start, end;
    float* arr;

    //test
    int arrSizeForTest = 10;
    arr = (float *) pIMem->pVTbl->Alloc(pIMem, arrSizeForTest * sizeof(float));
    fillFloatArray(arr, arrSizeForTest);
    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSizeForTest, sizeof(float), compareFloats);
    for (size_t i = 0; i < arrSizeForTest - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("insertionSort doesn't work for float.\n");
            return;
        }
    }
    pIMem->pVTbl->Free(pIMem, arr);

    //insertionSort
    arr = (float *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(float));
    fillFloatArray(arr, arrSize);
    start = clock();

    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSize, sizeof(float), compareFloats);

    end = clock();
    double insertionSortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    //qsort
    arr = (float *) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(float));
    fillFloatArray(arr, arrSize);
    start = clock();

    qsort(arr, arrSize, sizeof(float), compareFloats);

    end = clock();
    double qsortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    pIMem->pVTbl->Free(pIMem, arr);

    fprintf(file, "%s,%s,%d,%lf\n", "insertSort", "float", arrSize, insertionSortDuration);
    fprintf(file, "%s,%s,%d,%lf\n", "qsort", "float", arrSize, qsortDuration);
}


void fillStringArray(char **arr, int arrSize, IEcoMemoryAllocator1 *pIMem) {
    for (size_t i = 0; i < arrSize; i++) {
        arr[i] = (char *) pIMem->pVTbl->Alloc(pIMem, 20 * sizeof(char));
        size_t str_size = rand() % 10;
        for (size_t j = 0; j < str_size; ++j) {
            arr[i][j] = (char) (rand() % ('z' - 'a' + 1) + 'a');
        }
        arr[i][str_size] = 0;
    }
}

void testStringSort(IEcoLab1 *pIEcoLab1, FILE *file, int arrSize, IEcoMemoryAllocator1 *pIMem) {
    clock_t start, end;
    char** arr;

    //test
    int arrSizeForTest = 10;
    arr = (char **) pIMem->pVTbl->Alloc(pIMem, arrSizeForTest * sizeof(char *));
    fillStringArray(arr, arrSizeForTest, pIMem);
    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSizeForTest, sizeof(char *), compareStrings);
    for (size_t i = 0; i < arrSizeForTest - 1; i++) {
        if (strcmp(*(char **)arr, *(char **)(arr + sizeof(char))) > 0) {
            printf("insertionSort doesn't work for string.\n");
            return;
        }
    }

    char ** helping_arr = arr;
    for (size_t i = 0; i < arrSizeForTest; i++) {
        pIMem->pVTbl->Free(pIMem, arr[i]);
    }
    pIMem->pVTbl->Free(pIMem, helping_arr);

    //insertionSort
    arr = (char **) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(char *));
    fillStringArray(arr, arrSize, pIMem);
    start = clock();

    pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arrSize, sizeof(char *), compareStrings);

    end = clock();
    double insertionSortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    for (size_t i = 0; i < arrSize; ++i) {
        pIMem->pVTbl->Free(pIMem, arr[i]);
    }
    pIMem->pVTbl->Free(pIMem, arr);

    //qsort
    arr = (char **) pIMem->pVTbl->Alloc(pIMem, arrSize * sizeof(char *));
    fillStringArray(arr, arrSize, pIMem);
    start = clock();

    qsort(arr, arrSize, sizeof(char *), compareStrings);

    end = clock();
    double qsortDuration = (double)(end - start) / CLOCKS_PER_SEC;
    for (size_t i = 0; i < arrSize; ++i) {
        pIMem->pVTbl->Free(pIMem, arr[i]);
    }
    pIMem->pVTbl->Free(pIMem, arr);

    fprintf(file, "%s,%s,%d,%lf\n", "insertSort", "string", arrSize, insertionSortDuration);
    fprintf(file, "%s,%s,%d,%lf\n", "qsort", "string", arrSize, qsortDuration);
}
/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;

    IEcoCalculatorX* pIX = 0;
    IEcoCalculatorY* pIY = 0;

    int arrSizes[5] = {10000, 50000, 100000, 150000, 200000};




    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */
    name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);

    /* Заполнение блока памяти */
    pIMem->pVTbl->Fill(pIMem, name, 'a', 9);


    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result != 0 || pIY == 0) {
        goto Release;
    }

    printf("IEcoCalculatorY test:\n");
    printf("Multiplication test: 111 * 7 = %d\n", pIY->pVTbl->Multiplication(pIY, 111, 7));
    printf("Division test: 777 / 7 = %d\n", pIY->pVTbl->Division(pIY, 777, 7));
    pIY->pVTbl->Release(pIY);

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result != 0 || pIX == 0) {
        goto Release;
    }

    printf("IEcoCalculatorX test:\n");
    printf("Addition test: 770 + 7 = %d\n", pIX->pVTbl->Addition(pIX, 770, 7));
    printf("Subtraction test: 777 - 77 = %d\n", pIX->pVTbl->Subtraction(pIX, 777, 77));
    pIX->pVTbl->Release(pIX);

    printf("\nInterface test:\n");

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Query IX from lab - ok\n");
        pIX->pVTbl->Release(pIX);
    }
    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query IY from lab - ok\n");
        pIY->pVTbl->Release(pIY);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Query IX from IX - ok\n");
        pIX->pVTbl->Release(pIX);
    }

    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query IY from IY - ok\n");
        pIY->pVTbl->Release(pIY);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query IY from IX - ok\n");
        pIY->pVTbl->Release(pIY);
    }


//    FILE * resultFile;
//    srand(time(0));
//    fopen_s(&resultFile, "result.csv", "w");
//    fprintf(resultFile, "sort,type,size,time\n");
//    for (size_t i = 0; i < 5; i++) {
//        testIntSort(pIEcoLab1, resultFile, arrSizes[i], pIMem);
//        testDoubleSort(pIEcoLab1, resultFile, arrSizes[i], pIMem);
//        testFloatSort(pIEcoLab1, resultFile, arrSizes[i], pIMem);
//        testStringSort(pIEcoLab1, resultFile, arrSizes[i], pIMem);
//        printf("+");
//    }

    /* Освлбождение блока памяти */
    pIMem->pVTbl->Free(pIMem, name);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

