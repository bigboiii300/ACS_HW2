#include "EncryptionText.h"
#include "ReplaceByShift.h"
#include "ReplaceWithDigit.h"
#include "ReplaceWithSymbols.h"

//------------------------------------------------------------------------------
// Ввод параметров языка из файла
EncryptionText *EncryptionText::StaticIn(FILE *file) {
    EncryptionText *encryptText = NULL;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 1:
            encryptText = new ReplaceByShift;
            encryptText->In(file);
            break;
        case 2:
            encryptText = new ReplaceWithDigit;
            encryptText->In(file);
            break;
        default:
            encryptText = new ReplaceWithSymbols;
            encryptText->In(file);
            break;
    }
    return encryptText;
}

EncryptionText *EncryptionText::StaticInRnd() {
    EncryptionText *encryptText = NULL;
    int kind = Utils::randInt(1,3);
    switch (kind) {
        case 1:
            encryptText = new ReplaceByShift;
            encryptText->InRnd();
            break;
        case 2:
            encryptText = new ReplaceWithDigit;
            encryptText->InRnd();
            break;
        default:
            encryptText = new ReplaceWithSymbols;
            encryptText->InRnd();
            break;
    }
    return encryptText;
}