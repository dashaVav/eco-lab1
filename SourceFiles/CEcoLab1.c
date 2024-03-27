/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIY;
        ++pCMe->m_cRef;
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorX)) {
        if (pCMe->m_pInnerUnknownB == 0) {
            *ppv = &pCMe->m_pVTblIX;
        }
        else {
            pCMe->m_pInnerUnknownB->pVTbl->QueryInterface(pCMe->m_pInnerUnknownB, riid, ppv);
        }
        ++pCMe->m_cRef;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*X*/
int16_t ECOCALLMETHOD IEcoCalculatorX_QueryInterface (/* in */ IEcoCalculatorX* me, /* in */ const UGUID* riid, /* out */ void **ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    if (me == 0 || ppv == 0) {
        return -1;
    }

    return pCMe->m_pIX->pVTbl->QueryInterface(pCMe->m_pIX, riid, ppv);
}

uint32_t ECOCALLMETHOD IEcoCalculatorX_AddRef (/* in */ IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIX->pVTbl->AddRef(pCMe->m_pIX);
}

uint32_t ECOCALLMETHOD IEcoCalculatorX_Release (/* in */ IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
}

int32_t ECOCALLMETHOD IEcoCalculatorX_Addition (/* in */ IEcoCalculatorX* me, /* in */  int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    if (me == 0) {
        return -1;
    }


    return pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
}

int16_t ECOCALLMETHOD IEcoCalculatorX_Subtraction (/* in */ IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
}

/*Y*/
int16_t ECOCALLMETHOD IEcoCalculatorY_QueryInterface (/* in */IEcoCalculatorY* me, /* in */ const UGUID* riid, /* out */ void **ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));

    if (me == 0 || ppv == 0) {
        return -1;
    }

    return pCMe->m_pIY->pVTbl->QueryInterface(pCMe->m_pIY, riid, ppv);
}


uint32_t ECOCALLMETHOD IEcoCalculatorY_AddRef (/* in */ IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIY->pVTbl->AddRef(pCMe->m_pIY);
}

uint32_t ECOCALLMETHOD IEcoCalculatorY_Release (/* in */ IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
}

int32_t ECOCALLMETHOD IEcoCalculatorY_Multiplication (/* in */ IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
}

int16_t ECOCALLMETHOD IEcoCalculatorY_Division (/* in */ IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));

    if (me == 0) {
        return -1;
    }

    return pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
}


/* копирует данные из src в dest */
void byteCopy(void *dest, const void *src, size_t size) {
    char *d = dest;
    const char *s = src;
    for (size_t i = 0; i < size; ++i) {
        d[i] = s[i];
    }
}

/*
 *
 * <сводка>
 *   Функция qsort
 * </сводка>
 *
 * <описание>
 *   Сортировка вставками
 * </описание>
 *
 */

int16_t ECOCALLMETHOD CEcoLab1_qsort(/* in */ struct IEcoLab1* me, void *arrPrt, size_t arrSize, size_t elemSize, int (__cdecl *compare)(const void *, const void *)) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || arrPrt == 0 || compare == 0) {
        return -1;
    }

    /* Сортировка вставками */
    char* tmp = (char*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, elemSize);

    char *arr = (char *)arrPrt;

    for (size_t i = 1; i < arrSize; ++i) {
        byteCopy(tmp, arr + i * elemSize, elemSize);
        size_t j = i;
        while (j > 0 && compare(arr + (j - 1) * elemSize, tmp) > 0) {
            byteCopy(arr + j * elemSize, arr + (j - 1) * elemSize, elemSize);
            --j;
        }
        byteCopy(arr + j * elemSize, tmp, elemSize);
    }

    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, tmp);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);

    if (result != 0 || pCMe->m_pIY == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY,(void **) &pCMe->m_pIY);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, pOuterUnknown, &IID_IEcoUnknown,(void**) &pCMe->m_pInnerUnknownB);

    if (result != 0 || pCMe->m_pInnerUnknownB == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void **) &pCMe->m_pIX);
    }

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
        CEcoLab1_QueryInterface,
        CEcoLab1_AddRef,
        CEcoLab1_Release,
        CEcoLab1_qsort
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblLab2 = {
        IEcoCalculatorX_QueryInterface,
        IEcoCalculatorX_AddRef,
        IEcoCalculatorX_Release,
        IEcoCalculatorX_Addition,
        IEcoCalculatorX_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblLab2 = {
        IEcoCalculatorY_QueryInterface,
        IEcoCalculatorY_AddRef,
        IEcoCalculatorY_Release,
        IEcoCalculatorY_Multiplication,
        IEcoCalculatorY_Division
};


/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    pCMe->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblLab2;
    pCMe->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTblLab2;


    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
