// Copyright 2013 Dolphin Emulator Project / 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <string>

// Message alerts
enum MSG_TYPE
{
    INFORMATION,
    QUESTION,
    WARNING,
    CRITICAL
};

typedef bool (*MsgAlertHandler)(const char* caption, const char* text,
                                bool yes_no, int Style);
typedef std::string (*StringTranslator)(const char* text);

void RegisterMsgAlertHandler(MsgAlertHandler handler);
void RegisterStringTranslator(StringTranslator translator);

extern bool MsgAlert(bool yes_no, int Style, const char* format, ...)
#ifdef __GNUC__
    __attribute__((format(printf, 3, 4)))
#endif
    ;
void SetEnableAlert(bool enable);

#ifdef _MSC_VER
    #define SuccessAlert(format, ...) MsgAlert(false, INFORMATION, format, __VA_ARGS__)
    #define PanicAlert(format, ...) MsgAlert(false, WARNING, format, __VA_ARGS__)
    #define PanicYesNo(format, ...) MsgAlert(true, WARNING, format, __VA_ARGS__)
    #define AskYesNo(format, ...) MsgAlert(true, QUESTION, format, __VA_ARGS__)
    #define CriticalAlert(format, ...) MsgAlert(false, CRITICAL, format, __VA_ARGS__)
    // Use these macros (that do the same thing) if the message should be translated.
    #define SuccessAlertT(format, ...) MsgAlert(false, INFORMATION, format, __VA_ARGS__)
    #define PanicAlertT(format, ...) MsgAlert(false, WARNING, format, __VA_ARGS__)
    #define PanicYesNoT(format, ...) MsgAlert(true, WARNING, format, __VA_ARGS__)
    #define AskYesNoT(format, ...) MsgAlert(true, QUESTION, format, __VA_ARGS__)
    #define CriticalAlertT(format, ...) MsgAlert(false, CRITICAL, format, __VA_ARGS__)
#else
    #define SuccessAlert(format, ...) MsgAlert(false, INFORMATION, format, ##__VA_ARGS__)
    #define PanicAlert(format, ...) MsgAlert(false, WARNING, format, ##__VA_ARGS__)
    #define PanicYesNo(format, ...) MsgAlert(true, WARNING, format, ##__VA_ARGS__)
    #define AskYesNo(format, ...) MsgAlert(true, QUESTION, format, ##__VA_ARGS__)
    #define CriticalAlert(format, ...) MsgAlert(false, CRITICAL, format, ##__VA_ARGS__)
    // Use these macros (that do the same thing) if the message should be translated.
    #define SuccessAlertT(format, ...) MsgAlert(false, INFORMATION, format, ##__VA_ARGS__)
    #define PanicAlertT(format, ...) MsgAlert(false, WARNING, format, ##__VA_ARGS__)
    #define PanicYesNoT(format, ...) MsgAlert(true, WARNING, format, ##__VA_ARGS__)
    #define AskYesNoT(format, ...) MsgAlert(true, QUESTION, format, ##__VA_ARGS__)
    #define CriticalAlertT(format, ...) MsgAlert(false, CRITICAL, format, ##__VA_ARGS__)
#endif
