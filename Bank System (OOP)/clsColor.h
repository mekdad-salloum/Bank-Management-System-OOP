#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsColor
{

public:

    enum enColor
    {
        // ANSI
        Black, Red, Green, Yellow, Blue, Magenta, Cyan, White,
        BrightBlack, BrightRed, BrightGreen, BrightYellow,
        BrightBlue, BrightMagenta, BrightCyan, BrightWhite,

        // Grays
        Gray, LightGray, DarkGray, Silver,

        // Reds
        DarkRed, Crimson, Maroon, Salmon, Coral, Tomato, IndianRed,

        // Oranges
        Orange, DarkOrange, OrangeRed, Peach,

        // Yellows
        DarkYellow, Gold, Khaki, LemonYellow,

        // Greens
        DarkGreen, ForestGreen, LimeGreen, Lime, OliveGreen,
        Olive, SeaGreen, Mint, Teal, DarkTeal,

        // Blues
        DarkBlue, Navy, RoyalBlue, SteelBlue, SkyBlue,
        LightBlue, DodgerBlue, Turquoise, Aquamarine,

        // Purples
        Purple, DarkPurple, Indigo, Violet, DarkMagenta,
        Plum, Lavender, Orchid,

        // Pinks
        Pink, HotPink, DeepPink, LightPink, Rose,

        // Browns
        Brown, SaddleBrown, Sienna, Chocolate, Tan, Beige, Wheat
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
            // ── Classic ANSI base colors ──────────────────────────
        case Black:             return { 0,   0,   0 };
        case Red:               return { 255, 0,   0 };
        case Green:             return { 0,   255, 0 };
        case Yellow:            return { 255, 255, 0 };
        case Blue:              return { 0,   0,   255 };
        case Magenta:           return { 255, 0,   255 };
        case Cyan:              return { 0,   255, 255 };
        case White:             return { 255, 255, 255 };

                  // ── Bright colors ─────────────────────────────────────
        case BrightBlack:       return { 128, 128, 128 };   // Dark gray
        case BrightRed:         return { 255, 128, 128 };   // Light red
        case BrightGreen:       return { 128, 255, 128 };   // Light green
        case BrightYellow:      return { 255, 255, 128 };   // Light yellow
        case BrightBlue:        return { 128, 128, 255 };   // Light blue
        case BrightMagenta:     return { 255, 128, 255 };   // Light magenta
        case BrightCyan:        return { 128, 255, 255 };   // Light cyan
        case BrightWhite:       return { 255, 255, 255 };   // Bright white

                        // ── Gray shades ───────────────────────────────────────
        case Gray:              return { 128, 128, 128 };
        case LightGray:         return { 211, 211, 211 };
        case DarkGray:          return { 64,  64,  64 };
        case Silver:            return { 192, 192, 192 };

                   // ── Red shades ────────────────────────────────────────
        case DarkRed:           return { 139, 0,   0 };
        case Crimson:           return { 220, 20,  60 };   // Crimson
        case Maroon:            return { 128, 0,   0 };   // Maroon
        case Salmon:            return { 250, 128, 114 };   // Salmon
        case Coral:             return { 255, 127, 80 };   // Coral
        case Tomato:            return { 255, 99,  71 };   // Tomato
        case IndianRed:         return { 205, 92,  92 };   // Indian red

                      // ── Orange shades ─────────────────────────────────────
        case Orange:            return { 255, 165, 0 };   // Orange
        case DarkOrange:        return { 255, 140, 0 };   // Dark orange
        case OrangeRed:         return { 255, 69,  0 };   // Orange red
        case Peach:             return { 255, 218, 185 };   // Peach

                  // ── Yellow shades ─────────────────────────────────────
        case DarkYellow:        return { 184, 134, 11 };   // Dark yellow
        case Gold:              return { 255, 215, 0 };   // Gold
        case Khaki:             return { 240, 230, 140 };   // Khaki
        case LemonYellow:       return { 255, 250, 205 };   // Lemon yellow

                        // ── Green shades ──────────────────────────────────────
        case DarkGreen:         return { 0,   100, 0 };   // Dark green
        case ForestGreen:       return { 34,  139, 34 };   // Forest green
        case LimeGreen:         return { 50,  205, 50 };   // Lime green
        case Lime:              return { 0,   255, 0 };   // Bright lime
        case OliveGreen:        return { 107, 142, 35 };   // Olive green
        case Olive:             return { 128, 128, 0 };   // Olive
        case SeaGreen:          return { 46,  139, 87 };   // Sea green
        case Mint:              return { 152, 255, 152 };   // Mint
        case Teal:              return { 0,   128, 128 };   // Teal
        case DarkTeal:          return { 0,   80,  80 };   // Dark teal

                     // ── Blue shades ───────────────────────────────────────
        case DarkBlue:          return { 0,   0,   139 };   // Dark blue
        case Navy:              return { 0,   0,   128 };   // Navy
        case RoyalBlue:         return { 65,  105, 225 };   // Royal blue
        case SteelBlue:         return { 70,  130, 180 };   // Steel blue
        case SkyBlue:           return { 135, 206, 235 };   // Sky blue
        case LightBlue:         return { 173, 216, 230 };   // Light blue
        case DodgerBlue:        return { 30,  144, 255 };   // Dodger blue
        case Turquoise:         return { 64,  224, 208 };   // Turquoise
        case Aquamarine:        return { 127, 255, 212 };   // Aquamarine

                       // ── Purple shades ─────────────────────────────────────
        case Purple:            return { 128, 0,   128 };   // Purple
        case DarkPurple:        return { 75,  0,   130 };   // Dark purple (indigo)
        case Indigo:            return { 75,  0,   130 };   // Indigo
        case Violet:            return { 238, 130, 238 };   // Violet
        case DarkMagenta:       return { 139, 0,   139 };   // Dark magenta
        case Plum:              return { 221, 160, 221 };   // Plum
        case Lavender:          return { 230, 230, 250 };   // Lavender
        case Orchid:            return { 218, 112, 214 };   // Orchid

                   // ── Pink shades ───────────────────────────────────────
        case Pink:              return { 255, 192, 203 };   // Pink
        case HotPink:           return { 255, 105, 180 };   // Hot pink
        case DeepPink:          return { 255, 20,  147 };   // Deep pink
        case LightPink:         return { 255, 182, 193 };   // Light pink
        case Rose:              return { 255, 0,   127 };   // Rose

                 // ── Brown shades ──────────────────────────────────────
        case Brown:             return { 165, 42,  42 };   // Brown
        case SaddleBrown:       return { 139, 69,  19 };   // Saddle brown
        case Sienna:            return { 160, 82,  45 };   // Sienna
        case Chocolate:         return { 210, 105, 30 };   // Chocolate
        case Tan:               return { 210, 180, 140 };   // Tan
        case Beige:             return { 245, 245, 220 };   // Beige
        case Wheat:             return { 245, 222, 179 };   // Wheat
        }
        return { 255, 255, 255 }; // fallback
    }
    
    // RGB from enum
    static string ColorRGB(enColor color, bool isBackground = false)
    {
        auto [r, g, b] = ToRGB(color);
        return RGB(r, g, b, isBackground);
    }

};