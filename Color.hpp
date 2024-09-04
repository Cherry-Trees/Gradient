#include <iostream>
// namespace Color {

//     enum Code 
//     {
//         FG_RED      = 31,
//         FG_GREEN    = 32,
//         FG_BLUE     = 34,
//         FG_DEFAULT  = 39,
//         BG_RED      = 41,
//         BG_GREEN    = 42,
//         BG_BLUE     = 44,
//         BG_DEFAULT  = 49
//     };

//     class Modifier 
//     {

//         private:
//             Code code;
        
//         public:
//             Modifier(Code pCode) : code(pCode) {}

//             friend std::ostream& operator<<(std::ostream& os, const Modifier& mod) 
//             {
//                 return os << "\033[" << mod.code << "m";
//             }
//     };
// }



// struct Color
// {   

//     enum Code
//     {
//         FG_RED      = 31,
//         FG_GREEN    = 32,
//         FG_BLUE     = 34,
//         FG_DEFAULT  = 39,
//         BG_RED      = 41,
//         BG_GREEN    = 42,
//         BG_BLUE     = 44,
//         BG_DEFAULT  = 49
//     };

//     struct RGB {unsigned int r, g, b;};

//     union
//     {
//         RGB color;
//         Code code;
//     };

//     Color(const unsigned int R, const unsigned int G, const unsigned int B) : r(R), g(G), b(B) {}

//     friend std::ostream& operator<<(std::ostream& out, const Color& color)
//     {
//         // return out << "\033[38;2;" << color.r << ";" << color.g << ";" << color.b << "m";
//                    //<< "\033[39m";

//         return out << "\033[38;2;" << color.r << ";" << color.g << ";" << color.b << 'm' << "\033[39m";
//     }

//     // friend std::ostream& operator<<(std::ostream& out, const Color::Code& code)
//     // {
//     //     return out << "\033[" << (unsigned char)(code) << "m";
//     // }


// };

namespace Color
{
    enum Code
    {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };

    struct RGB255   { unsigned r, g, b; };
    struct RGB1     { unsigned r, g, b; };

    std::ostream& operator<<(std::ostream& os, const Code& code)    {return os << "\033[" << (unsigned)code << "m";}
    std::ostream& operator<<(std::ostream& os, const RGB255& color) {return os << "\033[38;2;" << color.r << ';' << color.g << ';' << color.b << 'm';}
    std::ostream& operator<<(std::ostream& os, const RGB1& color)   {return os << "\033[38;2;" << static_cast<unsigned>(255.999 * color.r) << 
                                                                                           ';' << static_cast<unsigned>(255.999 * color.g) << 
                                                                                           ';' << static_cast<unsigned>(255.999 * color.b) << 'm';}
}

