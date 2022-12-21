#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Set the registry key and value names
    string keyName = "HKEY_CURRENT_USER\\Software\\MyKey";
    string valueName = "MyValue";

    // Set the value data for the registry value
    string valueData = "This is the arbitrary code to be injected into the registry";

    // Set the type and size of the value data
    DWORD valueType = REG_SZ;
    DWORD valueSize = valueData.size() + 1;

    // Open the registry key
    HKEY hKey;
    LONG result = RegOpenKeyExA(HKEY_CURRENT_USER, "Software", 0, KEY_WRITE, &hKey);
    if (result != ERROR_SUCCESS)
    {
        cout << "Error opening registry key: " << result << endl;
        return 1;
    }

    // Set the value in the registry
    result = RegSetValueExA(hKey, valueName.c_str(), 0, valueType, (const BYTE*)valueData.c_str(), valueSize);
    if (result != ERROR_SUCCESS)
    {
        cout << "Error setting registry value: " << result << endl;
        return 1;
    }

    // Close the registry key
    RegCloseKey(hKey);

    cout << "Arbitrary code successfully injected into the registry" << endl;

    return 0;
}
