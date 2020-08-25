#include <jni.h>
#include <string>
#include <android/window.h>
#include <android/native_window_jni.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_morsecodec_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_morsecodec_MainActivity_Transelete(JNIEnv *env, jobject thiz,jstring transel_jstr) {

    const char *cstr = env->GetStringUTFChars(transel_jstr, nullptr);
    std::string transel = std::string(cstr);
    auto dot = '.';
    auto dash = '_';
    auto space = ' ';

    std::string transleted;
    for (int i = 0; i < transel.size(); i++)
    {
        if (transel[i] == ' ')// .-
        {
            transleted += "  ";
        }
        else if(transel[i] == '\n')
        {
            transleted += '\n';
        }
        //                         ENG                  ||                    RUS
        else if (transel[i] == 'a' || transel[i] == 'A' ||  transel[i] == "а"[1] ||  transel[i] == "А"[1])// .-
        {
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'b' || transel[i] == 'B' || transel[i] == "б"[1] || transel[i] == "Б"[1])// -...
        {
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'c' || transel[i] == 'C' || transel[i] == "ц"[1] || transel[i] == "Ц"[1])// -.-.
        {
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'd' || transel[i] == 'D' || transel[i] == "д"[1] || transel[i] == "Д"[1])// -..
        {
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'e' || transel[i] == 'E' || transel[i] == "е"[1] || transel[i] == "Е"[1])// .
        {
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'f' || transel[i] == 'F' || transel[i] == "ф"[1] || transel[i] == "Ф"[1])// ..-.
        {
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'g' || transel[i] == 'G' || transel[i] == "г"[1] || transel[i] == "Г"[1])// --.
        {
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'h' || transel[i] == 'H' || transel[i] == "х"[1] || transel[i] == "Х"[1])// ....
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'i' || transel[i] == 'I' || transel[i] == "и"[1] || transel[i] == "И"[1])// ..
        {
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'j' || transel[i] == 'J' || transel[i] == "й"[1] || transel[i] == "Й"[1])// .---
        {
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'k' || transel[i] == 'K' || transel[i] == "к"[1] || transel[i] == "К"[1])// -.-
        {
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'l' || transel[i] == 'L' || transel[i] == "л"[1] || transel[i] == "Л"[1])// .-..
        {
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'm' || transel[i] == 'M' || transel[i] == "м"[1] || transel[i] == "М"[1])// --
        {
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'n' || transel[i] == 'N' || transel[i] == "н"[1] || transel[i] == "Н"[1])// -.
        {
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'o' || transel[i] == 'O' || transel[i] == "о"[1] || transel[i] == "О"[1])// ---
        {
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'p' || transel[i] == 'P' || transel[i] == "п"[1] || transel[i] == "П"[1])// .--.
        {
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 'q' || transel[i] == 'Q' || transel[i] == "щ"[1] || transel[i] == "Щ"[1])// --.-
        {
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'r' || transel[i] == 'R' || transel[i] == "р"[1] || transel[i] == "Р"[1])// .-.
        {
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 's' || transel[i] == 'S' || transel[i] == "с"[1] || transel[i] == "С"[1])// ...
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == 't' || transel[i] == 'T' || transel[i] == "т"[1] || transel[i] == "Т"[1])// -
        {
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'u' || transel[i] == 'U' || transel[i] == "у"[1] || transel[i] == "У"[1])// ..-
        {
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'v' || transel[i] == 'V' || transel[i] == "ж"[1] || transel[i] == "Ж"[1])// ...-
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'w' || transel[i] == 'W' || transel[i] == "в"[1] || transel[i] == "В"[1])// .--
        {
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'x' || transel[i] == 'X' || transel[i] == "ь"[1] || transel[i] == "Ь"[1])// -..-
        {
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'y' || transel[i] == 'Y' || transel[i] == "ы"[1] || transel[i] == "Ы"[1])// -.--
        {
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == 'z' || transel[i] == 'Z' || transel[i] == "з"[1] || transel[i] == "З"[1])// --..
        {
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        //ENG - RUS = 32 - 26 = 6
        else if(transel[i] == "ш"[1] || transel[i] == "Ш"[1]){
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if(transel[i] == "ч"[1] || transel[i] == "Ч"[1]){
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if(transel[i] == "ъ"[1] || transel[i] == "Ъ"[1]){
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if(transel[i] == "э"[1] || transel[i] == "Э"[1]){
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if(transel[i] == "ю"[1] || transel[i] == "Ю"[1]){
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if(transel[i] == "я"[1] || transel[i] == "Я"[1]){
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '1')// .----
        {
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '2')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '3')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '4')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '5')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '6')// .----
        {
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '7')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '8')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '9')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '0')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '.')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == ',')// .----
        {
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == ';')// .----
        {
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == ':')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '?')// .----
        {
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '!')// .----
        {
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '-')// .----
        {
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '\'')// .----
        {
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
        else if (transel[i] == '(' || transel[i] == ')')// .----
        {
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += dash;
            transleted += dot;
            transleted += dash;
            transleted += space;
        }
        else if (transel[i] == '"')// .----
        {
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += dot;
            transleted += dash;
            transleted += dot;
            transleted += space;
        }
    }
    return env->NewStringUTF(transleted.c_str());
//return transleted;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_morsecodec_MainActivity_Translete_1backtoEng(JNIEnv *env, jobject thiz,
                                                              jstring transel_jstr) {
    const char *cstr = env->GetStringUTFChars(transel_jstr, nullptr);
    std::string transel = std::string(cstr);

    std::string transleted;
    std::string letter;
    bool scobka_state = true;
    for (int i = 0; i < transel.size(); i++) {
        while (transel[i] != ' ') {
            letter += transel[i];
            i++;
        }
        if (letter == "._")// (transel[i] == 'a' || transel[i] == 'A')// A
        {
            transleted += 'a';
            letter="";
        } else
            if (letter == "_...")//(transel[i] == 'b' || transel[i] == 'B')// -...
        {
            transleted += 'b';
            letter="";
        }
        else if (letter == "_._.")//(transel[i] == 'c' || transel[i] == 'C')// -.-.
        {
            transleted += 'c';
            letter="";
        }
        else if (letter == "_..")//(transel[i] == 'd' || transel[i] == 'D')// -..
        {
            transleted += 'd';
            letter="";
        }
        else if (letter == ".")//(transel[i] == 'e' || transel[i] == 'E')// .
        {
            transleted += 'e';
            letter="";
        }
        else if (letter == ".._.") //(transel[i] == 'f' || transel[i] == 'F')// ..-.
        {
            transleted += 'f';
            letter="";
        }
        else if (letter == "__.")//(transel[i] == 'g' || transel[i] == 'G')// --.
        {
            transleted += 'g';
            letter="";
        }
        else if (letter == "....")//(transel[i] == 'h' || transel[i] == 'H')// ....
        {
            transleted += 'h';
            letter="";
        }
        else if (letter == "..")//(transel[i] == 'i' || transel[i] == 'I')// ..
        {
            transleted += 'i';
            letter="";
        }
        else if (letter == ".___")//(transel[i] == 'j' || transel[i] == 'J')// .---
        {
            transleted += 'j';
            letter="";
        }
        else if  (letter == "_._")//(transel[i] == 'k' || transel[i] == 'K')// -.-
        {
            transleted += 'k';
            letter="";
        }
        else if (letter == "._..")//(transel[i] == 'l' || transel[i] == 'L')// .-..
        {
            transleted += 'l';
            letter="";
        }
        else if (letter == "__")//(transel[i] == 'm' || transel[i] == 'M')// --
        {
            transleted += 'm';
            letter="";
        }
        else if (letter == "_.")//(transel[i] == 'n' || transel[i] == 'N')// -.
        {
            transleted += 'n';
            letter="";
        }
        else if (letter == "___")//(transel[i] == 'o' || transel[i] == 'O')// ---
        {
            transleted += 'o';
            letter="";
        }
        else if (letter == ".__.")//(transel[i] == 'p' || transel[i] == 'P')// .--.
        {
            transleted += 'p';
            letter="";
        }
        else if (letter == "__._")//(transel[i] == 'q' || transel[i] == 'Q')// --.-
        {
            transleted += 'q';
            letter="";
        }
        else if (letter == "._.")//(transel[i] == 'r' || transel[i] == 'R')// .-.
        {
            transleted += 'r';
            letter="";
        }
        else if (letter == "...")//(transel[i] == 's' || transel[i] == 'S')// ...
        {
            transleted += 's';
            letter="";
        }
        else if (letter == "_")//(transel[i] == 't' || transel[i] == 'T')// -
        {
            transleted += 't';
            letter="";
        }
        else if (letter == ".._")//(transel[i] == 'u' || transel[i] == 'U')// ..-
        {
            transleted += 'u';
            letter="";
        }
        else if (letter == "..._")//(transel[i] == 'v' || transel[i] == 'V')// ...-
        {
            transleted += 'v';
            letter="";
        }
        else if (letter == ".__")//(transel[i] == 'w' || transel[i] == 'W')// .--
        {
            transleted += 'w';
            letter="";
        }
        else if (letter == "_.._")//(transel[i] == 'x' || transel[i] == 'X')// -..-
        {
            transleted += 'x';
            letter="";
        }
        else if (letter == "_.__")//(transel[i] == 'y' || transel[i] == 'Y')// -.--
        {
            transleted += 'y';
            letter="";
        }
        else if (letter == "__..")//(transel[i] == 'z' || transel[i] == 'Z')// --..
        {
            transleted += 'z';
            letter="";
        }
        else if (letter == ".____")//(transel[i] == '1')// .----
        {
            transleted += '1';
            letter="";
        }
        else if (letter == "..___")//(transel[i] == '2')// .----
        {
            transleted += '2';
            letter="";
        }
        else if (letter == "...__")//(transel[i] == '3')// .----
        {
            transleted += '3';
            letter="";
        }
        else if (letter == "...._")//(transel[i] == '4')// .----
        {
            transleted += '4';
            letter="";
        }
        else if (letter == ".....")//(transel[i] == '5')// .----
        {
            transleted += '5';
            letter="";
        }
        else if (letter == "_....")//(transel[i] == '6')// .----
        {
            transleted += '6';
            letter="";
        }
        else if (letter == "__...")//(transel[i] == '7')// .----
        {
            transleted += '7';
            letter="";
        }
        else if (letter == "___..")//(transel[i] == '8')// .----
        {
            transleted += '8';
            letter="";
        }
        else if (letter == "____.")//(transel[i] == '9')// .----
        {
            transleted += '9';
            letter="";
        }
        else if (letter == "_____")//(transel[i] == '0')// .----
        {
            transleted += '0';
            letter="";
        }
        else if (letter == "......")//(transel[i] == '.')// .----
        {
            transleted += '.';
            letter="";
        }
        else if (letter == "._._._")//(transel[i] == ',')// .----
        {
            transleted += ',';
            letter="";
        }
        else if (letter == "_._._.")//(transel[i] == ';')// .----
        {
            transleted += ';';
            letter="";
        }
        else if (letter == "___...")//(transel[i] == ':')// .----
        {
            transleted += ':';
            letter="";
        }
        else if (letter == "..__..")//(transel[i] == '?')// .----
        {
            transleted += '?';
            letter="";
        }
        else if (letter == "__..__")//(transel[i] == '!')// .----
        {
            transleted += '!';
            letter="";
        }
        else if (letter == "_...._")//(transel[i] == '-')// .----
        {
            transleted += '-';
            letter="";
        }
        else if (letter == ".____.")//(transel[i] == '\'')// .----
        {
            transleted += '\'';
            letter="";
        }
        else if (letter == "_.__._")//(transel[i] == '(' || transel[i] == ')')// .----
        {
            if(scobka_state)
            {
                transleted += '(';
                scobka_state = false;
            }
            else {
                transleted += ')';
                scobka_state = true;
            }
            letter="";
        }
        else if (letter == "._.._.")//(transel[i] == '"')// .----
        {
            transleted += '"';
            letter="";
        }else
        if (transel[i] == ' ')// .-
        {
            transleted += " ";
            i++;
        }
        else if(transel[i] == '\n')
        {
            transleted += '\n';
            i++;
        }
    }

    return env->NewStringUTF(transleted.c_str());
}
//26 in eng
//33 in rus
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_morsecodec_MainActivity_Translete_1backtoRus(JNIEnv *env, jobject thiz,
                                                              jstring transel_jstr) {
    const char *cstr = env->GetStringUTFChars(transel_jstr, nullptr);
    std::string transel = std::string(cstr);

    std::string transleted;
    std::string letter;
    bool scobka_state = true;
    for (int i = 0; i < transel.size(); i++) {
        while (transel[i] != ' ') {
            letter += transel[i];
            i++;
        }
        if (letter == "._")// (transel[i] == 'a' || transel[i] == 'A')// A
        {
            transleted += "а";
            letter="";
        } else
        if (letter == "_...")//(transel[i] == 'б' || transel[i] == 'Б')// -...
        {
            transleted += "б";
            letter="";
        }
        else if (letter == "_._.")//(transel[i] == 'ц' || transel[i] == 'Ц')// -.-.
        {
            transleted += "ц";
            letter="";
        }
        else if (letter == "_..")//(transel[i] == 'д' || transel[i] == 'D')// -..
        {
            transleted += "д";
            letter="";
        }
        else if (letter == ".")//(transel[i] == 'e' || transel[i] == 'E')// .
        {
            transleted += "е";
            letter="";
        }
        else if (letter == ".._.") //(transel[i] == 'ф' || transel[i] == 'F')// ..-.
        {
            transleted += "ф";
            letter="";
        }
        else if (letter == "__.")//(transel[i] == 'г' || transel[i] == 'G')// --.
        {
            transleted += "г";
            letter="";
        }
        else if (letter == "....")//(transel[i] == 'х' || transel[i] == 'H')// ....
        {
            transleted += "х";
            letter="";
        }
        else if (letter == "..")//(transel[i] == 'и' || transel[i] == 'I')// ..
        {
            transleted += "и";
            letter="";
        }
        else if (letter == ".___")//(transel[i] == 'й' || transel[i] == 'J')// .---
        {
            transleted += "й";
            letter="";
        }
        else if  (letter == "_._")//(transel[i] == 'к' || transel[i] == 'K')// -.-
        {
            transleted += "к";
            letter="";
        }
        else if (letter == "._..")//(transel[i] == 'л' || transel[i] == 'L')// .-..
        {
            transleted += "л";
            letter="";
        }
        else if (letter == "__")//(transel[i] == 'м' || transel[i] == 'M')// --
        {
            transleted += "м";
            letter="";
        }
        else if (letter == "_.")//(transel[i] == 'н' || transel[i] == 'N')// -.
        {
            transleted += "н";
            letter="";
        }
        else if (letter == "___")//(transel[i] == 'о' || transel[i] == 'O')// ---
        {
            transleted += "о";
            letter="";
        }
        else if (letter == ".__.")//(transel[i] == 'п' || transel[i] == 'P')// .--.
        {
            transleted += "п";
            letter="";
        }
        else if (letter == "__._")//(transel[i] == 'щ' || transel[i] == 'Q')// --.-
        {
            transleted += "щ";
            letter="";
        }
        else if (letter == "._.")//(transel[i] == 'р' || transel[i] == 'R')// .-.
        {
            transleted += "р";
            letter="";
        }
        else if (letter == "...")//(transel[i] == 'с' || transel[i] == 'S')// ...
        {
            transleted += "с";
            letter="";
        }
        else if (letter == "_")//(transel[i] == 'т' || transel[i] == 'T')// -
        {
            transleted += "т";
            letter="";
        }
        else if (letter == ".._")//(transel[i] == 'у' || transel[i] == 'U')// ..-
        {
            transleted += "у";
            letter="";
        }
        else if (letter == "..._")//(transel[i] == 'ж' || transel[i] == 'V')// ...-
        {
            transleted += "ж";
            letter="";
        }
        else if (letter == ".__")//(transel[i] == 'в' || transel[i] == 'W')// .--
        {
            transleted += "в";
            letter="";
        }
        else if (letter == "_.._")//(transel[i] == 'ь' || transel[i] == 'X')// -..-
        {
            transleted += "ь";
            letter="";
        }
        else if (letter == "_.__")//(transel[i] == 'ы' || transel[i] == 'Y')// -.--
        {
            transleted += "ы";
            letter="";
        }
        else if (letter == "__..")//(transel[i] == 'з' || transel[i] == 'Z')// --..
        {
            transleted += "з";
            letter="";
        }
        else if (letter == "____")//(transel[i] == 'ш' || transel[i] == 'Z')// --..
        {
            transleted += "ш";
            letter="";
        }
        else if (letter == "___.")//(transel[i] == 'ч' || transel[i] == 'Z')// --..
        {
            transleted += "ч";
            letter="";
        }
        else if (letter == ".__._.")//(transel[i] == 'ъ' || transel[i] == 'Z')// --..
        {
            transleted += "ъ";
            letter="";
        }else if (letter == "..._...")//(transel[i] == 'э' || transel[i] == 'Z')// --..
        {
            transleted += "э";
            letter="";
        }else if (letter == "..__")//(transel[i] == 'ю' || transel[i] == 'Z')// --..
        {
            transleted += "ю";
            letter="";
        }else if (letter == "._._")//(transel[i] == 'я' || transel[i] == 'Z')// --..
        {
            transleted += "я";
            letter="";
        }
        else if (letter == ".____")//(transel[i] == '1')// .----
        {
            transleted += '1';
            letter="";
        }
        else if (letter == "..___")//(transel[i] == '2')// .----
        {
            transleted += '2';
            letter="";
        }
        else if (letter == "...__")//(transel[i] == '3')// .----
        {
            transleted += '3';
            letter="";
        }
        else if (letter == "...._")//(transel[i] == '4')// .----
        {
            transleted += '4';
            letter="";
        }
        else if (letter == ".....")//(transel[i] == '5')// .----
        {
            transleted += '5';
            letter="";
        }
        else if (letter == "_....")//(transel[i] == '6')// .----
        {
            transleted += '6';
            letter="";
        }
        else if (letter == "__...")//(transel[i] == '7')// .----
        {
            transleted += '7';
            letter="";
        }
        else if (letter == "___..")//(transel[i] == '8')// .----
        {
            transleted += '8';
            letter="";
        }
        else if (letter == "____.")//(transel[i] == '9')// .----
        {
            transleted += '9';
            letter="";
        }
        else if (letter == "_____")//(transel[i] == '0')// .----
        {
            transleted += '0';
            letter="";
        }
        else if (letter == "......")//(transel[i] == '.')// .----
        {
            transleted += '.';
            letter="";
        }
        else if (letter == "._._._")//(transel[i] == ',')// .----
        {
            transleted += ',';
            letter="";
        }
        else if (letter == "_._._.")//(transel[i] == ';')// .----
        {
            transleted += ';';
            letter="";
        }
        else if (letter == "___...")//(transel[i] == ':')// .----
        {
            transleted += ':';
            letter="";
        }
        else if (letter == "..__..")//(transel[i] == '?')// .----
        {
            transleted += '?';
            letter="";
        }
        else if (letter == "__..__")//(transel[i] == '!')// .----
        {
            transleted += '!';
            letter="";
        }
        else if (letter == "_...._")//(transel[i] == '-')// .----
        {
            transleted += '-';
            letter="";
        }
        else if (letter == ".____.")//(transel[i] == '\'')// .----
        {
            transleted += '\'';
            letter="";
        }
        else if (letter == "_.__._")//(transel[i] == '(' || transel[i] == ')')// .----
        {
            if(scobka_state)
            {
                transleted += '(';
                scobka_state = false;
            }
            else {
                transleted += ')';
                scobka_state = true;
            }
            letter="";
        }
        else if (letter == "._.._.")//(transel[i] == '"')// .----
        {
            transleted += '"';
            letter="";
        }else
        if (transel[i] == ' ')// .-
        {
            transleted += " ";
            i++;
        }
        else if(transel[i] == '\n')
        {
            transleted += '\n';
            i++;
        }
    }

    return env->NewStringUTF(transleted.c_str());
}