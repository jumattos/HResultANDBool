#include "windows.h"
#include <iostream>

int OldCode(VARIANT_BOOL fResult, HRESULT hResult)
{
    if (SUCCEEDED(hResult && fResult == VARIANT_FALSE))
        return 1;
    else
        return 0;
}

int NewCode(VARIANT_BOOL fResult, HRESULT hResult)
{
    if (SUCCEEDED(hResult) && fResult == VARIANT_FALSE)
        return 1;
    else
        return 0;
}

int main()
{
    VARIANT_BOOL fResults[] = { VARIANT_FALSE, VARIANT_TRUE };
    HRESULT hResults[] = { S_OK, E_FAIL };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (OldCode(fResults[i], hResults[j]) != NewCode(fResults[i], hResults[j]))
            {
                std::cout << "Test failed" << std::endl;
            }
            else
            {
                std::cout << "Test succeeded" << std::endl;
            }
        }
    }
}

