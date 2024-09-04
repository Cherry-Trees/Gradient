#include "utils.hpp"
#include <iostream>

using namespace std;


ostream& operator<<(ostream& out, const Matrixf<4, 4>& mat)
{

    for (int i = 0; i < 4; i++)
    {
        out << "|\t";
        for (int j = 0; j < 4; j++)
        {
            out << mat[i][j] << "\t";
        }
        out << "|\n";
    }

    return out;
}

ostream& operator<<(ostream& out, const Vector2f& vec)
{
    return out << "{ " << vec.x << ' ' << vec.y << " }";
}

ostream& operator<<(ostream& out, const Vector3f& vec)
{
    return out << "{ " << vec.x << ' ' << vec.y << ' ' << vec.z << " }";
}


int main() {

    // Vector3f x = {1, 2, 3};
    // Matrixf<3, 3> f = {{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // }};

    // cout << x << endl;
    // x.rotateX(0.01);
    // x.rotateY(0.01);
    // x.rotateZ(0.01);
    
    // cout << x << endl;

    // Mesh mesh(Triangle({1, 5, 4}, {1, 3, 4}, {0, -1, 2}));
    // auto red = std::make_shared<Color::Modifier>(Color::FG_RED);
    // mesh.setColor(red);

    const int W = 60;
    const int H = 30;

    // Color::Modifier red(Color::FG_RED);
    // Color::Modifier def(Color::FG_DEFAULT);



    std::wstring pixel = L"▀";

    cout << Color::RGB255{
                static_cast<unsigned>(160.5),
                static_cast<unsigned>(20),
                static_cast<unsigned>(255 / 3.)
            };

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            cout << "\033[38;2;" << y * 4 << ";10;" << 255 - (x * 2) << 'm'; 
            // cout << Color::RGB255{y * 4u, 
            //             20, 255u - (x / 2.)};
            cout << Color::RGB255{
                static_cast<unsigned>(y * 5),
                static_cast<unsigned>(20),
                static_cast<unsigned>(255 - (x * 4))
            };
            cout << '\xDB';
            // cout << "#";
            // cout << def;
            cout << Color::FG_DEFAULT;

        }
        cout << '\n';
    }

    cout << Color::FG_DEFAULT;

    // \033[38;2;<r>;<g>;<b>m     #Select RGB foreground color
    // \033[48;2;<r>;<g>;<b>m     #Select RGB background color

    // printf("\n");
    // printf("\x1B[31mTexting\033[0m\t\t");
    // printf("\x1B[32mTexting\033[0m\t\t");
    // printf("\x1B[33mTexting\033[0m\t\t");
    // printf("\x1B[34mTexting\033[0m\t\t");
    // printf("\x1B[35mTexting\033[0m\n");
    
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[37mTexting\033[0m\t\t");
    // printf("\x1B[3;43;30mHIIII\033[0m\n");
    
    // printf("\033[3;42;30mTexting\033[0m\t\t");
    // printf("\033[3;43;30mTexting\033[0m\t\t");
    // printf("\033[3;44;30mTexting\033[0m\t\t");
    // printf("\033[3;104;30mTexting\033[0m\t\t");
    // printf("\033[3;100;30mTexting\033[0m\n");

    // printf("\033[3;47;35mTexting\033[0m\t\t");
    // printf("\033[2;47;35mTexting\033[0m\t\t");
    // printf("\033[1;47;35mTexting\033[0m\t\t");
    // printf("\t\t");
    // printf("\n");

    // CONSOLE_SCREEN_BUFFER_INFOEX

    return 0;
}
