#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <iostream>

volatile UINT w = 0;
DWORD WINAPI Add() {
    while (true) {
        w++;
        std::cout << w << std::endl;
        Sleep(100);
    }
    return 0;
}

int main()
{
    setlocale(0, "rus");
    wchar_t count[] = L"C:\\Users\\st310-04\\Desktop\\Демин\\Count\\x64\\Debug\\Count.exe";
    wchar_t Word[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
    wchar_t NotePad[] = L"C:\\WINDOWS\\system32\\notepad.exe";
    wchar_t Paint[] = L"C:\\WINDOWS\\system32\\mspaint.exe";
    wchar_t Excel[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
    STARTUPINFO si;
    PROCESS_INFORMATION excelApp[100];
    PROCESS_INFORMATION wordApp[100];
    PROCESS_INFORMATION paintApp[100];
    PROCESS_INFORMATION notepadApp[100];
    PROCESS_INFORMATION piApp[100];
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    if (!CreateProcess(count, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp[0])) {
        std::cout << "Child process is not Created";
        _getch();
        return 0;
    }
    int c = 0;
    int ex = 0;
    int word = 0;
    int pain = 0;
    int note = 0;

    /*if (!CreateProcess(Word, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &wordApp[0])) {
        std::cout << "Child process is not Created";
        _getch();
        return 0;
    }
    TerminateProcess(wordApp[0].hProcess, 1);
    CloseHandle(wordApp[0].hThread);
    CloseHandle(wordApp[0].hProcess);

    wordApp[0].hProcess = NULL;
    if (wordApp[0].hProcess == NULL) {
        std::cout << "Child process is not Creat101ed";
    }

    if (!CreateProcess(Word, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &wordApp[0])) {
        std::cout << "Child process is not00Created";
        _getch();
        return 0;
    }
    TerminateProcess(wordApp[0].hProcess, 1);
    CloseHandle(wordApp[0].hThread);
    CloseHandle(wordApp[0].hProcess);
    if (wordApp[0].hProcess == NULL) {
        std::cout << "Child process is not Creat112ed";
    }*/
    bool um=true;
    bool id = false;
    while (um) {
        system("cls");
        std::cout << "Выберите действие" << std::endl;
        std::cout << "1-Открть Word" << std::endl;
        std::cout << "2-Открть NotePad" << std::endl;
        std::cout << "3-Открть Paint" << std::endl;
        std::cout << "4-Открть Excel" << std::endl;
        std::cout << "5-Закрыть Word" << std::endl;
        std::cout << "6-Закрыть NotePad" << std::endl;
        std::cout << "7-Закрыть Paint" << std::endl;
        std::cout << "8-Закрыть Excel" << std::endl;
        std::cout << "9-Закрыть Всё1" << std::endl;
        std::cout << "C-Закрыть Счётчик" << std::endl;
        std::cout << "P-Приостановить Счётчик" << std::endl;
        std::cout << "S-Запустить Счётчик" << std::endl;
        c = _getch();
        switch (c)
        {
        case '1':
            if (!CreateProcess(Word, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &wordApp[word])) {
                std::cout << "Child process is not Created";
                _getch();
                return 0;
            }
            if (word < 100)
                word++;
            break;
        case '2':
            if (!CreateProcess(NotePad, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &notepadApp[note])) {
                std::cout << "Child process is not Created";
                _getch();
                return 0;
            }
            if (note < 100)
                note++;
            break;
        case '3':
            if (!CreateProcess(Paint, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &paintApp[pain])) {
                std::cout << "Child process is not Created";
                _getch();
                return 0;
            }
            if (pain < 100)
                pain++;
            break;
        case '4':
            if (!CreateProcess(Excel, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &excelApp[ex])) {
                std::cout << "Child process is not Created";
                _getch();
                return 0;
            }
            if (ex < 100)
                ex++;
            break;
        case '5':
            id = false;
            for (int i = 0; i < word; i++) {
                if (wordApp[i].hProcess != NULL) {
                    id = true;
                    break;
                }
            }
            if (id) {
                TerminateProcess(wordApp[word - 1].hProcess, 1);
                CloseHandle(wordApp[word - 1].hThread);
                CloseHandle(wordApp[word - 1].hProcess);
                wordApp[word - 1].hProcess = NULL;
                word--;
            }
            else {
                std::cout << "Нет открытых процессов";
                _getch();
            }
            break;
        case '6':
            id = false;
            for (int i = 0; i < note; i++) {
                if (notepadApp[i].hProcess != NULL) {
                    id = true;
                    break;
                }
            }
            if (id) {
                TerminateProcess(notepadApp[note - 1].hProcess, 1);
                CloseHandle(notepadApp[note - 1].hThread);
                notepadApp[note - 1].hProcess = NULL;
                note--;
            }
            else {
                std::cout << "Нет открытых процессов";
                _getch();
            }
            break;
        case '7':

            id = false;
            for (int i = 0; i < pain; i++) {
                if (paintApp[i].hProcess != NULL) {
                    id = true;
                    break;
                }
            }
            if (id) {
                TerminateProcess(paintApp[pain - 1].hProcess, 1);
                CloseHandle(paintApp[pain - 1].hThread);
                CloseHandle(paintApp[pain - 1].hProcess);
                notepadApp[pain - 1].hProcess = NULL;
                pain--;
            }
            else {
                std::cout << "Нет открытых процессов";
                _getch();
            }
            break;
        case '8':
            id = false;
            for (int i = 0; i < ex; i++) {
                if (excelApp[i].hProcess != NULL) {
                    id = true;
                    break;
                }
            }
            if (id) {
                TerminateProcess(excelApp[ex - 1].hProcess, 1);
                CloseHandle(excelApp[ex - 1].hThread);
                CloseHandle(excelApp[ex - 1].hProcess);
                notepadApp[ex - 1].hProcess = NULL;
                ex--;
            }
            else {
                std::cout << "Нет открытых процессов";
                _getch();
            }
            break;
        case '9':
            for (int a = 0; a < ex; a++) {
                if (excelApp[a].hProcess != NULL) {
                    TerminateProcess(excelApp[a].hProcess, 1);
                    CloseHandle(excelApp[a].hThread);
                    CloseHandle(excelApp[a].hProcess);
                    excelApp[a].hProcess = NULL;

                }
            }
            for (int a = 0; a < pain; a++) {
                if (paintApp[a].hProcess != NULL) {
                    TerminateProcess(paintApp[a].hProcess, 1);
                    CloseHandle(paintApp[a].hThread);
                    CloseHandle(paintApp[a].hProcess);
                    paintApp[a].hProcess = NULL;
                }
            }
            for (int a = 0; a < note; a++) {
                if (notepadApp[a].hProcess != NULL) {
                    TerminateProcess(notepadApp[a].hProcess, 1);
                    CloseHandle(notepadApp[a].hThread);
                    CloseHandle(notepadApp[a].hProcess);
                    notepadApp[a].hProcess = NULL;
                }
            }
            for (int a = 0; a < word; a++) {
                if (wordApp[a].hProcess != NULL) {
                    TerminateProcess(wordApp[a].hProcess, 1);
                    CloseHandle(wordApp[a].hThread);
                    CloseHandle(wordApp[a].hProcess);
                    wordApp[a].hProcess = NULL;
                }
            }
            break;
        case 'Q':
            um = false;
            for (int a = 0; a < ex; a++) {
                if (excelApp[a].hProcess != NULL) {
                    TerminateProcess(excelApp[a].hProcess, 1);
                    CloseHandle(excelApp[a].hThread);
                    CloseHandle(excelApp[a].hProcess);
                    excelApp[a].hProcess = NULL;

                }
            }
            for (int a = 0; a < pain; a++) {
                if (paintApp[a].hProcess != NULL) {
                    TerminateProcess(paintApp[a].hProcess, 1);
                    CloseHandle(paintApp[a].hThread);
                    CloseHandle(paintApp[a].hProcess);
                    paintApp[a].hProcess = NULL;
                }
            }
            for (int a = 0; a < note; a++) {
                if (notepadApp[a].hProcess != NULL) {
                    TerminateProcess(notepadApp[a].hProcess, 1);
                    CloseHandle(notepadApp[a].hThread);
                    CloseHandle(notepadApp[a].hProcess);
                    notepadApp[a].hProcess = NULL;
                }
            }
            for (int a = 0; a < word; a++) {
                if (wordApp[a].hProcess != NULL) {
                    TerminateProcess(wordApp[a].hProcess, 1);
                    CloseHandle(wordApp[a].hThread);
                    CloseHandle(wordApp[a].hProcess);
                    wordApp[a].hProcess = NULL;
                }
            }
            TerminateProcess(piApp[0].hProcess, 1);
            CloseHandle(piApp[0].hThread);
            CloseHandle(piApp[0].hProcess);
            break;
        case 'C':
                TerminateProcess(piApp[0].hProcess, 1);
                CloseHandle(piApp[0].hThread);
                CloseHandle(piApp[0].hProcess);
            break;
        case 'P':
            SuspendThread(piApp[0].hThread);
            break;
        case 'S':
            ResumeThread(piApp[0].hThread);
            break;
        default:
            break;
        }
    }

}