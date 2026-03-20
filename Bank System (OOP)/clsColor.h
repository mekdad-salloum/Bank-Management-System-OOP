#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsColor
{

public:

    enum enColor {
        Black, Red, Green, Yellow, Blue, Magenta, Cyan, White,
        BrightBlack, BrightRed, BrightGreen, BrightYellow,
        BrightBlue, BrightMagenta, BrightCyan, BrightWhite
    };

    // RGB helper
    static string RGB(int r, int g, int b, bool isBackground = false)
    {
        return "\x1B[" + string(isBackground ? "48;2;" : "38;2;") +
            to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m";
    }

    // Reset
    static string Reset() { return "\x1B[0m"; }

    // Vivid RGB mapping
    static tuple<int, int, int> ToRGB(enColor color)
    {
        switch (color)
        {
        case Black:         return { 0,0,0 };
        case Red:           return { 255,0,0 };
        case Green:         return { 0,255,0 };
        case Yellow:        return { 255,255,0 };
        case Blue:          return { 0,0,255 };
        case Magenta:       return { 255,0,255 };
        case Cyan:          return { 0,255,255 };
        case White:         return { 255,255,255 };

        case BrightBlack:   return { 85,85,85 };
        case BrightRed:     return { 255,85,85 };
        case BrightGreen:   return { 85,255,85 };
        case BrightYellow:  return { 255,255,85 };
        case BrightBlue:    return { 85,85,255 };
        case BrightMagenta: return { 255,85,255 };
        case BrightCyan:    return { 85,255,255 };
        case BrightWhite:   return { 255,255,255 };
        }
        return { 255,255,255 }; // fallback
    }

    // RGB from enum
    static string ColorRGB(enColor color, bool isBackground = false)
    {
        auto [r, g, b] = ToRGB(color);
        return RGB(r, g, b, isBackground);
    }

};