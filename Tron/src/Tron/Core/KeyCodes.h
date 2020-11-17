#pragma once

namespace Tron
{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space               = 32,
        Apostrophe          = 39, /* ' */
        Comma               = 44, /* , */
        Minus               = 45, /* - */
        Period              = 46, /* . */
        Slash               = 47, /* / */

        D0                  = 48, /* 0 */
        D1                  = 49, /* 1 */
        D2                  = 50, /* 2 */
        D3                  = 51, /* 3 */
        D4                  = 52, /* 4 */
        D5                  = 53, /* 5 */
        D6                  = 54, /* 6 */
        D7                  = 55, /* 7 */
        D8                  = 56, /* 8 */
        D9                  = 57, /* 9 */

        Semicolon           = 59, /* ; */
        Equal               = 61, /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
        Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

#define TN_KEY_SPACE           ::Tron::Key::Space
#define TN_KEY_APOSTROPHE      ::Tron::Key::Apostrophe    /* ' */
#define TN_KEY_COMMA           ::Tron::Key::Comma         /* , */
#define TN_KEY_MINUS           ::Tron::Key::Minus         /* - */
#define TN_KEY_PERIOD          ::Tron::Key::Period        /* . */
#define TN_KEY_SLASH           ::Tron::Key::Slash         /* / */
#define TN_KEY_0               ::Tron::Key::D0
#define TN_KEY_1               ::Tron::Key::D1
#define TN_KEY_2               ::Tron::Key::D2
#define TN_KEY_3               ::Tron::Key::D3
#define TN_KEY_4               ::Tron::Key::D4
#define TN_KEY_5               ::Tron::Key::D5
#define TN_KEY_6               ::Tron::Key::D6
#define TN_KEY_7               ::Tron::Key::D7
#define TN_KEY_8               ::Tron::Key::D8
#define TN_KEY_9               ::Tron::Key::D9
#define TN_KEY_SEMICOLON       ::Tron::Key::Semicolon     /* ; */
#define TN_KEY_EQUAL           ::Tron::Key::Equal         /* = */
#define TN_KEY_A               ::Tron::Key::A
#define TN_KEY_B               ::Tron::Key::B
#define TN_KEY_C               ::Tron::Key::C
#define TN_KEY_D               ::Tron::Key::D
#define TN_KEY_E               ::Tron::Key::E
#define TN_KEY_F               ::Tron::Key::F
#define TN_KEY_G               ::Tron::Key::G
#define TN_KEY_H               ::Tron::Key::H
#define TN_KEY_I               ::Tron::Key::I
#define TN_KEY_J               ::Tron::Key::J
#define TN_KEY_K               ::Tron::Key::K
#define TN_KEY_L               ::Tron::Key::L
#define TN_KEY_M               ::Tron::Key::M
#define TN_KEY_N               ::Tron::Key::N
#define TN_KEY_O               ::Tron::Key::O
#define TN_KEY_P               ::Tron::Key::P
#define TN_KEY_Q               ::Tron::Key::Q
#define TN_KEY_R               ::Tron::Key::R
#define TN_KEY_S               ::Tron::Key::S
#define TN_KEY_T               ::Tron::Key::T
#define TN_KEY_U               ::Tron::Key::U
#define TN_KEY_V               ::Tron::Key::V
#define TN_KEY_W               ::Tron::Key::W
#define TN_KEY_X               ::Tron::Key::X
#define TN_KEY_Y               ::Tron::Key::Y
#define TN_KEY_Z               ::Tron::Key::Z
#define TN_KEY_LEFT_BRACKET    ::Tron::Key::LeftBracket   /* [ */
#define TN_KEY_BACKSLASH       ::Tron::Key::Backslash     /* \ */
#define TN_KEY_RIGHT_BRACKET   ::Tron::Key::RightBracket  /* ] */
#define TN_KEY_GRAVE_ACCENT    ::Tron::Key::GraveAccent   /* ` */
#define TN_KEY_WORLD_1         ::Tron::Key::World1        /* non-US #1 */
#define TN_KEY_WORLD_2         ::Tron::Key::World2        /* non-US #2 */
#define TN_KEY_ESCAPE          ::Tron::Key::Escape
#define TN_KEY_ENTER           ::Tron::Key::Enter
#define TN_KEY_TAB             ::Tron::Key::Tab
#define TN_KEY_BACKSPACE       ::Tron::Key::Backspace
#define TN_KEY_INSERT          ::Tron::Key::Insert
#define TN_KEY_DELETE          ::Tron::Key::Delete
#define TN_KEY_RIGHT           ::Tron::Key::Right
#define TN_KEY_LEFT            ::Tron::Key::Left
#define TN_KEY_DOWN            ::Tron::Key::Down
#define TN_KEY_UP              ::Tron::Key::Up
#define TN_KEY_PAGE_UP         ::Tron::Key::PageUp
#define TN_KEY_PAGE_DOWN       ::Tron::Key::PageDown
#define TN_KEY_HOME            ::Tron::Key::Home
#define TN_KEY_END             ::Tron::Key::End
#define TN_KEY_CAPS_LOCK       ::Tron::Key::CapsLock
#define TN_KEY_SCROLL_LOCK     ::Tron::Key::ScrollLock
#define TN_KEY_NUM_LOCK        ::Tron::Key::NumLock
#define TN_KEY_PRINT_SCREEN    ::Tron::Key::PrintScreen
#define TN_KEY_PAUSE           ::Tron::Key::Pause
#define TN_KEY_F1              ::Tron::Key::F1
#define TN_KEY_F2              ::Tron::Key::F2
#define TN_KEY_F3              ::Tron::Key::F3
#define TN_KEY_F4              ::Tron::Key::F4
#define TN_KEY_F5              ::Tron::Key::F5
#define TN_KEY_F6              ::Tron::Key::F6
#define TN_KEY_F7              ::Tron::Key::F7
#define TN_KEY_F8              ::Tron::Key::F8
#define TN_KEY_F9              ::Tron::Key::F9
#define TN_KEY_F10             ::Tron::Key::F10
#define TN_KEY_F11             ::Tron::Key::F11
#define TN_KEY_F12             ::Tron::Key::F12
#define TN_KEY_F13             ::Tron::Key::F13
#define TN_KEY_F14             ::Tron::Key::F14
#define TN_KEY_F15             ::Tron::Key::F15
#define TN_KEY_F16             ::Tron::Key::F16
#define TN_KEY_F17             ::Tron::Key::F17
#define TN_KEY_F18             ::Tron::Key::F18
#define TN_KEY_F19             ::Tron::Key::F19
#define TN_KEY_F20             ::Tron::Key::F20
#define TN_KEY_F21             ::Tron::Key::F21
#define TN_KEY_F22             ::Tron::Key::F22
#define TN_KEY_F23             ::Tron::Key::F23
#define TN_KEY_F24             ::Tron::Key::F24
#define TN_KEY_F25             ::Tron::Key::F25

/* Keypad */
#define TN_KEY_KP_0            ::Tron::Key::KP0
#define TN_KEY_KP_1            ::Tron::Key::KP1
#define TN_KEY_KP_2            ::Tron::Key::KP2
#define TN_KEY_KP_3            ::Tron::Key::KP3
#define TN_KEY_KP_4            ::Tron::Key::KP4
#define TN_KEY_KP_5            ::Tron::Key::KP5
#define TN_KEY_KP_6            ::Tron::Key::KP6
#define TN_KEY_KP_7            ::Tron::Key::KP7
#define TN_KEY_KP_8            ::Tron::Key::KP8
#define TN_KEY_KP_9            ::Tron::Key::KP9
#define TN_KEY_KP_DECIMAL      ::Tron::Key::KPDecimal
#define TN_KEY_KP_DIVIDE       ::Tron::Key::KPDivide
#define TN_KEY_KP_MULTIPLY     ::Tron::Key::KPMultiply
#define TN_KEY_KP_SUBTRACT     ::Tron::Key::KPSubtract
#define TN_KEY_KP_ADD          ::Tron::Key::KPAdd
#define TN_KEY_KP_ENTER        ::Tron::Key::KPEnter
#define TN_KEY_KP_EQUAL        ::Tron::Key::KPEqual

#define TN_KEY_LEFT_SHIFT      ::Tron::Key::LeftShift
#define TN_KEY_LEFT_CONTROL    ::Tron::Key::LeftControl
#define TN_KEY_LEFT_ALT        ::Tron::Key::LeftAlt
#define TN_KEY_LEFT_SUPER      ::Tron::Key::LeftSuper
#define TN_KEY_RIGHT_SHIFT     ::Tron::Key::RightShift
#define TN_KEY_RIGHT_CONTROL   ::Tron::Key::RightControl
#define TN_KEY_RIGHT_ALT       ::Tron::Key::RightAlt
#define TN_KEY_RIGHT_SUPER     ::Tron::Key::RightSuper
#define TN_KEY_MENU            ::Tron::Key::Menu