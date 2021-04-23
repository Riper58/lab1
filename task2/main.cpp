#include <iostream>
#include "Cipher.h"
#include <locale>
#include <codecvt>
using namespace std;
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> codec;
    int key;
    wstring text;
    unsigned op;
    wcout<<L"Input key(rows): ";
    wcin>>key;
    Cipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op>2) {
            wcout<<L"Не может быть, попробуйте другую операцию\n";
        } else if (op>0 && op<3) {
            wcout<<L"Input text: ";
            wcin>>text;
            if (op==1) {
                wcout<<L"Encrypt text: "<<cipher.encrypt(text)<<endl;
            } else {
                wcout<<L"decrypt text: "<<cipher.decrypt(text)<<endl;
            }
        }
    } while (op!=0);
    return 0;
}
